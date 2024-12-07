#pragma once

#include "Precompile.h"
#include "Types.h"


namespace Tetris::Model::Blocks
{

	/// @brief Абстрактный креетер
	/// @tparam Base Базовый класс создаваемых объектов
	template <class Base>
	class AbstractCreator
	{
	public:
		/// @brief Конструктор
		AbstractCreator() {}

		/// @brief Виртуальный деструктор
		virtual ~AbstractCreator() {}

		/// @brief Создать объект
		/// @param color Цыет объекта 
		/// @return Возвращает созданный объект
		virtual Base* Create(TypeColor color) const = 0;
	};

	/// @brief Креетер
	/// @tparam C Тип создаваемого объекта
	/// @tparam Base Базовый класс создаваемых объектов
	template <class C, class Base>
	class Creator final : public AbstractCreator<Base>
	{
	public:
		/// @brief Конструктор
		Creator() {}

		/// @brief Виртуальный деструктор
		virtual ~Creator() {}

		/// @brief Создать блок
		/// @param color Цвет создаваемого блока
		/// @return Блок
		Base* Create(TypeColor color) const override{ return new C(color); }
	};

} // namespace