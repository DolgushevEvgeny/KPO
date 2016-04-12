#include "stdafx.h"
#include "Shape.h"

using namespace std;

CShape::CShape()
{
}


CShape::~CShape()
{
}

//std::string CShape::GetInformation()
//{
//	return GetType() + ": P=" + GetPerimetr().ToString() + "; S=" + GetSquare().ToString();
//}

CLongNumber CShape::GetPerimetr() const
{
	return m_perimetr;
}

CLongNumber CShape::GetSquare() const
{
	return m_square;
}

std::string CShape::GetType() const
{
	return m_shapeType;
}