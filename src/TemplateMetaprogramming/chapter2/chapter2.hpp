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

// 1 arg function
template<typename Ret, typename Arg1, typename X, typename Y>
struct replace_type<Ret(*)(Arg1), X, Y>
{
    typedef typename replace_type<Ret, X, Y>::type (*type) (typename replace_type<Arg1, X, Y>::type);
};

// 2 arg
template<typename Ret, typename Arg1, typename Arg2, typename X, typename Y>
struct replace_type<Ret(*)(Arg1, Arg2), X, Y>
{
    typedef typename replace_type<Ret, X, Y>::type (*type) (typename  replace_type<Arg1, X, Y>::type, typename  replace_type<Arg2, X, Y>::type);
};

}
