#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<string.h>

//#include "card_service.h"	//包含卡业务逻辑处理头文件
#include "model.h"			//包含数据类型定义头文件
#include "global.h"			//包含全局定义头文件

Card aCard[50];				//存储卡信息的数组
int nCurNo = 0;				//新卡插入位置(当前已有的卡有多少张)
int aIndex[50] = { -1 };		//下标集合
//int nResult=0;//查到的卡记录

/*
[函数名] addCardInfo
[功能] 添加卡信息
[参数] card: 添加的卡信息结构体
[返回值]	int型，TRUE标识添加成功，False标识添加失败
*/
int addCardInfo(Card card) {
	int i;
	//判断卡号是否已经存在
	for (i = 0; i < nCurNo; i++) {
		if (strcmp(card.aName, aCard[i].aName) == 0) {
			return FALSE;
		}
	}
	//将卡信息保存到数组中
	aCard[nCurNo] = card;
	nCurNo++;
	return TRUE;
}

/*
[函数名] queryCardInfo
[功能]  查询卡信息
[参数]  pName:需要查询的卡号
	   pIndex:查询到的卡信息数量的指针
[返回值] Card*: 查询到的卡信息指针
*/
Card* queryCardInfo(const char* pName, int* pIndex) {
	int i, j = 0;
	Card* pCard = NULL;
	pIndex = aIndex;	//这里pIndex指向了aIndex数组

	for (i = 0; i < nCurNo; i++) {
		//strstr()返回pName出现的第一个位置
		if (strstr(aCard[i].aName, pName) != NULL) {
			pIndex[j] = i;	//pIndex可以看成事aIndex
			j++;
			break;
		}
	}
	if (j != 0) {
		return &aCard[pIndex[j]];	//取地址
	}
	else {
		return NULL;
	}
}
