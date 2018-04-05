/*************************************************************************
	> File Name: cin.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月03日 星期二 21时14分18秒
 ************************************************************************/

#include <iostream>
using namespace std;

/*
 * cin 作为条件的意义
 * 类istream提供了一个转换把cin转换为类似与布尔类型
 * 这个转换所产生的值取决于istream对象内部状态
 * 这个状态会记住最近一次读数据的尝试是否成功
 * 因此: 可以用cin来作为条件等价与检测最近一次cin读取的数据是否成功
 *
 * 失败的几种情况:
 * 1. 读到文加的末尾,  ctrl+d
 * 2. 输入和我们试图读取的变量类型不一致
 * 3. 系统可能会在输入装置中检测到一个硬件问题
 */
int main()
{
    int count = 0;
    double sum  = 0;
    double x;
/*
    cin >> x;
    if(cin)
    等价于if(cin >> x) 
    * */
    //while(cin >> x)
    



    //cin>>x;
    //if(cin)
    if(cin >> x)
    {
        ++count;
        sum += x;
    }

    cout << sum << endl;

    return 0;
}
