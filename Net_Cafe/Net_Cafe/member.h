#pragma once
#include<time.h>

typedef struct Member {
	char username[20];
	char password[20];
	char name[20];
	char phone[16];
	int nonmember;				// 비회원 
	int total_Hour;				// 총 이용시간
	int total_PC_Charge;		// 총 이용금액(PC사용)
	int total_Food_Charge;		// 총 이용금액(매점이용)


	int order_Food_List[10];
	time_t start_time;			// pc 사용시간
	time_t end_time;			// pc 종료시간
	int use_time;

} Member;

Member mem[100];
Member nonMem[100];

int index = 0;	 //회원 인덱스

typedef struct Food {

	char food_Name[20];
	int food_Price;
} Food;

Food f[10] = {
	{ "과자",2200 },
{ "라면",1000 },
{ "마우스패드",30000 },
{ "샌드위치" ,1500 },
{ "아이스크림",800 },
{ "커피",1000 },
{ "컵밥",5000 },
{ "콜라",1000 },
{ "핫도그",1500 },
{ "허브티",3500 },
};

