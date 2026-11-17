#include "storeg.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;
bool isStorageCreate = false;

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

		// оствновились тут
	}
}
