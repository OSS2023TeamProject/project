#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "infomation.h"

typedef struct {
  char name[20]; //이름
  char department[40]; //소속 부서 이름
  char start[10]; //20230506 형태로 저장
  char end[10];
  char approval; // 승인 상태, 미처리 상태면 '-' 승인이면 'Y', 불허면 'N'
} Info;


int selectMenu_Employee(){
   int menu;
   printf("\n*** 휴가 관리 프로그램 ***\n");
   printf("1. 휴가 신청\n");
   printf("2. 휴가 조회\n");
   printf("3. 휴가 삭제\n");
   printf("4. 휴가 수정\n");
   printf("5. 저장\n");
   printf("6. 불러오기\n");
   printf("7. 이름 검색\n");
   printf("8. 종료\n");
   printf("=> 원하는 메뉴는? ");
   scanf("%d", &menu);
   printf("\n");
   return menu;
};


int addlist_Employee(Info* a[], int index){ //휴가 추가함수
    getchar();                                 // 버퍼 비우기
    printf("\n[ 휴가 신청 ]\n");
    printf("이름 : ");
    fgets(a[index]->name, sizeof(a[index]->name), stdin);
    a[index]->name[strlen(a[index]->name) - 1] = '\0'; // 개행문자 제거
    printf("부서명 : ");
    fgets(a[index]->department, sizeof(a[index]->department), stdin);

    a[index]->department[strlen(a[index]->department) - 1] ='\0'; // 개행문자 제거
    printf("시작 날짜 (yyyymmdd) : ");
    scanf("%s", a[index]->start);
    printf("끝나는 날짜 (yyyymmdd) : ");
    scanf("%s", a[index]->end);
    a[index]->approval = '-'; // 미처리 상태
    printf("=> 휴가 신청이 완료되었습니다.\n");
    return 1;
}; 
void readlist_Employee(Info* a[], int index){

};
int deletelist_Employee(Info* a[], int index){
    return 1;
};
void updatelist_Employee(Info* a[], int index){

};
void saveData_Employee(Info* a[], int index){

};
int loadData_Employee(Info* a[], int index){
    return 1;
};
int searchName_Employee(Info* a[], int index){
    return 1;
}; // 해당 함수를 통해 원하는 이름의 index를 반환
