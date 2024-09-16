#include <Windows.h>
#include <iostream>

class cursorPos
{
public:
	cursorPos();
	cursorPos(const cursorPos& cP);
	cursorPos(POINT p);
	int getPos();
	static int counter;
	POINT m_cP;
};
