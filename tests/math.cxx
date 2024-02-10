#include <iostream>

#include "fastml/errors.hxx"
#include "fastml/math/matrix.hxx"
#include "fastml/math/vector.hxx"

using namespace fastml::math;

int main() {
  Vector vec1 = {1, 2, 3};
  Vector vec2 = {3, 2, 1};

  Vector vec3 = Vector::values(3, 4);

  Vector vec4 = Vector::zeros(5);

  Vector vec5 = {1, 0, 1};
  Vector vec6 = {-.5, 1, .5};
  std::cout << std::boolalpha;
  std::cout << vec5 << " * " << vec6 << " = " << 0 << " (" << (vec5 * vec6 == 0)
            << ": " << vec5 * vec6 << ")" << std::endl;

  std::cout << "------Vector------" << std::endl;
  std::cout << "------------------" << std::endl;
  std::cout << std::boolalpha << vec1 << " + " << vec2 << " = " << vec3 << " ("
            << ((vec1 + vec2) == vec3) << ")" << std::endl;

  std::cout << vec4 << std::endl;
  try {
    std::cout << (vec3 + vec4) << std::endl;
  } catch (fastml::errors::vector_dim_error &e) {
    std::cerr << "vector_dim_error catched: " << e.what() << std::endl;
  }

  Matrix mat1 = Matrix::Identity(4);
  std::cout << mat1 << std::endl;
}
