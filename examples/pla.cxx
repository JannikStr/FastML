#include <iostream>

#include "fastml/math/vector.hxx"

using namespace fastml::math;

double f(int i) { return 1.0 / (i + 1); }

int main(int argc, char **argv) {

  Vector vec = {1, 2, 3, 4};
  std::cout << vec << std::endl;

  Vector vec2 = Vector::zeros(7);
  std::cout << vec2 << std::endl;

  Vector vec3 = Vector::from_func(8, f);
  std::cout << vec3 << std::endl;
  return EXIT_SUCCESS;
}
