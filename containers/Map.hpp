//
// Created by Lonmouth Mallador on 5/31/21.
//

#ifndef FT_CONTAINERS_MAP_HPP
#define FT_CONTAINERS_MAP_HPP

#include <iostream>

namespace ft {

template <class Key, class T, class Compare = std::less<Key>,
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
  struct node
  {
    key_type key;
    size_type size;
    mapped_type value;
    node *left_node;
    node *right_node;
    node(key_type k, mapped_type val) {
      key = k;
      value = val;
      left_node = nullptr;
      right_node = nullptr;
      size = 1;
    }
  };
  node *root;

public:

  explicit map(const key_compare &comp = key_compare(),
               const allocator_type &alloc = allocator_type()) {}

  template <class InputIterator>
  map (InputIterator first, InputIterator last,
       const key_compare& comp = key_compare(),
       const allocator_type& alloc = allocator_type()) {

  }

  map (const map& x) {

  }

  class iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
  public:
    key_type first;
    mapped_type second;
    node *i_node;

    iterator(){};

    iterator(node *node) : i_node(node) {}

    ~iterator(){};

    T *getObj() { return i_node->element; }
    T &operator*() const { return (i_node->element); }

    iterator operator++() {

    }

    iterator operator--() {

    }

    iterator operator++(int) {

    }

    iterator operator--(int) {


    }

    bool operator==(const iterator &i) const { return i_node == i.i_node; }

    bool operator!=(const iterator &i) const { return i_node != i.i_node; }
  };

  class const_iterator : public
                         std::iterator<std::bidirectional_iterator_tag, T> {
  public:
    key_type first;
    mapped_type second;
    node *i_node;

    iterator(){};

    iterator() : i_node() {}

    ~iterator(){};

    T *getObj() { return ; }
    T &operator*() const { return (); }

    iterator operator++() {

    }

    iterator operator--() {

    }

    iterator operator++(int) {

    }

    iterator operator--(int) {


    }

    bool operator==(const iterator &i) const { return i_node == i.i_node; }

    bool operator!=(const iterator &i) const { return i_node != i.i_node; }
  };

  bool empty() const {
    if (root->size == 0)
      return true;
    else
      return false;
  }

  size_type size() const {
    return root->size;
  }

  size_type max_size() const {
    return size_type(-1);
  }

  std::pair<iterator,bool> insert (const value_type& val) {

  }

  iterator insert (iterator position, const value_type& val) {

  }

  template <class InputIterator>
  void insert (InputIterator first, InputIterator last) {

  }

  void erase (iterator position) {

  }

  size_type erase (const key_type& k) {

  }

  void erase (iterator first, iterator last) {

  }

  void swap (map& x) {

  }

  void clear() {

  }

  key_compare key_comp() const {

  }

  iterator find (const key_type& k) {

  }

  const_iterator find (const key_type& k) const {

  }

  size_type count (const key_type& k) const {

  }

  iterator lower_bound (const key_type& k) {

  }

  const_iterator lower_bound (const key_type& k) const {

  }

  iterator upper_bound (const key_type& k) {

  }

  const_iterator upper_bound (const key_type& k) const {

  }

  std::pair<const_iterator,const_iterator> equal_range (const key_type& k)
      const {

  }

  std::pair<iterator,iterator> equal_range (const key_type& k) {

  }

private:

  node* rotate_right(node *n) {
    if (n == nullptr)
      return (nullptr);
    node *to_right = n->left;
    n->left_node = to_right->right_node;
    to_right->right_node = n;
    to_right->size = n->size;
    fix_size(n);
    return (to_right);
  }

  node* rotate_left(node *n) {
    if (n == nullptr)
      return (nullptr);
    node *to_left = n->right_node;
    n->right_node = to_left->left_node;
    to_left->left_node = n;
    to_left->size = n->size;
    fix_size(n);
    return (to_left);
  }

  node *push_to_root(node *n, key_type key, mapped_type val) {
    if (n == nullptr)
      return create_node(key, val);
    if (key < n->key) {
      n->left_node = push_to_root(n->left_node, key, val);
      return rotate_right(n);
    }
    n->right_node = push_to_root(n->right_node, key, val);
    return rotate_left(n);
  }

  node *push_node(node *n, key_type key, mapped_type val) {
    if (n == nullptr)
      return create_node(key, val);
    if (rand() % (n->size + 1) == 0)
      return push_to_root(n, key, val);
    if (key_compare(n->key, key))
      n->left_node = push_node(n->left_node, key, val);
    else
      n->right_node = push_node(n->right_node, key, val);
    fix_size(n);
    return (n);
  }

  node *join(node *n1, node *n2) {
    if (n1 == nullptr)
      return (n2);
    if (n2 == nullptr)
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
    if (n == nullptr)
      return n;
    if (n->key == key) {
      node *tmp = join(n->left_node, n->right_node);
      delete n;
      return tmp;
    }
    else if (key_compare(key, n->key))
      n->left_node = remove(n->left_node, key);
    else
      n->right_node - remove(n->right_node, key);
    return n;
  }

  node *create_node(key_type key, mapped_type) {

  }

  size_type get_size(node *n) {
    if (n == nullptr)
      return (0);
    return (n->size);
  }

  void fix_size(node *n) {
    n->size = get_size(n->right_node) + get_size(n->left_node) + 1;
  }
};

} // namespace ft
#endif // FT_CONTAINERS_MAP_HPP