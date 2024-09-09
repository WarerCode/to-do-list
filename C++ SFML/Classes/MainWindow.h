#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#include<map>

typedef unsigned int uint, id;
typedef std::pair<id, sf::RectangleShape*> toDo;

class MainWindow : public sf::RenderWindow
{
private:
	static sf::RenderWindow* pWin;
	static bool open;

	static uint width;
	static uint height;
	static uint notec;

	static sf::VideoMode* videoMode;
	static const sf::String title;
	static const sf::Color fill;

	static std::map<id, sf::RectangleShape*> notes;

public:
	MainWindow();
	virtual ~MainWindow();

	// Construct
	static void initWindow();
	static void initVariables();
	static void initNotes();

	static void pollEvents();
	static bool isOpen();
	static void render();
	static void addNote();
};

#endif