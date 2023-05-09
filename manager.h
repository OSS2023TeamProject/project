#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "infomation.h"

int selectmenu_Manager();
void approve_Manager(Info* a[], int index);
void readList_Manager(Info* a[], int index);
int deletelist_Manager(Info* a[], int index);
int loadData_Manager(Info* a[], int index);
void saveData_Manager(Info* a[], int index);
int searchName_Manager(Info* a[], int index); // 해당 함수를 통해 원하는 이름의 index를 반환

