/* cap/cutil/dumpchars.hpp */

#include<cmath>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<list>
#include<sstream>
#include<string>

#include"boost/lexical_cast.hpp"
#include"boost/numeric/conversion/cast.hpp"
#include"boost/phoenix.hpp"

#include"dumpchars.hpp"
#include"psi.hpp"


int intify( const char&c )
{
    int ret( 0 );
    memcpy( &ret, &c, 1 );
    return ret;
}

void
dump_char( const int&w, const size_t&i, const char&c )
{
    std::cout << ::cap::cutil::dump_char( w, i, c );
}

void dumpChars( const std::string&s ){
    const size_t n( s.size() );

    std::cout << "  string of length " << std::dec << n << std::endl ;

    if( 0 == n ) return;

    const int w( boost::numeric_cast< int >( std::ceil( std::log10( n ) ) ) ) ;

    size_t i( 0 );
    using namespace boost::phoenix;
    using namespace boost::phoenix::arg_names;

    std::for_each( s.begin(), s.end(), bind( &dump_char, w, ref( i )++, arg1 ) );
}




std::string
cap::cutil::dump_char( const char&c )
{
    const int n( intify( c ) );
    std::stringstream ss;
    ss
        << "0x"
        << std::hex
        << std::noshowbase
        << std::setfill('0')
        << std::setw( 2 )
        << n
        ;
    if( 31 < n && n < 127 )
        ss << " == '" << c << "'" ;
    return ss.str();
}




std::string
cap::cutil::dump_char( const int&w,
                       const size_t&i,
                       const char&c )
{
    std::stringstream ss;
    ss
        << std::endl
        << "    char["
        << std::setw( w )
        << std::setfill('0')
        << std::right
        << std::dec
        << i
        << "] == "
        << dump_char( c )
        ;

    return ss.str();
}


std::string
cap::cutil::dump_string( const std::string&s )
{
    const size_t n( s.size() );
    std::string ret
        ( "string of length " +
          boost::lexical_cast< std::string >( n ) );

    if( 0 == n ) return ret;

    const int w( boost::numeric_cast< int >( std::ceil( std::log10( n ) ) ) ) ;

    size_t i( 0 );
    using namespace boost::phoenix;
    using namespace boost::phoenix::arg_names;

    std::list< std::string >ls( s.size() );
    std::transform
        ( s.begin(), s.end(), ls.begin(),
          bind( &cap::cutil::dump_char, w, ref( i )++, arg1 ) );

    return
        std::accumulate
        ( ls.begin(), ls.end(), ret );
}

