#include "stdafx.h"
#include "Functions.h"

CLongNumber CFunctions::Sqr(const CLongNumber &number)
{
	return number * number;
}

CLongNumber CFunctions::Sqrt(const CLongNumber &number)
{
	if (number.GetVector().size() == 1 && number.GetVector()[0] == 0)
	{
		return CLongNumber();
	}

	CLongNumber start;
	CLongNumber end = number;
	CLongNumber middle;
	for (;;)
	{
		middle = (start + end) / CLongNumber(2);
		if (middle * middle == number)
		{
			return middle;
		}
		else
		{
			if (middle * middle > number)
			{
				if (end == middle)
				{
					return middle;
				}
				end = middle;
			}
			else
			{
				if (middle * middle < number)
				{
					if (start == middle)
					{
						return middle;
					}
				}
				start = middle;
			}
		}
	}
}
