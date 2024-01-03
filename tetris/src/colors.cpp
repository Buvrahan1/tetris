#include "colors.h"
#include "vector.h"

const Color darkGrey = {26, 31, 40, 255};
const Color green = {47, 230, 23, 255};
const Color red = {232, 18, 18, 255};
const Color orange = {226, 116, 17, 255};
const Color yellow = {237, 234, 4, 255};
const Color purple = {166, 0, 247, 255};
const Color cyan = {21, 204, 209, 255};
const Color blue = {13, 64, 216, 255};
const Color lightBlue = {59, 85, 162, 255};
const Color darkBlue = {44, 44, 127, 255};
const Color themaDarkGreen = {1, 50, 32, 255};
const Color themaGreen = {2, 113, 72, 255};

vectorClass<Color> GetCellColors()
{
    vectorClass<Color> CellColors;
    CellColors.push(darkGrey);
    CellColors.push(green);
    CellColors.push(red);
    CellColors.push(orange);
    CellColors.push(yellow);
    CellColors.push(purple);
    CellColors.push(cyan);
    CellColors.push(blue);
    return CellColors;
}