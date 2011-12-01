/* cap/cutil/dump_container.hpp */

#ifndef CAP___CUTIL___DUMP_CONTAINER_HPP
#define CAP___CUTIL___DUMP_CONTAINER_HPP

#include<iomanip>
#include<numeric>
#include<string>
#include<sstream>
#include<cmath>

#include<boost/numeric/conversion/cast.hpp>
#include<boost/lexical_cast.hpp>
#include<boost/phoenix.hpp>

namespace cap
{
    namespace cutil
    {
        template< typename C >
        std::string dump_container( const C&c )
        {
            std::string ret;
            ret += "container of size ";
            ret += boost::lexical_cast< std::string >( c.size() );
            ret += ":" ;

            const int w
                ( boost::numeric_cast< int >
                  ( std::ceil
                    ( std::log10
                      ( c.size() ) ) ) ) ;

            size_t i = 0;

            using namespace boost::phoenix;
            using namespace boost::phoenix::arg_names;
            return std::accumulate
                ( c.begin(), c.end(), s,
                  val("\n  [")
                  << std::setw( w )
                  //<< std::setfill('0')
                  << std::right
                  << boost::phoenix::ref( i )++
                  << "]  :  "
                  << arg1 );
            return ss.str();
        }
    }
}

#endif//ndef CAP___CUTIL___DUMP_CONTAINER_HPP
