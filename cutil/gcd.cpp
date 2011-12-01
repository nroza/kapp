/* cap/cutil/gcd.cpp */

#include<iostream>

#include"cutil/gcd.hpp"


int
main( int /* argc */, char**/* argv */ )
{
    std::cout
        << "cutil::gcd_ct< 12, 15, 21 >::value == "
        << std::dec
        << cutil::gcd_ct< 12, 15, 21 >::value
        << std::endl
        ;

    std::cout
        << "cutil::gcd_ct< 0, 987654321, 9973 >::value == "
        << std::dec
        << cutil::gcd_ct< 0, 987654321, 9973 >::value
        << std::endl
        ;

    std::cout
        << "cutil::gcd( 14, 21, 91, 49 ) == "
        << std::dec
        << cutil::gcd( 14, 21, 91, 49 )
        << std::endl
        ;

    return 0;
}
