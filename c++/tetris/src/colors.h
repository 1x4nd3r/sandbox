#pragma once
#include <raylib.h>
#include <vector>

#define NAVY       CLITERAL(Color){ 11, 33, 66, 255 }
#define BABYPINK   CLITERAL(Color){ 247, 212, 231, 255 }

extern const Color Empty;
extern const Color Green;
extern const Color Red;
extern const Color Orange;
extern const Color Yellow;
extern const Color Purple;
extern const Color Cyan;
extern const Color Blue;

extern const Color DarkBlue;
extern const Color LightBlue;

std::vector<Color> GetCellColors();