//
//  main.c
//  reverse
//
//  Created by ziggytao on 17/4/13.
//  Copyright © 2017年 ziggytao. All rights reserved.
//

#include <stdio.h>
#define MAXSIZE 20
#define CMAXSIZE 10000
void reverse(char s[]);//reverse a string
void rmove(char s[]);//remove '_' and characters after it in a string
void getString(char s[]);//get input and remove comments
int main(int argc, const char * argv[])
{
    int i;
    char s[CMAXSIZE];
    printf("Input:\n");
    getString(s);
    for(i = 0; s[i] != '\0'; i++)
    {
        printf("%c",s[i]);
    }
    printf("\n");
    return 0;
}
void reverse(char s[])//reverse a string
{
    int i,count;
    char temp;
    for(count = 0; s[count] != '\0';)
        count++;
    for(i = 0; i < count / 2; i++)
    {
        temp = s[i];
        s[i] = s[count - i - 1];
        s[count - i -1] = temp;
    }
}
void rmove(char s[])//remove '_' and characters after it in a string
{
    int i;
    for(i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == '_')
        {
            s[i] = '\0';
            break;
        }
    }
}
void getString(char s[])
{
    int i ,j = 0,count = 0;
    for(i = 0;;i++)
    {
        s[i] = getchar();
        if(s[i] == '{')
            count++;
        else if(s[i] == '}' )
        {
            count--;
            if(count == 0)
            {
                s[i + 1] = '\0';
                break;
            }
            
        }
        else if(s[i] == '/' && s[i - 1] == '/')
        {
            while((s[i - 1] = getchar()) != '\n')
                j++;
            i--;
        }
    }
}
