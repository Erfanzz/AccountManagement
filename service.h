#ifndef SERVICE_H
#define SERVICE_H

#include "model.h"

//声明addCardInfo函数
int addCardInfo(Card card);

//声明queryCardInfo函数
Card* queryCardInfo(const char* pName, int* pIndex);

#endif // !SERVICE_H
