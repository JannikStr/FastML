#include "fastml/math/vector.hxx"
#include "fastml/errors.hxx"
#include <algorithm>
#include <cstring>
#include <functional>

namespace fastml::math {
Vector::Vector(int len) noexcept : data(new double[len]), len(len) {}

Vector::Vector(const std::initializer_list<double> &vals) noexcept
    : data(new double[vals.size()]), len(vals.size()) {
  for (int i = 0; i < vals.size(); ++i) {
    data[i] = *(vals.begin() + i);
  }
}

Vector::Vector(const Vector &vec) noexcept
    : data(new double(vec.len)), len(vec.len) {
  for (int i = 0; i < len; ++i) {
    data[i] = vec.data[i];
  }
}

Vector::Vector(Vector &&vec) : data(std::move(vec.data)), len(vec.len) {}

Vector Vector::zeros(int len) noexcept {
  Vector vec(len);
  memset(vec.data.get(), 0, len);
  return vec;
}

Vector Vector::values(int len, int val) noexcept {
  Vector vec(len);
  for (int i = 0; i < len; ++i) {
    vec(i) = val;
  }
  return vec;
}

Vector Vector::from_func(int len, std::function<double(int)> func) {
  Vector vec(len);
  for (int i = 0; i < len; ++i) {
    vec(i) = func(i);
  }
  return vec;
}

double &Vector::operator()(int idx) { return data[idx]; }
double Vector::operator()(int idx) const { return data[idx]; }

Vector &Vector::operator+=(const Vector &rhs) {
  if (this->len != rhs.len)
    throw fastml::errors::vector_dim_error(this->len, rhs.len);
  for (int i = 0; i < this->len; ++i) {
    this->data[i] += rhs.data[i];
  }
  return *this;
}

Vector &Vector::operator-=(const Vector &rhs) {
  if (this->len != rhs.len)
    throw fastml::errors::vector_dim_error(this->len, rhs.len);
  for (int i = 0; i < this->len; ++i) {
    this->data[i] += rhs.data[i];
  }
  return *this;
}

std::ostream &operator<<(std::ostream &os, const Vector &vec) noexcept {
  os << "[";
  for (int i = 0; i < vec.len - 1; ++i) {
    os << vec.data[i] << ", ";
  }
  os << vec.data[vec.len - 1] << "]";
  return os;
}

Vector operator+(const Vector &lhs, const Vector &rhs) {
  Vector result(lhs);
  result += rhs;
  return result;
}

Vector operator-(const Vector &lhs, const Vector &rhs) {
  Vector result(lhs);
  result -= rhs;
  return result;
}

double operator*(const Vector &lhs, const Vector &rhs) {
  if (lhs.len != rhs.len)
    throw fastml::errors::vector_dim_error(lhs.len, rhs.len);
  double result = 0;
  for (int i = 0; i < lhs.len; ++i) {
    result += lhs.data[i] * rhs.data[i];
  }
  return result;
}

bool operator==(const Vector &lhs, const Vector &rhs) {
  if (lhs.len != rhs.len)
    return false;
  for (int i = 0; i < lhs.len; ++i) {
    if (lhs.data[i] != rhs.data[i])
      return false;
  }
  return true;
}

bool operator!=(const Vector &lhs, const Vector &rhs) { return !(lhs == rhs); }

} // namespace fastml::math
