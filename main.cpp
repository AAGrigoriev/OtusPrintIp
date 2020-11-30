#include <iostream>
#include "printIp.hpp"

int main()
{
    otusPrint::IP_Pool<4> pool;

    pool.read_from_stream(std::cin);

    pool.sort_reverse();

    pool.print();

    std::cout << pool.filter(1u);

    std::cout << pool.filter(46u, 70u);

    std::cout << pool.fileter_any(46u);

    return 0;
}
