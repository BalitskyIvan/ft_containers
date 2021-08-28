//
// Created by Lonmouth Mallador on 6/17/21.
//

#ifndef CONTAINERS_STACK_HPP
#define CONTAINERS_STACK_HPP


namespace ft {

template<class T, class Container >
class stack {

public:
    typedef Container	container_type;
    typedef T			value_type;
  typedef size_t		size_type;

  explicit stack (const container_type& = container_type()) {
    this->container = container;
  }

  bool empty() const {
      return this->container.empty();
  }

  size_type size() const {
     return this->container.size();
  }

  value_type& top() {
      return this->container.back();
  }

  const value_type& top() const {
      return this->container.back();
  }

  void push(const value_type& val) {
      this->container.push_back(val);
  }

  void pop() {
      this->container.pop_back();
  }
protected:
  container_type c;
private:
    container_type container;
};

};
// namespace ft
template <class T, class Container> bool ft::operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return lhs.getContainer() == rhs.getContainer(); };
template <class T, class Container> bool ft::operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return lhs.getContainer() != rhs.getContainer(); };
template <class T, class Container> bool ft::operator<  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return lhs.getContainer() < rhs.getContainer(); };
template <class T, class Container> bool ft::operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return lhs.getContainer() <= rhs.getContainer(); };
template <class T, class Container> bool ft::operator>  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return lhs.getContainer() > rhs.getContainer(); };
template <class T, class Container> bool ft::operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return lhs.getContainer() >= rhs.getContainer(); };

#endif // CONTAINERS_STACK_HPP
