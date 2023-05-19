#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "infomation.h"
#include "manager.h"


int selectmenu_Manager(){
int menu;
   printf("\n*** 휴가 관리 프로그램 (관리자용)***\n");
   printf("1. 휴가 승인\n");
   printf("2. 휴가 조회\n");
   printf("3. 휴가 삭제\n");
   printf("4. 저장\n");
   printf("0. 종료\n");
   printf("=> 원하는 메뉴는? ");
   scanf("%d", &menu);
   printf("\n");
   return menu;
};

void approve_Manager(Inf* a[], int index){
    int num;
    char ch;
    readList_Manager(a, index);
    
    printf("승인 또는 미승인하고 싶은 번호: ");
    scanf("%d", &num);
    num--;
    getchar();
    if(num < index && num >= 0){
        printf("승인하시려면 Y를 거절하시려면 N을 누르세요");
        scanf("%c", &ch);
        a[num]->approval = ch;
    }
};

void readList_Manager(Inf* a[], int index){
    printf("\n[ 휴가 조회 ]\n");
    printf("No\t이름\t부서명\t시작 날짜\t끝나는 날짜\t승인 상태\n");
    printf("——————————————————————————\n");
    for (int i = 0; i < index; i++) {
      printf("%d\t%s\t%s\t%s\t%s\t%c\n", i+1, a[i]->name, a[i]->department, a[i]->start, a[i]->end, a[i]->approval);
    }
};

int deletelist_Manager(Inf* a[], int index){
    int flag = 0;
    int num;
    int confirm;
    readList_Manager(a, index);
    
    printf("삭제 하고싶은 번호: ");
    scanf("%d", &num);
    num--;

    printf("정말로 삭제하시겠습니까? (Yes: 1, No: 2)");
    scanf("%d", &confirm);

    if(confirm == 1){
      for(int i=num; i<index-1; i++){
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
  
int loadData_Manager(Inf* a[], int index){
    int count = 0;
    FILE *fp;
    fp = fopen("list.txt", "r+");
    if(fp != NULL){
      while (feof(fp) == 0) {
        a[count] = (Inf*)malloc(sizeof(Inf));
        fscanf(fp, "%s %s %s %s %c", a[count]->name, a[count]->department, a[count]->start, a[count]->end, &a[count]->approval);
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
};

void saveData_Manager(Inf* a[], int index){
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
};

int searchName_Manager(Inf* a[], int index){
  char search[20];
  printf("검색할 이름을 입력해주세요 : ");
  scanf("%s", search);
  for (int i = 0; i < index; i++) {
    if (strcmp(a[i]->name, search) == 0) {
      return i;
    }
  }

  printf("=> 검색된 결과가 없습니다.\n");
  return -1; //없으면 0리턴
}