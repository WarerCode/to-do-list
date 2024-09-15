#ifndef NOTE_H
#define NOTE_H

#include"PushButton.h"
#include"Label.h"

class Note
{
private:
	PushButton* isDoneTrigger;
	Label* label;		// note's text area

	int index;			// from top 0 to buttom DELTA

public:
	Note(int _index); // index defines position
	virtual ~Note();
};

#endif // NOTE_H