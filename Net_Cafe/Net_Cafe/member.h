#pragma once
#include<time.h>

typedef struct Member {
	char username[20];
	char password[20];
	char name[20];
	char phone[16];
	int nonmember;				// ��ȸ�� 
	int total_Hour;				// �� �̿�ð�
	int total_PC_Charge;		// �� �̿�ݾ�(PC���)
	int total_Food_Charge;		// �� �̿�ݾ�(�����̿�)


	int order_Food_List[10];
	time_t start_time;			// pc ���ð�
	time_t end_time;			// pc ����ð�
	int use_time;

} Member;

Member mem[100];
Member nonMem[100];

int index = 0;	 //ȸ�� �ε���

typedef struct Food {

	char food_Name[20];
	int food_Price;
} Food;

Food f[10] = {
	{ "����",2200 },
{ "���",1000 },
{ "���콺�е�",30000 },
{ "������ġ" ,1500 },
{ "���̽�ũ��",800 },
{ "Ŀ��",1000 },
{ "�Ź�",5000 },
{ "�ݶ�",1000 },
{ "�ֵ���",1500 },
{ "���Ƽ",3500 },
};

