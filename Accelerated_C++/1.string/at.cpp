/*************************************************************************
	> File Name: at.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月05日 星期四 11时30分52秒
 ************************************************************************/
/*at() 检查数组下表是否合法
* 追求效率 使用str[]
* 追求安全稳定使用 str.at()*/
#include <iostream>
#include <string>
using namespace std;


int main()
{
    string strs = "hello world";

    //str.at(6) = '2';
    //str[116] = '2'; 不检查小标, 可能会引发断错误,可能会没事
    //str.at(116) = '2';  //检查数组下标错误


    cout << strs << endl;
    
    return 0;
}
