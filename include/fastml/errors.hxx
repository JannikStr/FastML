#include <exception>
#include <stdexcept>
namespace fastml::errors {
struct vector_dim_error : std::runtime_error {
  vector_dim_error(int ldim, int rdim)
      : std::runtime_error("Vector dimensions are differing (" +
                           std::to_string(ldim) + " and " +
                           std::to_string(rdim) + ")") {}
};

} // namespace fastml::errors
