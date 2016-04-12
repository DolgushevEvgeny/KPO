#include "stdafx.h"
#include "Circle.h"
#include "ShapeVisitor.h"
#include <math.h>

const CLongNumber M_PI_MULT = 314;
const CLongNumber M_PI_DIV = 100;

CCircle::CCircle(const Point &center, const CLongNumber &radius)
: m_radius(radius)
{
	m_perimetr = M_PI_MULT * m_radius * 2 / M_PI_DIV;
	m_square = M_PI_MULT * Sqr(m_radius) / M_PI_DIV;
	m_shapeType = "CIRCLE";
}

void CCircle::Accept(CShapeVisitor &visitor)
{
	return visitor.Visit(*this);
}

CCircle::~CCircle()
{
}