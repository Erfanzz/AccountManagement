#ifndef SERVICE_H
#define SERVICE_H

#include "model.h"

//����addCardInfo����
int addCardInfo(Card card);

//����queryCardInfo����
Card* queryCardInfo(const char* pName, int* pIndex);

#endif // !SERVICE_H
