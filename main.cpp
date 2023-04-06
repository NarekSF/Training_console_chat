#include <iostream>
#include "Chat.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	cout << "                  Chatterer1.0" << endl;
	cout << "...............  _____________ ..." << endl;
	cout << "..............//_____________/..." << endl;
	cout << ".............//___/---------/..." << endl;
	cout << "............//___/          ..." << endl;
	cout << "...........//___/          ..." << endl;
	cout << "..........//___/---------/..." << endl;
	cout << ".........//_____________/.тм" << endl;
	cout << endl;

	Chat chat;

	chat.start(); //включаем чат

	while (chat.isChatWork()) //активируем работу меню и иных функций чата
	{
		chat.showLoginMenu();

		while (chat.getCurrentUser())
		{
			chat.showUserMenu();
		}
	}

	return 0;
}