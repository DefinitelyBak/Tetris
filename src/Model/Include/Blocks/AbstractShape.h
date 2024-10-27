#pragma once

#include "data/DiscreptionShape.h"
#include "data/Command.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

#include <vector>
#include <array>

class AbstractShape
{
public:
	enum class Stage : int
	{
		First = 0,
		Second,
		Third,
		Fourth 
	};
	
	AbstractShape(DiscreptionShape shape);
	virtual ~AbstractShape(){};

	/// @brief 
	/// @param cm 
	virtual void Move(Command cm);

	/// @brief 
	/// @param next 
	/// @return 
	virtual DiscreptionShape GetDescription(bool next = false);

	virtual sf::Vector2i GetOffset(Command cmd); 

private:

	virtual std::array<std::array<sf::Vector2i,4>, 3>& Stages() = 0;

private:
	sf::Color _color;

	sf::Vector2i _center;

	Stage _stage;
};

