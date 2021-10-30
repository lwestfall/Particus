#include "vector_2.h"

vector_2::vector_2(double x, double y)
{
	this->x = x;
	this->y = y;
}

double vector_2::get_x() const
{
	return x;
}

double vector_2::get_y() const
{
	return y;
}

void vector_2::set_x(double new_x)
{
	x = new_x;
}

void vector_2::set_y(double new_y)
{
	y = new_y;
}

vector_2 vector_2::operator+(vector_2 const &v)
{
	double sum_x = x + v.get_x();
	double sum_y = y + v.get_y();
	return vector_2(sum_x, sum_y);
}

vector_2 vector_2::operator*(int const &i)
{
	return vector_2(x * i, y * i);
}
