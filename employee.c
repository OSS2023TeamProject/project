#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "infomation.h"
#include "employee.h"

typedef struct {
  char name[20]; //이름
  char department[40]; //소속 부서 이름
  char start[10]; //20230506 형태로 저장
  char end[10];
  char approval; // 승인 상태, 미처리 상태면 '-' 승인이면 'Y', 불허면 'N'
} Info;


int selectMenu_Employee(){
   int menu;
   printf("\n*** 휴가 관리 프로그램 (직원용)***\n");
   printf("1. 휴가 신청\n");
   printf("2. 휴가 조회\n");
   printf("3. 휴가 삭제\n");
   printf("4. 휴가 수정\n");
   printf("5. 저장\n");
   printf("0. 종료\n");
   printf("=> 원하는 메뉴는? ");
   scanf("%d", &menu);
   printf("\n");
   return menu;
}


int addlist_Employee(Inf* a[], int index){ //휴가 추가함수
    getchar();                                 // 버퍼 비우기
    Inf* ptr = (Inf*)malloc(sizeof(Inf));

    printf("\n[ 휴가 신청 ]\n");
    printf("이름 : ");
    fgets(ptr->name, sizeof(ptr->name)+1, stdin);
    ptr->name[strlen(ptr->name) - 1] = '\0'; // 개행문자 제거
    printf("[중복체크]\n");

    if(checkDuplicated(a, index, ptr->name) == 1){
      printf("중복되었습니다\n");
      return 0;
    }
    printf("중복되지 않았습니다. 다음 과정을 진행해주세요.\n");
    printf("부서명 : ");
    fgets(ptr->department, sizeof(ptr->department)+1, stdin);

    ptr->department[strlen(ptr->department) - 1] ='\0'; // 개행문자 제거
    printf("시작 날짜 (yyyymmdd) : ");
    scanf("%s", ptr->start);
    printf("끝나는 날짜 (yyyymmdd) : ");
    scanf("%s", ptr->end);
    ptr->approval = '-'; // 미처리 상태

    a[index] = ptr;
    printf("=> 휴가 신청이 완료되었습니다.\n");

    return 1;
} 


int readlist_Employee(Inf* a[], int index){
    int search = searchName_Employee(a, index);
    if(search != -1){
      printf("\n[ 휴가 조회 ]\n");
      printf("No\t이름\t부서명\t시작 날짜\t끝나는 날짜\t승인 상태\n");
      printf("——————————————————————————--------------------------------------\n");
      for (int i = 0; i < index; i++) {
        if(!strcmp(a[search]->name, a[i]->name)){
          printf("%d\t%s\t%s\t%s\t%s\t%c\n", i+1, a[i]->name, a[i]->department, a[i]->start, a[i]->end, a[i]->approval);
          continue;
        }
        printf("******************* You can't access this ********************\n");
      }
    }

    return search;
}

int deletelist_Employee(Inf* a[], int index){
  int flag = 0;
  int idx;
  int confirm;
  int search = readlist_Employee(a, index);

  for (int i = 0; i < index; i++) {
      if(search == i){
        flag = 1;
        idx = i;
        break;
      }
  }
  
  if(flag == 1){
    printf("정말로 삭제하시겠습니까? (Yes: 1, No: 2)");
    scanf("%d", &confirm);

    if(confirm == 1){
      for(int i=idx; i<index-1; i++){
        a[i] = a[i+1];
      }
      free(a[index-1]);  // 동적 할당된 메모리 해제
      a[index-1] = NULL;
      printf("삭제하였습니다.\n");
      return 1;
    }
    else if(confirm == 2){
      printf("취소하였습니다.\n");
      return 0;
    }
    else{
      printf("Error!\n");
      return 0;
    }
  }
  else{
    return 0;
  }
}

//사용자가 입력한 인덱스에 해당하는 휴가 정보를 수정하는 함수
void updatelist_Employee(Inf* a[], int index){
  int flag = 0;
  int idx;
  int confirm;
  int search = readlist_Employee(a, index);

  for (int i = 0; i < index; i++) {
      if(search == i){
        flag = 1;
        idx = i;
        break;
      }
  }
  
  if(flag == 1){
    printf("정말로 수정하시겠습니까? (Yes: 1, No: 2)");
    scanf("%d", &confirm);

    if(confirm == 1){
      printf("수정할 정보를 입력하세요.\n");
      printf("이름 : ");
      scanf("%s", a[idx]->name);
      printf("부서명 : ");
      scanf("%s", a[idx]->department);
      printf("시작 날짜 : ");
      scanf("%s", a[idx]->start);
      printf("끝나는 날짜 : ");
      scanf("%s", a[idx]->end);
      printf("수정되었습니다.\n");
      return;
    }
    else if(confirm == 2){
      printf("취소하였습니다.\n");
      return;
    }
    else{
      printf("Error!\n");
      return;
    }
  }
  else{
    return;
  }
}

//프로그램을 종료하기 전에 휴가 정보를 파일에 저장하는 함수
//구조체 변수의 내용을 파일에 한 줄씩 저장
void saveData_Employee(Inf* a[], int index){
  FILE *fp;
  fp = fopen("list.txt", "wt");
  if (fp == NULL) {
 	  printf("파일 열기 실패\n");
    return;
  }
  for (int i = 0; i < index; i++) {
    fprintf(fp, "%s %s %s %s %c", a[i]->name, a[i]->department, a[i]->start, a[i]->end, a[i]->approval);
    if(i != index -1) fprintf(fp, "\n");
  }
  fclose(fp);
  printf("저장되었습니다.\n");
  return;
}

//프로그램을 실행할 때 파일에서 휴가 정보를 읽어오는 함수
//파일에서 한 줄씩 읽어서 구조체 변수에 저장
int loadData_Employee(Inf* a[], int index){
    int count = 0;
    FILE *fp;
    fp = fopen("list.txt", "r+");
    if(fp != NULL){
      while (feof(fp) == 0) {
        a[count] = (Inf*)malloc(sizeof(Inf));
        fscanf(fp, "%s %s %s %s %c\n", a[count]->name, a[count]->department, a[count]->start, a[count]->end, &a[count]->approval);
        if(!strcmp(a[count]->name, "")){
            free(a[count]);
            count--;
        }
        count++;
      }
      printf("=> 로딩 성공!\n");
      fclose(fp);
      return count;
    }
    else{
      printf("파일 없음!\n");
      return 0;
    }
} 

// 해당 함수를 통해 원하는 이름의 index를 반환
int searchName_Employee(Inf* a[], int index){
  char search[20];
  printf("검색할 이름을 입력해주세요 : ");
  scanf("%s", search);
  for (int i = 0; i < index; i++) {
    if (strcmp(a[i]->name, search) == 0) {
      return i;
    }
  }

  printf("=> 검색된 결과가 없습니다.\n");
  return -1; //없으면 -1리턴
}

int checkDuplicated(Inf* a[], int index, char* name){
  if (index == 0) return -1;

  int flag = 0;

  for(int i=0; i<index; i++)
    if(!strcmp(a[i]->name, name)){
      flag = 1;
      break;
  }

  return flag;
}