#include "stdafx.h"
#include "RectangleCreator.h"
#include "Rectangle.h"

using namespace std;

unique_ptr<CShape> CRectangleCreator::Create(const Point &point1, const Point &point2) const
{
	return make_unique<CRectangle>(point1, point2);
}

CRectangleCreator* CRectangleCreator::GetInstance()
{
	if (!inst)
	{
		inst = new CRectangleCreator();
	}
	return inst;
}

void CRectangleCreator::DestroyInstance()
{
	if (inst)
	{
		delete inst;
		inst = nullptr;
	}
}

CRectangleCreator *CRectangleCreator::inst = nullptr;