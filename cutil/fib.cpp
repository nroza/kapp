/* cap/cutil/fib.cpp */

#include<iostream>

#include<boost/preprocessor.hpp>

#include"cutil/fib.hpp"


int
main( int /* argc */,
      char**/* argv */ )
{
    using namespace cutil;

#define N 20

    for( ull i = 0 ; i < N ; ++i )
        std::cout
            << "fib( "
            << std::dec << i << " ) == "
            << std::dec << fib( i )
            << std::endl
            ;

#define FIB_CT( z, n, data )                    \
    std::cout                                   \
        << "fib_ct< "                           \
        << BOOST_PP_STRINGIZE( n )              \
        << " >::value == "                      \
        << std::dec                             \
        << fib_ct< n >::value                   \
        << std::endl ;                          \
        /*  */

    BOOST_PP_REPEAT( N , FIB_CT , _ );

    return 0;
}
