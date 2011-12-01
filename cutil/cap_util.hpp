/* cap/cutil/cap_util.hpp */

#ifndef CAP___CUTIL___CAP_UTIL_HPP
#define CAP___CUTIL___CAP_UTIL_HPP


#include<algorithm>
#include<ctime>
#include<map>
#include<set>
#include<stdexcept>
#include<string>




template< class Map_ >
typename Map_::mapped_type mapGet( Map_&map, typename Map_::key_type key ){
    /* this will throw for a non-existent key */
    return map.find( key )->second ;
}


template< class Map_ >
void mapSet( Map_&map, typename Map_::value_type value ){
    /* this will throw for an already existent key */
    if( map.insert( value ).second ) return;
    throw std::logic_error( "key already exists" );
}    


template< class Map_ >
void mapSet( Map_&map, typename Map_::key_type key, typename Map_::mapped_type mapped ){
    mapSet( map, typename Map_::value_type( key, mapped ) );
}


struct TimeStamp{
    static std::string str( void ){
        std::time_t time_since_epoch;
        std::time( &time_since_epoch );
        std::tm *current_time = std::localtime( &time_since_epoch );
        return std::asctime( current_time ) ;
    }
};


/* quash x to the bounds specified by lo and hi */
template< class T_ >
T_ quash( T_ x, T_ lo, T_ hi ){
    using namespace std;
    if(lo>hi) swap(lo,hi);
    return min(max(x,lo),hi);
}


//template< class Map_K_V_, class K, class V >
template< class T, class U >
bool
found( const std::map< T, U >&m,
       const T&t,
       typename std::map< T, U >::const_iterator&it )
{
    it = m.find( t );
    typename std::map< T, U >::const_iterator end = m.cend();
    return end != it ;
}


#endif//ndef CAP___CUTIL___CAP_UTIL_HPP
