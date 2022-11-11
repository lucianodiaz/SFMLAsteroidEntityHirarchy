#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <list>
#include <memory>

#include "Configuration.hpp"
#include "Entity.hpp"


class World : public sf::Drawable
{
public:
	//make it non repicable
	World(const World&) = delete;
	World& operator=(const World&) = delete;
	//
	
	World(float x, float y):_x(x),_y(y){}
	~World() { clear(); };

	void add(Entity* entity);
	void clear();
	bool isCollide(const Entity& other);
	int size() { return _entities.size() + _entities_tmp.size(); }

	void add(Configuration::Sounds sound_id);

	const std::list<Entity*> getEntities()const { return _entities; };

	int getX() const { return _x; };
	int getY() const { return _y; };
	void update(sf::Time deltaTime);

private:

	std::list<Entity*> _entities;
	std::list<Entity*> _entities_tmp;
	
	std::list<std::unique_ptr<sf::Sound>> _sounds;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	const int _x;
	const int _y;
};

