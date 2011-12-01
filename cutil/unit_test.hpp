/* cap/cutil/cap_unit_test.hpp */


#ifndef CAP___CUTIL___UNIT_TEST_HPP
#define CAP___CUTIL___UNIT_TEST_HPP

/* helper function for unit testing classes' private members */

namespace cap
{
    namespace cutil
    {
        template< typename T >
        void unit_test( T&t )
        {
            t.test();
        }
    }
}


#if 0
/* usage example */
class WantsUnitTest
{
    void test( void );
    template< typename T >
    friend void cap::unit_test( T&t );
};

int
main( int, char** )
{
    WantsUnitTest w;
    cap::unit_test( w );
    return 0;
}
#endif//0


#endif//ndef CAP___CUTIL___UNIT_TEST_HPP
