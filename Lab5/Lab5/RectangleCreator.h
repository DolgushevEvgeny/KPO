#pragma once

#include "Shape.h"
#include "Point.h"

class CRectangleCreator
{
public:
	std::unique_ptr<CShape> Create(const Point &point1, const Point &point2) const;
	static CRectangleCreator* GetInstance();
	static void DestroyInstance();

private:
	static CRectangleCreator *inst;
	CRectangleCreator() {};
};