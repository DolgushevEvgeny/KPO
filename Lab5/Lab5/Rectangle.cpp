#include "stdafx.h"
#include "Rectangle.h"
#include "ShapeVisitor.h"
#include <cmath>

CRectangle::CRectangle(Point A, Point B)
: m_sideA(A.x - B.x)
, m_sideB(A.y - B.y)
{
	m_sideA.MakePositive();
	m_sideB.MakePositive();
	m_perimetr = (m_sideA + m_sideB) * 2;
	m_square = m_sideA * m_sideB;
	m_shapeType = "RECTANGLE";
}

void CRectangle::Accept(CShapeVisitor &visitor)
{
	return visitor.Visit(*this);
}

CRectangle::~CRectangle()
{
}