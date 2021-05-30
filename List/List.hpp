//
// Created by Lonmouth Mallador on 1/29/21.
//

#ifndef FT_CONTAINERS_LIST_HPP
#define FT_CONTAINERS_LIST_HPP

#define NODE_CREATION_SIZE 1

#include <cstddef>
#include <iostream>

namespace ft {
template <typename T> struct Node {
  T element;
  Node *next;
  Node *prev;
};

template <class T, class Alloc = std::allocator<T> > class list {

public:
  typedef T value_type;
  typedef typename Alloc::pointer pointer;
  typedef typename Alloc::const_pointer const_pointer;
  typedef typename Alloc::reference reference;
  typedef typename Alloc::const_reference const_reference;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef Alloc allocator_type;

private:
  typedef
      typename Alloc::template rebind<Node<value_type> >::other node_allocator;
  allocator_type allocator;
  node_allocator node_alloc;

public:
  explicit list(const allocator_type &alloc = allocator_type())
      : allocator(alloc), node_alloc(alloc) {
    node = create_empty_node();
  }

  explicit list(size_type n, const value_type &val = value_type(),
                const allocator_type &alloc = allocator_type()) {
    node = create_empty_node();
    insert(begin(), n, val);
  }

  template <class InputIterator>
  list(InputIterator first, InputIterator last,
       const allocator_type &alloc = allocator_type()) {
    node = create_empty_node();
    insert<InputIterator>(begin(), first, last);
  }

  list(const list &x) {
    node = create_empty_node();
    insert(begin(), x.begin(), x.end);
  }

  list &operator=(const list &x) { insert(begin(), x.begin(), x.end); }

  bool empty() const;

  class iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
  public:
    Node<T> *i_node;

    iterator(){};

    iterator(Node<T> *node) : i_node(node) {}

    ~iterator(){};

    T *getObj() { return i_node->element; }
    T &operator*() const { return (i_node->element); }

    iterator operator++() {
      i_node = i_node->next;
      return *this;
    }

    iterator operator--() {
      i_node = i_node->prev;
      return *this;
    }

    iterator operator++(int) {
      iterator iter(*this);
      i_node = i_node->next;
      return iter;
    }

    iterator operator--(int) {
      iterator it = *this;
      i_node = i_node->prev;
      return it;
    }

    bool operator==(const iterator &i) const { return i_node == i.i_node; }

    bool operator!=(const iterator &i) const { return i_node != i.i_node; }
  };

  class const_iterator
      : public std::iterator<std::bidirectional_iterator_tag, const T> {
  private:
    Node<T> *obj;

  public:
    const_iterator(){};

    const_iterator(Node<T> *obj) : obj(obj) {}

    T *getObj() { return obj->element; }

    const T &operator*() const { return (obj->element); }
  };

  class reverse_iterator
      : public std::iterator<std::bidirectional_iterator_tag, T> {
  private:
    Node<T> *obj;

  public:
    reverse_iterator(){};

    reverse_iterator(Node<T> *obj) : obj(obj) {}

    ~reverse_iterator(){};

    T *getObj() { return obj->element; }

    T &operator*() const { return (obj->element); }
  };

  class const_reverse_iterator
      : public std::iterator<std::bidirectional_iterator_tag, const T> {
  private:
    Node<T> *obj;

  public:
    const_reverse_iterator(){};

    const_reverse_iterator(Node<T> *obj) : obj(obj) {}

    T *getObj() { return obj->element; }

    const T &operator*() const { return (obj->element); }
  };

  iterator begin() { return iterator(node->next); };

  iterator end() { return iterator(node); };

  const_iterator begin() const { return iterator(node); };

  const_iterator end() const { return iterator(node->prev); };

  reverse_iterator rbegin() { return (reverse_iterator(begin())); };

  reverse_iterator rend() { return (reverse_iterator(end())); };

  const_reverse_iterator rend() const {
    return (const_reverse_iterator(begin()));
  };

  const_reverse_iterator rbegin() const {
    return (const_reverse_iterator(end()));
  };

  size_type size() const { return size_n; }

  size_type max_size() const { return size_type(-1); }

  iterator insert(iterator position, const value_type &val) {
    push_node(position, create_node(val));
    return position;
  }

  void insert(iterator position, size_type n, const value_type &val) {
    for (int i = 0; i < n; i++)
      push_node(position, create_node(val));
  }

  template <class InputIterator>
  void insert(iterator position, InputIterator first, InputIterator last) {
    for (; first != last; first++)
      push_node(position, create_node(*first));
  }

  iterator erase(iterator position) {
    Node<value_type> *current = position.i_node;
    Node<value_type> *next = position.i_node->next;
    Node<value_type> *prev = position.i_node->prev;
    next->prev = prev;
    prev->next = next;
    deallocate_node(current);
    size_n--;
    return next;
  }

  iterator erase(iterator first, iterator last) {
    while (first != last)
      first = erase(first);
    return last;
  }

  reference front() { return *begin(); }

  const_reference front() const { return *begin(); }

  reference back() { return *end(); }

  const_reference back() const { return *end(); }

  template <class InputIterator>
  void assign(InputIterator first, InputIterator last,
              typename std::enable_if<
                  std::__is_input_iterator<InputIterator>::value>::type * = 0) {
    iterator first_my = begin();
    iterator last_my = end();
    for (; first != last && first_my != last_my; first++, first_my++)
      *first_my = *first;
    if (first_my == last_my)
      insert(first_my, first, last);
    else
      erase(first_my, last_my);
  }

  void assign(size_type n, const value_type &val) {
    iterator first = begin();
    iterator last = end();
    for (; n > 0 && first != last; n--, first++)
      *first = val;
    if (first == last)
      insert(first, n, val);
    else
      erase(first, last);
  }

  void push_front(const value_type &val) { insert(begin(), val); }

  void pop_front() { erase(begin()); }

  void push_back(const value_type &val) { insert(end(), val); }

  void pop_back() { erase(end()->prev); }

  void swap(list &x) { swap_lists(this->node, x.node); }

  void clear() { erase(begin(), end()); }

  void resize(size_type n, value_type val = value_type()) {
    if (n > size_n) {
      iterator it = end();
      for (int i = size_n; i < n; i++)
        insert(it, val);
    } else if (n < size_n) {
      iterator it = begin();
      int i = 0;
      while (i < n) {
        it++;
        i++;
      }
      erase(it, end());
    }
  }

  void splice(iterator position, list &x) {
    insert<iterator>(position, x.begin(), x.end());
    x.clear();
  }

  void splice(iterator position, list &x, iterator i) {
    push_node(position, create_node(i.i_node->element));
    x.erase(i);
  }

  void splice(iterator position, list &x, iterator first, iterator last) {
    insert<iterator>(position, first, last);
    x.erase(first, last);
  }

  void remove(const value_type &val) {
    iterator first = begin();
    iterator last = end();

    while (first != last) {
      if (first.i_node->element == val) {
        erase(first);
        break;
      }
      first++;
    }
  }

  template <class Predicate> void remove_if(Predicate pred) {
    iterator first = begin();
    iterator last = end();

    while (first != last) {
      if (pred(first.i_node->element)) {
        erase(first);
      }
      first++;
    }
  }

  void unique()
  {

  }

  template <class BinaryPredicate>
  void unique (BinaryPredicate binary_pred)
  {

  }

  void sort() { sort(default_compare); }

  template <class Compare> void sort(Compare &comp) {
    bool isSorted = false;

    while (!isSorted) {
      isSorted = true;
      iterator current = begin();
      iterator next = begin().i_node->next;

      while (next != end()) {
        if (!comp(current.i_node->element, next.i_node->element)) {
          isSorted = false;
          Node<value_type> *next_node = current.i_node->next;
          Node<value_type> *prev_node = current.i_node->prev;

          current.i_node->next = next_node->next;
          current.i_node->prev = next_node;
          next_node->next->prev = current.i_node;
          next_node->next = current.i_node;
          next_node->prev = prev_node;
          prev_node->next = next_node;
        }
        next++;
        current++;
      }
    }
  }

  void reverse() {
    iterator first = begin();
    iterator last = end();

    while (first != last) {
      last--;
      value_type tmp = first.i_node->element;
      first.i_node->element = last.i_node->element;
      last.i_node->element = tmp;
      if (last == first)
        break;
      first++;
    }
  }

  virtual ~list() { clear(); };

private:
  Node<value_type> *node;
  size_type size_n;

  void push_node(iterator current, Node<value_type> *new_node) {
    current = current.i_node->prev;
    Node<value_type> *temp = current.i_node->next;
    current.i_node->next = new_node;
    temp->prev = new_node;
    new_node->prev = current.i_node;
    new_node->next = temp;
    size_n++;
  }

  void swap_lists(Node<value_type> *x, Node<value_type> *y) {
    if (x->next != x) {
      if (y->next != y) {
        std::swap(x->next, y->next);
        std::swap(x->prev, y->prev);
        x->next->prev = x->prev->next = x;
        y->next->prev = y->prev->next = y;
      } else {
        y->next = x->next;
        y->prev = x->prev;
        y->next->prev = y->prev->next = y;
        x->next = x->prev = x;
      }
    } else if (y->next != y) {
      x->next = y->next;
      x->prev = y->prev;
      x->next->prev = x->prev->next = x;
      y->next = y->prev = y;
    }
  }

  static bool default_compare(const value_type val1, const value_type val2) {
    return (val1 < val2);
  }

  bool default_predicate(const value_type val1, const value_type val2) {
    return (val1 == val2);
  }

  Node<value_type> *allocate_single_node() {
    return node_alloc.allocate(NODE_CREATION_SIZE);
  }

  void deallocate_node(Node<value_type> *node) {
    node_alloc.deallocate(node, NODE_CREATION_SIZE);
  }

  Node<value_type> *create_node(const value_type &val) {
    Node<value_type> *new_node = allocate_single_node();
    try {
      allocator.construct(&(new_node->element), val);
    } catch (...) {
      deallocate_node(new_node);
      return 0;
    }
    return new_node;
  }

  Node<value_type> *create_empty_node() {
    size_n = 0;
    Node<value_type> *new_node = allocate_single_node();
    new_node->next = new_node;
    new_node->prev = new_node;
    return new_node;
  }
};

template <class T, class Alloc> bool list<T, Alloc>::empty() const {
  if (size_n == 0)
    return true;
  else
    return false;
}

} // namespace ft

#endif // FT_CONTAINERS_LIST_HPP
