#include "stdafx.h"
#include "CircleCreator.h"
#include "Circle.h"

using namespace std;

unique_ptr<CShape> CCircleCreator::Create(const Point &center, CLongNumber radius) const
{
	return make_unique<CCircle>(center, radius);
}

CCircleCreator* CCircleCreator::GetInstance()
{
	if (!inst)
	{
		inst = new CCircleCreator();
	}
	return inst;
}

void CCircleCreator::DestroyInstance()
{
	if (inst)
	{
		delete inst;
		inst = nullptr;
	}
}

CCircleCreator *CCircleCreator::inst = nullptr;