#include "Types.h"


namespace Tetris::Model
{

	Offsets operator+(const Offsets& lhs, const Offsets& rhs)
    {
        Offsets res;

        for(int i = 0; i < 5; ++i)
            res[i] = lhs[i] + rhs[i];

        return res;
    }

	Offsets operator-(const Offsets& lhs, const Offsets& rhs)
    {
        Offsets res;

        for(int i = 0; i < 5; ++i)
            res[i] = lhs[i] - rhs[i];

        return res;
    }

	bool operator==(const Offsets& lhs, const Offsets& rhs)
    {
        for(int i = 0; i < 5; ++i)
            if (!(lhs[i] == rhs[i])) return false;

        return true;
    }

    bool operator!=(const Offsets& lhs, const Offsets& rhs)
    {
        return !(lhs == rhs);
    }

    Position operator+(const Position& lhs, const Position& rhs)
    {
        Position res;

        res.first = lhs.first + rhs.first;
        res.second = lhs.second + rhs.second;

        return res;
    }

    Position operator-(const Position& lhs, const Position& rhs)
    {
        Position res;

        res.first = lhs.first - rhs.first;
        res.second = lhs.second - rhs.second;

        return res;
    }

    bool operator==(const Position& lhs, const Position& rhs)
    {
        if(lhs.first != rhs.first || lhs.second != rhs.second) return false;

        return true;
    }

    bool operator!=(const Position& lhs, const Position& rhs)
    {
        return !(lhs == rhs);
    }

    Offsets operator+(const Offsets& lhs, const Position& rhs)
    {
        Offsets res;

        for(int i = 0; i < 5; ++i)
            res[i] = lhs[i] + rhs;

        return res;
    }

	Offsets operator+(const Position& lhs, const Offsets& rhs)
    {
        return rhs + lhs;
    }

	Offsets operator-(const Offsets& lhs, const Position& rhs)
    {
        Offsets res;

        for(int i = 0; i < 5; ++i)
            res[i] = lhs[i] - rhs;

        return res;
    }

	Positions operator+(const Positions& lhs, const Position& rhs)
    {
        Positions res;

        for(int i = 0; i < 4; ++i)
            res[i] = lhs[i] + rhs;

        return res;
    }

	Positions operator+(const Position& lhs, const Positions& rhs)
    {
        return rhs + lhs;
    }

	Positions operator-(const Positions& lhs, const Position& rhs)
    {
        Positions res;

        for(int i = 0; i < 4; ++i)
            res[i] = lhs[i] - rhs;

        return res;  
    }

}