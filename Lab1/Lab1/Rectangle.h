#pragma once
#include "Point.h"
#include "Shape.h" 

class CRectangle : public CShape
{
public:
	CRectangle(Point A, Point B);
	~CRectangle();

private:
	double m_sideA;
	double m_sideB;
};

