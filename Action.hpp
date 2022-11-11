#pragma once

#include <SFML/Window/Event.hpp>

class Action
{
public:
	enum Type
	{
		RealtTime=1,
		Pressed =1<<1,
		Released = 1<<2
	};
	//Constructor for keyboard
	Action(const sf::Keyboard::Key& key, int type = Type::RealtTime | Type::Pressed);
	//constructor for Mouse
	Action(const sf::Mouse::Button& button, int type = Type::RealtTime | Type::Pressed);

	//Check if event if event is in Real time or is a poll
	bool test()const;

	//overload = operator and create a constructor for copy
	Action(const Action& other);
	Action& operator=(const Action& other);

	//overload to check if an event or action is equal or not
	bool operator==(const sf::Event& event) const;
	bool operator==(const Action& other)const;

private:
	template<typename> friend class ActionTarget;
	sf::Event _event;
	int _type;
};

