#pragma once

#include "data/DiscreptionShape.h"

template <class Base>
class AbstractCreator
{
public:
	AbstractCreator() {}
	virtual ~AbstractCreator() {}
	virtual Base* Create(DiscreptionShape shape) const = 0;
};

template <class C, class Base>
class Creator : public AbstractCreator<Base>
{
public:
	Creator() { }
	virtual ~Creator() {}
	Base* Create(DiscreptionShape shape) const { return new C(shape); }
};