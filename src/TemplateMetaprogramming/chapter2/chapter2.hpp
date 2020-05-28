#pragma once

namespace TemplateMetaprogramming
{

/**
 *  Exercise 2.0 
 */

template<typename T>
struct add_const_ref
{
    typedef T const & type;
};

template<typename T>
struct add_const_ref<T&>
{
    typedef T const & type;
};

/**
 *  Exercise 2.1 
 */

template<typename C, typename X, typename Y>
struct replace_type
{
    typedef C type;
};

template<typename C, typename Y>
struct replace_type<C, C, Y>
{
    typedef Y type;
};

template<typename C, typename Y>
struct replace_type<C*, C, Y>
{
    typedef Y* type;
};

template<typename C, typename Y>
struct replace_type<C&, C, Y>
{
    typedef Y& type;
};

template<typename C, typename Y, int N>
struct replace_type<C[N], C, Y>
{
    typedef Y type[N];
};

template<typename C, typename Y, int N>
struct replace_type<C*[N], C, Y>
{
    typedef Y* type[N];
};

// need something that takes a function type, and does the prepend of an argument, allows for changing the arguments one by one
template<typename Function, typename NewArg>
struct prepend_function_argument {};

template<typename Ret, typename NewArg, typename... ExistingArgs>
struct prepend_function_argument<Ret(*)(ExistingArgs...), NewArg>
{
    typedef typename Ret(*type)(NewArg, ExistingArgs...);
};

// recursive case 
template<typename Ret, typename X, typename Y, typename FirstArg, typename... Args>
struct replace_type<Ret(*)(FirstArg, Args...), X, Y>
{
    // typedef typename append_function_argument<Ret(*)(Args), typename replace_type<LastArg, X, Y>::type>::type type;
    using type = typename prepend_function_argument<typename replace_type<Ret(*)(Args...), X, Y>::type, typename replace_type<FirstArg, X, Y>::type>::type;
};

// base case 1 arg
template<typename Ret, typename X, typename Y, typename Arg1>
struct replace_type<Ret(*)(Arg1), X, Y>
{
    using type = typename replace_type<Ret, X, Y>::type (*) (typename replace_type<Arg1, X, Y>::type);
};

}
