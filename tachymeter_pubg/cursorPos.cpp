#include "cursorPos.h"

#define push_down(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)

int cursorPos::counter = 0;
cursorPos::cursorPos()
{
	this->m_cP.x = 0;
	this->m_cP.y = 0;
}
cursorPos::cursorPos(const cursorPos& cP)
{
	this->m_cP = cP.m_cP;
}
cursorPos::cursorPos(POINT p)
{
	this->m_cP = p;
}
int cursorPos::getPos()
{
	POINT cPos;
	while (true)
	{
		if (push_down(VK_MBUTTON))
		{
			if (GetCursorPos(&(this->m_cP)))
			{
				if (counter == 1)
				{
					this->counter++;
					return 1;
				}
				system("cls");
				this->counter++;
				return 1;
			}
			else
			{
				this->m_cP.x = 0;
				this->m_cP.y = 0;
				std::cout << "获取鼠表指针位置失败\n";
				return -1;
			}
		}
		else if (push_down(VK_END))
		{
			return 0;
		}
	}
}