#include "stdafx.h"
#include "Shape.h"


CShape::CShape()
{
}


CShape::~CShape()
{
}

std::string CShape::GetInformation()
{
	return GetType() + ": P=" + std::to_string(GetPerimetr()) + "; S=" + std::to_string(GetSquare());
}

double CShape::GetPerimetr() const
{
	return m_perimetr;
}

double CShape::GetSquare() const
{
	return m_square;
}

std::string CShape::GetType() const
{
	return m_shapeType;
}