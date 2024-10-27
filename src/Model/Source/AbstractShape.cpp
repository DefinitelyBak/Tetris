#include "Model/AbstractShape.h"

#include <algorithm>

AbstractShape::AbstractShape(DiscreptionShape shape) :
	_color(shape.color), _center(shape.coordinates[0]), _stage(Stage::First)
{}

void AbstractShape::Move(Command cmnd)
{
	switch (cmnd)
	{
	case Command::Left:
		_center.x -= 1;
		break;
	case Command::Up:
		_stage = (static_cast<int>(_stage) + 1 > 3) ? Stage(0) : Stage(static_cast<int>(_stage) + 1);
		break;
	case Command::Right:
		_center.x += 1;
		break;
	case Command::Down:
		_center.y += 1;
		break;
	default:
		break;
	}
}

DiscreptionShape AbstractShape::GetDescription(bool next)
{
	std::array<sf::Vector2i, 4> position;
	auto stages = Stages();
	int localStage;
	int stage = static_cast<int>(_stage);
	
	if (!next)
		localStage = stage;
	else
		localStage = static_cast<int>((stage + 1 > 3) ? Stage(0) : Stage(stage + 1));


	position[0] = {0,0};
	position[1] = stages[0][localStage];
	position[2] = stages[1][localStage];
	position[3] = stages[2][localStage];

	std::for_each(position.begin(), position.end(), [this](auto& n) { n += _center; });
	
	DiscreptionShape result;
	result.color = _color;
	result.coordinates = position;

    return result;
}

sf::Vector2i AbstractShape::GetOffset(Command cmd)
{
	auto cmp = [](const sf::Vector2i& a, const sf::Vector2i& b)
	{
		if (a.x < b.x && a.y <= b.y) return true;
		return false;
	};
	int stage = static_cast<int>(_stage);

	std::array<sf::Vector2i, 3> offset;
	offset[0] = Stages()[0][stage];
	offset[1] = Stages()[1][stage];
	offset[2] = Stages()[2][stage];
	if (cmd == Command::L_UP)
		return *std::min_element(offset.begin(), offset.end(), cmp);
	if (cmd == Command::R_UP)
		return *std::max_element(offset.begin(), offset.end(), cmp);

    return sf::Vector2i(0, 0);
}