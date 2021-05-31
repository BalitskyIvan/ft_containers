//
// Created by Lonmouth Mallador on 5/31/21.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

namespace ft {

template < class T, class Alloc = allocator<T> > class vector {

public:

  typedef T value_type;
  typedef typename Alloc::pointer pointer;
  typedef typename Alloc::const_pointer const_pointer;
  typedef typename Alloc::reference reference;
  typedef typename Alloc::const_reference const_reference;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef Alloc allocator_type;

  explicit vector (const allocator_type& alloc = allocator_type()) {

  }

  explicit vector (size_type n, const value_type& val = value_type(),
                   const allocator_type& alloc = allocator_type()) {

  }

  template <class InputIterator>
  vector (InputIterator first, InputIterator last,
          const allocator_type& alloc = allocator_type()) {

  }

  vector (const vector& x) {

  }
}

private:


} // namespace ft

#endif // FT_CONTAINERS_VECTOR_HPP
