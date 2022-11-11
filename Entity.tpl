#include <utility>

template<typename ... Args>
void Entity::setPosition(Args&& ... args)
{
    _sprite.setPosition(std::forward<Args>(args)...);
}