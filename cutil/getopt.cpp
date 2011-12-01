/* cap/cereal/factory.cpp */

#include<boost/phoenix.hpp>

#include"cutil/getopt.hpp"




//using namespace cap::cutil::getopt;


#if 0
std::string
cap::cutil::getopt::usage_message( std::string argv_0,
                                   option*begin,
                                   option*end )
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
              += construct< std::string >( bind( &option::name, arg1 ) ) ] ) );
    return ret;
}
#endif




std::string
cap::cutil::getopt::nonopt_message( int optind,
                                    int argc,
                                    char**argv )
{
    std::string ret;
    if( ! ( optind < argc ) ) return ret;

    ret += "\n\nnon-option arguments:";
    while( optind < argc )
        ret +=
            std::string( " \"" ) +
            std::string( argv[ optind++ ] ) +
            std::string( "\"" ) ;
    return ret;
}

