//
//  main.c
//  jaya
//
//  Created by 조재현 on 2016. 12. 2..
//  Copyright © 2016년 조재현. All rights reserved.
//

#include "Header.h"


int main(int argc, const char * argv[])
{
    // insert code here...
    // Value
    int i = 0;
    
    for(i = 0; i < ARR_LEN; i++)
        city[i] = 0;
    
    // Function
    initArray();
    checkWeight(i);
    
    // Print
    //printArray();
    printf("count = %d\n", count);
    
    return 0;
}

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

void checkWeight(int i)
{
    // Value
    static int weight[ARR_LEN];
    int min = 9999;
    int j = 0;
    
    // Check city
    if(checkCity(i) == -1)
        return;
    
    // Check
    for(j = 0; j < ARR_LEN; j++)
    {
        if(arr[i][j] < min)
            min = arr[i][j];
    }
    
    for(j = 0; j < ARR_LEN; j++)
    {
        weight[j] = 9999;
        
        if(arr[i][j] == min)
        {
            weight[j] = min;
            
            city[i] = 1;
            count += min;
            
            checkWeight(j);
        }
        
    }
}

int checkCity(int n)
{
    // Check
    if(city[n] == 1)
        return -1;
    
    return 1;
}
