#pragma once
#include "Point.h"
#include "Shape.h" 

class CCircle : public CShape
{
public:
	CCircle(Point center, double radius);
	~CCircle();

private:
	double m_radius;
};

