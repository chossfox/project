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
    checkWeight(0);
    
    // Print
    printf("city\n");
    printCity();
    printf("\n\n");
    
    printf("array\n");
    printArray();
    printf("\n\n");
    
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

void printCity()
{
    int i;
    
    for(i = 0; i < ARR_LEN; i++)
        printf("%4d ", city[i]);
    printf("\n");
}

void checkWeight(int i)
{
    // Value
    int min = NUM_MAX;
    int j = 0;
    
    // Check city
    if(checkCity(i) == -1)
    {
        return;
    }
    
    // Roof
    for(j = 0; j < ARR_LEN; j++)
    {
        if(visit == 0)
        {
            printf("count : %d\n", count);
            printCity();
            exit(5);
        }
        
        
        min = checkMin(i);
        
        //printf("i = %d, j = %d, min = %d\n", i, j, min);
        
        city[i] = 1;
        visit--;
        count += min;
        
        printf("city[%d] -> city[%d], visit = %d\n\n", i, j, visit);
        //printCity();
        checkWeight(j);
    }
}

int checkCity(int n)
{
    // Check
    if(city[n] == 1)
        return -1;
    
    return 1;
}

int checkMin(int i)
{
    // Value
    int min = NUM_MAX;
    int j;
    
    // Check
    for(j = 0; j < ARR_LEN; j++)
    {
        if(arr[i][j] == 0)
        {
            city[j] = 1;
            continue;
        }
        
        if(arr[i][j] < min)
        {
            min = arr[i][j];
            arr[i][j] = NUM_MAX;
        }
    }
    
    if(min == NUM_MAX)
        return 0;
    
    return min;
}
