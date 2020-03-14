#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

#include "menu.h"
#include "model.h"
#include "service.h"
#include "global.h"
#include "tool.h"


/*
[函数名] outputMenu
[功能] 输出系统菜单
[参数] void
[返回值] void
*/
void outputMenu() {
	printf("----------菜单-----------\n");
	printf("1.添加卡\n");
	printf("2.查询卡\n");
	printf("3.上机\n");
	printf("4.下机\n");
	printf("5.充值\n");
	printf("6.退费\n");
	printf("7.查询系统\n");
	printf("8.注销卡\n");
	printf("0.退出\n");
	
	//提示用户选择菜单编号
	printf("请选择菜单项编号（0~8）：");
}

/*
[函数名] add
[功能] 添加卡
[参数] void
[返回值] void
*/
void add() {
	char aName[32] = { 0 };
	char aPwd[20] = { 0 };
	Card card;
	struct tm* endTime;
	struct tm* startTime;

	printf("-----------添加卡----------");
	
	/*提示并接收输入的卡号*/
	printf("请输入卡号（长度为1~18）：");
	scanf("%s", aName);

	//判断输入的卡号是否符合要求
	if (getSize(aName) >= 18) {
		printf("输入的卡号过长! \n");
		return;
	}
	strcpy(card.aName, aName);

	//提示并接收密码
	printf("请输入密码（长度1~15）:");
	scanf("%s", aPwd);

	//判断输入的密码是否符合标准
	if (getSize(aPwd) > 15) {
		printf("输入的密码长度过长! \n");
		return;
	}

	//将输入的密码保存至卡结构体中
	strcpy(card.aPwd, aPwd);

	//提示输入开卡金额
	printf("请输入开卡金额（RMB）：");
	scanf("%f", &card.fBalance);

	//其余信息
	card.fTotalUse = card.fBalance;
	card.nDel = 0;
	card.nStatus = 0;
	card.nUseCount = 0;
	card.tStart = card.tEnd = card.tLast = time(NULL);
	
	/*根据开卡时间，计算截止时间，每张卡有效期1年*/
	startTime = localtime(&card.tStart);
	endTime = localtime(&card.tEnd);
	endTime->tm_year = startTime->tm_year + 1;
	card.tEnd = mktime(endTime);

	//调用service里的函数把这张卡加进去
	if (addCardInfo(card) == FALSE) {
		printf("添加卡信息失败！\n");
	}
	else {
		printf("添加卡信息成功！\n");
	}
}

/*************************************************
[函数名] getSize
[功能]  获取pInput所指向的字符串的字符数量
[参数]  pInput:需要求字符数的字符串
[返回值] int: 字符串中字符的个数
*************************************************/
int getSize(const char* pInput)
{
	int nSize = 0;

	// 计算字符串的字符个数
	while (*(pInput + nSize) != '\0')
	{
		nSize++;
	}

	// 返回字符个数
	return nSize;
}
/*
[函数名] query
[功能] 查询卡
[参数] void
[返回值] void
*/
void query() {
	char aName[18] = { 0 };
	Card* pCard = NULL;
	char aLastTime[TIMELENGTH] = { 0 };		//最近一次上机的时间（字符数组）
	int* pIndex = NULL;
	int i = 0;
	
	printf("----------查询卡----------\n");

	//提示并接收输入的卡信息
	printf("请输入查询的卡号（长度1~18）:");
	scanf("%s", aName);

	//查询卡
	pCard = queryCardInfo(aName, pIndex);

	//如果pCard为NULL，标识没有该卡的信息
	if (pCard == NULL) {
		printf("没有该卡的信息！\n");
	}
	else {
		//表头
		printf("卡号\t\t状态\t余额\t累计使用\t使用次数\t上次使用时间\n");
		//转换时间
		timeToString(pCard->tLast, aLastTime);
		printf("%s\t\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\n",pCard->aName, pCard->nStatus, pCard->fBalance,
			pCard->fTotalUse, pCard->nUseCount, aLastTime);
	}
}

/*
[函数名] logon
[功能] 上机
[参数] void
[返回值] void
*/
void logon() {

}

/*
[函数名] settle
[功能] 下机
[参数] void
[返回值] void
*/
void settle() {

}

/*
[函数名] addMoney
[功能] 充值
[参数] void
[返回值] void
*/
void addMoney() {

}

/*
[函数名] refundMoney
[功能] 退费
[参数] void
[返回值] void
*/
void refundMoney() {

}

/*
[函数名] annul
[功能] 注销卡
[参数] void
[返回值] void
*/
void annul() {

}

/*
[函数名] exitApp
[功能] 退出应用程序
[参数] void
[返回值] void
*/
void exitApp() {

}
