#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#include "menu.h"

int main() {
	int nSelection = -1;
	printf("\n欢迎进入计费管理系统\n");
	printf("\n");

	do {
		//输出系统菜单
		outputMenu();
		
		//初始化选择的菜单项编号为-1
		nSelection = -1;

		//输入菜单项编号
		scanf("%d", &nSelection);

		//清除输入流缓存
		fflush(stdin);

		//输出选择的菜单编号
		switch (nSelection) {
			case 1: {	//添加卡
				add();
				break;
			}
			case 2: {	//查询卡
				query();
				break;
			}
			case 3: {	//上机
				logon();
				break;
			}
			case 4: {	//下机
				settle();
				break;
			}
			case 5: {	//充值
				addMoney();
				break;
			}
			case 6: {	//退费
				refundMoney();
				break;
			}
			case 7: {	//查询统计
				printf("查询统计\n");
				break;
			}
			case 8: {	//注销卡
				annul();
				break;
			}
			case 0: {	//退出
				exitApp();
				break;
			}
			default: {
				printf("输入的菜单编号有误！\n");
				break;
			}
		}
		printf("\n");
	} while (nSelection != 0);	//整个程序运行过程运用do-while循环，一旦输入0，则return 0结束main函数
	return 0;
}