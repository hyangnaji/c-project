#pragma once

#include<stdio.h>
#include<string.h>
#include<windows.h>						
#include<stdlib.h>
#include<time.h>						// 시간관련 헤드파일 (time_t, difftime...)
#include<process.h>						// _beginthread, _endthread,

#define FOODNUM 10						// 매점 품목 수
#define memberCharge 50					// 회원 2초당 요금
#define nonMemCharge 100;				// 비회원 2초당 요금 

FILE *lp;

void main_menu();						// 메인메뉴
void member_menu();						// 회원메뉴
void login_menu();						// 로그인메뉴
void join_menu();						// 회원가입
void nonmember_menu();					// 비회원메뉴
void admin_menu();						// 관리자메뉴
void Search_Member();					// ID/PW 잦기 메뉴
void showAllMember();					// 전체회원보기
void food_list();						// 매점메뉴보기
void change_food();						// 매점 가격변경
void Search_Member_PW();				// ID 잦기
void Search_Member_ID();				// PW 잦기
void input_data();						// 파일 입출력
time_t pcStart();						// pc사용 시작시간
time_t pcStop();						// pc사용 종료시간
void order_food(int);					// 매점주문
void charge(time_t, time_t, int);		// 총 사용요금 계산
void non_member_login();				// 비회원 로그인
void checkmem();						// 회원/비회원 확인메뉴
void find_check_mem();					// 회원 체크
void find_check_nomem();				// 비회원 체크
void gotoxy(int, int);					// 텍스트 표시위치 지정
void show_use();						// 이용시간, 요금 표시
void total_Sales();						// 총 매출 표시
void show_VIP(int);						// PC이용, 매점이용 가장많이한 회원 출력
void update_data();						// 회원 수정
void update_n_delete_menu();			// 회원 수정 및 삭제 메뉴
void delete_data();						// 회원 삭제

HANDLE time_thread;						// 타이머 쓰레드 접근
void show_time();						// 타이머 표시
int swOn = 0;							// 타이머 스위치 1=On, 0=Off, 

int pause = 1;

int No = 0;								// 회원번호 or 비회원 자리번호