#pragma once

#include"config.h"
#include"member.h"

int flag = 0;	//0 : 손님, 1 : 회원, 2 : 관리자

void main_menu() {      //메인 메뉴
	int login = 0;

	system("cls");

	gotoxy(5, 1); printf("---<< 환영합니다. >>---");
	gotoxy(5, 3); printf("어서오세요. PC방입니다.");
	gotoxy(5, 4); printf("=== 로그인 해주세요 ===");
	gotoxy(5, 5); printf("0. 회원 가입");
	gotoxy(5, 6); printf("1. 회원 로그인");
	gotoxy(5, 7); printf("2. 비회원 로그인");
	gotoxy(5, 8); printf("3. ID/PW 찾기");
	gotoxy(5, 9); printf("4. 계산하기");
	gotoxy(5, 10); printf("======================");
	gotoxy(5, 11); printf("선택 :: ");
	scanf("%d", &login);

	switch (login) {
	case 0:
		join_menu();
		break;
	case 1:
		login_menu();
		break;
	case 2:
		non_member_login();
		break;
	case 3:
		Search_Member();
		break;
	case 4:
		checkmem();
		break;
	case 4868:
		admin_menu();
		break;
	case 9999:
		gotoxy(5, 12); printf("종료합니다.\n");
		return pause = 0;
	default:
		gotoxy(5, 12); printf("잘못입력하셨습니다.\n");
	}
}

void login_menu() {

	system("cls");

	char username[20] = { 0 }, Username[20] = { 0 };
	char password[20] = { 0 }, Password[20] = { 0 };


	gotoxy(5, 5); printf("==< 회원 로그인 >== \n");
	gotoxy(5, 6); printf("username(ID) = ");
	scanf("%s", username);
	gotoxy(5, 7); printf("password(PW) = ");
	scanf("%s", password);


	for (int i = 0; i < index; i++) {
		strcpy(Username, mem[i].username);
		strcpy(Password, mem[i].password);
		if (strcmp(Username, username) == 0 && strcmp(Password, password) == 0) {
			No = i;
			return member_menu();
		}
	}
	for (int i = 0; i < index; i++) {
		strcpy(Username, mem[i].username);
		strcpy(Password, mem[i].password);
		if (strcmp(Username, username) != 0 && strcmp(Password, password) == 0) {
			gotoxy(5, 8);   printf("ID를 확인해주십시오.\n");
			getch();

			return main_menu();
		}
	}
	for (int i = 0; i < index; i++) {
		strcpy(Username, mem[i].username);
		strcpy(Password, mem[i].password);
		if (strcmp(Username, username) == 0 && strcmp(Password, password) != 0) {
			gotoxy(5, 8);   printf("PW를 확인해주십시오.\n");
			getch();

			return main_menu();
		}
	}
	gotoxy(5, 8);   printf("ID와 PW를 확인해주십시오.\n");

	getch();

}


void member_menu() {   //회원 메뉴
	flag = 1;
	int select;

	system("cls");

	if (swOn == 0) {
		gotoxy(5, 1); printf("--<< 환영합니다. >>--");
	}
	else {
		show_use();
	}

	gotoxy(5, 5);	printf("===== 회원 메뉴 =====\n");
	gotoxy(5, 6);	printf("1. 컴퓨터 사용시작\n");
	gotoxy(5, 7);	printf("2. 컴퓨터 사용종료\n");
	gotoxy(5, 8);	printf("3. 음식 주문\n");
	gotoxy(5, 9);	printf("=====================\n");
	gotoxy(5, 10);	printf("선  택 :: ");
	gotoxy(15, 10);   scanf("%d", &select);

	switch (select) {
	case 1:
		if (swOn == 0) {
			mem[No].start_time = pcStart();				// 사용시작
		}
		else {
			gotoxy(5, 11);	printf("이미 PC를 사용중입니다.");
			getch();

		}

		member_menu();
		break;
	case 2:
		if (swOn == 1) {
			mem[No].end_time = pcStop();					// 사용종료
		}
		else {
			gotoxy(5, 11);	printf("PC를 사용중이 아닙니다.");
			getch();
			member_menu();
		}

		return;
	case 3:
		if (swOn == 1) {
			food_list();
			order_food(flag);
			member_menu();
		}
		else {
			gotoxy(5, 11);	printf("PC를 사용중이 아닙니다.");
			member_menu();
		}

		break;
	default:
		gotoxy(5, 11); printf("선택이 올바르지 않습니다.\n");
		getch();
	}
}

void Search_Member() {
	int num = 0;

	system("cls");

	gotoxy(5, 4);	printf("== ID/PW찾기 ==\n");
	gotoxy(5, 5);	printf("1. ID찾기\n");
	gotoxy(5, 6);	printf("2. PW찾기\n");
	gotoxy(5, 7);	printf("===============\n");
	gotoxy(5, 8);	printf("선택 :: ");
	scanf("%d", &num);

	switch (num) {
	case 1:
		Search_Member_ID();
		break;
	case 2:
		Search_Member_PW();
		break;
	default:
		gotoxy(5, 10);	printf("메뉴를 다시 입력해주세요.");
	}
}

void Search_Member_ID() {


	char phone[16] = { 0 };

	system("cls");

	gotoxy(5, 3); printf("====< ID찾기 >====\n");
	gotoxy(5, 5); printf("아래 내용을 입력해주세요.");
	gotoxy(5, 6); printf("전화번호 = ");
	scanf("%s", phone);


	for (int i = 0; i < 15; i++) {
		Sleep(100);
		printf("=");
	}


	for (int i = 0; i < index; i++) {
		if (strcmp(phone, phone) == 0 && strcmp(phone, mem[i].phone) == 0) {
			gotoxy(5, 8); printf("\nID는 %s입니다.\n", mem[i].username);
			//gets(stdin);
			getch();
			return;
		}
	}


	gotoxy(5, 8); printf("\n찾으시는 ID가 없습니다.\n");
	gets(stdin);
	getch();

}



void Search_Member_PW() {
	char phone[16] = { 0 };
	char username[20] = { 0 };

	system("cls");

	gotoxy(5, 3); printf("====< PW찾기 >====\n");
	gotoxy(5, 5); printf("아래 내용을 입력해주세요.");
	gotoxy(5, 6); printf("ID = ");
	scanf("%s", username);
	gotoxy(5, 7); printf("전화번호 = ");
	scanf("%s", phone);


	for (int i = 0; i < 15; i++) {
		Sleep(100);
		printf("=");
	}

	for (int i = 0; i < index; i++) {
		if (strcmp(username, mem[i].username) == 0 && strcmp(phone, mem[i].phone) == 0) {
			gets(stdin);
			gotoxy(5, 8); printf("PW는 %s입니다.\n", mem[i].password);
			getch();
			return;
		}
	}
	for (int i = 0; i < index; i++) {
		if (strcmp(username, mem[i].username) == 0 && strcmp(phone, mem[i].phone) != 0) {
			gets(stdin);
			gotoxy(5, 8); printf("전화번호가 잘못되었습니다.\n");
			getch();
			return;
		}
	}
	for (int i = 0; i < index; i++) {
		if (strcmp(username, mem[i].username) != 0 && strcmp(phone, mem[i].phone) == 0) {
			gets(stdin);
			gotoxy(5, 8); printf("ID가 잘못되었습니다.\n");
			getch();
			return;
		}
	}
	for (int i = 0; i < index; i++) {
		if (strcmp(username, mem[i].username) != 0 && strcmp(phone, mem[i].phone) != 0) {
			gets(stdin);
			gotoxy(5, 8); printf("일치하는 정보가 없습니다.\n");
			getch();
			return;
		}
	}
}

void non_member_login() {
	int num = 0;
	system("cls");

	gotoxy(5, 4);	printf("==< 비회원 로그인 >==\n");
	gotoxy(5, 5);	printf("번호입력 = ");
	scanf("%d", &num);

	nonMem[num].nonmember = num;
	nonMem[num].total_PC_Charge = 0;
	nonMem[num].total_Hour = 0;
	nonMem[num].total_Food_Charge = 0;

	gotoxy(5, 7);	printf("%d로 로그인 되었습니다.", num);

	getch();
	nonmember_menu(num);
}


void nonmember_menu() {      //비회원 메뉴
	flag = 0;

	int select;

	system("cls");

	if (swOn == 0) {
		gotoxy(5, 1); printf("--<< 환영합니다. >>--");
	}
	else {
		show_use();
	}

	gotoxy(5, 5);	printf("==== 비회원 메뉴 ====\n");
	gotoxy(5, 6);	printf("1. 컴퓨터 사용 시작\n");
	gotoxy(5, 7);	printf("2. 컴퓨터 사용 종료\n");
	gotoxy(5, 8);	printf("3. 음식 주문\n");
	gotoxy(5, 9);	printf("======================\n");
	gotoxy(5, 10);	printf("선  택 :: ");
	scanf("%d", &select);

	switch (select) {
	case 1:
		if (swOn == 0) {
			nonMem[No].start_time = pcStart();				// 사용시작

		}
		else {
			gotoxy(5, 11);	printf("이미 PC를 사용중입니다.");
			getch();

		}

		nonmember_menu(nonMem);
		break;
	case 2:
		if (swOn == 1) {
			nonMem[No].end_time = pcStop();				// 사용종료		
		}
		else {
			gotoxy(5, 11);	printf("PC를 사용중이 아닙니다.");
			getch();

			nonmember_menu(nonMem);
		}

		break;
	case 3:
		if (swOn == 1) {
			food_list();
			order_food(flag);
			nonmember_menu();
		}
		else {
			gotoxy(5, 11);	printf("PC를 사용중이 아닙니다.");
			getch();

			nonmember_menu();
		}

		break;
	default:
		gotoxy(5, 11); printf("선택이 올바르지 않습니다.\n");
		getch();
	}
}

void admin_menu() {      //관리자 메뉴

	int admin = 0;
	int memNo = 0;

	system("cls");

	gotoxy(5, 4);	printf("==< 관리자 메뉴 >==\n");
	gotoxy(5, 5);	printf("1. 매점금액변경\n");
	gotoxy(5, 6);	printf("2. 전체회원목록\n");
	gotoxy(5, 7);	printf("3. 정산\n");
	gotoxy(5, 8);	printf("4. 회원수정/탈퇴\n");
	gotoxy(5, 9);	printf("===================\n");
	gotoxy(5, 10);	printf("선택 :: ");
	scanf("%d", &admin);

	switch (admin) {
	case 1:
		change_food();
		break;
	case 2:
		showAllMember();
		break;
	case 3:
		total_Sales();
		break;
	case 4:
		update_n_delete_menu();
		break;
	default:
		gotoxy(5, 10); printf("선택이 올바르지 않습니다.\n");
		getch();
		return;
	}
}

void join_menu() {	// 회원가입
	char username[20] = { 0 };
	char password[50] = { 0 };
	char name[20] = { 0 };
	char phone[16] = { 0 };
	int total_Hour = 0;
	int total_PC_Charge = 0;
	int total_Food_Charge = 0;

	int pos = 5;

	int check;
	system("cls");

	gotoxy(5, pos++);	printf("====[ 회원 가입 ]====\n");

	do {
		check = 0;
		gotoxy(5, pos); printf("username(ID) = ");
		gotoxy(21, pos++); scanf("%s", username);

		for (int i = 0; i < index; i++) {
			if (strcmp(mem[i].username, username) == 0) {
				gotoxy(5, pos++); printf("이미 존재하는 회원입니다.\n");
				check = 1;
			}
		}

		if (strlen(username) > 20) {
			gotoxy(5, pos++); printf("ID가 형식에 맞지 않습니다.\n");
			check = 1;
		}

	} while (check != 0);
	fflush(stdin);
	do {
		check = 0;

		gotoxy(5, pos); printf("password(PW) = ");
		gotoxy(21, pos++); scanf("%s", password);

		if (strlen(password) > 20) {
			gotoxy(5, pos++); printf("비밀번호가 형식에 맞지 않습니다.\n");
			check = 1;
		}

	} while (check != 0);
	fflush(stdin);
	gotoxy(5, pos); printf("이름 = ");
	gotoxy(13, pos++); scanf("%s", name);
	fflush(stdin);
	do {
		check = 0;

		gotoxy(5, pos); printf("전화번호(010-1234-1234) = ");
		gotoxy(32, pos++); scanf("%s", phone);

		if (strlen(phone) == 13) {
			for (int i = 0; i < index; i++) {
				if (strcmp(mem[i].phone, phone) == 0) {
					gotoxy(5, pos++); printf("이미 존재하는 회원입니다.\n");
					check = 1;
				}
			}
		}
		else {
			gotoxy(5, pos++); printf("전화번호가 형식에 맞지 않습니다.\n");
			check = 1;
		}

	} while (check != 0);
	fflush(stdin);

	strcpy(mem[index].username, username);
	strcpy(mem[index].password, password);
	strcpy(mem[index].name, name);
	strcpy(mem[index].phone, phone);
	mem[index].total_PC_Charge = 0;
	mem[index].total_Hour = 0;
	mem[index].total_Food_Charge = 0;

	lp = fopen("PC.txt", "a+");

	fprintf(lp, "%s %s %s %s %d %d %d\n", mem[index].username, mem[index].password, mem[index].name, 
		mem[index].phone, mem[index].total_Hour, mem[index].total_PC_Charge, mem[index].total_Food_Charge);

	index++;

	gotoxy(5, pos++); printf("회원가입이 완료되었습니다.\n");

	fclose(lp);

	getch();

}

void change_food() {	// 매점 가격변경

	int foodNo, changePrice;
	system("cls");

	gotoxy(5, 4);	printf("상품 가격을 변경합니다.");

	food_list();

	gotoxy(5, 5);	printf("상품번호 = ");
	scanf("%d", &foodNo);

	for (int i = 0; i < FOODNUM; i++) {
		if (foodNo - 1 == i) {

			gotoxy(5, 5);	printf("변경가격(%d원) = ", f[i].food_Price);
			scanf("%d", &changePrice);

			f[i].food_Price = changePrice;

			gotoxy(5, 7);  printf("가격 변경 완료.");
			return admin_menu();

		}

	}

	printf("상품번호가 없습니다.\n");

	getch();

}


void food_list() {	// 매점메뉴보기

	gotoxy(30, 2); printf("----------<메뉴>----------");

	for (int i = 0; i < FOODNUM; i++) {
		gotoxy(30, i + 4); printf("%2d번 %11s - %5d원\n", i + 1, f[i].food_Name, f[i].food_Price);
	}

	gotoxy(30, 14); printf("--------------------------");
}

void showAllMember() {	// 전체회원보기
	char tmp[4] = { 0 };

	system("cls");
	printf("==========[ 회 원 목 록 ]=========\n");

	for (int i = 1; i < index; i++) {
		strncpy(tmp, mem[i].password, 3);
		tmp[3] = '\0';
		printf("| ID\t\t : %13s |\n| PW\t\t : \t  %s*** |\n| NAME\t\t : %13s |\n| PHONE\t\t : %13s |\n| 누적사용시간\t : %13d |\n| 누적사용요금\t : %13d |\n",
			mem[i].username, tmp, mem[i].name,
			mem[i].phone, mem[i].total_Hour, mem[i].total_PC_Charge + mem[i].total_Food_Charge);
		printf(" --------------------------------\n");

	}
	printf("==================================\n");
	getch();

}

void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x; Pos.Y = y; // X, Y좌표
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


void input_data() {	// 파일 입출력
	char username[20] = { 0 };
	char password[20] = { 0 };
	char name[20] = { 0 };
	char phone[20] = { 0 };
	int total_Hour = 0;
	int total_PC_Charge = 0;
	int total_Food_Charge = 0;

	lp = fopen("PC.txt", "rt");
	if (NULL != lp) {
		while (EOF != fscanf(lp, "%s %s %s %s %d %d %d", username, password, name, phone, &total_Hour, 
			&total_PC_Charge, &total_Food_Charge)) {

			strcpy(mem[index].username, username);
			strcpy(mem[index].password, password);
			strcpy(mem[index].name, name);
			strcpy(mem[index].phone, phone);
			mem[index].total_Hour = total_Hour;
			mem[index].total_PC_Charge = total_PC_Charge;
			mem[index].total_Food_Charge = total_Food_Charge;

			index++;
		}
	}
	else printf("파일이 없습니다.\n");

	fclose(lp);
}

void show_use() {	// 이용시간, 요금 표시
	gotoxy(5, 1); printf("사용시간 :: ");
	gotoxy(5, 2); printf("이용요금 :: ");
}

void total_Sales() {	// 총 매출 표시
	int total_PC = 0, total_food = 0;
	int pos = 5;
	system("cls");

	for (int i = 1; i < index; i++) {

		total_PC += mem[i].total_PC_Charge;
		total_food += mem[i].total_Food_Charge;

	}

	gotoxy(5, pos++);	printf(" ==========[ 매 출 정 산 ]==========");
	gotoxy(5, pos++);	printf(" ===================================");
	gotoxy(5, pos++);	printf("| 회원 누적 PC요금    >> %8d원 |", total_PC);
	gotoxy(5, pos++);	printf("| 비회원 누적 PC요금  >> %8d원 |", mem[0].total_PC_Charge);
	gotoxy(5, pos++);	printf(" -----------------------------------");
	gotoxy(5, pos++);	printf("| 회원 누적매점매출   >> %8d원 |", total_food);
	gotoxy(5, pos++);	printf("| 비회원 누적매점매출 >> %8d원 |", mem[0].total_Food_Charge);
	gotoxy(5, pos++);	printf(" -----------------------------------");

	gotoxy(5, pos++);	printf("| 총 매출             >> %8d원 |", total_PC + total_food + mem[0].total_Food_Charge + mem[0].total_PC_Charge);
	gotoxy(5, pos++);	printf(" ===================================");

	show_VIP(pos);
}

void show_VIP(int pos) {	// PC이용, 매점이용 가장많이한 회원 출력

	int maxFood = mem[1].total_Food_Charge;
	int maxPC = mem[1].total_PC_Charge;
	int maxFood_num = 1, maxPC_num = 1;

	for (int i = 1; i < index; i++) {
		if (maxFood < mem[i].total_Food_Charge) {
			maxFood_num = i;
		}
		if (maxPC < mem[i].total_PC_Charge) {
			maxPC_num = i;
		}
	}

	pos++;

	gotoxy(5, pos++); printf(" ---------< 매점이용  VIP >---------");
	gotoxy(5, pos++); printf("| %10s |      %13d원 |", mem[maxFood_num].username, mem[maxFood_num].total_Food_Charge);
	gotoxy(5, pos++); printf(" ---------<  PC이용  VIP  >---------");
	gotoxy(5, pos++); printf("| %10s |   %4d초 |  %6d원 |", mem[maxPC_num].username, mem[maxPC_num].total_Hour, mem[maxPC_num].total_PC_Charge);
	gotoxy(5, pos++); printf(" ===================================");
	getch();

}

void update_n_delete_menu() {
	int select = 0;
	system("cls");
	gotoxy(5, 3); printf("====< 수정 및 탈퇴 메뉴 >====");
	gotoxy(5, 5); printf("1. 회원 수정");
	gotoxy(5, 6); printf("2. 회원 탈퇴");
	gotoxy(5, 7); printf("=============================");
	gotoxy(5, 8); printf("선택 :: ");
	scanf("%d", &select);

	switch (select) {
	case 1:
		update_data();
		break;
	case 2:
		delete_data();
		break;
	default:
		printf("메뉴선택이 잘못되었습니다.\n");
		return;
	}
}


void update_data() {	// 수정
	char phone[20] = { 0 };
	char name[20] = { 0 };
	int check = 0;

	system("cls");
	do {
		gotoxy(5, 3); printf("====< 수정할 회원 찾기 >====\n");
		gotoxy(5, 5); printf("아래 내용을 입력해주세요.");
		gotoxy(5, 6); printf("전화번호 = ");
		scanf("%s", phone);

		if (strlen(phone) != 13) {
			gotoxy(5, 8); printf("전화번호가 형식에 맞지 않습니다.\n");
			check = 1;
		}

		gotoxy(5, 7); printf("이름 = ");
		scanf("%s", name);

	} while (check != 0);

	gotoxy(5, 9);
	for (int i = 0; i < 30; i++) {
		Sleep(50);
		printf("=");
	}

	system("cls");

	for (int i = 0; i < index; i++) {
		if (strcmp(phone, mem[i].phone) == 0 && strcmp(name, mem[i].name) == 0) {
			int check = 0;
			char default_return[20] = "0";

			char username[20] = { 0 };
			char password[20] = { 0 };
			char name[20] = { 0 };
			char phone[20] = { 0 };

			gotoxy(5, 3); printf("이전 값을 넣으시려면 0을 입력하세요.\n");

			do {
				check = 0;
				gotoxy(5, 4); printf("이전 아이디 :: %s == 수정할 아이디 :: ", mem[i].username);
				scanf("%s", username);

				if (strcmp(username, default_return) == 0) {
					strcpy(username, mem[i].username);
				}
				for (int j = 0; j < index; j++) {
					if (strcmp(username, mem[j].username) == 0) {
						if (strcmp(username, mem[i].username) == 0) {
							continue;
						}
						check = 1;						
						gotoxy(5, 4); printf("이미 등록된 아이디가 있습니다. 다시 입력해주세요.\n");
						username[0] = '/0';
					}
				}
								
			} while (check != 0);

			gotoxy(5, 5); printf("이전 비밀번호 :: %s == 수정할 패스워드 :: ", mem[i].password);
			scanf("%s", password);
			if (strcmp(password, default_return) == 0) {
				strcpy(password, mem[i].password);
			}

			gotoxy(5, 6); printf("이전 이름 :: %s == 수정할 이름 :: ", mem[i].name);
			scanf("%s", name);
			if (strcmp(name, default_return) == 0) {
				strcpy(name, mem[i].name);
			}

			do {
				check = 0;
				gotoxy(5, 7); printf("이전 전화번호 :: %s == 수정할 전화번호 :: ", mem[i].phone);
				scanf("%s", phone);
				if (strcmp(phone, default_return) == 0) {
					strcpy(phone, mem[i].phone);
				}
				for (int j = 0; j < index; j++) {
					if (strcmp(phone, mem[j].phone) == 0) {
						if (strcmp(phone, mem[i].phone) == 0) {
							continue;
						}
						check = 1;
						gotoxy(5, 7); printf("이미 등록된 전화번호가 있습니다. 다시 입력해주세요.\n");
						phone[0] = '/0';
					}
				}
				if (strcmp(phone, mem[i].phone) == 0) {
					check = 0;
				}
				
			} while (check != 0);

			strcpy(mem[i].username, username);
			strcpy(mem[i].password, password);
			strcpy(mem[i].name, name);
			strcpy(mem[i].phone, phone);

			gotoxy(5, 9); printf("수정이 완료되었습니다.\n");

			//gets(stdin);
			getch();

			lp = fopen("PC.txt", "wt");
			for (int i = 0; i < index; i++) {

				fprintf(lp, "%s %s %s %s %d %d %d\n", mem[i].username, mem[i].password, mem[i].name, mem[i].phone, mem[i].total_Hour, mem[i].total_PC_Charge, mem[i].total_Food_Charge);

			}

			fclose(lp);


			return;
			
		}
	}

	gotoxy(5, 8); printf("\n해당 전화번호는 등록되어있지 않습니다.\n");
	gets(stdin);
	getch();

}

void delete_data() {
	char phone[20] = { 0 };
	char name[20] = { 0 };
	int check = 0;

	system("cls");
	do {
		gotoxy(5, 3); printf("====< 탈퇴할 회원 찾기 >====\n");
		gotoxy(5, 5); printf("아래 내용을 입력해주세요.");
		gotoxy(5, 6); printf("전화번호 = ");
		scanf("%s", phone);

		if (strlen(phone) != 13) {
			gotoxy(5, 8); printf("전화번호가 형식에 맞지 않습니다.\n");
			check = 1;
		}

		gotoxy(5, 7); printf("이름 = ");
		scanf("%s", name);

	} while (check != 0);

	gotoxy(5, 9);
	for (int i = 0; i < 30; i++) {
		Sleep(50);
		printf("=");
	}

	system("cls");

	for (int i = 0; i < index; i++) {
		if (strcmp(phone, mem[i].phone) == 0 && strcmp(name, mem[i].name) == 0) {
			for (int j = i+1; j < index; j++) {
				strcpy(mem[i].username, mem[j].username);
				strcpy(mem[i].password, mem[j].password);
				strcpy(mem[i].name, mem[j].name);
				strcpy(mem[i].phone, mem[j].phone);
				mem[i].total_Hour = mem[j].total_Hour;
				mem[i].total_PC_Charge = mem[j].total_PC_Charge;
				mem[i].total_Food_Charge = mem[j].total_PC_Charge;
			}
			index--;

			lp = fopen("PC.txt", "wt");
			for (int i = 0; i < index; i++) {

				fprintf(lp, "%s %s %s %s %d %d %d\n", mem[i].username, mem[i].password, mem[i].name, mem[i].phone, mem[i].total_Hour, mem[i].total_PC_Charge, mem[i].total_Food_Charge);

			}

			fclose(lp);

			gotoxy(5, 8);  printf("탈퇴가 완료되었습니다. 안녕히 가세요\n");
			getch();
			return;
		}
	}

	for (int i = 0; i < index; i++) {
		if (strcmp(phone, mem[i].phone) == 0 && strcmp(name, mem[i].name) != 0) {
			gotoxy(5, 8); printf("이름을 확인해주십시오.\n");
			getch();
			return admin_menu();
		}
	}

	for (int i = 0; i < index; i++) {
		if (strcmp(name, mem[i].name) == 0 && strcmp(phone, mem[i].phone) != 0) {
			gotoxy(5, 8); printf("전화번호를 확인해 주십시오.\n");
			getch();
			return admin_menu();
		}
	}
	

	gotoxy(5, 8); printf("\n해당 전화번호는 등록되어있지 않습니다.\n");
	gets(stdin);
	getch();


}