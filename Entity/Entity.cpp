//
// Created by lmallado on 03.05.2021.
//

#include <iostream>
#include "Entity.hpp"

Entity::~Entity() {
    std::cout << "Destructor called on value: " << value << std::endl;
}

Entity::Entity(int value) : value(value) {
    std::cout << "Constructor called on value: " << value << std::endl;
}

int Entity::getValue() const {
    return value;
}

std::ostream &operator<<(std::ostream &os, const Entity &entity) {
    os << "value: " << entity.getValue();
    return os;
}

