#include "MainWindow.h"
#include"General.h"

sf::RenderWindow* MainWindow::pWin = nullptr;
sf::VideoMode* MainWindow::videoMode = nullptr;

uint MainWindow::width = 0;
uint MainWindow::height = 0;
uint MainWindow::notec = 0;
bool MainWindow::open = true;

const sf::String MainWindow::title = "To Do List";
const sf::Color MainWindow::fill = { 0,0,0,0 }; // some color
std::map<id, sf::RectangleShape*> MainWindow::notes = {};

MainWindow::MainWindow() {
	initVariables();
	initWindow();
}

MainWindow::~MainWindow() {
	delete pWin;
	delete videoMode;
}

void MainWindow::initWindow() {
	videoMode = new sf::VideoMode(width, height, 16U); // 16 bits per pixel depth
	pWin = new sf::RenderWindow(*videoMode, title, sf::Style::Titlebar | sf::Style::Close);
	// 16 bits for 4 canals means by 4 bits per canal [0 - 15]

	pWin->setFramerateLimit(60);
	pWin->setActive(true);
}

void MainWindow::initVariables() {
	width = WINDOW_WIDTH;
	height = WINDOW_HEIGHT;
}

void MainWindow::initNotes() {
	
}

void MainWindow::render() {
	pWin->clear(fill);

	pollEvents();
	for (auto& note : notes) {
		pWin->draw(*note.second);
	}

	pWin->display();
}

void MainWindow::pollEvents() {
	sf::Event ev;
	while (pWin->pollEvent(ev)) {
		switch (ev.type) {
		case sf::Keyboard::Escape:
			pWin->close();
			open = false;
			break;
		case sf::Event::Closed:
			pWin->close();
			open = false;
			break;
		default:
			break;
		}
	}
}

bool MainWindow::isOpen() {
	return open;
}

void MainWindow::addNote() {

}
