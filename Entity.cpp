#include "Entity.hpp"
#include "Configuration.hpp"

Entity::Entity(Configuration::Textures tex_id, World& world) : _world(world),_alive(true)
{
	sf::Texture& texture = Configuration::textures.get(tex_id);
	_sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2);
}

const sf::Vector2f& Entity::getPosition() const
{
	return _sprite.getPosition();
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}
