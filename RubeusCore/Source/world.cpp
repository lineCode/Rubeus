#include <world.h>

namespace Rubeus
{
	RWorld::RWorld()
	{
	}

	RWorld::RWorld(std::vector<RGameObject*> & gameObjects)
		: m_ActiveGameObjects(gameObjects)
	{
	}

	void RWorld::tick()
	{
		for (auto& item : m_ActiveGameObjects)
		{
			item->tick();
		}
	}

	RWorld::~RWorld()
	{
	}

	void RWorld::add(RGameObject & gameObject)
	{
		m_ActiveGameObjects.push_back(&gameObject);
	}

	void RWorld::add(const std::vector<RGameObject *> & gameObjects)
	{
		for (auto item : gameObjects)
		{
			m_ActiveGameObjects.push_back(item);
		}
	}

	void RWorld::setObjectArray(std::vector<RGameObject *> & gameObjects)
	{
		m_ActiveGameObjects = gameObjects;
	}
}
