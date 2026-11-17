#ifndef _STOREG_HPP_
#define _STOREG_HPP_

#include "servicefun.hpp"

extern size_t sizeSt;
extern size_t* idArr;
extern std::wstring* nameArr;
extern size_t* countArr;
extern double* priceArr;

extern bool isStorageCreate;

void CreateStorage(int mode = 0);
void ShowStoreg(int mode = 0);


#endif // !_STOREG_HPP_