#pragma once

#include"config.h"
#include"member.h"

int flag = 0;	//0 : �մ�, 1 : ȸ��, 2 : ������

void main_menu() {      //���� �޴�
	int login = 0;

	system("cls");

	gotoxy(5, 1); printf("---<< ȯ���մϴ�. >>---");
	gotoxy(5, 3); printf("�������. PC���Դϴ�.");
	gotoxy(5, 4); printf("=== �α��� ���ּ��� ===");
	gotoxy(5, 5); printf("0. ȸ�� ����");
	gotoxy(5, 6); printf("1. ȸ�� �α���");
	gotoxy(5, 7); printf("2. ��ȸ�� �α���");
	gotoxy(5, 8); printf("3. ID/PW ã��");
	gotoxy(5, 9); printf("4. ����ϱ�");
	gotoxy(5, 10); printf("======================");
	gotoxy(5, 11); printf("���� :: ");
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
		gotoxy(5, 12); printf("�����մϴ�.\n");
		return pause = 0;
	default:
		gotoxy(5, 12); printf("�߸��Է��ϼ̽��ϴ�.\n");
	}
}

void login_menu() {

	system("cls");

	char username[20] = { 0 }, Username[20] = { 0 };
	char password[20] = { 0 }, Password[20] = { 0 };


	gotoxy(5, 5); printf("==< ȸ�� �α��� >== \n");
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
			gotoxy(5, 8);   printf("ID�� Ȯ�����ֽʽÿ�.\n");
			getch();

			return main_menu();
		}
	}
	for (int i = 0; i < index; i++) {
		strcpy(Username, mem[i].username);
		strcpy(Password, mem[i].password);
		if (strcmp(Username, username) == 0 && strcmp(Password, password) != 0) {
			gotoxy(5, 8);   printf("PW�� Ȯ�����ֽʽÿ�.\n");
			getch();

			return main_menu();
		}
	}
	gotoxy(5, 8);   printf("ID�� PW�� Ȯ�����ֽʽÿ�.\n");

	getch();

}


void member_menu() {   //ȸ�� �޴�
	flag = 1;
	int select;

	system("cls");

	if (swOn == 0) {
		gotoxy(5, 1); printf("--<< ȯ���մϴ�. >>--");
	}
	else {
		show_use();
	}

	gotoxy(5, 5);	printf("===== ȸ�� �޴� =====\n");
	gotoxy(5, 6);	printf("1. ��ǻ�� ������\n");
	gotoxy(5, 7);	printf("2. ��ǻ�� �������\n");
	gotoxy(5, 8);	printf("3. ���� �ֹ�\n");
	gotoxy(5, 9);	printf("=====================\n");
	gotoxy(5, 10);	printf("��  �� :: ");
	gotoxy(15, 10);   scanf("%d", &select);

	switch (select) {
	case 1:
		if (swOn == 0) {
			mem[No].start_time = pcStart();				// ������
		}
		else {
			gotoxy(5, 11);	printf("�̹� PC�� ������Դϴ�.");
			getch();

		}

		member_menu();
		break;
	case 2:
		if (swOn == 1) {
			mem[No].end_time = pcStop();					// �������
		}
		else {
			gotoxy(5, 11);	printf("PC�� ������� �ƴմϴ�.");
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
			gotoxy(5, 11);	printf("PC�� ������� �ƴմϴ�.");
			member_menu();
		}

		break;
	default:
		gotoxy(5, 11); printf("������ �ùٸ��� �ʽ��ϴ�.\n");
		getch();
	}
}

void Search_Member() {
	int num = 0;

	system("cls");

	gotoxy(5, 4);	printf("== ID/PWã�� ==\n");
	gotoxy(5, 5);	printf("1. IDã��\n");
	gotoxy(5, 6);	printf("2. PWã��\n");
	gotoxy(5, 7);	printf("===============\n");
	gotoxy(5, 8);	printf("���� :: ");
	scanf("%d", &num);

	switch (num) {
	case 1:
		Search_Member_ID();
		break;
	case 2:
		Search_Member_PW();
		break;
	default:
		gotoxy(5, 10);	printf("�޴��� �ٽ� �Է����ּ���.");
	}
}

void Search_Member_ID() {


	char phone[16] = { 0 };

	system("cls");

	gotoxy(5, 3); printf("====< IDã�� >====\n");
	gotoxy(5, 5); printf("�Ʒ� ������ �Է����ּ���.");
	gotoxy(5, 6); printf("��ȭ��ȣ = ");
	scanf("%s", phone);


	for (int i = 0; i < 15; i++) {
		Sleep(100);
		printf("=");
	}


	for (int i = 0; i < index; i++) {
		if (strcmp(phone, phone) == 0 && strcmp(phone, mem[i].phone) == 0) {
			gotoxy(5, 8); printf("\nID�� %s�Դϴ�.\n", mem[i].username);
			//gets(stdin);
			getch();
			return;
		}
	}


	gotoxy(5, 8); printf("\nã���ô� ID�� �����ϴ�.\n");
	gets(stdin);
	getch();

}



void Search_Member_PW() {
	char phone[16] = { 0 };
	char username[20] = { 0 };

	system("cls");

	gotoxy(5, 3); printf("====< PWã�� >====\n");
	gotoxy(5, 5); printf("�Ʒ� ������ �Է����ּ���.");
	gotoxy(5, 6); printf("ID = ");
	scanf("%s", username);
	gotoxy(5, 7); printf("��ȭ��ȣ = ");
	scanf("%s", phone);


	for (int i = 0; i < 15; i++) {
		Sleep(100);
		printf("=");
	}

	for (int i = 0; i < index; i++) {
		if (strcmp(username, mem[i].username) == 0 && strcmp(phone, mem[i].phone) == 0) {
			gets(stdin);
			gotoxy(5, 8); printf("PW�� %s�Դϴ�.\n", mem[i].password);
			getch();
			return;
		}
	}
	for (int i = 0; i < index; i++) {
		if (strcmp(username, mem[i].username) == 0 && strcmp(phone, mem[i].phone) != 0) {
			gets(stdin);
			gotoxy(5, 8); printf("��ȭ��ȣ�� �߸��Ǿ����ϴ�.\n");
			getch();
			return;
		}
	}
	for (int i = 0; i < index; i++) {
		if (strcmp(username, mem[i].username) != 0 && strcmp(phone, mem[i].phone) == 0) {
			gets(stdin);
			gotoxy(5, 8); printf("ID�� �߸��Ǿ����ϴ�.\n");
			getch();
			return;
		}
	}
	for (int i = 0; i < index; i++) {
		if (strcmp(username, mem[i].username) != 0 && strcmp(phone, mem[i].phone) != 0) {
			gets(stdin);
			gotoxy(5, 8); printf("��ġ�ϴ� ������ �����ϴ�.\n");
			getch();
			return;
		}
	}
}

void non_member_login() {
	int num = 0;
	system("cls");

	gotoxy(5, 4);	printf("==< ��ȸ�� �α��� >==\n");
	gotoxy(5, 5);	printf("��ȣ�Է� = ");
	scanf("%d", &num);

	nonMem[num].nonmember = num;
	nonMem[num].total_PC_Charge = 0;
	nonMem[num].total_Hour = 0;
	nonMem[num].total_Food_Charge = 0;

	gotoxy(5, 7);	printf("%d�� �α��� �Ǿ����ϴ�.", num);

	getch();
	nonmember_menu(num);
}


void nonmember_menu() {      //��ȸ�� �޴�
	flag = 0;

	int select;

	system("cls");

	if (swOn == 0) {
		gotoxy(5, 1); printf("--<< ȯ���մϴ�. >>--");
	}
	else {
		show_use();
	}

	gotoxy(5, 5);	printf("==== ��ȸ�� �޴� ====\n");
	gotoxy(5, 6);	printf("1. ��ǻ�� ��� ����\n");
	gotoxy(5, 7);	printf("2. ��ǻ�� ��� ����\n");
	gotoxy(5, 8);	printf("3. ���� �ֹ�\n");
	gotoxy(5, 9);	printf("======================\n");
	gotoxy(5, 10);	printf("��  �� :: ");
	scanf("%d", &select);

	switch (select) {
	case 1:
		if (swOn == 0) {
			nonMem[No].start_time = pcStart();				// ������

		}
		else {
			gotoxy(5, 11);	printf("�̹� PC�� ������Դϴ�.");
			getch();

		}

		nonmember_menu(nonMem);
		break;
	case 2:
		if (swOn == 1) {
			nonMem[No].end_time = pcStop();				// �������		
		}
		else {
			gotoxy(5, 11);	printf("PC�� ������� �ƴմϴ�.");
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
			gotoxy(5, 11);	printf("PC�� ������� �ƴմϴ�.");
			getch();

			nonmember_menu();
		}

		break;
	default:
		gotoxy(5, 11); printf("������ �ùٸ��� �ʽ��ϴ�.\n");
		getch();
	}
}

void admin_menu() {      //������ �޴�

	int admin = 0;
	int memNo = 0;

	system("cls");

	gotoxy(5, 4);	printf("==< ������ �޴� >==\n");
	gotoxy(5, 5);	printf("1. �����ݾ׺���\n");
	gotoxy(5, 6);	printf("2. ��üȸ�����\n");
	gotoxy(5, 7);	printf("3. ����\n");
	gotoxy(5, 8);	printf("4. ȸ������/Ż��\n");
	gotoxy(5, 9);	printf("===================\n");
	gotoxy(5, 10);	printf("���� :: ");
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
		gotoxy(5, 10); printf("������ �ùٸ��� �ʽ��ϴ�.\n");
		getch();
		return;
	}
}

void join_menu() {	// ȸ������
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

	gotoxy(5, pos++);	printf("====[ ȸ�� ���� ]====\n");

	do {
		check = 0;
		gotoxy(5, pos); printf("username(ID) = ");
		gotoxy(21, pos++); scanf("%s", username);

		for (int i = 0; i < index; i++) {
			if (strcmp(mem[i].username, username) == 0) {
				gotoxy(5, pos++); printf("�̹� �����ϴ� ȸ���Դϴ�.\n");
				check = 1;
			}
		}

		if (strlen(username) > 20) {
			gotoxy(5, pos++); printf("ID�� ���Ŀ� ���� �ʽ��ϴ�.\n");
			check = 1;
		}

	} while (check != 0);
	fflush(stdin);
	do {
		check = 0;

		gotoxy(5, pos); printf("password(PW) = ");
		gotoxy(21, pos++); scanf("%s", password);

		if (strlen(password) > 20) {
			gotoxy(5, pos++); printf("��й�ȣ�� ���Ŀ� ���� �ʽ��ϴ�.\n");
			check = 1;
		}

	} while (check != 0);
	fflush(stdin);
	gotoxy(5, pos); printf("�̸� = ");
	gotoxy(13, pos++); scanf("%s", name);
	fflush(stdin);
	do {
		check = 0;

		gotoxy(5, pos); printf("��ȭ��ȣ(010-1234-1234) = ");
		gotoxy(32, pos++); scanf("%s", phone);

		if (strlen(phone) == 13) {
			for (int i = 0; i < index; i++) {
				if (strcmp(mem[i].phone, phone) == 0) {
					gotoxy(5, pos++); printf("�̹� �����ϴ� ȸ���Դϴ�.\n");
					check = 1;
				}
			}
		}
		else {
			gotoxy(5, pos++); printf("��ȭ��ȣ�� ���Ŀ� ���� �ʽ��ϴ�.\n");
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

	gotoxy(5, pos++); printf("ȸ�������� �Ϸ�Ǿ����ϴ�.\n");

	fclose(lp);

	getch();

}

void change_food() {	// ���� ���ݺ���

	int foodNo, changePrice;
	system("cls");

	gotoxy(5, 4);	printf("��ǰ ������ �����մϴ�.");

	food_list();

	gotoxy(5, 5);	printf("��ǰ��ȣ = ");
	scanf("%d", &foodNo);

	for (int i = 0; i < FOODNUM; i++) {
		if (foodNo - 1 == i) {

			gotoxy(5, 5);	printf("���氡��(%d��) = ", f[i].food_Price);
			scanf("%d", &changePrice);

			f[i].food_Price = changePrice;

			gotoxy(5, 7);  printf("���� ���� �Ϸ�.");
			return admin_menu();

		}

	}

	printf("��ǰ��ȣ�� �����ϴ�.\n");

	getch();

}


void food_list() {	// �����޴�����

	gotoxy(30, 2); printf("----------<�޴�>----------");

	for (int i = 0; i < FOODNUM; i++) {
		gotoxy(30, i + 4); printf("%2d�� %11s - %5d��\n", i + 1, f[i].food_Name, f[i].food_Price);
	}

	gotoxy(30, 14); printf("--------------------------");
}

void showAllMember() {	// ��üȸ������
	char tmp[4] = { 0 };

	system("cls");
	printf("==========[ ȸ �� �� �� ]=========\n");

	for (int i = 1; i < index; i++) {
		strncpy(tmp, mem[i].password, 3);
		tmp[3] = '\0';
		printf("| ID\t\t : %13s |\n| PW\t\t : \t  %s*** |\n| NAME\t\t : %13s |\n| PHONE\t\t : %13s |\n| �������ð�\t : %13d |\n| ���������\t : %13d |\n",
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
	Pos.X = x; Pos.Y = y; // X, Y��ǥ
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


void input_data() {	// ���� �����
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
	else printf("������ �����ϴ�.\n");

	fclose(lp);
}

void show_use() {	// �̿�ð�, ��� ǥ��
	gotoxy(5, 1); printf("���ð� :: ");
	gotoxy(5, 2); printf("�̿��� :: ");
}

void total_Sales() {	// �� ���� ǥ��
	int total_PC = 0, total_food = 0;
	int pos = 5;
	system("cls");

	for (int i = 1; i < index; i++) {

		total_PC += mem[i].total_PC_Charge;
		total_food += mem[i].total_Food_Charge;

	}

	gotoxy(5, pos++);	printf(" ==========[ �� �� �� �� ]==========");
	gotoxy(5, pos++);	printf(" ===================================");
	gotoxy(5, pos++);	printf("| ȸ�� ���� PC���    >> %8d�� |", total_PC);
	gotoxy(5, pos++);	printf("| ��ȸ�� ���� PC���  >> %8d�� |", mem[0].total_PC_Charge);
	gotoxy(5, pos++);	printf(" -----------------------------------");
	gotoxy(5, pos++);	printf("| ȸ�� ������������   >> %8d�� |", total_food);
	gotoxy(5, pos++);	printf("| ��ȸ�� ������������ >> %8d�� |", mem[0].total_Food_Charge);
	gotoxy(5, pos++);	printf(" -----------------------------------");

	gotoxy(5, pos++);	printf("| �� ����             >> %8d�� |", total_PC + total_food + mem[0].total_Food_Charge + mem[0].total_PC_Charge);
	gotoxy(5, pos++);	printf(" ===================================");

	show_VIP(pos);
}

void show_VIP(int pos) {	// PC�̿�, �����̿� ���帹���� ȸ�� ���

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

	gotoxy(5, pos++); printf(" ---------< �����̿�  VIP >---------");
	gotoxy(5, pos++); printf("| %10s |      %13d�� |", mem[maxFood_num].username, mem[maxFood_num].total_Food_Charge);
	gotoxy(5, pos++); printf(" ---------<  PC�̿�  VIP  >---------");
	gotoxy(5, pos++); printf("| %10s |   %4d�� |  %6d�� |", mem[maxPC_num].username, mem[maxPC_num].total_Hour, mem[maxPC_num].total_PC_Charge);
	gotoxy(5, pos++); printf(" ===================================");
	getch();

}

void update_n_delete_menu() {
	int select = 0;
	system("cls");
	gotoxy(5, 3); printf("====< ���� �� Ż�� �޴� >====");
	gotoxy(5, 5); printf("1. ȸ�� ����");
	gotoxy(5, 6); printf("2. ȸ�� Ż��");
	gotoxy(5, 7); printf("=============================");
	gotoxy(5, 8); printf("���� :: ");
	scanf("%d", &select);

	switch (select) {
	case 1:
		update_data();
		break;
	case 2:
		delete_data();
		break;
	default:
		printf("�޴������� �߸��Ǿ����ϴ�.\n");
		return;
	}
}


void update_data() {	// ����
	char phone[20] = { 0 };
	char name[20] = { 0 };
	int check = 0;

	system("cls");
	do {
		gotoxy(5, 3); printf("====< ������ ȸ�� ã�� >====\n");
		gotoxy(5, 5); printf("�Ʒ� ������ �Է����ּ���.");
		gotoxy(5, 6); printf("��ȭ��ȣ = ");
		scanf("%s", phone);

		if (strlen(phone) != 13) {
			gotoxy(5, 8); printf("��ȭ��ȣ�� ���Ŀ� ���� �ʽ��ϴ�.\n");
			check = 1;
		}

		gotoxy(5, 7); printf("�̸� = ");
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

			gotoxy(5, 3); printf("���� ���� �����÷��� 0�� �Է��ϼ���.\n");

			do {
				check = 0;
				gotoxy(5, 4); printf("���� ���̵� :: %s == ������ ���̵� :: ", mem[i].username);
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
						gotoxy(5, 4); printf("�̹� ��ϵ� ���̵� �ֽ��ϴ�. �ٽ� �Է����ּ���.\n");
						username[0] = '/0';
					}
				}
								
			} while (check != 0);

			gotoxy(5, 5); printf("���� ��й�ȣ :: %s == ������ �н����� :: ", mem[i].password);
			scanf("%s", password);
			if (strcmp(password, default_return) == 0) {
				strcpy(password, mem[i].password);
			}

			gotoxy(5, 6); printf("���� �̸� :: %s == ������ �̸� :: ", mem[i].name);
			scanf("%s", name);
			if (strcmp(name, default_return) == 0) {
				strcpy(name, mem[i].name);
			}

			do {
				check = 0;
				gotoxy(5, 7); printf("���� ��ȭ��ȣ :: %s == ������ ��ȭ��ȣ :: ", mem[i].phone);
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
						gotoxy(5, 7); printf("�̹� ��ϵ� ��ȭ��ȣ�� �ֽ��ϴ�. �ٽ� �Է����ּ���.\n");
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

			gotoxy(5, 9); printf("������ �Ϸ�Ǿ����ϴ�.\n");

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

	gotoxy(5, 8); printf("\n�ش� ��ȭ��ȣ�� ��ϵǾ����� �ʽ��ϴ�.\n");
	gets(stdin);
	getch();

}

void delete_data() {
	char phone[20] = { 0 };
	char name[20] = { 0 };
	int check = 0;

	system("cls");
	do {
		gotoxy(5, 3); printf("====< Ż���� ȸ�� ã�� >====\n");
		gotoxy(5, 5); printf("�Ʒ� ������ �Է����ּ���.");
		gotoxy(5, 6); printf("��ȭ��ȣ = ");
		scanf("%s", phone);

		if (strlen(phone) != 13) {
			gotoxy(5, 8); printf("��ȭ��ȣ�� ���Ŀ� ���� �ʽ��ϴ�.\n");
			check = 1;
		}

		gotoxy(5, 7); printf("�̸� = ");
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

			gotoxy(5, 8);  printf("Ż�� �Ϸ�Ǿ����ϴ�. �ȳ��� ������\n");
			getch();
			return;
		}
	}

	for (int i = 0; i < index; i++) {
		if (strcmp(phone, mem[i].phone) == 0 && strcmp(name, mem[i].name) != 0) {
			gotoxy(5, 8); printf("�̸��� Ȯ�����ֽʽÿ�.\n");
			getch();
			return admin_menu();
		}
	}

	for (int i = 0; i < index; i++) {
		if (strcmp(name, mem[i].name) == 0 && strcmp(phone, mem[i].phone) != 0) {
			gotoxy(5, 8); printf("��ȭ��ȣ�� Ȯ���� �ֽʽÿ�.\n");
			getch();
			return admin_menu();
		}
	}
	

	gotoxy(5, 8); printf("\n�ش� ��ȭ��ȣ�� ��ϵǾ����� �ʽ��ϴ�.\n");
	gets(stdin);
	getch();


}