#pragma once

#include <SFML/Audio.hpp> //sf::Music
#include <unordered_map> //unordered_map
#include <string> //string
#include <memory> //unique_ptr
#include <stdexcept> //runtime_error
#include <utility> //forward


template<typename RESOURCE,typename IDENTIFIER = int>
class ResourceManager
{
public:
	//This class can't be copied
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;
	//

	ResourceManager() = default;

	template<typename ... Args>
	void load(const IDENTIFIER& id,Args&& ... args);

	RESOURCE& get(const IDENTIFIER& id) const;

private:
	  std::unordered_map<IDENTIFIER,std::unique_ptr<RESOURCE>> _map;
};

template<typename IDENTIFIER>
class ResourceManager<sf::Music, IDENTIFIER>
{
public:
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;

	ResourceManager() = default;

	template<typename ... Args>
	void load(const IDENTIFIER & id, Args&& ... args);

	sf::Music& get(const IDENTIFIER & id)const;

private:
	std::unordered_map<IDENTIFIER, std::unique_ptr<sf::Music>> _map;
};


template<typename RESOURCE, typename IDENTIFIER>
template<typename ...Args>
void ResourceManager<RESOURCE, IDENTIFIER>::load(const IDENTIFIER& id, Args && ...args)
{
	std::unique_ptr<RESOURCE> ptr(new RESOURCE);
	if (!ptr->loadFromFile(std::forward<Args>(args)...))
	{
		throw std::runtime_error("Imposible to load file");
	}
	_map.emplace(id, std::move(ptr));
}


template<typename RESOURCE, typename IDENTIFIER>
RESOURCE& ResourceManager<RESOURCE, IDENTIFIER>::get(const IDENTIFIER& id) const
{
	return *_map.at(id);
}


//Specialization Template for SF::Music Case
template<typename IDENTIFIER>
template<typename ...Args>
inline void ResourceManager<sf::Music, IDENTIFIER>::load(const IDENTIFIER& id, Args && ...args)
{
	std::unique_ptr<sf::Music> ptr(new sf::Music);
	if (!ptr->openFromFile(std::forward<Args>(args)...))
	{
		throw std::runtime_error("Imposible to load file");
	}
	_map.emplace(id, std::move(ptr));
}

template<typename IDENTIFIER>
sf::Music& ResourceManager<sf::Music,IDENTIFIER>::get(const IDENTIFIER& id) const
{
	return *_map.at(id);
}