#include <io.h>
#include <fcntl.h>
#include "authorization.hpp"
	


int main()
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);

	Start();









	return 0;
}
/*
	авторизация ввод логина пороля для каждого типа юзера свое меню
	аккаунт база данных пользователя + функции
	продажи товаров формирование чека оплата 
	склад сами товары редактирование склада
	служебные 
	без stl

*/