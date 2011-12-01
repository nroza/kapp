/* cap/cutil/make_copy.hpp */

#ifndef CAP___CUTIL___MAKE_COPY_HPP
#define CAP___CUTIL___MAKE_COPY_HPP

#include<cassert>

namespace cap
{
    namespace cutil
    {
        template< typename Out, typename In >
        /* todo: concepts...

           In, Out are "container-like" classes that support:

           ::value_type, ::size(void), ::resize(size_t), ::operator[](size_t),
           &::value_type (i.e. addressable ::value_type) */
        Out make_copy( const In&in )
        {
            const size_t
                n_ival( sizeof( typename In::value_type ) ),
                n_oval( sizeof( typename Out::value_type ) );
            const size_t b_total( in.size() * n_ival );
            const size_t size_out
                ( b_total / n_oval +
                  ( ( b_total % n_oval ) ? 1 : 0 ) );

            Out out;
            out.resize( size_out,
                        typename Out::value_type( 0 ) );

            assert
                ( b_total ==
                  out.size() * n_oval +
                  ( b_total % n_oval ? 1 : 0 ) );

            memcpy( &out[0], &in[0], b_total );
            return out;
        }
    }
}
#endif//ndef CAP___CUTIL___MAKE_COPY_HPP
