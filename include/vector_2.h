#ifndef VECTOR_2_H
#define VECTOR_2_H

class vector_2 {
	public:
		vector_2(double x, double y);
		double get_x() const;
		double get_y() const;
		void set_x(double new_x);
		void set_y(double new_y);
		vector_2 operator+(vector_2 const &v);
	private:
		double x;
		double y;
};

#endif /* VECTOR_2_H */