#pragma once
#include "Message.h"

class User
{
	std::string _login;
	std::string _password;
	std::string _name;

public:
	User(const std::string& login, const std::string& password, const std::string& name) : _login(login), _password(password), _name(name) {}
	~User() = default;

	const std::string& getUserLogin() const { return _login; }
	const std::string& getUserPassword() const { return _password; }
	const std::string& getUserName() const { return _name; }

	void setUserLogin(const std::string& login) { _login = login; }
	void setUserPassword(const std::string& password) { _password = password; }
	void setUserName(const std::string& name) { _name = name; }
};
