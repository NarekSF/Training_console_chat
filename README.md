Проект тренировочного консольного чата

Группа 1007

Максим Данченко, Нарек Мадатян, Анастасия Силаева

Консольный чат:

В программе раелизован необходимый функционал чата.
Вы можете регистрироваться и входить в аккаунт с помощью логина и пароля, отправлять сообщения как всем, так и определенному человеку. Также вы сможете выйти выбрав соответствующую функцию в меню.

Основной функционал чата реализован в классе Chat: Класс содержит вектора _users - пользователи и _messages - сообщения 
shared_ptr getUserByLogin(const std::string& login) // проверка массива пользователей на совпадение логина 
shared_ptr getUserByName(const std::string& name) // проверка массива пользователей на совпадение имени

Максим Данченко: классы User, Message, Сhat, отвечал за регистрацию пользователей и за вход в чат Нарек Мадатян: класс Chat, обмен сообщениями между пользователями Анастасия Силаева: Main.cpp, дополнительный функционал
