//
//  Header.h
//  jaya
//
//  Created by 조재현 on 2016. 12. 2..
//  Copyright © 2016년 조재현. All rights reserved.
//

// Header
#include <stdio.h>
#include <Stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

// Define
#define ARR_LEN 17
#define BUF_LEN 100000
#define NUM_MAX 9999

// Value
int arr[ARR_LEN][ARR_LEN];
int stack[ARR_LEN];
int count = 0;
int city[ARR_LEN];
int visit = ARR_LEN;

// Function List
void initArray();
void printArray();
void printCity();
void checkWeight(int i);
int checkCity(int n);
int checkMin(int i);
