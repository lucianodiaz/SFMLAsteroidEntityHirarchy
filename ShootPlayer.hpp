#pragma once
#include "Entity.hpp"
class ShootPlayer :
    public Entity
{
public:
    ShootPlayer(const Entity& entity);

    virtual bool isCollide(const Entity& other)const;
    virtual void update(sf::Time deltaTime);
};

