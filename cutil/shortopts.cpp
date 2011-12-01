/* cap/cutil/shortopts.cpp */

#include<boost/phoenix.hpp>

#include"cutil/shortopts.hpp"

#if 0
std::string
cap::cutil::shortopts( option*begin, option*end )
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
