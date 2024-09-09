#include "Label.h"
#include "General.h"

const sf::Color Label::background = { 8, 8, 8 };
sf::Font Label::font;

void Label::initFont() {
	if (!font.loadFromFile("src/fonts/Deledda Open Thin.ttf")) {
		std::cerr << "\nLABEL::INITFONT::failed to load font\n" << std::endl;
		exit(EXIT_FAILURE);
	}
}

Label::Label(std::string _note) {
	this->note = _note;
	this->borders = new sf::RectangleShape(sf::Vector2f(	// 70 % of window in the width
		WINDOW_WIDTH * EPSILONE, WINDOW_HEIGHT / DELTA));	// 5% (1/20) of window height
	this->initFont();
}

Label::~Label() {
	delete this->borders;
}

void Label::rewrite(std::string newNote) {
	this->note = newNote;
}

void Label::draw(sf::RenderWindow* pWin) {
	pWin->draw(*this->borders);
}

std::string Label::getNote() {
	return this->note;
}
