#include "MainWindow.h"

sf::RenderWindow* MainWindow::pWin = nullptr;
sf::VideoMode* MainWindow::videoMode = nullptr;

uint MainWindow::width = 0;
uint MainWindow::height = 0;
uint MainWindow::notec = 0;

const sf::String MainWindow::title = "To Do List";
const sf::Color MainWindow::fill = { 0,0,0,0 }; // some color
std::map<id, sf::RectangleShape*> MainWindow::notes = {};

MainWindow::MainWindow()
{
	initVariables();
	initWindow();
}

MainWindow::~MainWindow()
{
	delete pWin;
	delete videoMode;
}

void MainWindow::initWindow()
{
	videoMode = new sf::VideoMode(width, height, 16U); // 16 bits per pixel depth
	pWin = new sf::RenderWindow(*videoMode, title, sf::Style::Titlebar | sf::Style::Close);
	// 16 bits for 4 canals means by 4 bits per canal [0 - 15]

	pWin->setFramerateLimit(60);
}

void MainWindow::initVariables()
{
	width = 600;
	height = 800;
}

void MainWindow::render()
{
	pWin->clear(fill);

	pollEvents();
	for (auto& note : notes) {
		pWin->draw(*note.second);
	}

	pWin->display();
}

void MainWindow::pollEvents()
{
	sf::Event ev;
	while (pWin->pollEvent(ev)) {
		switch (ev.type) {
		case sf::Keyboard::Escape:
			pWin->close();
			break;
		default:
			break;
		}
	}
}

void MainWindow::addNote(toDo* thing)
{
	notes.emplace(toDo(thing->first, thing->second));
}
