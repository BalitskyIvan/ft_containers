//
// Created by lmallado on 01.08.2021.
//

#ifndef CONTAINERS_REIMPLEMENTED_STAFF_HPP
#define CONTAINERS_REIMPLEMENTED_STAFF_HPP

#include "Vector.hpp"

namespace ft {
    template<bool B, class T = void>
    struct enable_if {
    };

    template<class T>
    struct enable_if<true, T> {
        typedef T type;
    };

    template<typename T1, typename T2>
    struct pair {
    public:
        typedef T1 first_type;
        typedef T2 second_type;

        first_type first;
        second_type second;

        pair() : first(first_type()), second(second_type()) {}

        template<class U, class V>
        pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}

        pair(const first_type &a, const second_type &b) : first(a), second(b) {}

        ~pair() {};

        pair &operator=(const pair &pr) {
            if (this != &pr) {
                first = pr.first;
                second = pr.second;
            }
            return *this;
        }
    };

    template<class T1, class T2>
    pair<T1, T2> make_pair(T1 x, T2 y) {
        return pair<T1, T2>(x, y);
    }

    template<class T, class Alloc = std::allocator<T> >
    class vector;

    template<class T, class Container = ft::vector<T> >
    class stack;

    template<class T, class Container>
    bool operator==(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);

    template<class T, class Container>
    bool operator!=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);

    template<class T, class Container>
    bool operator<(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);

    template<class T, class Container>
    bool operator<=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);

    template<class T, class Container>
    bool operator>(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);

    template<class T, class Container>
    bool operator>=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);

}

#endif //CONTAINERS_REIMPLEMENTED_STAFF_HPP
