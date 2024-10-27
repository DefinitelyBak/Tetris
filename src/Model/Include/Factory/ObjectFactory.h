#pragma once

#include "AbstractCreator.h"
#include <map>

template <class Base, class IdType>
class ObjectFactory
{
protected:
	typedef AbstractCreator<Base> AbstractFactory;
	typedef std::map<IdType, AbstractFactory*> FactoryMap;
	FactoryMap	_factory;

public:
	ObjectFactory() {}
	virtual ~ObjectFactory() {};

	template <class C>
	void add(const IdType& id)
	{
		registerClass(id, new Creator<C, Base>());
	}

protected:
	void registerClass(const IdType& id, AbstractFactory* p)
	{
		typename FactoryMap::iterator it = _factory.find(id);
		if (it == _factory.end())
			_factory[id] = p;
		else
			delete p;
	}
};