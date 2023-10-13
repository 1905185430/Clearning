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
    printf("\n");
}//输出数组函数put_out

int max_to_min(int *myarray,int  length)
{
    for (int r=0 ; r<=length ; r++)
    {
        for (int i=0 ; i<=length-r ; i++ )
        {
            if(myarray[r-1]<=myarray[length-i-1])
            {
                int temp;
                temp = myarray[r-1];
                myarray[r-1] = myarray[length-i-1];
                myarray[length-i-1] = temp;
            }
        }
        put_out(myarray,length);
    }
}

int main(void)
{
    int *myarray = NULL,length;


    printf("请输入随机数组的长度\n");
    scanf("%d",&length);
    
    myarray = (int *)malloc(length+1);

    if (myarray == NULL) 
    {  
        printf("内存分配失败\n");  
        exit (-1);  // 如果内存分配失败，返回非零值以表明程序异常结束  
    }  

    get_array( myarray, length, random);

    put_out(myarray,length);

    max_to_min(myarray,length);

    put_out(myarray,length);

    free(myarray);

    return 0;
}