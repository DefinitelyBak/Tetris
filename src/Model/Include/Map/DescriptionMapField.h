#pragma once


namespace Model::Map
{
    /// @brief Цвет поля карты
    enum class Color: int
    {
        None,
        Red,
        Green,
        Yellow,
        Blue,
        Orange
    };

    /// @brief Описание поля карты
    struct Field
    {
        Field(Color color = Color::None, int x = 0, int y = 0):
            color{color}, x{x}, y{y} {};
          
        Color color {Color::None};
        int x {0};
        int y {0};
    };

} // namespace