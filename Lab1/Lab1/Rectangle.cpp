#include "stdafx.h"
#include "Rectangle.h"
#include <cmath>

CRectangle::CRectangle(Point A, Point B)
	: m_sideA(abs(A.x - B.x))
	, m_sideB(abs(A.y - B.y))
{
	m_perimetr = (m_sideA + m_sideB) * 2;
	m_square = m_sideA * m_sideB;
	m_shapeType = "RECTANGLE";
}

CRectangle::~CRectangle()
{
}