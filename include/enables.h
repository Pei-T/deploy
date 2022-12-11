#include <iostream>

namespace pd{
class enable_iostream_of_this {
    public:
     template <typename T>
     std::ostream &operator<<(T &&obj);
     template <typename T>
     std::istream &operator>>(T &&obj);
};
class noncopyable {
protected:
    noncopyable() {}
    ~noncopyable() {}
private:
    //禁止拷贝
    noncopyable(const noncopyable &that) = delete;
    noncopyable(noncopyable &&that) = delete;
    noncopyable &operator=(const noncopyable &that) = delete;
    noncopyable &operator=(noncopyable &&that) = delete;
};
}  // namespace pds