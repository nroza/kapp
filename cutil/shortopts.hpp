/* cap/cutil/shortopts.hpp */

#ifndef CAP___CUTIL___SHORTOPTS_HPP
#define CAP___CUTIL___SHORTOPTS_HPP

#include<string>

#include<getopt.h>

#include<boost/phoenix.hpp>




namespace cap
{
    namespace cutil
    {
        /* takes a pointer to the first element of an array of
           options; returns a string representation of short options,
           constructed from the val member of each; when the has_arg
           value is required_argument, adds ":" after the letter */
#if 0
        std::string shortopts( option*begin, option*end );
#else
        template< typename Iter >
        std::string
        shortopts( Iter begin, Iter end )
        {
            std::string ret;
            using namespace boost::phoenix;
            using namespace boost::phoenix::arg_names;
            std::for_each
                ( begin, end,
                  ( boost::phoenix::ref( ret ) += bind( &option::val, arg1 ),
                    if_( required_argument == bind( &option::has_arg, arg1 ) )
                    [ boost::phoenix::ref( ret ) += val( ":" ) ] ) );
            return ret;
        }
#endif
    }
}

#endif//ndef CAP___CUTIL___SHORTOPTS_HPP
