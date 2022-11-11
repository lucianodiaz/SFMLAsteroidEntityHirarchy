#pragma once
#include <SFML/Graphics.hpp>
#include "World.hpp"

class Entity : public sf::Drawable
{
public:
	Entity(const Entity&) = delete;
	Entity& operator=(const Entity&) = delete;

	Entity(Configuration::Textures tex_id, World& world);

	virtual ~Entity();

	

	//Helpers
	virtual bool isAlive()const { return _alive; }

	virtual bool isCollide(const Entity& other)const = 0;

	template<typename ... Args>
	void setPosition(Args&& ... args);

	const sf::Vector2f& getPosition()const;

	const sf::Sprite& sprite()const { return _sprite; };

	//updates
	virtual void update(sf::Time deltaTime)=0;
	virtual void onDestroy() { _alive = false; }

protected:
	sf::Sprite _sprite;
	sf::Vector2f _impulse;
	World& _world;
	bool _alive;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#include "Entity.tpl"