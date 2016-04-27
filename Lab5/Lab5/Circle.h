#pragma once
#include "Point.h"
#include "Shape.h"

class CLongNumber;

class CCircle : public CShape
{
public:
	CCircle(const Point &center, const CLongNumber &radius);
	void Accept(CShapeVisitor &visitor) const;
	~CCircle();
	CLongNumber m_radius;	
};