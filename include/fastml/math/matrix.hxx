#ifndef FASTML_MATH_MATRIX
#define FASTML_MATH_MATRIX

#include <functional>
#include <memory>
#include <ostream>

namespace fastml::math {

class Matrix {
  std::unique_ptr<double[]> data;
  uint rdim, cdim;

public:
  Matrix() = delete;
  Matrix(uint rdim, uint cdim);
  Matrix(const Matrix &mat);
  Matrix(Matrix &&mat);

  static Matrix Zeros(unsigned rdim, unsigned cdim);
  static Matrix Identity(unsigned dim);
  static Matrix From_func(unsigned rdim, unsigned cdim,
                          std::function<double(int, int)>);

public:
  friend std::ostream &operator<<(std::ostream &os, const Matrix &mat);
};

std::ostream &operator<<(std::ostream &os, const Matrix &mat);
} // namespace fastml::math

#endif
