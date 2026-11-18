#include "storeg.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;
bool isStorageCreate = false;

size_t maxStorageSize = 6700;
size_t currentStorageSize = 0;

double maxPrice = 250000;

void CreateStorage(int mode)
{
	if (mode == 0 && !isStorageCreate)
	{
		const size_t staticSize = 20;

		size_t idArrstatic[staticSize]{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
		std::wstring nameArrStatic[staticSize]
		{
			L"Сабля Пистолетова",L"Мясо для джедаев",L"Грязнульки силиконовые",
			L"Голландский штурвал",L"Бобровая струя",L"Трехствольное орудие викинга(змей горыныч)",
			L"Палка судьбы",L"Греховный огурец",L"Кнопка счастья",L"Турбонадув Любви",
			L"АнтиОдиночество 3000",L"Генератор мурашек",L"Батарейка страсти",
			L"Шалун домашний",L"Последний шанс жениться",L"Дедовский разгон",
			L"Губернатор чувств",L"Пылесос одиночества",L"Титаник в штанах",
			L"Бензапила купидона"
		};
		size_t coutArrStatic[staticSize]{ 15,10,14,11,14,16,15,15,14,10,10,10,10,10,10,16,15,13,12,12 };
		double priceArrStatic[staticSize]{ 7300,1499,23700,2500,1369,5700,4670,2300,6800,4600,12000,10500,5600,4300,6500,15600,8700,8500,6500,9800 };
		sizeSt = staticSize;
		idArr = new size_t[sizeSt];
		nameArr = new std::wstring[sizeSt];
		countArr = new size_t[sizeSt];
		priceArr = new double[sizeSt];

		FillArray(idArr, idArrstatic, sizeSt);
		FillArray(nameArr, nameArrStatic, sizeSt);
		FillArray(countArr, coutArrStatic, sizeSt);
		FillArray(priceArr, priceArrStatic, sizeSt);

		for (size_t i = 0; i < sizeSt; i++)
		{
			currentStorageSize += countArr[i];
		}

		isStorageCreate = true;
	}
	else if (mode == 1)
	{

	}
	else
	{
		std::wcout << L"Склад уже создан\n\n";
		Sleep(1500);
	}
}
void ShowStorage(int mode)
{
	if (mode == 0)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\tТовары \"Казанова\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t"
			<< L"Кол-во\t" << L"Цена\n\n";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::fixed << std::setw(40) << nameArr[i]
				<< L"\t" << countArr[i] << L"\t" << std::setprecision(2) << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		system("pause");
	}
	else if (mode == 1)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\tПополнение товаров \"Казанова\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t"
			<< L"Кол-во\t";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::fixed << std::setw(40) << nameArr[i]
				<< L"\t" << countArr[i] << L"\t" << L"\n\n";
		}
		std::wcout << L"\n\n";
		std::wcout << "Занято на складе " << currentStorageSize << L" из " <<
			maxStorageSize << L" мест\n\n";
	}
	else if (mode == 2)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\tСписание товаров \"Казанова\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t"
			<< L"Кол-во\t";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::fixed << std::setw(40) << nameArr[i]
				<< L"\t" << countArr[i] << L"\t" << L"\n\n";
		}
		std::wcout << L"\n\n";
		std::wcout << L"Занято на складе " << currentStorageSize << L" из " <<
			maxStorageSize << L" мест\n\n";
	}
	else if (mode == 3)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\tИзменение цен \"Казанова\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t"
			<< L"Цена\t";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::fixed << std::setw(40) << nameArr[i]
				<< L"\t" << std::setprecision(2) << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
	}
}

void AddProduct()
{
	std::wstring chooseId, chooseCount, choose;

	while (true)
	{
		ShowStorage(1);
		std::wcout << L"Ведите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции пополнения товара\n\n";
			Sleep(1500);
			return;
		}
		else if (IsNumber(chooseId))
		{
			int id = std::stoi(chooseId) - 1;
			if (id < 0 || id > sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите кол-во товара для пополнения: ";
				Getline(chooseCount);

				if (IsNumber(chooseCount))
				{
					size_t count = std::stoull(chooseCount);
					if (count < 0)
					{
						std::wcout << L"Некорректное кол-во! На складе осталось "
							<< maxStorageSize - currentStorageSize << L" свободных мест\n\n";
						Sleep(1700);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" ----->"
								<< countArr[id] + count << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							Getline(choose);
							if (choose == L"1")
							{
								std::wcout << L"Товар успешно пополнен\n\n";
								countArr[id] += count;
								currentStorageSize += count;
								Sleep(1500);
								break;
							}
							else if (choose == L"2")
							{
								std::wcout << L"Отмена пополнения " << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err();
							}
						}
					}
				}
			}
		}
	}
}

void RemoveProduct()
{
	std::wstring chooseId, chooseCount, choose;

	while (true)
	{
		ShowStorage(2);
		std::wcout << L"Ведите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции списания товара\n\n";
			Sleep(1500);
			return;
		}
		else if (IsNumber(chooseId))
		{
			int id = std::stoi(chooseId) - 1;
			if (id < 0 || id > sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите кол-во товара для списания: ";
				Getline(chooseCount);

				if (IsNumber(chooseCount))
				{
					size_t count = std::stoull(chooseCount);
					if (count < 0 || count > countArr[id])
					{
						std::wcout << L"Некорректное кол-во! На складе осталось "
							<< countArr[id] << L" Штук\n\n";
						Sleep(1700);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" ----->"
								<< countArr[id] - count << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							Getline(choose);
							if (choose == L"1")
							{
								std::wcout << L"Товар успешно списан\n\n";
								countArr[id] -= count;
								currentStorageSize -= count;
								Sleep(1500);
								break;
							}
							else if (choose == L"2")
							{
								std::wcout << L"Отмена списания " << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err();
							}
						}
					}
				}
			}
		}
	}
}

void ChangePrice()
{
	std::wstring chooseId, choosePrice, choose;

	while (true)
	{
		ShowStorage(3);
		std::wcout << L"Ведите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции изменения цены\n\n";
			Sleep(1500);
			return;
		}
		else if (IsNumber(chooseId))
		{
			int id = std::stoi(chooseId) - 1;
			if (id < 0 || id > sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите новую стоимость товара: ";
				Getline(choosePrice);

				if (IsNumber(choosePrice))
				{
					double count = std::stod(choosePrice);
					if (count < 0 || count > maxPrice) // Остановился тут
					{
						std::wcout << L"Некорректное кол-во! На складе осталось "
							<< countArr[id] << L" Штук\n\n";
						Sleep(1700);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" ----->"
								<< countArr[id] - count << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							Getline(choose);
							if (choose == L"1")
							{
								std::wcout << L"Товар успешно списан\n\n";
								countArr[id] -= count;
								currentStorageSize -= count;
								Sleep(1500);
								break;
							}
							else if (choose == L"2")
							{
								std::wcout << L"Отмена списания " << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err();
							}
						}
					}
				}
			}
		}
	}
}
