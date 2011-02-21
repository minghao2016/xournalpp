#include "RemoveLayerUndoAction.h"

#include "../model/Page.h"
#include "../model/Layer.h"
#include "../control/Control.h"
#include "../model/Document.h"

RemoveLayerUndoAction::RemoveLayerUndoAction(XojPage * page, Layer * layer, int layerPos) {
	this->page = page;
	this->layer = layer;
	this->layerPos = layerPos;
}

RemoveLayerUndoAction::~RemoveLayerUndoAction() {
	if (!undone) {
		// The layer was NOT undone, also NOT restored
		delete this->layer;
	}
}

String RemoveLayerUndoAction::getText() {
	return "Delete layer";
}

bool RemoveLayerUndoAction::undo(Control * control) {
	this->page->insertLayer(this->layer, layerPos);
	Document * doc = control->getDocument();
	int id = doc->indexOf(this->page);
	control->getWindow()->getXournal()->layerChanged(id);

	control->getWindow()->updateLayerCombobox();

	this->undone = true;

	return true;
}

bool RemoveLayerUndoAction::redo(Control * control) {
	this->page->removeLayer(this->layer);
	Document * doc = control->getDocument();
	int id = doc->indexOf(this->page);
	control->getWindow()->getXournal()->layerChanged(id);

	control->getWindow()->updateLayerCombobox();

	this->undone = false;

	return true;
}
