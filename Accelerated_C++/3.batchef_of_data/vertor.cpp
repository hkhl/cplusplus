/*************************************************************************
	> File Name: vertor.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月03日 星期二 21时34分56秒
 ************************************************************************/
/* 输入 排序 输出 */


/* vector向量 一种容器形式的类型,保存一系列特定类型的值,动态增长 */
/*
 *vector<T>::size_type  一种类型确保了能保存可能存在的最大向量的所有元素
 *定义 vector<T>v  一个空向量,该向量可以保存T类型的元素
 *v.begin()  返回数值指向v的第一个元素
 *v.end() 指向最后一个元素
 *v.push_back(e) 向向量末尾添加一个元素, 该元素初始值为e
 *v[i] 类似数组a[i] 取值
 *v.size() 返回v的元素个数
 *
 *
 */

#include <iostream>
#include <vector>     //vector
#include <algorithm>  //sort 少量数据用insert sort  大量数据:quick sort
using namespace std;

int main()
{
    double x;
    double y = 4.9;
    y = x;
    vector<double> homework;

    while(cin >> x)
        homework.push_back(x);


    cout << endl;
    /* 保持环境独立性 */
    // homework.size() 返回值类型就是size_type, 无符号整型
    vector<double>::size_type size = homework.size();

    
    sort(homework.begin(), homework.end());


    /* homework.begin() 和 homework.end() 类似于指针(数组的首尾地址) */

    /* 使用迭代器输出 */
    for(vector<double>::iterator iter = homework.begin(); iter < homework.end(); iter++)
    {
        cout << *iter << endl;
    }

    /*for(int i = 0; i < size; i++)
    {
        cout << homework[i] << endl;
    }*/

    return 0;
}
