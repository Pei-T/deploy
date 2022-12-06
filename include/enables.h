#include <iostream>

namespace pd{
class enable_iostream_of_this {
    public:
     template <typename T>
     std::ostream &operator<<(T &&obj);
     template <typename T>
     std::istream &operator>>(T &&obj);
};
}  // namespace pds