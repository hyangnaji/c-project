#pragma once

#include"config.h"
#include"member.h"
#include"interface.h"

time_t pcStart() {

	time_t start;

	gotoxy(5, 10);	printf("PC사용을 시작합니다.\n");

	swOn = 1;
	time_thread = (HANDLE)_beginthread(show_time, 0, NULL);

	Sleep(1000);
	return time(&start);
}

time_t pcStop() {

	time_t end;

	gotoxy(5, 10);	printf("PC사용을 종료합니다.\n");

	swOn = 0;
	CloseHandle(time_thread);

	Sleep(1000);
	return time(&end);
}

void charge(time_t start, time_t end, int check) {
	double dif;
	int pc_charge, food_charge = 0, pos = 10;
	dif = difftime(end, start);
	system("cls");

	if (check == 1) {
		gets(stdin);
		pc_charge = memberCharge;
		pc_charge += ((int)(dif) / 2)* memberCharge;


		gotoxy(5, 5);	printf("====================================");
		gotoxy(5, 6);	printf("사용시간 >> %4.0lf | PC요금 >> %5d원", dif, pc_charge);
		gotoxy(5, 8);	printf("구입물품\n");
		gotoxy(5, 9);	printf("------------------------------------");
		for (int i = 0; i < FOODNUM; i++) {
			if (mem[No].order_Food_List[i] > 0) {

				gotoxy(5, pos++);	printf("%14s - %2d개 - %6d원\n", f[i].food_Name, mem[No].order_Food_List[i], f[i].food_Price*mem[No].order_Food_List[i]);

				food_charge += (f[i].food_Price*mem[No].order_Food_List[i]);
			}
		}
		gotoxy(5, pos++);	printf("매점이용요금 >>              %5d원", food_charge);
		gotoxy(5, pos++);	printf("------------------------------------");

		gotoxy(5, pos++);	printf("총 이용요금  >>             %6d원\n", pc_charge + food_charge);
		gotoxy(5, pos++);	printf("====================================");

		mem[No].total_Hour += (int)dif;
		mem[No].total_PC_Charge += pc_charge;
		mem[No].total_Food_Charge += food_charge;
		mem[No].order_Food_List[0] = '\0';
		mem[No].start_time = 0;
		mem[No].end_time = 0;

		lp = fopen("PC.txt", "wt");
		for (int i = 0; i < index; i++) {

			fprintf(lp, "%s %s %s %s %d %d %d\n", mem[i].username, mem[i].password, mem[i].name, mem[i].phone, mem[i].total_Hour, mem[i].total_PC_Charge, mem[i].total_Food_Charge);

		}

		fclose(lp);
		getch();

	}
	else if (check == 0) {
		gets(stdin);
		pc_charge = nonMemCharge;
		pc_charge += ((int)(dif) / 2)* nonMemCharge;

		gotoxy(5, 5);	printf("====================================");
		gotoxy(5, 6);	printf("사용시간 >> %4.0lf | PC요금 >> %5d원", dif, pc_charge);
		gotoxy(5, 8);	printf("구입물품\n");
		gotoxy(5, 9);	printf("------------------------------------");
		for (int i = 0; i < FOODNUM; i++) {
			if (nonMem[No].order_Food_List[i] > 0) {

				gotoxy(5, pos++);	printf("%14s - %2d개 - %6d원\n",
					f[i].food_Name, nonMem[No].order_Food_List[i], f[i].food_Price*nonMem[No].order_Food_List[i]);
				food_charge += (f[i].food_Price*nonMem[No].order_Food_List[i]);
			}
		}
		gotoxy(5, pos++);	printf("매점이용요금 >> %5d원", food_charge);
		gotoxy(5, pos++);	printf("------------------------------------");

		gotoxy(5, pos++);	printf("총 이용요금 >> %6d원\n", pc_charge + food_charge);
		gotoxy(5, pos++);	printf("====================================");


		nonMem[No].total_Hour += (int)dif;
		nonMem[No].total_PC_Charge += pc_charge;
		nonMem[No].total_Food_Charge += food_charge;

		nonMem[No].start_time = 0;
		nonMem[No].end_time = 0;

		mem[0].total_PC_Charge += pc_charge;
		mem[0].total_Food_Charge += food_charge;

		getch();
	}


	gotoxy(5, pos++);	printf("계산이 완료되었습니다.");

	getch();
}

void checkmem() {
	system("cls");


	int num = 0;

	gotoxy(5, 5); printf("== 선택화면 ==\n");
	gotoxy(5, 6); printf("1. 회원\n");
	gotoxy(5, 7); printf("2. 비회원\n");
	gotoxy(5, 8); printf("선택 :: ");
	scanf("%d", &num);

	switch (num) {
	case 1:
		find_check_mem();
		break;
	case 2:
		find_check_nomem();
		//		charge(mem[0].start_time, mem[0].end_time, 0, 0);
		break;
	default:
		gotoxy(5, 9); printf("잘못된 입력입니다. 다시 입력해주세요.\n");
	}

}

void find_check_mem() {
	char find_username[20] = { 0 };
	char find_name[20] = { 0 };
	int select = 0, number = 0;

	int pos = 5;
	system("cls");

	gotoxy(5, pos++); printf("이름이 어떻게 되시죠? = ");
	scanf("%s", find_name);

	printf("\n");
	for (int i = 0; i < index; i++) {
		if (strcmp(find_name, mem[i].name) == 0) {	//회원 중 일치하는 이름이 있으면
			gotoxy(5, pos++); printf("%d. ID : %s, NAME : %s, PHONE : %s\n", ++number, mem[i].username, mem[i].name, mem[i].phone);
		}
	}
	if (number > 1) {
		gotoxy(5, pos++); printf("ID를 입력해주세요 = ");
		scanf("%s", find_username);
		for (int j = 0; j < index; j++) {
			if (strcmp(find_username, mem[j].username) == 0) {
				charge(mem[j].start_time, mem[j].end_time, 1);
				getch();
				return;
			}
		}
	}
	else {
		for (int j = 0; j < index; j++) {
			if (strcmp(find_name, mem[j].name) == 0) {
				charge(mem[j].start_time, mem[j].end_time, 1);
				getch();
				return;
			}
		}
	}


	gotoxy(5, pos++); printf("일치하는 회원이 없습니다.");
	getch();
}


void find_check_nomem() {

	int find_username = 0;
	system("cls");

	gotoxy(5, 5); printf("비회원 번호가 어떻게 되시죠? = ");
	scanf("%d", &find_username);

	for (int i = 0; i < sizeof(nonMem); i++) {
		if (nonMem[i].nonmember == find_username) {
			charge(nonMem[i].start_time, nonMem[i].end_time, 0);
			printf("\n");

			return;
		}
	}

	gotoxy(5, 6); printf("일치하는 회원이 없습니다.");

}


void show_time() {
	long i = 0;

	int min = 0, MIN = 0, hrs = 0, sec = 0;
	int d = 0, f = 0;

	int pos = 1;

	int charge = 0;

	while (swOn) {

		if (i % 60 == 0) {

			min = i / 60;
			d = 60 * min;

			if (min % 60 == 0) {
				hrs = min / 60;
				f = 60 * hrs;
			}
		}
		sec = i - d;
		MIN = min - f;

		if (hrs < 10) {
			gotoxy(17, pos); printf("0%d", hrs);
		}
		else {
			gotoxy(17, pos); printf(":%d", hrs);
		}
		if (min < 10) {
			gotoxy(19, pos); printf(":0%d", MIN);
		}
		else {
			gotoxy(19, pos); printf(":%2d", MIN);
		}

		if (sec < 10) {
			gotoxy(21, pos); printf(":0%d", sec);
		}
		else {
			gotoxy(21, pos); printf(":%2d", sec);
		}

		if (i % 2 == 0) {

			if (flag == 0) {
				charge += nonMemCharge;
			}
			else {
				charge += memberCharge;
			}

			gotoxy(19, pos + 1); printf("%5d", charge);
		}

		gotoxy(13, 10);	printf(" ");
		Sleep(1000);
		i++;
	}
	//_endthread();
}

void order_food(int flag) {
	gets(stdin);
	int order_No;
	gotoxy(5, 10); printf("주문 :: \t");
	gotoxy(13, 10); scanf("%d", &order_No);

	for (int i = 0; i < FOODNUM; i++) {
		if ((order_No - 1) == i) {
			if (flag == 1) {
				mem[No].order_Food_List[i]++;
				gotoxy(30, 16); printf("%s 이/가 주문이 완료되었습니다.\n\n", f[i].food_Name);

				getch();
			}
			else if (flag == 0) {

				nonMem[No].order_Food_List[i]++;
				gotoxy(30, 16); printf("%s 이/가 주문이 완료되었습니다.\n\n", f[i].food_Name);

				getch();
			}
		}

	}


	if (order_No < 0 || order_No>10) {
		gotoxy(30, 16); printf("그런 상품 없습니다.\n");
		getch();
		return order_food(flag);
	}

}