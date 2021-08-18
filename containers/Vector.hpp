//
// Created by Lonmouth Mallador on 5/31/21.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <iostream>
#include <cstddef>
#include <limits>
#include "reimplemented_staff.hpp"

namespace ft {

    template<class T, class Alloc = std::allocator<T> >
    class vector {

    public:
        typedef T value_type;
        typedef typename Alloc::pointer pointer;
        typedef typename Alloc::const_pointer const_pointer;
        typedef typename Alloc::reference reference;
        typedef typename Alloc::const_reference const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef Alloc allocator_type;

        explicit vector(const allocator_type &alloc = allocator_type())
                : allocator(alloc), size_a(0), capacity_a(5) {
            array = allocator.allocate(capacity_a);
        }

        explicit vector(size_type n, const value_type &val = value_type(),
                        const allocator_type &alloc = allocator_type())
                : allocator(alloc), size_a(0), capacity_a(5) {
            array = allocator.allocate(capacity_a);
            for (int i = 0; i < n; i++)
                insert(begin(), val);
        }

        template<class InputIterator>
        vector(InputIterator first, InputIterator last,
               const allocator_type &alloc = allocator_type(),
               typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type l = 0)
                : allocator(alloc), size_a(0), capacity_a(5) {
            array = allocator.allocate(capacity_a);
            for (; first != last; first++)
                push_back(*first);
        }

        vector(const vector &x) : allocator(x.allocator), size_a(0), capacity_a(5) {
            array = allocator.allocate(capacity_a);
            iterator cur = begin();
            const_iterator first = x.begin();
            const_iterator last = x.end();
            for (; first != last; first++, cur++)
                insert(cur, *first);
        }

        class iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
        public:
            value_type *item;

            iterator() {};

            iterator(value_type *item) : item(item) {}

            ~iterator() {};

            T *getObj() { return *item; }

            T &operator*() const { return (*item); }

            iterator operator++() {
                item++;
                return *this;
            }

            iterator operator--() {
                item--;
                return *this;
            }

            iterator operator++(int) {
                iterator iter(*this);
                item++;
                return iter;
            }

            iterator operator--(int) {
                iterator it = *this;
                item--;
                return it;
            }

            difference_type operator-(iterator it) { return item - it.item; }

            iterator operator+(iterator it) { return item + it.item; }

            iterator operator-(difference_type n) { return item - n; }

            iterator operator+(difference_type n) { return item + n; }

            bool operator<(const iterator &i) const { return item < i.item; }

            bool operator>(const iterator &i) const { return item > i.item; }

            bool operator<=(const iterator &i) const { return item <= i.item; }

            bool operator>=(const iterator &i) const { return item >= i.item; }

            bool operator==(const iterator &i) const { return i.item == item; }

            bool operator!=(const iterator &i) const { return i.item != item; }
        };

        class const_iterator
                : public std::iterator<std::bidirectional_iterator_tag, const T> {
        public:
            value_type *item;

            const_iterator() {};

            const_iterator(value_type *i) : item(i) {}

            ~const_iterator() {};

            const_iterator operator++() {
                item++;
                return *this;
            }

            const_iterator operator--() {
                item--;
                return *this;
            }

            const_iterator operator++(int) {
                const_iterator iter(*this);
                item++;
                return iter;
            }

            const_iterator operator--(int) {
                const_iterator iter(*this);
                item--;
                return iter;
            }

            T *getObj() { return *item; }

            const T &operator*() const { return (*item); }

            bool operator==(const const_iterator &i) const { return i.item == item; }

            bool operator!=(const const_iterator &i) const { return i.item != item; }
        };

        iterator begin() { return iterator(array); }

        const_iterator begin() const { return const_iterator(array); }

        iterator end() { return iterator(array + size_a); }

        const_iterator end() const { return const_iterator(array + size_a); }

        iterator insert(iterator position, const value_type &val) {
            return push_item(position, val);
        }

        void insert(iterator position, size_type n, const value_type &val) {
            for (int i = 0; i < n; i++) {
                push_item(position, val);
            }
        }

        template<class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last,
                    typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type l = 0) {
            iterator it = begin();
            size_t iter_pos = 0;
            for (; it != position && it != end(); iter_pos++, it++);
            for (; first != last; first++) {
                it = begin();
                int i = 0;
                for (; i < iter_pos; i++, it++);
                value_type tmp = *first;
                push_item(it, tmp);
            }
        }

        iterator erase(iterator position) { return erase_item(position); }

        iterator erase(iterator first, iterator last) {
            iterator tmp = first;
            for (; first != last; first++)
                erase_item(tmp);
            return tmp;
        }

        void push_back(const value_type &val) { push_item(end(), val); }

        size_type size() const { return size_a; }

        size_type max_size() const { return size_type(-1); }

        void resize(size_type n, value_type val = value_type()) {
            if (size_a > n) {
                capacity_a = n * 2;
                value_type *new_array = allocator.allocate(capacity_a);
                for (int i = 0; i < n; i++)
                    new_array[i] = array[i];
                allocator.deallocate(array, size_a);
                size_a = n;
                array = new_array;
            } else
                insert(end(), n - size_a, val);
        }

        size_type capacity() const { return capacity_a; }

        bool empty() const {
            if (size_a == 0)
                return true;
            else
                return false;
        }

        void reserve(size_type n) {
            if (capacity_a < n) {
                capacity_a = n;
                value_type *new_array = allocator.allocate(capacity_a);
                for (int i = 0; i < size_a; i++)
                    new_array[i] = array[i];
                allocator.deallocate(array, size_a);
                array = new_array;
            }
        }

        reference operator[](size_type n) { return *iterator(array + n); }

        const_reference operator[](size_type n) const {
            return *const_iterator(array + n);
        }

        reference at(size_type n) { return array[n]; }

        const_reference at(size_type n) const { return array[n]; }

        reference front() {
            return array[0];
        }

        const_reference front() const {
            return array[0];
        }

        reference back() {
            return array[size_a - 1];
        }

        const_reference back() const {
            return array[size_a - 1];
        }

        template<class InputIterator>
        void assign(InputIterator first, InputIterator last) {
            erase(begin(), end());
            insert(begin(), first, ++last);
        }

        void assign(size_type n, const value_type &val) {
            erase(begin(), end());
            insert(begin(), n, val);
        }

        void pop_back() {
            erase(end());
        }

        void swap(vector &x) {
            size_type tmp = x.size_a;
            x.size_a = size_a;
            size_a = tmp;
            tmp = x.capacity_a;
            x.capacity_a = capacity_a;
            capacity_a = tmp;
            std::swap(x.array, array);
        }

        void clear() {
            erase(begin(), end());
        }


    private:
        allocator_type allocator;
        size_type size_a;
        size_type capacity_a;
        value_type *array;

        iterator push_item(iterator position, const value_type &val) {
            if (size_a + 1 < capacity_a) {
                move_items_right(position, array);
                allocator.construct((array + get_pointer_position(position)), val);
                size_a++;
                return position;
            } else {
                capacity_a *= 2;
                value_type *new_array = allocator.allocate(capacity_a + 1);
                for (int i = 0; i < size_a; i++)
                    new_array[i] = array[i];
                move_items_right(iterator(new_array + get_pointer_position(position)),
                                 new_array);
                int cur_pos = get_pointer_position(position);
                allocator.deallocate(array, size_a);
                allocator.construct(new_array + cur_pos, val);
                size_a++;
                array = new_array;
                return iterator(array + cur_pos);
            }
        }

        iterator erase_item(iterator position) {
            return move_items_left(get_pointer_position(position), array);
        }

        void move_items_right(iterator position, value_type *arr) {
            int current = 0;
            iterator first = iterator(arr);
            if (position == iterator(arr + size_a))
                return;
            for (; first != position && first != end(); first++, current++);
            value_type tmp = arr[current];
            for (; current < size_a; current++) {
                value_type next = arr[current + 1];
                arr[current + 1] = tmp;
                tmp = next;
            }
        }

        iterator move_items_left(int cur_pos, value_type *arr) {
            int t = cur_pos;
            for (; cur_pos < size_a - 1; cur_pos++)
                arr[cur_pos] = arr[cur_pos + 1];
            size_a--;
            return iterator(arr + t);
        }

        int get_pointer_position(iterator it) {
            iterator first = begin();
            int i = 0;
            for (; first != it && first != end(); first++, i++);
            return i;
        }

    };
} // namespace ft

// namespace ft

#endif // FT_CONTAINERS_VECTOR_HPP
