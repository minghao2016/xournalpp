/*
 * Xournal++
 *
 * A job which redraws a page or a page region
 *
 * @author Xournal Team
 * http://xournal.sf.net
 *
 * @license GPL
 */

#ifndef __RENDERJOB_H__
#define __RENDERJOB_H__

#include "Job.h"

class Rectangle;
class PageView;

class RenderJob: public Job {
public:
	RenderJob(PageView * view);
	virtual ~RenderJob();

public:
	virtual JobType getType();

	void * getSource();

	void run();

public:
	static void repaintRectangle(PageView * view, Rectangle * rect);

private:
	void repaintRectangle(Rectangle * rect);

private:
	PageView * view;
};

#endif /* __RENDERJOB_H__ */
