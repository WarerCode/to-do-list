#include "Label.h"
#include "General.h"

const sf::Color Label::background = { 8, 8, 8 };
sf::Font Label::font;

void Label::initFont() {
	if (!font.loadFromFile("src/fonts/Deledda Open Thin.ttf")) {
		std::cerr << "\nLABEL::INITFONT::failed to load font\n" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void Label::initText() {
	this->text.setCharacterSize(TEXT_SIZE);
	this->text.setPosition(this->pos);
}

Label::Label(std::string _note, sf::Vector2f _pos) {
	this->pos = _pos;

	this->note = _note;
	this->borders = new sf::RectangleShape(sf::Vector2f(		// 70 % of window in the width
		WINDOW_WIDTH * EPSILONE, WINDOW_HEIGHT / (2 * DELTA)));	// 5% (1/20) of window height
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
	pWin->draw(this->text);
}

std::string Label::getNote() {
	return this->note;
}
