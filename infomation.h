#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Infomation{
    char name[20]; // 이름
    char department[40]; // 소속 부서 이름
    char start[10];// 20230506 형태로 저장
    char end[10];
    char approval; // 승인 상태, 미처리 상태면 '-' 승인이면 'Y', 불허면 'N'
} Info;

#endif