/* cap/cutil/simpleton.hpp */

/*
  Simpleton; a simple singleton implementation; a mixin class to be
  used via crtp; function-scoped static initialization. References
  follow:

  http://www.research.ibm.com/designpatterns/pubs/ph-jun96.txt

  http://kera.name/articles/2010/09/tomalaks-tuesday-tip-8-outsmarting-static-initialization/
*/


#ifndef CAP___CUTIL___SIMPLETON_HPP
#define CAP___CUTIL___SIMPLETON_HPP

#include<iostream>

namespace cap
{
    namespace cutil
    {
        template< class Derived >
        class simpleton{
        private:
            /* allow nothing to call copy ctor, assignment operator */
            simpleton( const simpleton& ){}
            simpleton&operator=( const simpleton& ){}
        protected:
            /* allow inheritors to call default ctor */
            simpleton( void ){}
        public:
            static Derived&instance( void ){
                static Derived theInstance;
                return theInstance;
            }
            virtual ~simpleton( void ){}
        };


        /* example usage */
        class make_me_simpleton
            :public simpleton< make_me_simpleton >//crtp
        {
        private:
            /* the following two lines allow only the inherited class to call
               the default ctor: */
            make_me_simpleton( void ){}
            friend class simpleton< make_me_simpleton >;
        public:
            /* regular class members follow */
            void test( void ){
                std::cout << "Hello, simpleton!" << std::endl ;
            }
        };
        
    }
}




#endif//ndef CUTIL___SIMPLETON_HPP
