#pragma once

#include "Model/AbstractShape.h"

class Iblock : public AbstractShape
{
public:

	Iblock(DiscreptionShape shape) : AbstractShape(shape) {};

private:

	std::array<std::array<sf::Vector2i,4>, 3>& Stages() override
	{
		static bool initResult;
		static std::array<std::array<sf::Vector2i,4>, 3> result;

		if (initResult) return result;

		result[0] = std::array<sf::Vector2i,4>({{-2,0},{0,-2},{2,0},{0,2}});
		result[1] = std::array<sf::Vector2i,4>({{-2,0},{0,-2},{2,0},{0,2}});
		result[2] = std::array<sf::Vector2i,4>({{1,0},{0,1},{-1,0},{0,-1}});

		initResult = true;
		return result;
	};
};