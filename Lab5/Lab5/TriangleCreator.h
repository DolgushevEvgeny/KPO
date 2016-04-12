#pragma once

#include "Shape.h"
#include "Point.h"

class CTriangleCreator
{
public:
	std::unique_ptr<CShape> Create(const Point &point1, const Point &point2, const Point &point3) const;
	static CTriangleCreator* GetInstance();
	static void DestroyInstance();

private:
	static CTriangleCreator *inst;
	CTriangleCreator() {};
};