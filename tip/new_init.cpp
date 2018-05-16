#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int *q = new int[10];   //只申请空间不初始化  相当于malloc
    int *p = new int[10](); //初始化为0


    for (int i = 0 ; i < 10; i++)
    {
        cout << p[0] << endl;
    }

    delete []q;
    delete []p;

    return 0;

}
