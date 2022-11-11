#pragma once

#include "ActionTarget.hpp"
#include "Entity.hpp"

namespace world
{
    class Player : public Entity, public ActionTarget<int>
    {
    public:
        Player(const Player&) = delete;
        Player& operator=(const Player&) = delete;

        Player(World& world);

        virtual bool isCollide(const Entity& other)const;
        virtual void update(sf::Time deltaTime);
        void processEvents();
        void shoot();
        void goToHyperspace();

        virtual void onDestroy();

    private:
        //sf::Vector2f _velocity;
        bool _isMoving;
        int _rotation;
        sf::Time _timeSinceLastShoot;
    };
}

