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


int addlist_Employee(Info* a[], int index){
    return 1;
}; // 휴가를 추가하는 함수
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
