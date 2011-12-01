/* cap/cutil/gcd.hpp */

#ifndef CAP___CUTIL___GCD_HPP
#define CAP___CUTIL___GCD_HPP


#if !defined( __GXX_EXPERIMENTAL_CXX0X__ )
#error "this file requires one of the following: -std=c++0x, -std=gnu++0x"
#endif


namespace cutil
{

    typedef unsigned long long int ull;

#undef GCC_NEEDS_HELP_WITH_VARIADIC_TEMPLATES
#define GCC_NEEDS_HELP_WITH_VARIADIC_TEMPLATES 1

#if GCC_NEEDS_HELP_WITH_VARIADIC_TEMPLATES
    /* declaration of primary variadic template */
    template< ull... t >
    struct gcd_ct;
#endif


    /* Partial specialisation of the primary template for head and
       tail decomposition. */
    template< ull a, ull b, ull... t >
    struct gcd_ct
#if GCC_NEEDS_HELP_WITH_VARIADIC_TEMPLATES
    < a, b, t... >
#endif
    {
        static const ull value =
            gcd_ct< gcd_ct< a, b >::value, t... >::value ;
    };


    template< ull b >
    struct gcd_ct< 0, b >
    {
        static const ull value = b;
    };


    template< ull a, ull b >
    struct gcd_ct
#if GCC_NEEDS_HELP_WITH_VARIADIC_TEMPLATES
    < a, b >
#endif
    {
        static const ull value =
            gcd_ct< b%a, a >::value ;
    };


    template< typename N >
    N gcd( N a, N b )
    {
        return b ? gcd( b, a%b ) : a ;
    }

    template< typename N, typename... T >
    N gcd( N a, N b, T... t )
    {
        return gcd( gcd( a, b ), t... );
    }
}





#endif//ndef CAP___CUTIL___GCD_HPP
