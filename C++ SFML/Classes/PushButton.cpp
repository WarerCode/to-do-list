#include "PushButton.h"

const color PushButton::on = {0, 255, 0};
const color PushButton::off = {255, 0, 0};

PushButton::PushButton(int x, int y) {
	this->size = new vec2i{ abs(x), abs(y) };
	this->triggered = new bool{ false }; // strange maybe?
}

PushButton::~PushButton() {
	delete this->size;
	delete this->triggered;
}

void PushButton::triggering() {
	*(this->triggered) = !(*triggered);
}
