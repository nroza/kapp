/* cap/cutil/endian.cpp */

#include<iostream>
#include<iomanip>

namespace
{
    union _endian
    {
        char byte[ sizeof( unsigned int ) ];
        unsigned int n;
    };
}

int
main( int, char** )
{
    _endian endian;
    endian.n = 1;
    for( size_t i = 0, n = sizeof( unsigned int ); i < n; ++i )
        std::cout
            << "endian.byte["
            << std::dec << i << "] == "
            << std::dec << int( endian.byte[i] )
            << std::endl
            ;
}
