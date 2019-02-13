#include <iostream>

#include <ZType>
#include <ZVariant>


int main()
{
    zyxcba::ZVariant v(100);

    std::cout<<v.getNumber() << " Hello World!" << std::endl;
    return 0;
}
