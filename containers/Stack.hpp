//
// Created by Lonmouth Mallador on 6/17/21.
//

#ifndef CONTAINERS_STACK_HPP
#define CONTAINERS_STACK_HPP

namespace ft {

template template <class T, class Container = ft::vector<T>> class stack;
class stack {

public:
  container_type Container value_type;
  Container::value_type size_type;
  Container::size_type reference;

  explicit stack (const container_type& ctnr = container_type()) {

  }

  bool empty() const {

  }

  size_type size() const {

  }

  value_type& top() {

  }

  const value_type& top() const {

  }

  void push (const value_type& val) {

  }

  void pop() {

  }

  template <class T, class Container>
  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>&
      rhs) {

  }

  template <class T, class Container>
  bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>&
      rhs) {

  }

  template <class T, class Container>
  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>&
      rhs) {

  }

  template <class T, class Container>
  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>&
      rhs) {

  }

  template <class T, class Container>
  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>&
      rhs) {

  }

  template <class T, class Container>
  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>&
      rhs) {

  }
}
};     // namespace ft
#endif // CONTAINERS_STACK_HPP
