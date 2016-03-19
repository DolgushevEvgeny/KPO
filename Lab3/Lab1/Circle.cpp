#include "stdafx.h"
#include "Circle.h"
#include <math.h>

const double M_PI = 3.1415926535897932384626433832795;

CCircle::CCircle(Point center, double radius)
	: m_radius(radius)
{
	m_perimetr = M_PI * m_radius * 2;
	m_square = M_PI * pow(m_radius, 2);
	m_shapeType = "CIRCLE";
}

CCircle::~CCircle()
{
}