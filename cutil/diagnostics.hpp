/* cap/cutil/diagnostics.hpp */

#ifndef CAP___CUTIL___DIAGNOSTICS_HPP
#define CAP___CUTIL___DIAGNOSTICS_HPP

#include<string>

#include<boost/lexical_cast.hpp>
#include<boost/preprocessor.hpp>
#include<boost/date_time/posix_time/posix_time.hpp>
//#include<boost/date_time/gregorian/formatters.hpp>


#define LOCATION_STRING()                       \
    __FILE__                                    \
    ":"                                         \
    BOOST_PP_STRINGIZE( __LINE__ )              \
    /* " in "                                      \ */
    /* __PRETTY_FUNCTION__                         \ */
    /*  */

#define PRINT_LOCATION( ostream )               \
    ostream << LOCATION_STRING() ;              \
    do{}while( 0 )                              \
        /*  */

#define THIS_STRING()                           \
    std::string                                 \
    ( "this == " +                              \
      boost::lexical_cast< std::string >        \
      ( this ) )

#define PRINT_THIS( ostream )                   \
    ostream                                     \
    << "this == "                               \
    << std::hex << std::showbase                \
    << this                                     \
    << std::endl                                \
    ;                                           \
    do{}while( 0 )                              \
        /*  */

#define WHEN_WHERE_STRING()                                             \
    std::string                                                         \
    ( boost::posix_time::to_simple_string                               \
      ( boost::posix_time::microsec_clock::local_time() ) +             \
      std::string( ";  " ) +                                            \
      std::string( __PRETTY_FUNCTION__ ) +                              \
      std::string( ";  " ) +                                            \
      std::string( LOCATION_STRING() ) )                                \
    /*  */

#define WHEN_WHERE_ERRNO_STRING()               \
    std::string                                 \
    ( WHEN_WHERE_STRING() +                     \
      std::string( ";  " ) +                    \
      std::string( strerror( errno ) ) )        \
    /*  */

#define WHEN_WHERE_ERRCODE_STRING( ERROR_CODE ) \
    std::string                                 \
    ( WHEN_WHERE_STRING() +                     \
      std::string( ";  " ) +                    \
      std::string                               \
      ( strerror                                \
        ( ERROR_CODE . value() ) ) )            \
    /*  */


#endif//ndef CAP___CUTIL___DIAGNOSTICS_HPP
