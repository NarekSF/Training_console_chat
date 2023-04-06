#include "Chat.h"
#include <iostream>

void Chat::start()
{
	isChatWork_ = true;
}

std::shared_ptr<User> Chat::getUserByLogin(const std::string& login) const
{
	for (auto& user : users_)
	{
		if (login == user.getUserLogin())
			return std::make_shared<User>(user);
	}
	return nullptr;
}

std::shared_ptr<User> Chat::getUserByName(const std::string& name) const
{
	for (auto& user : users_)
	{
		if (name == user.getUserName())
			return std::make_shared<User>(user);
	}
	return nullptr;
}

void Chat::login()
{
	std::string login, password;
	char operation;

	do
	{
		std::cout << "login: ";
		std::cin >> login;
		std::cout << "password: ";
		std::cin >> password;

		currentUser_ = getUserByLogin(login);

		if (currentUser_ == nullptr || (password != currentUser_->getUserPassword()))
		{
			currentUser_ = nullptr;

			std::cout << "login failed" << std::endl;
			std::cout << "(0)exit or (any key) repeat: ";
			std::cin >> operation;

			if (operation == '0')
				break;
		}
	} while (!currentUser_);
}

void Chat::signUp()
{
	std::string login, password, name;

	std::cout << "login: ";
	std::cin >> login;
	std::cout << "password: ";
	std::cin >> password;
	std::cout << "name: ";
	std::cin >> name;

	if (getUserByLogin(login) || login == "all")
	{
		throw UserLoginExp();
	}

	if (getUserByName(name) || name == "all")
	{
		throw UserNameExp();
	}

	User user = User(login, password, name);
	users_.push_back(user);
	currentUser_ = std::make_shared<User>(user);
}

void Chat::showChat() const
{
	std::string from;
	std::string to;

	std::cout << "--- Chat ---" << std::endl;

	for (auto& mess : messages_)
	{
		if (currentUser_->getUserLogin() == mess.getFrom() || currentUser_->getUserLogin() == mess.getTo() || mess.getTo() == "all")
		{
			from = (currentUser_->getUserLogin() == mess.getFrom()) ? "me" : getUserByLogin(mess.getFrom())->getUserName();
		}

		if (mess.getTo() == "all")
		{
			to = "all";
		}
		else
		{
			to = (currentUser_->getUserLogin() == mess.getTo()) ? "me" : getUserByLogin(mess.getTo())->getUserName();
		}

		std::cout << std::endl;
		std::cout << "- Message from " << from << " to " << to << ": " << mess.getText() << std::endl;
	}

	std::cout << "__________________________________________________________________________________________" << std::endl;
}

void Chat::showLoginMenu()
{
	currentUser_ = nullptr;

	char operation;

	do
	{
		std::cout << std::endl;
		std::cout << "(1)-Login" << std::endl;
		std::cout << "(2)-Sign Up" << std::endl;
		std::cout << "(0)-Exit" << std::endl;
		std::cout << std::endl << ">> ";
		std::cin >> operation;

		switch (operation)
		{
		case '1':
			login();
			break;

		case '2':
			try
			{
				signUp();
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
			break;

		case '0':
			isChatWork_ = false;
			break;

		default:
			std::cout << " ??? " << std::endl;
			break;
		}
	} while (!currentUser_ && isChatWork_);
}

void Chat::showUserMenu()
{
	char operation;

	std::cout << std::endl;
	std::cout << "[(1) Show chat] [(2)Add message] [(3)Users] [(0) Logout]";
	std::cout << std::endl << ">> ";
	std::cin >> operation;

	switch (operation)
	{
	case '1':
		showChat();
		break;

	case '2':
		addMessage();
		break;

	case'3':
		showAllUsersName();
		break;

	case '0':
		currentUser_ = nullptr;
		break;

	default:
		std::cout << " ?a? " << std::endl;
		break;
	}
}

void Chat::showAllUsersName() const
{
	std::cout << "--- Users ---" << std::endl;

	for (auto& user : users_)
	{
		std::cout << user.getUserName();

		if (currentUser_->getUserLogin() == user.getUserLogin())
			std::cout << "(me)";
		std::cout << std::endl;
	}
	std::cout << "__________________________________________________________________________________________" << std::endl;
}

void Chat::addMessage()
{
	std::string to, text;
	
	std::cout << "To (name or all): ";
	std::cin >> to;
	std::cout << "Text: ";
	std::cin.ignore();

	getline(std::cin, text);

	if (!(to == "all" || getUserByName(to)))
	{
		std::cout << "Can't find user " << "(" << to << ")" << std::endl;
		return;
	}

	if (to == "all")
		messages_.push_back(Message{ currentUser_->getUserLogin(), "all", text });
	else
		messages_.push_back(Message{ currentUser_->getUserLogin(),getUserByName(to)->getUserLogin(),text });
}