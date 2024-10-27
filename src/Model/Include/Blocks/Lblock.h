#pragma once

#include "AbstractShape.h"


namespace Model::Blocks
{

	/// @brief класс L блок
	class Lblock : public AbstractShape
	{
	public:
		/// @brief Конструктор
		/// @param color цвет блока
		Lblock(Map::Color color) : AbstractShape(color) 
		{
			_positionToDescription = {
				{State::Up, {
					PosotionFiel( 0, 1 ), // *  o  *
					PosotionFiel( 0, 0 ), // *  0  *
					PosotionFiel( 0,-1 ), // *  o  o
					PosotionFiel( 1,-1 )
				}},
				{State::Right, {
					PosotionFiel( 1, 0 ), // *  *  *
					PosotionFiel( 0, 0 ), // o  0  o
					PosotionFiel(-1, 0 ), // o  *  *
					PosotionFiel(-1,-1 )
				}},
				{State::Down, {
					PosotionFiel( 0,-1 ), // o  o  *
					PosotionFiel( 0, 0 ), // *  0  *
					PosotionFiel( 0, 1 ), // *  o  *
					PosotionFiel(-1, 1 )
				}},
				{State::Left, {
					PosotionFiel(-1, 0 ), // *  *  o
					PosotionFiel( 0, 0 ), // o  0  o
					PosotionFiel( 1, 0 ), // *  *  *
					PosotionFiel( 1, 1 )
				}}
			};

		};

	};

} // namespace