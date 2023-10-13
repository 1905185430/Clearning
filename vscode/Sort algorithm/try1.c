#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int random(void)
{
    return rand() % 100;
}//随机数函数

int get_array ( int *array, size_t arraySize, int (*choose_value)(void))
{
    for (size_t i=0 ; i < arraySize ; i++ )
    {
        array[i] = choose_value();
    }
}//赋值函数

int put_out(int *array ,int length)
{
    int *ptr;
    ptr = array;
    for (int i=0; i<length ; i++)
    {
        printf("%d\t",*(ptr+i));
    }
}//输出数组函数put_out

int main(void)
{
    int *myarray = NULL,length;

    printf("请输入随机数组的长度\n");
    scanf("%d",&length);
    
    myarray = (int *)malloc(length+1);
    get_array( myarray, length, random);

    put_out(myarray,length);

    return 0;
}