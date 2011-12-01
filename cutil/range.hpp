/* cap/cutil/range.hpp */

#ifndef CAP___CUTIL___RANGE_HPP
#define CAP___CUTIL___RANGE_HPP

namespace cap
{
    namespace cutil
    {
        template< typename C >
        C
        range( typename C::value_type const&a,
               typename C::value_type const&b )
        {
            C ret;
            for( typename C::value_type c( std::min( a, b ) );
                 c <= std::max( a, b )
                     ; c++ )
                ret.insert( c );
            return ret;
        }
    }
}

#endif//ndef CAP___CUTIL___RANGE_HPP
