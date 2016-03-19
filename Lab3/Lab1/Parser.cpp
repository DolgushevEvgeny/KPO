#include "stdafx.h"

using namespace std;

CParser::CParser(const std::string &input)
	: m_letterIndex(0)
{
	SetShapeType(input);
	SetPoints(input);
}

CParser::~CParser()
{
}

void CParser::SetShapeType(const std::string &input)
{
	string shapeType = "";
	for (size_t i = m_letterIndex; i < input.size(); ++i)
	{
		if (input[i] != ':')
		{
			shapeType += input[i];
		}
		else
		{
			m_letterIndex += i + 2;
			if (shapeType == "TRIANGLE")
			{
				m_shapeType = SHAPETYPE::TRIANGLE;
				break;
			}
			else
			{
				if (shapeType == "RECTANGLE")
				{
					m_shapeType = SHAPETYPE::RECTANGLE;
					break;
				}
				else
				{
					m_shapeType = SHAPETYPE::CIRCLE;
					break;
				}
			}
		}
	}

	return;
}

bool CParser::IsDigit(char symbol)
{
	if (symbol >= '0' && symbol <= '9')
	{
		return true;
	}
	else
	{
		if (symbol == '-')
		{
			return true;
		}
	}

	return false;
}

int CParser::FromStrToInt(const std::string &input)
{
	istringstream i(input);
	int x;
	if (!(i >> x))
	{
		return 0;
	}

	return x;
}

Point CParser::ParsePoint(const std::string &input)
{
	double x = 0, y = 0;

	size_t index;
	for (index = 0; index < input.size(); ++index)
	{
		if (input[index] == '=')
		{
			++index;
			break;
		}
	}

	string coord;
	vector<string> coords;
	for (size_t i = index; i < input.size(); ++i)
	{
		if (IsDigit(input[i]))
		{
			coord += input[i];
		}
		else
		{
			if (coord.size())
			{
				coords.push_back(coord);
				coord.clear();
			}
		}
	}

	coords.push_back(coord);
	Point point{ FromStrToInt(coords[0]), FromStrToInt(coords[1]) };

	return point;
}

int CParser::ParseRadius(const string &input)
{
	size_t index;
	for (index = 0; index < input.size(); ++index)
	{
		if (input[index] == '=')
		{
			++index;
			break;
		}
	}

	string radius = input.substr(index, input.length() - index);

	return FromStrToInt(radius);
}

void CParser::SetPoints(const std::string &input)
{
	string source = input.substr(m_letterIndex, input.length() - m_letterIndex);
	vector<string> array1;
	istringstream is(source);
	string s;
	while (getline(is, s, ' '))
	{
		array1.push_back(s);
	}

	switch (m_shapeType)
	{
	case SHAPETYPE::CIRCLE: m_points.push_back(ParsePoint(array1[0])); m_radius = ParseRadius(array1[1]); break;
	default:
		for (size_t i = 0; i < array1.size(); ++i)
		{
			m_points.push_back(ParsePoint(array1[i]));
		}
		break;
	}
}

SHAPETYPE CParser::GetShapeType() const
{
	return m_shapeType;
}

int CParser::GetRadius() const
{
	return m_radius;
}

vector<Point> CParser::GetPoints() const
{
	return m_points;
}