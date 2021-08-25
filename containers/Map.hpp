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
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef value_type *pointer;
        typedef const value_type *const_pointer;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef Alloc allocator_type;

    private:
        static const int NODE_CREATION_SIZE = 1;

        struct node {
            size_type size;
            pointer value;
            node *root;
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
        node *begin_node;
        node *end_node;
        key_compare comparator;
        typedef typename allocator_type::template rebind<node>::other node_allocator_rebind;
        node_allocator_rebind node_allocator;
        allocator_type alloc;
    public:
        explicit map(const key_compare &comp = key_compare(),
                     const allocator_type &alloc = allocator_type()) : tree_size(0), comparator(comp), root(NULL), begin_node(NULL), end_node(NULL) {
        }

        template<class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type()) : tree_size(0), comparator(comp), root(NULL), begin_node(NULL), end_node(NULL)  {

        }

        map(const map &x) : tree_size(x.size()), root(x.root), comparator(x.comparator), begin_node(x.begin_node), end_node(x.end_node)  {}

        class iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
        private:

            node *get_next(node *cur_node) {
                node *next_max = find_next_element(cur_node);
                if (next_max != NULL && next_max->value->first > i_node->value->first &&
                    next_max->value->first < cur_node->value->first)
                    return next_max;
                if (cur_node->value->first > i_node->value->first)
                    return cur_node;
                return NULL;
            }

            node *get_prev(node *cur_node) {
                node *nearest_max = find_prev_element(cur_node);
                if (nearest_max != NULL && nearest_max->value.first < i_node->value->first &&
                    nearest_max->value->first > cur_node->value->first)
                    return nearest_max;
                if (cur_node->value->first < i_node->value->first)
                    return cur_node;
                return NULL;
            }

            node *find_next_element(node *cur_node) {
                node *max_left = NULL;
                node *max_right = NULL;
                if (cur_node == NULL || i_node == NULL)
                    return NULL;
                if (cur_node->left_node != NULL)
                    max_left = get_next(cur_node->left_node);
                if (cur_node->right_node != NULL)
                    max_right = get_next(cur_node->right_node);
                if ((max_left == NULL && max_right != NULL) ||
                    (max_right != NULL && max_left != NULL &&
                     max_right->value->first < max_left->value->first))
                    return max_right;
                if ((max_right == NULL && max_left != NULL) ||
                    (max_right != NULL && max_left != NULL &&
                     max_left->value->first < max_right->value->first))
                    return max_left;
                return NULL;
            }

            node *find_prev_element(node *cur_node) {
                node *nearest_left = NULL;
                node *nearest_right = NULL;
                if (cur_node == NULL || i_node == NULL)
                    return NULL;
                if (cur_node->left_node != NULL)
                    nearest_left = get_prev(cur_node->left_node);
                if (cur_node->right_node != NULL)
                    nearest_right = get_prev(cur_node->right_node);
                if ((nearest_left == NULL && nearest_right != NULL) ||
                (nearest_left != NULL && nearest_right != NULL &&
                nearest_right->value->first > nearest_left->value->first))
                    return nearest_right;
                if ((nearest_right == NULL && nearest_left != NULL) ||
                (nearest_right != NULL && nearest_left != NULL &&
                nearest_left->value->first > nearest_right->value->first))
                    return nearest_left;
                return NULL;
            }

        public:
            node *i_node;
            node *r;

            iterator() {};

            iterator(node *node) : i_node(node) {
                if (node != NULL)
                    r = &node->root;
            }

            iterator(const iterator &iter) { *this = iter; };

            ~iterator() {};

            T *getObj() { return i_node->value; }

            T &operator*() const { return (i_node->value); }

            iterator operator++() {
                i_node = find_next_element(r);
                return *this;
            }

            iterator operator--() {
                i_node = find_prev_element(r);
                return *this;
            }

            iterator operator++(int) {
                iterator iter(*this);
                i_node = find_next_element(r);
                return iter;
            }

            iterator operator--(int) {
                iterator iter(*this);
                i_node = find_prev_element(r);
                return iter;
            }

            pointer operator->() { return i_node->value; }

            bool operator==(const iterator &i) const { return i_node == i.i_node; }

            bool operator!=(const iterator &i) const { return i_node != i.i_node; }

            iterator &operator=(const iterator &iter) {
                this->i_node = iter.i_node;
                r = iter.r;
                return *this;
            };
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

            pointer operator->() const { return i_node->value; }

            iterator operator++() {}

            iterator operator--() {}

            iterator operator++(int) {}

            iterator operator--(int) {}

            bool operator==(const iterator &i) const { return i_node == i.i_node; }

            bool operator!=(const iterator &i) const { return i_node != i.i_node; }
        };

        iterator begin() { if (tree_size == 0) return iterator(NULL); else return iterator(begin_node); };

        const_iterator begin() const { if (tree_size == 0) return const_iterator(NULL); else return const_iterator(begin_node); };

        iterator end() { return iterator(end_node); };

        const_iterator end() const { return const_iterator(end_node); };

        bool empty() const {
            if (root->size == 0)
                return true;
            else
                return false;
        }

        size_type size() const { return tree_size; }

        size_type max_size() const { return size_type(-1); }

        std::pair<iterator, bool> insert(const value_type &val) {
            iterator f = find(val.first);
            if (f != iterator(NULL))
                return std::make_pair(f, true);
            std::pair<iterator, bool> pair = std::make_pair(iterator(push_node(root, val)), true);
            return pair;
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

        iterator find(const key_type &k) {
            return iterator(find_node(root, k));
        }

        const_iterator find(const key_type &k) const {
            return const_iterator(find_node(root, k));
        }

        size_type count(const key_type &k) const { return 0; }

        iterator lower_bound(const key_type &k) {}

        const_iterator lower_bound(const key_type &k) const {}

        iterator upper_bound(const key_type &k) {}

        const_iterator upper_bound(const key_type &k) const {}

        std::pair<const_iterator, const_iterator>
        equal_range(const key_type &k) const {}

        std::pair<iterator, iterator> equal_range(const key_type &k) {}

    private:

        node *find_node(node *cur_root, const key_type &k) {
            if (cur_root == NULL)
                return cur_root;
            if (k == cur_root->value->first)
                return cur_root;
            if (k < cur_root->value->first)
                return find_node(cur_root->left_node, k);
            else
                return find_node(cur_root->right_node, k);
        }

        node *rotate_right(node *n) {
            node *to_right = n->left_node;
            if (to_right == NULL)
                return (NULL);
            n->left_node = to_right->right_node;
            to_right->right_node = n;
            to_right->size = n->size;
            fix_size(n);
            return (to_right);
        }

        node *rotate_left(node *n) {
            node *to_left = n->right_node;
            if (to_left == NULL)
                return (NULL);
            n->right_node = to_left->left_node;
            to_left->left_node = n;
            to_left->size = n->size;
            fix_size(n);
            return (to_left);
        }

        node *push_to_root(node *n, const_reference val) {
            if (n == NULL) {
                node *new_n = create_node(val);
                if (begin_node == NULL || begin_node->value->first > new_n->value->first)
                    begin_node = new_n;
                if (end_node == NULL || end_node->value->first < new_n->value->first)
                    end_node = new_n;
                if (n == root)
                    root = new_n;
                return new_n;
            }
            if (val.first < n->value->first) {
                n->left_node = push_to_root(n->left_node, val);
                node *new_n = rotate_right(n);
                if (n == root)
                    root = new_n;
                return new_n;
            }
            n->right_node = push_to_root(n->right_node, val);
            node *new_n = rotate_left(n);
            if (n == root)
                root = new_n;
            return new_n;
        }

        node *push_node(node *n, const_reference val) {
            if (n == NULL)
                return push_to_root(NULL, val);
            if (rand() % (n->size + 1) == 0)
                return push_to_root(n, val);
            if (comparator(n->value->first, val.first))
                n->left_node = push_node(n->left_node, val);
            else
                n->right_node = push_node(n->right_node, val);
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

        node *create_node(const_reference val) {
            node *n = node_allocator.allocate(NODE_CREATION_SIZE);
            n->left_node = NULL;
            n->right_node = NULL;
            n->size = 0;
            n->root = *root;
            n->value = alloc.allocate(1);
            alloc.construct(n->value, val);
            tree_size++;
            return n;
        }

        size_type get_size(node *n) {
            if (n == NULL)
                return (0);
            return (n->size);
        }

        iterator get_begin_node() {
            return iterator(search_min_node(root));
        }

        node *search_min_node(node *cur_min) {
            node *min_left = NULL;
            node *min_right = NULL;
            if (cur_min->left_node != NULL)
                min_left = search_min_node(cur_min->left_node);
            if (cur_min->right_node != NULL)
                min_right = search_min_node(cur_min->right_node);
            if (min_left != NULL && min_left->value->first < cur_min->value->first &&
            (min_right == NULL || min_left->value->first < min_right->value->first))
                return min_left;
            if (min_right != NULL && min_right->value->first < cur_min->value->first &&
            (min_left == NULL || min_right->value->first < min_left->value->first))
                return min_right;
            return cur_min;
        }

        iterator get_end_node() {
            iterator first = iterator(root);
            for (int i = 0; i < tree_size; i++, first++);
            return first;
        }

        void fix_size(node *n) {
            n->size = get_size(n->right_node) + get_size(n->left_node) + 1;
        }
    };

} // namespace ft
#endif // FT_CONTAINERS_MAP_HPP
