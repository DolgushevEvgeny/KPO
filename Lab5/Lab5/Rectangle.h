#pragma once
#include "Point.h"
#include "Shape.h" 

class CRectangle : public CShape
{
public:
	CRectangle(Point A, Point B);
	void Accept(CShapeVisitor &visitor);
	~CRectangle();

	CLongNumber m_sideA;
	CLongNumber m_sideB;
};