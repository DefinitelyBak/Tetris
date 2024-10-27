#pragma once

#include "ObjectFactory.h"
#include "model/AbstractShape.h"

enum class IdShape {
	Iblock,
	Tblock,
	Oblock,
	Jblock
};

class ShapeFactory:public ObjectFactory<AbstractShape, IdShape>
{
public:
	AbstractShape* Create(IdShape id, DiscreptionShape shape) {
		return _factory[id]->Create(shape);
	}

	int Size() const {
		return _factory.size();
	};
};

