#ifndef BUTTON_H
#define BUTTON_H

#include<SFML/Graphics.hpp>

typedef sf::Vector2i vec2i;
typedef sf::Color color;

class PushButton : sf::RectangleShape // pushButton
{
private:
	vec2i* size;
	static const color on;
	static const color off;

	bool* triggered;

public:
	PushButton(int x, int y);
	virtual ~PushButton();

	void triggering();
};

# endif // BUTTON_H