#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "manager.h"
#include "employee.h"
//#include "infomation.h"

int main(void){
    Info* a[20];
    int index = 0;
    int menu;

    int kind_menu;
    printf("Enter 1 if you are an employee or 2 if you are a manager\n");
    printf("Enter : ");
    scanf("%d", &kind_menu);

    if(kind_menu == 1){ // employee
        index = loadData_Employee(a, index);

        while(1){
            menu = selectMenu_Employee();
            if (menu == 0) break;
            
            switch(menu){
                case 1:
                    break;
                default:
                    break;

            }
        }
        

        
    }
    else if(kind_menu == 2){ // manager
        index = loadData_Manager(a, index);

        while(1){
            menu = selectmenu_Manager();
            if(menu == 0) break;

            switch(menu){
                case 1:
                    approve_Manager(a, index);
                    break;
                case 2:
                    readList_Manager(a, index);
                    break;
                case 3:
                    index -= deletelist_Manager(a, index);
                    break;
                case 4:
                    saveData_Manager(a, index);
                    break;
                default:
                    printf("Error!\n");
                    break;
            }
        }
    }
    else
        printf("Error!");
    
    return 0;
}