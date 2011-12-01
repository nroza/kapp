/* cap/cutil/dumpchars.hpp */

#ifndef CAP___CUTIL___DUMPCHARS_HPP
#define CAP___CUTIL___DUMPCHARS_HPP

#include<string>

void dumpChars( const std::string&s );

namespace cap
{
    namespace cutil
    {
        std::string
        dump_char( const char&c );

        std::string
        dump_char( const int&w,
                   const size_t&i,
                   const char&c );

        std::string
        dump_string( const std::string& );
    }
}

#endif//ndef CAP___CUTIL___DUMPCHARS_HPP
