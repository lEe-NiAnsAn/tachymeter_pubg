#include <Windows.h>
#include <iostream>
#include <cmath>
#include "cursorPos.h"

#define push_up(VK_NONAME) (!(GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)

int main()
{	
	std::cout << "ʹ������м�ȷ�����㣬ʹ��end���˳�\n";
	cursorPos cp1;
	cursorPos cp2;
	while (true)
	{
		if (cp1.getPos() >= 0)
		{
			if (cursorPos::counter == 0)
			{
				std::cout << "�˳�\n";
				break;
			}
			else
			{
				std::cout << "������꣺ ("
					<< cp1.m_cP.x << "," << cp1.m_cP.y << ")\n";
				while (true)
				{
					if(push_up(VK_MBUTTON))
					{
						if (cp2.getPos() >= 0)
						{
							if (cursorPos::counter == 1)
							{
								std::cout << "�˳�\n";
								break;
							}
							else
							{
								std::cout << "�յ����꣺ ("
									<< cp2.m_cP.x << "," << cp2.m_cP.y << ")\n";
								break;
							}
						}
					}
				}
				break;
			}
		}
	}
	if (cursorPos::counter == 2)
	{
		float distance = sqrt(pow((cp1.m_cP.x - cp2.m_cP.x), 2) + pow((cp1.m_cP.y - cp2.m_cP.y), 2));
		std::cout << "�������Ϊ��" << distance << "\n";
	}
	system("pause");
	return 0;
}
