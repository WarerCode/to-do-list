#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include<SFML/Graphics.hpp>

typedef sf::Vector2i vec2i;
typedef sf::RectangleShape rect;
typedef sf::Color color;

class PushButton : public rect // pushButton
{
private:
	rect* buttonRect;

	vec2i* size;
	static const float outlineThickness;
	static const color line;
	static const color on;
	static const color off;

	bool* triggered;

public:
	PushButton(int xSize, int ySize, int xPos, int yPos);
	virtual ~PushButton();

	void triggering();
	void draw(sf::RenderWindow* pWin);
};

# endif // BUTTON_H