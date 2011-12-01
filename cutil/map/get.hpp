/* cap/cutil/map/get.hpp */

#ifndef CAP___CUTIL___MAP___GET_HPP
#define CAP___CUTIL___MAP___GET_HPP

namespace cap
{
    namespace cutil
    {
        namespace map
        {
            template< typename Map >
            typename Map::mapped_type
            get( const Map&map, const typename Map::key_type&key )
            {
                /* throws for nonexistent key */
                return map.find( key )->second;
            }
        }
    }
}

#endif//ndef CAP___CUTIL___MAP___GET_HPP
