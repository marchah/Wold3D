#include <string>

#include "Scene.hh"
#include "CaseFactory.hh"

#include <fstream>

Scene::Scene()
{
	this->map_ = new Map();
}

Scene::~Scene()
{
	delete this->map_;
}

void	Scene::addLineToMap(const std::string &line, int x)
{
	this->map_->addLine();
	for (unsigned int i = 0; i < line.length(); i++)
	{
		ICase *tmp = CaseFactory::createCase(line[i]);

		if (tmp->isPlayer())
		{
			this->player_ = static_cast<APlayer*>(tmp);
			this->player_->setPOV(APlayer::POV(x, i, -1.0, 0.0));
			this->map_->addCase(CaseFactory::createCase(ICase::EMPTY));
		}
		else
			this->map_->addCase(tmp);
	}
}

void Scene::create(const std::string &pathMapFile)
{
	std::ifstream mapFile(pathMapFile, std::ios::in);
	std::string line;

	if (!mapFile)
		throw new SceneException("Error: can't open map file:" + pathMapFile);
	for (int x = 0; std::getline(mapFile, line); x++)
		this->addLineToMap(line, x);
	mapFile.close();
}

Map*		Scene::getMap() const
{
	return this->map_;
}

APlayer*	Scene::getPlayer() const
{
	return this->player_;
}