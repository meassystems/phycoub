/*
 * Vector.cpp
 *
 *  Created on: Oct 14, 2016
 *      Author: root
 */

#include "Vector.h"
#include <math.h>

namespace phycoub {

Vector::Vector(): x_(0.), y_(0.), z_(0.) {}
Vector::Vector(double v): x_(v), y_(v), z_(v) {}
Vector::Vector(double x, double y, double z): x_(x), y_(y), z_(z) {}
Vector::~Vector() {}

Vector Vector::operator+(const Vector &vector) const {
	return Vector(this->x_ + vector.x_, this->y_ + vector.y_, this->z_ + vector.z_);
}
Vector Vector::operator-(const Vector &vector) const {
	return Vector(this->x_ - vector.x_, this->y_ - vector.y_, this->z_ - vector.z_);
}
Vector Vector::operator*(const Vector &vector) const {
	Vector res_;
	res_.x_ = (this->y_ * vector.z_) - (this->z_ * vector.y_);
	res_.y_ = (this->x_ * vector.z_) - (this->z_ * vector.x_);
	res_.z_ = (this->x_ * vector.y_) - (this->y_ * vector.x_);

	return res_;
}
Vector &Vector::operator+=(const Vector &vector) {
	this->x_ += vector.x_;
	this->y_ += vector.y_;
	this->z_ += vector.z_;
	return *this;
}
Vector &Vector::operator-=(const Vector &vector) {
	this->x_ -= vector.x_;
	this->y_ -= vector.y_;
	this->z_ -= vector.z_;
	return *this;
}
Vector &Vector::operator*=(const Vector &vector) {
	this->x_ = (this->y_ * vector.z_) - (this->z_ * vector.y_);
	this->y_ = (this->x_ * vector.z_) - (this->z_ * vector.x_);
	this->z_ = (this->x_ * vector.y_) - (this->y_ * vector.x_);

	return *this;
}
bool Vector::operator==(const Vector &vector) const {
	if (this->x_ == vector.x_ && this->y_ == vector.y_ && this->z_ == vector.z_)
		return true;
	return false;
}
bool Vector::operator >(const Vector &vector) const {
	return this->getModule() > vector.getModule();
}
bool Vector::operator <(const Vector &vector) const {
	return this->getModule() < vector.getModule();
}
bool Vector::operator >=(const Vector &vector) const {
	return this->getModule() >= vector.getModule();
}
bool Vector::operator <=(const Vector &vector) const {
	return this->getModule() <= vector.getModule();
}
//-----------------------------------------------------
Vector Vector::operator+(const double &value) const {
	return Vector(this->x_ + value, this->y_ + value, this->z_ + value);
}
Vector Vector::operator-(const double &value) const {
	return Vector(this->x_ - value, this->y_ - value, this->z_ - value);
}
Vector Vector::operator*(const double &value) const {
	Vector res_;
	res_.x_ = this->x_ * value;
	res_.y_ = this->y_ * value;
	res_.z_ = this->z_ * value;

	return res_;
}
Vector Vector::operator/(const double &value) const {
	Vector res_;
	res_.x_ = this->x_ / value;
	res_.y_ = this->y_ / value;
	res_.z_ = this->z_ / value;

	return res_;
}
Vector &Vector::operator+=(const double &value) {
	this->x_ += value;
	this->y_ += value;
	this->z_ += value;
	return *this;
}
Vector &Vector::operator-=(const double &value) {
	this->x_ -= value;
	this->y_ -= value;
	this->z_ -= value;
	return *this;
}
Vector &Vector::operator*=(const double &value) {
	this->x_ = this->x_ * value;
	this->y_ = this->y_ * value;
	this->z_ = this->z_ * value;

	return *this;
}
Vector &Vector::operator/=(const double &value) {
	this->x_ = this->x_ / value;
	this->y_ = this->y_ / value;
	this->z_ = this->z_ / value;

	return *this;
}
bool Vector::operator==(const double &value) const {
	if (this->getModule() == value)
		return true;
	return false;
}
bool Vector::operator >(const double &value) const {
	return this->getModule() > value;
}
bool Vector::operator <(const double &value) const {
	return this->getModule() < value;
}
bool Vector::operator >=(const double &value) const {
	return this->getModule() >= value;
}
bool Vector::operator <=(const double &value) const {
	return this->getModule() <= value;
}
//---------------------------------------------------------
double &Vector::operator[](int index) {
	switch(index) {
	case 0:
		return this->x_;
	case 1:
		return this->y_;
	case 2:
		return this->z_;
	default:
		throw "Error, index by bounds";
	}
}
double Vector::operator[](int index) const{
	switch(index) {
	case 0:
		return this->x_;
	case 1:
		return this->y_;
	case 2:
		return this->z_;
	default:
		throw "Error, index by bounds";
	}
}

double Vector::getModule() const{
	return sqrt(pow(this->x_, 2) + pow(this->y_, 2) + pow(this->z_, 2));
}
bool Vector::below(const Vector& vector) const {

	if(this->x_ >= vector.x_ && this->y_ >= vector.y_ && this->z_ >= vector.z_) {
		return false;
	}

	return true;
}
bool Vector::beyond(const Vector& vector) const {
	if(this->x_ <= vector.x_ && this->y_ <= vector.y_ && this->z_ <= vector.z_) {
		return false;
	}

	return true;
}


} /* namespace phycoub */
