#ifndef	SCENE_HH_
#define SCENE_HH_

#include "APlayer.hh"
#include "Map.hh"

class	Scene
{
	Map		*map_;
	APlayer *player_;

	Scene & operator=(const Scene & s) { return *this; }
	Scene(const Scene & s) {}
public:
	Scene();
	~Scene();
	void		create(const std::string &pathMapFile);
	Map*		getMap() const;
	APlayer*	getPlayer() const;
private:
	void addLineToMap(const std::string &line, int x);
};

class SceneException : public std::exception
{
	std::string   _message;
public:
	SceneException(std::string const &msg) : _message(msg) {}
	~SceneException() throw() {}
	std::string const &   What() const throw() {return (this->_message);}
};

#endif // SCENE_HH_