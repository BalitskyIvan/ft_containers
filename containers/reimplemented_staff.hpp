//
// Created by lmallado on 01.08.2021.
//

#ifndef CONTAINERS_REIMPLEMENTED_STAFF_HPP
#define CONTAINERS_REIMPLEMENTED_STAFF_HPP

namespace ft {
    template<bool, typename>
    struct enable_if { };

    template<typename Tp>
    struct enable_if<true, Tp>
            { typedef Tp type; };

}

#endif //CONTAINERS_REIMPLEMENTED_STAFF_HPP
