#include "fastml/math/matrix.hxx"
#include <cstring>

namespace fastml::math {
Matrix::Matrix(uint rdim, uint cdim)
    : data(new double[rdim * cdim]), rdim(rdim), cdim(cdim) {}

Matrix::Matrix(const Matrix &mat)
    : data(new double[mat.rdim * mat.cdim]), rdim(mat.rdim), cdim(mat.cdim) {}

Matrix::Matrix(Matrix &&mat)
    : data(std::move(mat.data)), rdim(mat.rdim), cdim(mat.cdim) {
  mat.rdim = 0;
  mat.cdim = 0;
}

Matrix Matrix::Zeros(uint rdim, uint cdim) {
  Matrix mat(rdim, cdim);
  memset(mat.data.get(), 0, rdim * cdim);
  return mat;
}

Matrix Matrix::Identity(uint dim) {
  Matrix result = Matrix::Zeros(dim, dim);
  for (int i = 0; i < dim; ++i) {
    result.data[i * dim + i] = 1;
  }
  return result;
}

Matrix Matrix::From_func(uint rdim, uint cdim,
                         std::function<double(int, int)> f) {
  Matrix result(rdim, cdim);
  for (uint rowIdx = 0; rowIdx < rdim; ++rowIdx) {
    for (uint colIdx = 0; colIdx < cdim; ++colIdx) {
      result.data[rowIdx * cdim + colIdx] = f(rowIdx, colIdx);
    }
  }
  return result;
}

std::ostream &operator<<(std::ostream &os, const Matrix &mat) {
  os << "[";
  for (uint rowIdx = 0; rowIdx < mat.rdim; ++rowIdx) {
    os << "[";
    for (uint colIdx = 0; colIdx < mat.cdim - 1; ++colIdx) {
      os << mat.data[rowIdx * mat.cdim + colIdx] << ", ";
    }
    os << mat.data[rowIdx * mat.cdim + mat.cdim - 1] << "]\n";
  }
  return os << "]";
}

} // namespace fastml::math
