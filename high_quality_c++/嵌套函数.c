/*************************************************************************
	> File Name: 1.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月06日 星期五 13时15分55秒
 ************************************************************************/
 /*gcc  嵌套函数*/

#include <stdio.h>

void s()
{
    int x()
    {
        printf("1111111111111\n");
        int r = 3;
        printf("asdasdasd\n");

    }
    printf("12312323dsasd\n");

    x();
}
int main()
{
    /*标准不支持c嵌套函数*/
    /*仅仅GNU gcc 编译器支持而已*/
    s();
    //x();  no

    return 0;
}
