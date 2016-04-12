#include "stdafx.h"
#include "TriangleCreator.h"
#include "Triangle.h"

using namespace std;

unique_ptr<CShape> CTriangleCreator::Create(const Point &point1, const Point &point2, const Point &point3) const
{
	return make_unique<CTriangle>(point1, point2, point3);
}

CTriangleCreator* CTriangleCreator::GetInstance()
{
	if (!inst)
	{
		inst = new CTriangleCreator();
	}
	return inst;
}

void CTriangleCreator::DestroyInstance()
{
	if (inst)
	{
		delete inst;
		inst = nullptr;
	}
}

CTriangleCreator *CTriangleCreator::inst = nullptr;