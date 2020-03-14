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
[������] outputMenu
[����] ���ϵͳ�˵�
[����] void
[����ֵ] void
*/
void outputMenu() {
	printf("----------�˵�-----------\n");
	printf("1.��ӿ�\n");
	printf("2.��ѯ��\n");
	printf("3.�ϻ�\n");
	printf("4.�»�\n");
	printf("5.��ֵ\n");
	printf("6.�˷�\n");
	printf("7.��ѯϵͳ\n");
	printf("8.ע����\n");
	printf("0.�˳�\n");
	
	//��ʾ�û�ѡ��˵����
	printf("��ѡ��˵����ţ�0~8����");
}

/*
[������] add
[����] ��ӿ�
[����] void
[����ֵ] void
*/
void add() {
	char aName[32] = { 0 };
	char aPwd[20] = { 0 };
	Card card;
	struct tm* endTime;
	struct tm* startTime;

	printf("-----------��ӿ�----------");
	
	/*��ʾ����������Ŀ���*/
	printf("�����뿨�ţ�����Ϊ1~18����");
	scanf("%s", aName);

	//�ж�����Ŀ����Ƿ����Ҫ��
	if (getSize(aName) >= 18) {
		printf("����Ŀ��Ź���! \n");
		return;
	}
	strcpy(card.aName, aName);

	//��ʾ����������
	printf("���������루����1~15��:");
	scanf("%s", aPwd);

	//�ж�����������Ƿ���ϱ�׼
	if (getSize(aPwd) > 15) {
		printf("��������볤�ȹ���! \n");
		return;
	}

	//����������뱣�������ṹ����
	strcpy(card.aPwd, aPwd);

	//��ʾ���뿪�����
	printf("�����뿪����RMB����");
	scanf("%f", &card.fBalance);

	//������Ϣ
	card.fTotalUse = card.fBalance;
	card.nDel = 0;
	card.nStatus = 0;
	card.nUseCount = 0;
	card.tStart = card.tEnd = card.tLast = time(NULL);
	
	/*���ݿ���ʱ�䣬�����ֹʱ�䣬ÿ�ſ���Ч��1��*/
	startTime = localtime(&card.tStart);
	endTime = localtime(&card.tEnd);
	endTime->tm_year = startTime->tm_year + 1;
	card.tEnd = mktime(endTime);

	//����service��ĺ��������ſ��ӽ�ȥ
	if (addCardInfo(card) == FALSE) {
		printf("��ӿ���Ϣʧ�ܣ�\n");
	}
	else {
		printf("��ӿ���Ϣ�ɹ���\n");
	}
}

/*************************************************
[������] getSize
[����]  ��ȡpInput��ָ����ַ������ַ�����
[����]  pInput:��Ҫ���ַ������ַ���
[����ֵ] int: �ַ������ַ��ĸ���
*************************************************/
int getSize(const char* pInput)
{
	int nSize = 0;

	// �����ַ������ַ�����
	while (*(pInput + nSize) != '\0')
	{
		nSize++;
	}

	// �����ַ�����
	return nSize;
}
/*
[������] query
[����] ��ѯ��
[����] void
[����ֵ] void
*/
void query() {
	char aName[18] = { 0 };
	Card* pCard = NULL;
	char aLastTime[TIMELENGTH] = { 0 };		//���һ���ϻ���ʱ�䣨�ַ����飩
	int* pIndex = NULL;
	int i = 0;
	
	printf("----------��ѯ��----------\n");

	//��ʾ����������Ŀ���Ϣ
	printf("�������ѯ�Ŀ��ţ�����1~18��:");
	scanf("%s", aName);

	//��ѯ��
	pCard = queryCardInfo(aName, pIndex);

	//���pCardΪNULL����ʶû�иÿ�����Ϣ
	if (pCard == NULL) {
		printf("û�иÿ�����Ϣ��\n");
	}
	else {
		//��ͷ
		printf("����\t\t״̬\t���\t�ۼ�ʹ��\tʹ�ô���\t�ϴ�ʹ��ʱ��\n");
		//ת��ʱ��
		timeToString(pCard->tLast, aLastTime);
		printf("%s\t\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\n",pCard->aName, pCard->nStatus, pCard->fBalance,
			pCard->fTotalUse, pCard->nUseCount, aLastTime);
	}
}

/*
[������] logon
[����] �ϻ�
[����] void
[����ֵ] void
*/
void logon() {

}

/*
[������] settle
[����] �»�
[����] void
[����ֵ] void
*/
void settle() {

}

/*
[������] addMoney
[����] ��ֵ
[����] void
[����ֵ] void
*/
void addMoney() {

}

/*
[������] refundMoney
[����] �˷�
[����] void
[����ֵ] void
*/
void refundMoney() {

}

/*
[������] annul
[����] ע����
[����] void
[����ֵ] void
*/
void annul() {

}

/*
[������] exitApp
[����] �˳�Ӧ�ó���
[����] void
[����ֵ] void
*/
void exitApp() {

}
