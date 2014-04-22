#ifndef	IWINDOW_HH_
#define IWINDOW_HH_

#include "Scene.hh"

#include <vector>

class	IWindow
{
public:

	typedef struct s_color
	{
		int red;
		int green;
		int blue;
	} Color;

	virtual ~IWindow() {}
	virtual void	run(Scene *scene) = 0;
	virtual bool	windowIsOpen() const = 0;
	virtual void	drawLine(float posX, float drawStart, float drawEnd, const IWindow::Color &color) const = 0;
	virtual int		getHeight() const = 0;
	virtual int		getWidth() const = 0;
};

#endif // IWINDOW_HH_