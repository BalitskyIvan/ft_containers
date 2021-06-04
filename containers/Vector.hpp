//
// Created by Lonmouth Mallador on 5/31/21.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

namespace ft {

template <class T, class Alloc = std::allocator<T> > class vector {

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
                  const allocator_type &alloc = allocator_type()) {}

  template <class InputIterator>
  vector(InputIterator first, InputIterator last,
         const allocator_type &alloc = allocator_type()) {}

  vector(const vector &x) {}

  class iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
  public:
    value_type *item;

    iterator(){};

    iterator(value_type *item) : item(item) {}

    ~iterator(){};

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

    bool operator==(const iterator &i) const { return *i.item == *item; }

    bool operator!=(const iterator &i) const { return *i.item != *item; }
  };

  class const_iterator
      : public std::iterator<std::bidirectional_iterator_tag, const T> {
  public:
    value_type *item;

    const_iterator(){};

    const_iterator(value_type *i) : item(i) {}
    ~const_iterator(){};

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
    push_item(position, val);
    return --position;
  }

  void insert(iterator position, size_type n, const value_type &val) {
    for (int i = 0; i < n; i++)
      push_item();
  }

  template <class InputIterator>
  void insert(iterator position, InputIterator first, InputIterator last) {
    for (; first != last; first++)
      push_item(position, *first);
  }

  void push_back(const value_type &val) { push_item(end(), val); }

  size_type size() const { return size_a; }

  size_type max_size() const { return size_type(-1); }

  size_type capacity() const { return capacity_a; }

  bool empty() const {
    if (size_a == 0)
      return true;
    else
      return false;
  }

private:
  allocator_type allocator;
  size_type size_a;
  size_type capacity_a;
  value_type *array;

  void push_item(iterator position, const value_type &val) {
    if (size_a + 1 < capacity_a) {
      move_items_right(position, array);
      allocator.construct((array + size_a), val);
      size_a++;
    } else {
      capacity_a *= 2;
      value_type *new_array = allocator.allocate(capacity_a);
      for (int i = 0; i < size_a; i++) {
        new_array[i] = array[i];
      }
      move_items_right(iterator(new_array + size_a), new_array);
      allocator.construct(&new_array[size_a], val);
      allocator.deallocate(array, size_a);
      size_a++;
      array = new_array;
    }
  }

  void move_items_right(iterator position, value_type *arr) {
    int current = 0;
    iterator first = iterator(arr);
    if (position == iterator(arr + size_a)) {
      return;
    }
    for (; first != position; first++, current++);
    value_type tmp = arr[current];
    for (; current < size_a; current++) {
      value_type next = arr[current + 1];
      arr[current + 1] = tmp;
      tmp = next;
    }
  }

  void move_items_left(iterator position, value_type *arr) {
    int current = 0;
    iterator first = begin();
    for (; first != position; first++, current++)
      ;
    value_type tmp = arr[current + 1];
    for (; current != size_a; current++) {
      value_type next = arr[current];
      arr[current] = tmp;
      tmp = next;
    }
  }

};
} // namespace ft

// namespace ft

#endif // FT_CONTAINERS_VECTOR_HPP
