#pragma once
#include "Point.h"
#include "Shape.h" 

class CRectangle : public CShape
{
public:
	CRectangle(Point A, Point B);
	~CRectangle();

private:
	int m_sideA;
	int m_sideB;
};

