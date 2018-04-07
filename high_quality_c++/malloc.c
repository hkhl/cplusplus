/************************************************************************
	> File Name: 1.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年03月15日 星期四 22时14分26秒
 ************************************************************************/

/* malloc申请空间实际分配? */

#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
    printf("int 长度为　：%ld\n", sizeof(int));
    int *p, b = 1;
    int nbytes;
    
    /*malloc参数可为0 但不可以为负*/
    //测试本机64位机,只要参数小于24(包括0)  
    //第一次最小分配24字节
    //若大于24字节, 例如1000,则分配1000或者1000大一点内存
    p = (int *)malloc(0); 
    
    if(p == NULL)
    {
        perror("malloc");
        exit(1);
    }
    /* malloc_usable_size函数返回malloc申请空间的大小 */
    nbytes = malloc_usable_size(p);
    printf("动态内存的长度为：%d\n", nbytes);
    printf("a的长度:%ld\n", sizeof(p)); //指针:32位4字节,64位8字节
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 4;
    p[5] = 5;
    //p[6] = 6;     //当超出分配的空间24,程序崩溃(必须有free, 设置NULL则是个良好的习惯)
    printf("b = %d\n", b);
    printf("p = %d\n", *p);
    printf("指针地址：b - %p\n", &b);
    printf("释放前，指针地址：a - %p\n", p);
    free(p);
    p = NULL;
    printf("释放后，指针地址：a - %p\n", p);
    if(p != NULL)
    printf("p = %d\n", *p);
    else
    printf("p is NULL, %p \n", p);

    return 0;
}
