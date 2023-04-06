#pragma once
#include <string>

class Message
{
	const std::string _from;
	const std::string _to;
	const std::string _text;

public:
	Message(const std::string& from, const std::string& to, const std::string& text) : _from(from), _to(to), _text(text) {}
	~Message() = default;

	const std::string& getFrom() const { return _from; }
	const std::string& getTo() const { return _to; }
	const std::string& getText() const { return _text; }
};
