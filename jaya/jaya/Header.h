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

// Value
int arr[ARR_LEN][ARR_LEN];


// Function List
void initArray();
void printArray();

// Function
void initArray()
{
    // Value
    char buf[BUF_LEN];
    int i, j;
    int temp = 0;
    memset(buf, '\0', BUF_LEN);
    char *str;
    char *tok;
    char check = '\0';
    
    // 1. open
    if((temp = open("/Users/JJo/Desktop/Xcode poroject/project/ALL_atsp/br17.atsp", O_RDWR)) == -1)
    {
        perror("[1] open error ");
        exit(1);
    }
    
    // 2. read
    if(read(temp, buf, BUF_LEN) == -1)
    {
        perror("[2] read error ");
        exit(2);
    }

    // 3-1. strstr

    if((str = strstr(buf, "9999")) == NULL)
    {
        perror("[3] strstr error ");
        exit(3);
    }
    
    // 3-2. strtok
    if((str = strtok(str, "EOF")) == NULL)
    {
        perror("[3] strtok error ");
        exit(3);
    }

    // printf("%s\n", str);
    
    // 4. str to int
    tok = strtok(str, " ");
    arr[0][0] = (int)strtol(tok, &tok, 10);
    
    for(i = 0; i < ARR_LEN; i++)
    {
        for(j = 0; j < ARR_LEN; j++)
        {
            if(i == 0 && j == 0)
                continue;
            
            tok = strtok(NULL, " ");
            arr[i][j] = (int)strtol(tok, NULL, 10);
        }
    }
}

void printArray()
{
    int i, j;
    
    for(i = 0; i < ARR_LEN; i++)
    {
        for(j = 0; j < ARR_LEN; j++)
        {
            printf("%4d ", arr[i][j]);
        }
        printf("\n\n");
    }
}
