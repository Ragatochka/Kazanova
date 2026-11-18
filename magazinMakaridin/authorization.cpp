#include "authorization.hpp"

void Start()
{
	while (true)
	{
		if (Login())
		{
			if (currentStatus == L"GoodBoy")
			{
				CreateStorage();
				GoodBoyMenu();
			}
			else if (currentStatus == L"BadBoy")
			{
				//todo
			}
			else if (currentStatus == L"BadBunny")
			{
				//todo
			}
			else
			{
				std::wcerr << L"\n\nCURRENT_STATUS_LOGIN_ERROR";
			}
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
		std::wcout << L"\n\n\t\t\t   Казанова\n\n\n";
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
					Sleep(1500);
					currentStatus = statusArr[i];
					return true;
				}
			}
			std::wcout << L"Неверный логин или пароль. Повторите попытку\n\n";
			Sleep(1500);
		}
	}
}

void GoodBoyMenu()
{
	std::wstring choose;

	while (true)
	{
		system("cls");

		std::wcout << L"1 - Начать продажу\n";
		std::wcout << L"2 - Показать склад\n";
		std::wcout << L"3 - Пополнить товары\n";
		std::wcout << L"4 - Списать товары\n";
		std::wcout << L"5 - Изменить цены\n";
		std::wcout << L"6 - Редактировать склад\n";
		std::wcout << L"7 - Редактировать сотрудников\n";
		std::wcout << L"8 - Показать прибыль\n";
		std::wcout << L"0 - Выход\n\n";
		std::wcout << L"Ввод: ";
		Getline(choose);

		if (choose == L"1")
		{

		}
		else if (choose == L"2")
		{
			ShowStorage();
		}
		else if (choose == L"3")
		{
			AddProduct();
		}
		else if (choose == L"4")
		{
			RemoveProduct();
		}
		else if (choose == L"5")
		{

		}
		else if (choose == L"6")
		{

		}
		else if (choose == L"7")
		{

		}
		else if (choose == L"8")
		{

		}
		else if (choose == L"0")
		{

		}
		else
		{
			Err();
		}
	}
}
