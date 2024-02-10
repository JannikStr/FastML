#ifndef FASTML_MATH_VECTOR
#define FASTML_MATH_VECTOR
#include <functional>
#include <initializer_list>
#include <memory>
#include <ostream>

namespace fastml::math {

class Vector {
  std::unique_ptr<double[]> data;
  int len;

public:
  Vector() = delete;
  explicit Vector(int) noexcept;
  Vector(const std::initializer_list<double> &) noexcept;
  Vector(const Vector &) noexcept;
  Vector(Vector &&);

  static Vector zeros(int len) noexcept;
  static Vector values(int len, int val) noexcept;
  static Vector from_func(int len, std::function<double(int)>);

public:
  double &operator()(int);
  double operator()(int) const;

  Vector &operator+=(const Vector &);
  Vector &operator-=(const Vector &);

  friend std::ostream &operator<<(std::ostream &, const Vector &) noexcept;

  friend Vector operator+(const Vector &, const Vector &);
  friend Vector operator-(const Vector &, const Vector &);
  friend double operator*(const Vector &, const Vector &);

  friend bool operator==(const Vector &, const Vector &);
  friend bool operator!=(const Vector &, const Vector &);
};

std::ostream &operator<<(std::ostream &, const Vector &) noexcept;
Vector operator+(const Vector &, const Vector &);
Vector operator-(const Vector &, const Vector &);
double operator*(const Vector &, const Vector &);

bool operator==(const Vector &, const Vector &);
bool operator!=(const Vector &, const Vector &);

} // namespace fastml::math

#endif
