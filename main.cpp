#include <iostream>
#include "printIp.hpp"

int main()
{
    otusPrint::IP_Pool<4> pool;

    pool.read_from_stream(std::cin);

    pool.sort_reverse();

    std::cout << "\n";

    std::cout << pool.filter(1u,1u);

    return 0;
}
