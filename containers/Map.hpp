//
// Created by Lonmouth Mallador on 5/31/21.
//

#ifndef FT_CONTAINERS_MAP_HPP
#define FT_CONTAINERS_MAP_HPP

#include <iostream>
#include <cstddef>
#include <cstdlib>

namespace ft {

    template<class Key, class T, class Compare = std::less<Key>,
            class Alloc = std::allocator<std::pair<const Key, T> > >
    class map {

    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef std::pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
        typedef typename Alloc::pointer pointer;
        typedef typename Alloc::const_pointer const_pointer;
        typedef typename Alloc::reference reference;
        typedef typename Alloc::const_reference const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef Alloc allocator_type;

    private:
        static const int NODE_CREATION_SIZE = 1;

        struct node {
            key_type key;
            size_type size;
            mapped_type value;
            node *left_node;
            node *right_node;
        };

        class value_compare : public std::binary_function<value_type, value_type, bool> {
        public:
            bool operator()(const value_type &v1, const value_type &v2) const { return comp(v1.first, v2.first); };
        public:
            key_compare compare;
            explicit value_compare(key_compare comp) : compare(comp) {};
        };

        size_type tree_size;
        node *root;
        key_compare comparator;
        typedef typename allocator_type::template rebind<node>::other node_allocator_rebind;
        node_allocator_rebind node_allocator;
        Alloc alloc;
    public:
        explicit map(const key_compare &comp = key_compare(),
                     const allocator_type &alloc = allocator_type()) : tree_size(0), comparator(comp), root(NULL) {
        }

        template<class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type()) : tree_size(0), comparator(comp), root(NULL) {

        }

        map(const map &x) : tree_size(x.size()), root(x.root), comparator(x.comparator) {}

        class iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
        private:
            iterator find_next_element(node cur_node, node cur_max_node) {
                if (cur_node->left_node != NULL) {
                    cur_node = cur_node->left_node;
                    if (cur_max_node == NULL && cur_node.key > i_node->key)
                        cur_max_node = cur_node;
                    else if (cur_node.key > i_node->key && cur_node.key < cur_max_node.key)
                        cur_max_node = cur_node;
                    return find_next_element(cur_max_node);
                }
                if (cur_node->right_node != NULL) {
                    cur_node = cur_node->right_node;
                    if (cur_max_node == NULL && cur_node.key > i_node->key)
                        cur_max_node = cur_node;
                    else if (cur_node.key > i_node->key && cur_node.key < cur_max_node.key)
                        cur_max_node = cur_node;
                    return find_next_element(cur_max_node);
                }
                return cur_max_node;
            }

            iterator find_prev_element(node cur_node, node cur_min_node) {
                if (cur_node->left_node != NULL) {
                    cur_node = cur_node->left_node;
                    if (cur_min_node == NULL && cur_node.key < i_node->key)
                        cur_min_node = cur_node;
                    else if (cur_node.key < i_node->key && cur_node.key > cur_min_node.key)
                        cur_min_node = cur_node;
                    return find_prev_element(cur_min_node);
                }
                if (cur_node->right_node != NULL) {
                    cur_node = cur_node->right_node;
                    if (cur_min_node == NULL && cur_node.key < i_node->key)
                        cur_min_node = cur_node;
                    else if (cur_node.key < i_node->key && cur_node.key > cur_min_node.key)
                        cur_min_node = cur_node;
                    return find_prev_element(cur_min_node);
                }
                return cur_min_node;
            }

        public:
            key_type first;
            mapped_type second;
            node *i_node;

            iterator() {};

            iterator(node *node) : i_node(node) {}

            ~iterator() {};

            T *getObj() { return i_node->element; }

            T &operator*() const { return (i_node->element); }

            iterator operator++() {
                i_node = find_next_element(i_node, NULL);
                return *this;
            }

            iterator operator--() {
                i_node = find_prev_element(i_node, NULL);
                return *this;
            }

            iterator operator++(int) {
                iterator iter(*this);
                i_node = find_next_element(i_node, NULL);
                return iter;
            }

            iterator operator--(int) {
                iterator iter(*this);
                i_node = find_prev_element(i_node, NULL);
                return iter;
            }

            bool operator==(const iterator &i) const { return i_node == i.i_node; }

            bool operator!=(const iterator &i) const { return i_node != i.i_node; }
        };

        class const_iterator
                : public std::iterator<std::bidirectional_iterator_tag, T> {
        public:
            key_type first;
            mapped_type second;
            node *i_node;

            const_iterator() {};

            const_iterator(node *n) : i_node(n) {};

            ~const_iterator() {};

            T *getObj() { return NULL; }

            T &operator*() const { return (i_node->value); }

            iterator operator++() {}

            iterator operator--() {}

            iterator operator++(int) {}

            iterator operator--(int) {}

            bool operator==(const iterator &i) const { return i_node == i.i_node; }

            bool operator!=(const iterator &i) const { return i_node != i.i_node; }
        };

        bool empty() const {
            if (root->size == 0)
                return true;
            else
                return false;
        }

        size_type size() const { return tree_size; }

        size_type max_size() const { return size_type(-1); }

        std::pair<iterator, bool> insert(const value_type &val) {
            return std::make_pair(iterator(push_node(root, val.first, val.second)), true);
        }

        iterator insert(iterator position, const value_type &val) {

            push_node();
        }

        template<class InputIterator>
        void insert(InputIterator first, InputIterator last) {}

        void erase(iterator position) {}

        size_type erase(const key_type &k) { return 0; }

        void erase(iterator first, iterator last) {}

        void swap(map &x) {}

        void clear() {}

        key_compare key_comp() const {}

        iterator find(const key_type &k) {}

        const_iterator find(const key_type &k) const {}

        size_type count(const key_type &k) const { return 0; }

        iterator lower_bound(const key_type &k) {}

        const_iterator lower_bound(const key_type &k) const {}

        iterator upper_bound(const key_type &k) {}

        const_iterator upper_bound(const key_type &k) const {}

        std::pair<const_iterator, const_iterator>
        equal_range(const key_type &k) const {}

        std::pair<iterator, iterator> equal_range(const key_type &k) {}

    private:
        node *rotate_right(node *n) {
            if (n == NULL)
                return (NULL);
            node *to_right = n->left_node;
            n->left_node = to_right->right_node;
            to_right->right_node = n;
            to_right->size = n->size;
            fix_size(n);
            return (to_right);
        }

        node *rotate_left(node *n) {
            if (n == NULL)
                return (NULL);
            node *to_left = n->right_node;
            n->right_node = to_left->left_node;
            to_left->left_node = n;
            to_left->size = n->size;
            fix_size(n);
            return (to_left);
        }

        node *push_to_root(node *n, key_type key, mapped_type val) {
            if (n == NULL)
                return create_node(key, val);
            if (key < n->key) {
                n->left_node = push_to_root(n->left_node, key, val);
                return rotate_right(n);
            }
            n->right_node = push_to_root(n->right_node, key, val);
            return rotate_left(n);
        }

        node *push_node(node *n, key_type key, mapped_type val) {
            if (n == NULL)
                return create_node(key, val);
            if (rand() % (n->size + 1) == 0)
                return push_to_root(n, key, val);
            if (comparator(n->key, key))
                n->left_node = push_node(n->left_node, key, val);
            else
                n->right_node = push_node(n->right_node, key, val);
            fix_size(n);
            return (n);
        }

        node *join(node *n1, node *n2) {
            if (n1 == NULL)
                return (n2);
            if (n2 == NULL)
                return (n1);
            if (rand() % (n1->size + n2->size) < n1->size) {
                n1->right_node = join(n1->right_node, n2);
                fix_size(n1);
                return (n1);
            } else {
                n1->left_node = join(n1, n2->left_node);
                fix_size(n2);
                return (n2);
            }
        }

        node *remove(node *n, key_type key) {
            if (n == NULL)
                return n;
            if (n->key == key) {
                node *tmp = join(n->left_node, n->right_node);
                delete n;
                return tmp;
            } else if (comparator(key, n->key))
                n->left_node = remove(n->left_node, key);
            else
                n->right_node - remove(n->right_node, key);
            return n;
        }

        node *create_node(key_type key, mapped_type val) {
            node *n = node_allocator.allocate(NODE_CREATION_SIZE);
            n->left_node = NULL;
            n->right_node = NULL;
            n->size = 0;
            n->key = key;
            n->value = alloc.allocate(1);
            alloc.construct(n->value, val);
            return n;
        }

        size_type get_size(node *n) {
            if (n == NULL)
                return (0);
            return (n->size);
        }

        void fix_size(node *n) {
            n->size = get_size(n->right_node) + get_size(n->left_node) + 1;
        }
    };

} // namespace ft
#endif // FT_CONTAINERS_MAP_HPP
