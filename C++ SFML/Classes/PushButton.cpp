#include "PushButton.h"

const float PushButton::outlineThickness = 2;
const color PushButton::line = { 16, 16, 16 };
const color PushButton::on = {0, 255, 0};
const color PushButton::off = {255, 0, 0};

PushButton::PushButton(int x, int y, int xPos, int yPos) {
	this->size = new vec2i{ abs(x), abs(y) };
	this->triggered = new bool{ false }; // strange maybe?
	this->buttonRect = new rect{ static_cast<sf::Vector2f>(*this->size) };
	this->buttonRect->setPosition(static_cast<sf::Vector2f>(vec2i{ xPos, yPos }));
	this->buttonRect->setOutlineThickness(outlineThickness);
	this->buttonRect->setOutlineColor(line);

	if (*(this->triggered)) {
		this->buttonRect->setFillColor(on);
	}
	else {
		this->buttonRect->setFillColor(off);
	}
}

PushButton::~PushButton() {
	delete this->size;
	delete this->triggered;
	delete this->buttonRect;
}

void PushButton::triggering() {
	*(this->triggered) = !(*triggered);
	if (*(this->triggered)) {
		this->buttonRect->setFillColor(on);
	}
	else {
		this->buttonRect->setFillColor(off);
	}
}

void PushButton::draw(sf::RenderWindow* pWin) {
	pWin->draw(*this->buttonRect);
}
