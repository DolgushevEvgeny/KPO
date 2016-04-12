#pragma once

#include "Shape.h"
#include "Point.h"

class CCircleCreator
{
public:
	std::unique_ptr<CShape> Create(const Point &center, CLongNumber radius) const;
	static CCircleCreator* GetInstance();
	static void DestroyInstance();

private:
	static CCircleCreator *inst;
	CCircleCreator() {};
};