/**
 * @file		Include/awerere_collide_data_object.h.
 *
 * @brief	Declares the Collide data class
 */

#pragma once

namespace Rubeus
{
	namespace Awerere
	{
		/**
		 * @class	ACollideData
		 *
		 * @brief	A container holding information related to detected collisions.
		 */
		class ACollideData
		{
		private:

			/** @brief	Variable storing if the two colliders are intersecting */
			const bool m_IsIntersect;

			/** @brief	Variable storing the value of the gap between the two colliders.
						(is less than 0 if colliders are intersecting) */
			const float m_Gap;

		public:

			/**
			 * @fn		ACollideData(const bool isIntersect, const float gap)
			 *
			 * @brief	Constructor
			 * @warning
			 *
			 * @param	isIntersect	Bool containing if the colliders are intersecting.
			 * @param	gap			The penetration distance of the collision.
			 */
			ACollideData(const bool isIntersect, const float gap);

			/**
			 * @fn		~ACollideData()
			 *
			 * @brief	Destructor
			 */
			~ACollideData();

			/**
			 * @fn		inline const bool & getIsIntersect() const
			 *
			 * @brief	Returns if the colliders have intersected
			 *
			 * @return	The intersection boolean.
			 */
			inline const bool & getIsIntersect() const { return m_IsIntersect; }

			/**
			 * @fn		inline const float & getGap() const
			 *
			 * @brief	Returns the separation gap between the colliders
			 */
			inline const float & getGap() const { return m_Gap; }

		protected:
		};
	}
}