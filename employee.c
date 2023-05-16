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
}


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
} 


void readlist_Employee(Info* a[], int index){
    printf("\n[ 휴가 조회 ]\n");
    printf("이름\t부서명\t시작 날짜\t끝나는 날짜\t승인 상태\n");
    printf("——————————————————————————\n");
    for (int i = 0; i < index; i++) {
      printf("%s\t%s\t%s\t%s\t%c\n", a[i]->name, a[i]->department, a[i]->start, a[i]->end, a[i]->approval);
  }
}

//사용자가 입력한 인덱스에 해당하는 휴가 정보를 삭제하는 함수
int deletelist_Employee(Info* a[], int index){
    if (index < 0) {
   	 printf("존재하지 않는 인덱스입니다.\n");
    return 0;
  }
    if (a[index] == NULL) {
   	 printf("이미 삭제된 정보입니다.\n");
    return 0;
  }
    free(a[index]);  // 동적 할당된 메모리 해제
    a[index] = NULL; // 포인터를 NULL로 초기화
    printf("삭제되었습니다.\n");
    return 1;
}

//사용자가 입력한 인덱스에 해당하는 휴가 정보를 수정하는 함수
void updatelist_Employee(Info* a[], int index){
    if (index < 0) {
   	 printf("존재하지 않는 인덱스입니다.\n");
    return;
  }
    if (a[index] == NULL) {
   	 printf("이미 삭제된 정보입니다.\n");
    return;
  }
    printf("수정할 정보를 입력하세요.\n");
    printf("이름 : ");
    scanf("%s", a[index]->name);
    printf("부서명 : ");
    scanf("%s", a[index]->department);
    printf("시작 날짜 : ");
    scanf("%s", a[index]->start);
    printf("끝나는 날짜 : ");
    scanf("%s", a[index]->end);
    printf("승인 상태(-:미처리, Y:허가, N:불허) : ");
    scanf(" %c", &a[index]->approval);
    printf("수정되었습니다.\n");
}

//프로그램을 종료하기 전에 휴가 정보를 파일에 저장하는 함수
//구조체 변수의 내용을 파일에 한 줄씩 저장
void saveData_Employee(Info* a[], int index){
    FILE *fp;
    fp = fopen("employee.txt", "wt");
    if (fp == NULL) {
   	 printf("파일 열기 실패\n");
    return;
  }
    for (int i = 0; i < index; i++) {
   	 if (a[i] == NULL)
        	 continue; // 삭제된 정보는 저장하지 않음
    fprintf(fp, "%s %s %s %s %c\n", a[i]->name, a[i]->department, a[i]->start, a[i]->end, a[i]->approval);
  }
  fclose(fp);
  printf("저장되었습니다.\n");
}

//프로그램을 실행할 때 파일에서 휴가 정보를 읽어오는 함수
//파일에서 한 줄씩 읽어서 구조체 변수에 저장
int loadData_Employee(Info* a[], int index){
    FILE *fp;
    fp = fopen("employee.txt", "r");
    if (fp == NULL) {
   	 printf("=> 파일 없음\n");
    return 0;
  }
    int i = 0;
    while (feof(fp) == 0) {
    	a[i] = (Info *)malloc(sizeof(Info));
    	fscanf(fp, "%s", a[i]->name);
    	fscanf(fp, "%s", a[i]->department);
    	fscanf(fp, "%s", a[i]->start);
    	fscanf(fp, "%s", a[i]->end);
    	fscanf(fp, "%s", &a[i]->approval);
    	i++;
  }
    index = i - 1;
    printf("=> 로딩 성공!\n");
    fclose(fp);
    return 1;
}


int searchName_Employee(Info* a[], int index){
    return 1;
}; // 해당 함수를 통해 원하는 이름의 index를 반환
