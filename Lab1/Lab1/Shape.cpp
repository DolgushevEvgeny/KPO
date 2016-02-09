#include "stdafx.h"
#include "Shape.h"

using namespace std;

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

int CShape::GetPerimetr() const
{
	return (int)m_perimetr;
}

int CShape::GetSquare() const
{
	return (int)m_square;
}

std::string CShape::GetType() const
{
	return m_shapeType;
}