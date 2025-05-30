#include "colors.h"

const Color Empty = BLACK;
const Color Green = GREEN;
const Color Red = RED;
const Color Orange = ORANGE;
const Color Yellow = YELLOW;
const Color Purple = PURPLE;
const Color Cyan = LIME;
const Color Blue = BLUE;

std::vector<Color> GetCellColors()
{
    return {Empty, Green, Red, Orange, Yellow, Purple, Cyan, Blue};
}