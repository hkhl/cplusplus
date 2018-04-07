/*************************************************************************
	> File Name: malloc-space.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月06日 星期五 17时11分03秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*用的虚拟内存, 不停的分配物理内存, 所有malloc几乎无上限*/
int main()
{

    int GB = 0;
    int *p = NULL;
    while(1)
    {
        p = (int *)malloc((1<<30));
        if(NULL == p)
        {
            printf("exit\n");
            exit(1);
        }
        ++GB;
        printf("%dGB\n", GB);
        usleep(10);  //睡10us
    }
    return 0;
}
