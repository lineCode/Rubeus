#include <awerere_collision_engine.h>

namespace Rubeus
{
	namespace Awerere
	{
		ACollisionEngine::ACollisionEngine(GraphicComponents::RWindowComponent & windowComponent, std::vector<RGameObject *> & gameObjects, const float & gridHeight, const float & gridWidth, const float & cellHeight, const float & cellWidth)
			:
			m_WindowComponent(windowComponent),
			m_CollisionGrid(gridHeight, gridWidth, cellHeight, cellWidth),
			m_GameObjects(gameObjects)
		{
			m_XFlags.reserve(m_GameObjects.size());
			m_YFlags.reserve(m_GameObjects.size());
		}

		ACollisionEngine::~ACollisionEngine()
		{
		}

		void ACollisionEngine::assignFlags()
		{
			size_t gameObjectsCount = m_GameObjects.size();

			for (int i = 0; i < gameObjectsCount; i++)
			{
				m_XFlags.push_back(std::vector<int>());
				m_YFlags.push_back(std::vector<int>());

				// X AXIS FLAGGING
				int leftFlag = m_GameObjects[i]->m_Sprite->getPosition().x / m_CollisionGrid.m_CellWidth;
				int rightFlag = (m_GameObjects[i]->m_Sprite->getPosition().x + m_GameObjects[i]->m_Sprite->getSize().x) / m_CollisionGrid.m_CellWidth;

				for (int p = 0; p < m_CollisionGrid.m_XCount; p++)
				{

					if (p >= leftFlag && p < rightFlag)
					{
						m_XFlags[i].push_back(1);
					}
					else
					{
						m_XFlags[i].push_back(0);
					}
				}

				// Y AXIS FLAGGING
				leftFlag = m_GameObjects[i]->m_Sprite->getPosition().y / m_CollisionGrid.m_CellHeight;
				rightFlag = (m_GameObjects[i]->m_Sprite->getPosition().y + m_GameObjects[i]->m_Sprite->getSize().y) / m_CollisionGrid.m_CellHeight;

				for (int p = 0; p < m_CollisionGrid.m_YCount; p++)
				{
					if (p >= leftFlag && p < rightFlag)
					{
						m_YFlags[i].push_back(1);
					}
					else
					{
						m_YFlags[i].push_back(0);
					}
				}

				// https://gamedev.stackexchange.com/questions/72030/using-uniform-grids-for-collision-detection-efficient-way-to-keep-track-of-wha
			}
		}

		void ACollisionEngine::executePhaseTwo()
		{
		}

		void ACollisionEngine::eraseCache()
		{
			m_FirstPassers.clear();
		}
	}
}
