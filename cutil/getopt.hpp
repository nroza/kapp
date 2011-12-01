/* cap/cutil/getopt.hpp */

#ifndef CAP___CUTIL___GETOPT_HPP
#define CAP___CUTIL___GETOPT_HPP


#include<string>

#include<getopt.h>

#include<boost/phoenix.hpp>




namespace cap
{
    namespace cutil
    {
        namespace getopt
        {
#if 0
            std::string
            usage_message( std::string argv_0,
                           option*begin,
                           option*end );
#else
            template< typename Iter >
            std::string
            usage_message( std::string argv_0,
                           Iter begin,
                           Iter end )
            {
                using namespace boost::phoenix;
                using namespace boost::phoenix::arg_names;
                std::string ret( "\n\nusage:" );
                std::for_each
                    ( begin, end,
                      ( boost::phoenix::ref( ret )
                        += val( "\n  " )
                        + construct< std::string >( argv_0 )
                        + val( " ( -" )
                        + construct< char >( bind( &option::val, arg1 ) )
                        + val( " | --" )
                        + construct< std::string >( bind( &option::name, arg1 ) )
                        + val( " ) " ),
                        if_( required_argument == bind( &option::has_arg, arg1 ) )
                        [ boost::phoenix::ref( ret )
                          += construct< std::string >
                          ( bind( &option::name, arg1 ) ) ] ) );
                return ret;
            }
#endif
            std::string
            nonopt_message( int optind,
                            int argc,
                            char**argv );
        }
    }
}

#endif//ndef CAP___CUTIL___GETOPT_HPP
