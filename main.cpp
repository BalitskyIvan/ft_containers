#include "Entity/Entity.hpp"
#include "List/List.hpp"
#include <list>

int main() {
  //  {
  //    ft::list<Entity> abc2;
  //    Entity *entity = new Entity(1);
  //
  //    abc2.push_front(*entity);
  //    abc2.push_front(Entity(2));
  //    abc2.push_front(Entity(3));
  //    abc2.push_front(Entity(4));
  //    abc2.push_front(Entity(5));
  //
  //    ft::list<Entity>::iterator first = abc2.begin();
  //    ft::list<Entity>::iterator last = abc2.end();
  //    for (int i = 0; i < 8; i++) {
  //      std::cout << *last << std::endl;
  //      --last;
  //    }
  //  }
  //  {
  //    std::cout << "\nstd:\n" << std::endl;
  //
  //    std::list<Entity> abc2;
  //    Entity *entity = new Entity(1);
  //    abc2.push_front(*entity);
  //    abc2.push_front(Entity(2));
  //    abc2.push_front(Entity(3));
  //    abc2.push_front(Entity(4));
  //    abc2.push_front(Entity(5));
  //    delete entity;
  //    std::list<Entity>::iterator first = abc2.begin();
  //    std::list<Entity>::iterator last = abc2.end();
  //    for (int i = 0; i < 8; i++) {
  //      std::cout << *last << std::endl;
  //      --last;
  //    }
  //  }

  {
    ft::list<int> first(3, 100);  // three ints with a value of 100
    ft::list<int> second(5, 200); // five ints with a value of 200

    first.swap(second);

    std::cout << "first contains:";
    for (ft::list<int>::iterator it = first.begin(); it != first.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "second contains:";
    for (ft::list<int>::iterator it = second.begin(); it != second.end(); it++)
      std::cout << ' ' << *it; 
    std::cout << '\n';
  }
  {
    std::list<int> first(3, 100);  // three ints with a value of 100
    std::list<int> second(5, 200); // five ints with a value of 200

    first.swap(second);

    std::cout << "first contains:";
    for (std::list<int>::iterator it = first.begin(); it != first.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "second contains:";
    for (std::list<int>::iterator it = second.begin(); it != second.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
  }
  return 0;
}
