/* psi_software_platform/src/psi/cap/poly_function.hpp */

#ifndef POLY_FUNCTION_HPP
#define POLY_FUNCTION_HPP


#include<algorithm>
#include<vector>

#include"boost/lambda/lambda.hpp"
#include"boost/assign/list_of.hpp"
#include"boost/assert.hpp"

#include"psi.hpp"


template< class T_ >
class PolyFunction{
    //const T_ ident[] = { 0, 1 };
    typedef typename std::vector<T_>::const_iterator Iter_;
    std::vector< T_ >c_;

public:

    /* evaluate the polynomial and its derivative simultaneously; see
       Numerical Recipes 5.3 for details */
    std::pair< T_, T_ >evalBoth( const T_&x )const{
        T_ p = 0, dp = 0;
        using namespace boost::lambda;
        std::for_each( c_.rbegin(), c_.rend(),
                       ( var(dp) *= constant_ref(x),
                         var(dp) += var(p),
                         var(p)  *= constant_ref(x),
                         var(p)  += boost::lambda::_1 ) );
        return std::pair< T_, T_ >( p, dp );
    }

    T_ operator()( const T_&x )const{ return evalBoth(x).first; }

    /* return a PolyFunction that represents the derivative of this */
    PolyFunction derivative( void ){
        std::vector< T_ >d;
        for( size_t i = 1, n = c_.size(); i < n; ++i )
            d.push_back( i * c_[i] );
        return PolyFunction( d.begin(), d.end() );
    }

    PolyFunction( Iter_ first, Iter_ last ):c_( first, last ){}

    PolyFunction( void ){
        c_.push_back(0);
        c_.push_back(1);
        /* using namespace boost::assign; */
        /* c_ = list_of(0)(1); */
        BOOST_ASSERT( 2 == c_.size() );
    }
};

template< class T_ >
PolyFunction< T_ >
derivative( PolyFunction< T_ >f ){
    return f.derivative();
}


#endif//ndef POLY_FUNCTION_HPP
