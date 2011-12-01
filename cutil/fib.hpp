/* cap/cutil/fib.hpp */

#ifndef CAP___CUTIL___FIB_HPP
#define CAP___CUTIL___FIB_HPP


namespace cutil
{

    typedef unsigned long long int ull;


    template< ull n, ull a, ull b >
    struct fib_ct_impl;

    template< ull a, ull b >
    struct fib_ct_impl< 0, a, b >
    {
        static const ull value = a;
    };

    template< ull a, ull b >
    struct fib_ct_impl< 1, a, b >
    {
        static const ull value = b;
    };

    template< ull n, ull a, ull b >
    struct fib_ct_impl
    {
        static const ull value =
            fib_ct_impl< n-1, b, a+b >::value ;
    };

    template< ull n >
    struct fib_ct
    {
        static const ull value =
            fib_ct_impl< n, 0, 1 >::value ;
    };


    ull fib_impl( ull n, ull a, ull b )
    {
        if( 1 < n ) return fib_impl( n-1, b, a+b );
        if( 0 < n ) return b;
        return a;
    }

    ull fib( ull n )
    {
        return fib_impl( n, 0, 1 );
    }
}





#endif//ndef CAP___CUTIL___FIB_HPP
