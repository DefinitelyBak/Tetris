#pragma once
/*
#include "model/AbstractShape.h"
#include "SFML/System/Vector2.hpp"

#include "data/DiscreptionModel.h"
#include "data/Command.h"

class ModelMap
{
public:
	ModelMap(Size sizeMap);

	void SetShape(std::weak_ptr<AbstractShape> shapePtr);

	void Update();

	bool CheckPosition(std::array<sf::Vector2i, 4>);

	int  CheckTetris();

	DiscreptionModel GetConfig();

private:
	bool CheakLine(int numberLine);

	int GetIdColor(sf::Color color);

	std::weak_ptr<AbstractShape> _actualShapePtr; 

	Size _sizeMap;

	std::vector<int> _map;

	std::array<sf::Vector2i, 4> _lastCoordinates; 
};
*/