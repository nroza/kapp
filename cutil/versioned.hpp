/* cap/cutil/versioned.hpp */

#ifndef CAP___CUTIL___VERSIONED___HPP
#define CAP___CUTIL___VERSIONED___HPP

#include<string>

#define CAP_TIMESTAMP() __DATE__ __TIME__

namespace cap
{
    namespace cutil
    {
        struct versioned
        {
            virtual std::string version( void )const = 0 ;
            virtual ~versioned( void ){}
        };
    }
}

#endif//ndef CAP___CUTIL___VERSIONED___HPP
