//#include "printIp.hpp"

#include "iostream"

class Primbase
{
public:
    int value;
    virtual Primbase *foo() // new slot in vtable
    {
        std::cout << "Prinbase\n";
        return this;
    }

    virtual ~Primbase() {}
};

class Der : public Primbase
{
public:
    // primary base
    virtual Der *foo() override // replaces Primbase::foo() in vtable
    {
        std::cout << "Der\n";
        static int value2 = 4;
        return this;
    }

    virtual ~Der() {}
};

int main()
{

Primbase* base = new Der;



base->foo();
    // otusPrint::IP_Pool<4> pool;

    // pool.read_from_stream(std::cin);

    // pool.sort_reverse();

    //  pool.print();

    // std::cout << "\n";

    //std::cout << pool.filter(1u,1u);

    return 0;
}
