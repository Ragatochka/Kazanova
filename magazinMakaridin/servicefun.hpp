#ifndef _SERVICEFUN_HPP_
#define _SERVICEFUN_HPP_

#include <iostream>
#include <string>
#include <Windows.h>
#include<iomanip>
void Getline(std::wstring& str);

__forceinline void Err()
{
	std::wcout << L"Некорректный ввод\n\n";
	Sleep(1500);
}

template <class ArrType>
void FillArray(ArrType* dynamicArr, ArrType* staticArr, size_t commonSize)
{
	for (size_t i = 0; i < commonSize; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}

#endif // !_SERVICEFUN_HPP_
