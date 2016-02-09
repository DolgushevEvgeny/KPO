#pragma once
#include "Point.h"
#include "Shape.h" 

class CCircle : public CShape
{
public:
	CCircle(Point center, double radius);
	~CCircle();

private:
	int m_radius;
};

