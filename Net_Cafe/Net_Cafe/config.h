#pragma once

#include<stdio.h>
#include<string.h>
#include<windows.h>						
#include<stdlib.h>
#include<time.h>						// �ð����� ������� (time_t, difftime...)
#include<process.h>						// _beginthread, _endthread,

#define FOODNUM 10						// ���� ǰ�� ��
#define memberCharge 50					// ȸ�� 2�ʴ� ���
#define nonMemCharge 100;				// ��ȸ�� 2�ʴ� ��� 

FILE *lp;

void main_menu();						// ���θ޴�
void member_menu();						// ȸ���޴�
void login_menu();						// �α��θ޴�
void join_menu();						// ȸ������
void nonmember_menu();					// ��ȸ���޴�
void admin_menu();						// �����ڸ޴�
void Search_Member();					// ID/PW ��� �޴�
void showAllMember();					// ��üȸ������
void food_list();						// �����޴�����
void change_food();						// ���� ���ݺ���
void Search_Member_PW();				// ID ���
void Search_Member_ID();				// PW ���
void input_data();						// ���� �����
time_t pcStart();						// pc��� ���۽ð�
time_t pcStop();						// pc��� ����ð�
void order_food(int);					// �����ֹ�
void charge(time_t, time_t, int);		// �� ����� ���
void non_member_login();				// ��ȸ�� �α���
void checkmem();						// ȸ��/��ȸ�� Ȯ�θ޴�
void find_check_mem();					// ȸ�� üũ
void find_check_nomem();				// ��ȸ�� üũ
void gotoxy(int, int);					// �ؽ�Ʈ ǥ����ġ ����
void show_use();						// �̿�ð�, ��� ǥ��
void total_Sales();						// �� ���� ǥ��
void show_VIP(int);						// PC�̿�, �����̿� ���帹���� ȸ�� ���
void update_data();						// ȸ�� ����
void update_n_delete_menu();			// ȸ�� ���� �� ���� �޴�
void delete_data();						// ȸ�� ����

HANDLE time_thread;						// Ÿ�̸� ������ ����
void show_time();						// Ÿ�̸� ǥ��
int swOn = 0;							// Ÿ�̸� ����ġ 1=On, 0=Off, 

int pause = 1;

int No = 0;								// ȸ����ȣ or ��ȸ�� �ڸ���ȣ