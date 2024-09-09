#ifndef LABEL_H
#define LABEL_H

#include<string>
#include<SFML/Graphics.hpp>

class Label : sf::RectangleShape
{
private:
	std::string note;

	sf::RectangleShape* borders;
	static const sf::Color background;
	static sf::Font font;

	void initFont();

public:
	Label(std::string _note = "");
	virtual ~Label();

	void rewrite(std::string newNote);
	virtual void draw(sf::RenderWindow* pWin);

	// Accessors
	std::string getNote();
};



#endif // !LABEL_H