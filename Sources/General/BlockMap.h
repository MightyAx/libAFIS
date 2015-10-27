#ifndef GENERAL_BLOCKMAP_H
#define GENERAL_BLOCKMAP_H

#include "General/Calc.h"
#include "General/Point.h"
#include "General/Size.h"
#include "General/RectangleC.h"

typedef struct PointGrid PointGrid;
typedef struct RectangleGrid RectangleGrid;
typedef struct BlockMap BlockMap;

struct PointGrid
{
    int *allX;
    int *allY;
};

struct RectangleGrid
{
    PointGrid corners;
};

struct BlockMap
{
    Size pixelCount;
    Size blockCount;
    Size cornerCount;
    RectangleC allBlocks;
    RectangleC allCorners;
    PointGrid corners;
    RectangleGrid blockAreas;
    PointGrid blockCenters;
    RectangleGrid cornerAreas;
};

BlockMap BlockMap_Construct(const Size *pixelSize, int maxBlockSize);

PointGrid PointGrid_Construct(const Size *s);
void PointGrid_Destruct(PointGrid *me);
Point PointGrid_GetPointFromCoordinates(const PointGrid *me, int y, int x);
Point PointGrid_GetPointFromPoint(const PointGrid *me, const Point *at);

RectangleGrid RectangleGrid_Construct(const PointGrid *c);
RectangleC RectangleGrid_GetRectangleCFromCoordinates(const RectangleGrid *me, int y, int x);
RectangleC RectangleGrid_GetRectangleCFromPoint(const RectangleGrid *me, const Point *at);

#endif
