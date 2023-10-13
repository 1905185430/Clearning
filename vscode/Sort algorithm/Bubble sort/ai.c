#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
int random(void)  
{  
    return rand() % 100;  
}  
  
int get_array ( int *array, size_t arraySize, int (*choose_value)(void))  
{  
    for (size_t i=0 ; i < arraySize ; i++ )  
    {  
        array[i] = choose_value();  
    }  
}  
  
int put_out(int *array ,int length)  
{  
    for (int i=0; i<length ; i++)  
    {  
        printf("%d\t",*(array+i));  
    }  
    printf("\n");  
}  
  
void max_to_min(int *array,int length)  
{  
    int done;  
    for(int i=0 ; i < length ; i++ )  
    {  
        array[i]=*(array+i);  
    }  
    for(done=1; done<length; done++)  
    {  
        for(int i=0 ; i < length-done ; i++ )  
        {  
            if(array[i]<array[i+1])  
            {  
                int temp = array[i];  
                array[i] = array[i+1];  
                array[i+1] = temp;  
            }  
        }  
    }  
}  
  
int main(void)  
{  
    int *myarray = NULL,length;  
      
    printf("请输入随机数组的长度\n");  
    scanf("%d",&length);  
      
    myarray = (int *)malloc(length*sizeof(int));  // length 是数组元素数量，应该乘以 sizeof(int) 得到字节数  
    get_array( myarray, length, random);  
  
    put_out(myarray,length);  
  
    max_to_min(myarray,length);  // 修改了这里，将 max_to_min 的返回值改为 void，并将数组作为参数传入。  
  
    put_out(myarray,length);  // 现在可以输出排序后的数组了。  
  
    free(myarray);  // 在结束前释放内存。  
  
    return 0;  
}