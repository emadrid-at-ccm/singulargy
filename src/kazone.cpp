#include <stdint.h>

namespace ep {

namespace tile {

struct Abbey {
    constexpr static auto quantity = 4;
};

enum Side: uint8_t { EAST, NORTH, WEST, SOUTH, NONE };

struct RoadAbbey {
    constexpr static auto quantity = 2; // 6
    constexpr static auto road1 = EAST;
    constexpr static auto connect1 = NONE;
};

struct Straight {
    constexpr static auto quantity = 8; // 14
    constexpr static auto road1 = EAST;
    constexpr static auto road2 = WEST;
    constexpr static auto connect1 = WEST;
    constexpr static auto connect2 = EAST;
};

struct Elbow {
    constexpr static auto quantity = 9; // 23
    constexpr static auto road1 = EAST;
    constexpr static auto road2 = NORTH;
    constexpr static auto connect1 = NORTH;
    constexpr static auto connect2 = EAST;
};

struct Tee {
    constexpr static auto quantity = 4; // 27
    constexpr static auto road1 = EAST;
    constexpr static auto road2 = WEST;
    constexpr static auto road3 = SOUTH;
    constexpr static auto connect1 = NONE;
    constexpr static auto connect2 = NONE;
    constexpr static auto connect3 = NONE;
};

struct Cross {
    constexpr static auto quantity = 1; // 28
    constexpr static auto road1 = EAST;
    constexpr static auto road2 = WEST;
    constexpr static auto road3 = SOUTH;
    constexpr static auto road4 = NORTH;
    constexpr static auto connect1 = NONE;
    constexpr static auto connect2 = NONE;
    constexpr static auto connect3 = NONE;
    constexpr static auto connect4 = NONE;
};

template<int Q> struct QT { constexpr static auto quantity = Q; };
template<int N, Side S, Side To> struct M;
template<Side S, Side To> struct M<1, S, To> {
    constexpr static auto moon1 = S;
    constexpr static auto moon1to = To;
};

struct Moon: QT<5>, M<1, EAST, NONE> {};

struct BarMoon: QT<4>, M<1, EAST, NONE> {};

}

}
