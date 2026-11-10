#include "authorization.hpp"

void Start()
{
	while (true)
	{
		if (Login())
		{
			system("pause");
		}
		else
		{

		}
	}
}

bool Login()
{
	std::wstring login, pass;
	while (true)
	{
		system("cls");
		std::wcout << L"\n\n\n\t\t\tДобро пожаловать!";
		std::wcout << L"\n\n\t\t\t   Казанова 69\n";
		std::wcout << L"Ведите логин или \"exit\" для входа: ";
		Getline(login);
		if (login == L"exit" || login == L"Exit")
		{
			return false;
		}
		else
		{
			std::wcout << L"Введите пароль; ";
			Getline(pass);
			for (size_t i = 0; i < userSize; i++)
			{
				if (login == loginArr[i] && pass == passArr[i])
				{
					std::wcout << L"Добро пожаловать " << loginArr[i] << L"\n";
					std::wcout << L"Ваш уровень доступа: " << statusArr[i] << L"\n";
					currentId = userIdArr[i];
					currentStatus = statusArr[i];
					return true;
				}
			}
			std::wcout << L"Неверный логин или пароль. Повторите попытку\n\n";
			Sleep(1500);
		}
	}
}
