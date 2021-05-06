//
// Created by lmallado on 03.05.2021.
//

#ifndef CONTAINERS_ENTITY_HPP
#define CONTAINERS_ENTITY_HPP


#include <ostream>

class Entity {
private:
    int value;
public:
    Entity(int value);

    int getValue() const;

    virtual ~Entity();

};

std::ostream &operator<<(std::ostream &os, const Entity &entity);

#endif //CONTAINERS_ENTITY_HPP
