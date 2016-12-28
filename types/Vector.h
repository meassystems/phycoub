/*
 * Vector.h
 *
 *  Created on: Oct 14, 2016
 *      Author: root
 */

#ifndef VECTOR_H_
#define VECTOR_H_

namespace phycoub {
/*
 * Класс вектора в трехмерном пространстве.
 */
class Vector {
public:
	Vector();
	explicit Vector(double v);
	Vector(double x, double y , double z);
	virtual ~Vector();

	Vector& operator=(const double& vector);
	//-----------------------------------------
	Vector operator+(const Vector& vector) const;
	Vector operator-(const Vector& vector) const;
	Vector operator*(const Vector& vector) const;
	Vector &operator+=(const Vector& vector);
	Vector &operator-=(const Vector& vector);
	Vector &operator*=(const Vector& vector);
	bool operator==(const Vector& vector) const;
	bool operator>(const Vector& vector) const;
	bool operator<(const Vector& vector) const;
	bool operator>=(const Vector& vector) const;
	bool operator<=(const Vector& vector) const;
	//-----------------------------------------
	Vector operator+(const double& value) const;
	Vector operator-(const double& value) const;
	Vector operator*(const double& value) const;
	Vector operator/(const double& value) const;
	Vector &operator+=(const double& value);
	Vector &operator-=(const double& value);
	Vector &operator*=(const double& value);
	Vector &operator/=(const double& value);
	bool operator==(const double& value) const;
	bool operator>(const double& value) const;
	bool operator<(const double& value) const;
	bool operator>=(const double& value) const;
	bool operator<=(const double& value) const;
	//-----------------------------------------
	double &operator[](int index);
	double operator[](int index) const;

	double getModule() const;
	bool below(const Vector& vector) const;
	bool beyond(const Vector& vector) const;

	double x_, y_, z_;
};

} /* namespace phycoub */

#endif /* VECTOR_H_ */
