#include "printIp.hpp"

int main()
{
    printIP::IP_Pool<4> pool;

    pool.read_from_stream(std::cin);
    
    pool.sort_reverse();

    pool.print();

    return 0;
}