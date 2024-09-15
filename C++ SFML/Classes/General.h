#ifndef GENERAL_H
#define GENERAL_H

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 1000
#define BACK_FILL sf::Color{255, 255, 100}
#define EPSILONE 0.7f					// it width of note in windows
#define DELTA 10						// count of notes in window
#define TEXT_NOTE_HEIGHT_RATIO 0.7f		// text height / note height
#define TEXT_SIZE static_cast<int>((WINDOW_HEIGHT / DELTA) * TEXT_NOTE_HEIGHT_RATIO) // in pixels

#include<iostream>
#include<fstream>

#endif
