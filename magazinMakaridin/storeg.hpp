#ifndef _STOREG_HPP_
#define _STOREG_HPP_

#include "servicefun.hpp"

extern size_t sizeSt;
extern size_t* idArr;
extern std::wstring* nameArr;
extern size_t* countArr;
extern double* priceArr;

extern bool isStorageCreate;


extern size_t maxStorageSize;
extern size_t currentStorageSize;

extern double maxPrice;


void CreateStorage(int mode = 0);
void ShowStorage(int mode = 0);
void AddProduct();
void RemoveProduct();
void ChangePrice();

#endif // !_STOREG_HPP_