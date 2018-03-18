#include <iostream>

using namespace std;

template<typename t1, typename t2>
auto multiply(t1 x, t2  y) -> decltype(x*y)
{
    static_assert(sizeof(decltype(x*y)) <= sizeof(int), "Result is too big");
    return x*y;
}

int main() {

    multiply(20000L, 20000L);

}
