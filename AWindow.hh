#ifndef	AWINDOW_HH_
#define AWINDOW_HH_

#include "IWindow.hh"

#define _USE_MATH_DEFINES
#include <math.h>

#include "AlgoRayCasting.hh"

class	AWindow : public IWindow
{
protected:
	int		height_;
	int		width_;
	IAlgo	*algo_;


	virtual AWindow & operator=(const AWindow & w) { this->height_ = w.height_; this->width_ = w.width_; return *this; }
	AWindow(const AWindow & w) : height_(w.height_), width_(w.width_) {}
public:
	AWindow(int height, int width) : height_(height), width_(width) {	}
	virtual ~AWindow() {}
	virtual void	run(Scene *scene) = 0;
	virtual bool	windowIsOpen() const = 0;
	virtual void	drawLine(float posX, float drawStart, float drawEnd, const IWindow::Color &color) const = 0;
	virtual int		getHeight() const { return this->height_;}
	virtual int		getWidth() const { return this->width_;}
};

#endif // AWINDOW_HH_