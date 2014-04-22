#ifndef	WINDOW_SFML_HH_
#define WINDOW_SFML_HH_

#include "AWindow.hh"

#include <SFML/Graphics.hpp>

class	WindowSFML : public AWindow
{
	sf::RenderWindow	*window_;
	sf::Clock			clock_;

	WindowSFML(const WindowSFML & w) : AWindow(w.height_, w.width_) { this->clock_ = w.clock_; }
	virtual WindowSFML & operator=(const WindowSFML & w) { this->height_ = w.height_; this->width_ = w.width_; this->clock_ = w.clock_; return *this; }
public:
	WindowSFML(int height, int width, const std::string& nameWindow = "Wolf3D");
	
	virtual ~WindowSFML();
	virtual void	run(Scene *scene);
	virtual bool	windowIsOpen() const;
	virtual void	drawLine(float posX, float drawStart, float drawEnd, const IWindow::Color &color) const;
private:
	virtual void	drawFloor() const;
	virtual void	drawCeil() const;
	virtual void	display() const;

};

#endif // WINDOW_SFML_HH_