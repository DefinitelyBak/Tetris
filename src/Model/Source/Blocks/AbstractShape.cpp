#include "Blocks/AbstractShape.h"


namespace Model::Blocks
{

	AbstractShape::AbstractShape(Map::Color color): _color(color){};

    AbstractShape::DescriptionFigure AbstractShape::GetDescription()
	{
        if (_positionToDescription.contains(_state))
            return _positionToDescription[_state];

        return AbstractShape::DescriptionFigure();
    };

    AbstractShape::State AbstractShape::GetState() const
    {
        return _state;
    };

	Map::Color AbstractShape::GetColor() const
	{
		return _color;
	};

    void AbstractShape::RotateShape()
    {
		if(!_positionToDescription.contains(_state))
			return;
		
		ChangeState(_state);
	};

    AbstractShape::DescriptionFigure AbstractShape::TryRotateShape() 
	{
		State state = _state;
		ChangeState(state);

		if(_positionToDescription.contains(state))
			return _positionToDescription[state];

		return AbstractShape::DescriptionFigure();
	};

    void AbstractShape::ChangeState(State& state)
	{
		switch (state)
		{
		case State::Left:
			state = State::Up;
			break;
		case State::Up:
			state = State::Right;
			break;				
		case State::Right:
			state = State::Down;
			break;
		case State::Down:
			state = State::Left;
			break;
		default:
			break;
		}
    };

}