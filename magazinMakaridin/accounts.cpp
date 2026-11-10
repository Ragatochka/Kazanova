#include "accounts.hpp"

size_t userSize = 3;
size_t currentId = 0;
std::wstring currentStatus;

std::wstring* loginArr = new std::wstring[userSize]{ L"Billy Herrington",L"Bo Sin",L"Johnny Sins" };
std::wstring* passArr = new std::wstring[userSize]{ L"Billy Herrington",L"Bo Sin",L"Johnny Sins" };
std::wstring* statusArr = new std::wstring[userSize]{ L"GoodBoy",L"BadBoy",L"BadBunny" };
size_t* userIdArr = new size_t[userSize]{0, 1, 2 };
