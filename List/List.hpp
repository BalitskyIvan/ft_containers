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
    insert(begin(), first, last);
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

  iterator begin() { return node->next; };

  iterator end() { return node; };

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
  void insert(iterator position, iterator first, iterator last) {
    for (; first != last; first++)
      push_node(position, *first);
  }

  iterator erase(iterator position) {
    Node<value_type> prev = *position;
    Node<value_type> next = (*position).next;
    prev->next = next;
    next->prev = prev;
    deallocate_node(*position);
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
  void assign(InputIterator first, InputIterator last) {
    //			iterator first_my = begin();
    //			iterator last_my = end();
    //			while (first_my != last_my)
    //				if () {
    //				} else {
    //					first = erase(first);
    //				}
  }

  void assign(size_type n, const value_type &val) {
    //			iterator first = begin();
    //			iterator last = end();
    //			int i = 0;
    //			while (first != last)
    //				if (i < n) {
    //					i++;
    //				} else {
    //					first = erase(first);
    //				}
  }

  void push_front(const value_type &val) { insert(begin(), val); }

  void pop_front() { erase(begin()); }

  void push_back(const value_type &val) { insert(end(), val); }

  void pop_back() { erase(end()->prev); }

  void swap(list &x) { swap_lists(this->node, x.node); }

  void resize(size_type n, value_type val = value_type()) {
    if (n > size_n) {
      iterator it = end();
      for (int i = size_n; i < n; i++) {
        insert(it, val);
        i++;
      }
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

  virtual ~list(){
      //	erase(begin(), end());
  };

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
