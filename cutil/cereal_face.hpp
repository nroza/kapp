/* cap/cutil/cereal_face.hpp */


#ifndef CAP___CUTIL___CEREAL_FACE_HPP
#define CAP___CUTIL___CEREAL_FACE_HPP

#include<string>
#include<vector>
//#include<boost/date_time/posix_time/posix_time.hpp>
#include"cutil/psi.hpp"


namespace cap
{
    namespace cutil
    {
        struct cereal
        {
            /* thread-safe; guaranteed to acquire exclusive access to the
               serial port for processing a single command. */
            virtual std::string cmd( const std::string ) = 0;

            /* thread-safe; guaranteed to acquire exclusive access to the
               serial port for processing /every/ command. */
            virtual
            std::vector< std::string >
            cmds( const std::vector< std::string >&v ) = 0;

            virtual cereal&wait( u32 v ) = 0;
            virtual u32  wait( void  )const = 0;

            /* using boost::posix_time::time_duration; */
            /* virtual cereal&wait( time_duration const&d ) = 0; */
            /* virtual time_duration wait( void  )const = 0; */

            virtual void bugOn( void ) = 0;
            virtual void bugOff( void ) = 0;

            virtual ~cereal( void ){}
        };
    }
}

#endif//ndef CAP___CUTIL___CEREAL_FACE_HPP
