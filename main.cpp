#include "List/List.hpp"
#include <list>
#include <map>
#include "Entity/Entity.hpp"

int main() {
    {
        ft::list<Entity> abc2;
        Entity *entity = new Entity(1);

        abc2.push_front(*entity);
        abc2.push_front(Entity(2));
        abc2.push_front(Entity(3));
        delete entity;
        ft::list<Entity>::iterator first = abc2.begin();
        ft::list<Entity>::iterator last = abc2.end();
        for (int i = 0; i < 6; i++)
        {
            std::cout << *first << std::endl;
            ++first;
        }
    }
    {
        std::cout << "\nstd:\n" << std::endl;

        std::list<Entity> abc2;
        Entity *entity = new Entity(1);
        abc2.push_front(*entity);
        abc2.push_front(Entity(2));
        abc2.push_front(Entity(3));
        delete entity;
        std::list<Entity>::iterator first = abc2.begin();
        std::list<Entity>::iterator last = abc2.end();
        for (int i = 0; i < 6; i++)
        {
            std::cout << *first << std::endl;
            ++first;
        }
    }

    return 0;
}
