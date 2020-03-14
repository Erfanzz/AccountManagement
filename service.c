#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<string.h>

//#include "card_service.h"	//������ҵ���߼�����ͷ�ļ�
#include "model.h"			//�����������Ͷ���ͷ�ļ�
#include "global.h"			//����ȫ�ֶ���ͷ�ļ�

Card aCard[50];				//�洢����Ϣ������
int nCurNo = 0;				//�¿�����λ��(��ǰ���еĿ��ж�����)
int aIndex[50] = { -1 };		//�±꼯��
//int nResult=0;//�鵽�Ŀ���¼

/*
[������] addCardInfo
[����] ��ӿ���Ϣ
[����] card: ��ӵĿ���Ϣ�ṹ��
[����ֵ]	int�ͣ�TRUE��ʶ��ӳɹ���False��ʶ���ʧ��
*/
int addCardInfo(Card card) {
	int i;
	//�жϿ����Ƿ��Ѿ�����
	for (i = 0; i < nCurNo; i++) {
		if (strcmp(card.aName, aCard[i].aName) == 0) {
			return FALSE;
		}
	}
	//������Ϣ���浽������
	aCard[nCurNo] = card;
	nCurNo++;
	return TRUE;
}

/*
[������] queryCardInfo
[����]  ��ѯ����Ϣ
[����]  pName:��Ҫ��ѯ�Ŀ���
	   pIndex:��ѯ���Ŀ���Ϣ������ָ��
[����ֵ] Card*: ��ѯ���Ŀ���Ϣָ��
*/
Card* queryCardInfo(const char* pName, int* pIndex) {
	int i, j = 0;
	Card* pCard = NULL;
	pIndex = aIndex;	//����pIndexָ����aIndex����

	for (i = 0; i < nCurNo; i++) {
		//strstr()����pName���ֵĵ�һ��λ��
		if (strstr(aCard[i].aName, pName) != NULL) {
			pIndex[j] = i;	//pIndex���Կ�����aIndex
			j++;
			break;
		}
	}
	if (j != 0) {
		return &aCard[pIndex[j]];	//ȡ��ַ
	}
	else {
		return NULL;
	}
}
