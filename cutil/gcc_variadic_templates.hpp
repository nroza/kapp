/* cap/cutil/gcc_variadic_templates.hpp */


#ifndef CAP___CUTIL___GCC_VARIADIC_TEMPLATES_HPP
#define CAP___CUTIL___GCC_VARIADIC_TEMPLATES_HPP


/* C++0x variadic templates came to gcc 4.3, but they still need a lot
   of massaging to work. This code shows how.

   References:

   Peter Alexander. "Using C++0x Variadic Templates with g++."
   Poita.org. Ed. Peter Alexander. 28 November 2010. Poita.org. 6 June
   2011
   <http://poita.org/index.php/blog/1-latest-news/53-using-c0x-variadic-templates-with-g>

   */


namespace gcc_variadic_templates{

    /* Define this preprocessor flag to include the additional helper
       code that gcc needs to process the variadic template defined
       below. If gcc was absolutely standard compliant, this
       additional code would not be needed. */
#define GCC_NEEDS_HELP_WITH_VARIADIC_TEMPLATES 1


#if GCC_NEEDS_HELP_WITH_VARIADIC_TEMPLATES
    /* Declaration of primary variadic template. */
    template< typename... T >
    struct count;
#endif

    /* Partial specialisation of the primary template for head and
       tail decomposition. */
    template< typename H, typename... T >
    struct count
#if GCC_NEEDS_HELP_WITH_VARIADIC_TEMPLATES
    < H, T... >
#endif
    {
        static const int value = 1 + count< T... >::value;
    };

    template<>
    struct count<>
    {
        static const int value = 0;
    };
}

#endif//ndef CAP___CUTIL___GCC_VARIADIC_TEMPLATES_HPP
