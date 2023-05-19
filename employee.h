#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "infomation.h"

int selectMenu_Employee();
int addlist_Employee(Inf* a[], int index); // 휴가를 추가하는 함수
int readlist_Employee(Inf* a[], int index);
int deletelist_Employee(Inf* a[], int index);
void updatelist_Employee(Inf* a[], int index);
void saveData_Employee(Inf* a[], int index);
int loadData_Employee(Inf* a[], int index);
int searchName_Employee(Inf* a[], int index); // 해당 함수를 통해 원하는 이름의 index를 반환
int checkDuplicated(Inf* a[], int index, char* name); // 휴가 신청시 중복되었는지 검사하는 함수

/*
변수 index에 대한 설명
index값은 Info* a[]에 저장된 요소의 개수와 일치해야합니다.

index를 통해서 list(Info* a[])에서 마지막 요소까지 접근할 수 있습니다.
index를 통해 조회를 할 땐 for(int i = 0; i<index; i++)와 같이 하면 마지막까지 조회할 수 있습니다.
예를 들어 a[]에 3개가 저장되어 있을 땐 index = 3입니다. 따라서 위와 같이 반복문을 구현하면 마지막까지 조회할 수 있습니다.

또한 index를 통해서 저장기능을 구현할 땐 a[index]를 이용하여 malloc하면 됩니다.
에를 들어 a[]에 3개가 저장되어 있을 땐 index = 3입니다. 따라서 현재 배열에는 a[2]까지 정보가 저장되어있습니다. 
    배열에 정보를 저장하고 싶으시다면 a[3] 즉, a[index]를 사용하면 됩니다
그리고 배열에 정보를 추가하였으니 main함수에서 index값을 수정해주어야 합니다. 우선 함수의 return값을 1로 설정합니다. main 함수에서 index 값을 추가해주어야합니다.
삭제 기능은 더하기를 빼기로만 하면 됩니다.

loadData()와 같은 경우 데이터를 불러 올 때 저장된 정보의 개수를 센 뒤 그 값을 return하시면 됩니다.
*/




