
#include <iostream>
#include <fstream>

#include "WindowSFML.hh"
#include "Scene.hh"

int main()
{
	Scene *scene = new Scene();


	scene->create("./Ressources/Maps/map3.txt");
	scene->getMap()->displayMapOnConsole();

	IWindow *w = new WindowSFML(640, 960);

	while (w->windowIsOpen())
	{
		w->run(scene);
	}
	std::string cmd;
	std::getline(std::cin, cmd);

	delete scene;
	delete w;
	return 1;
}
