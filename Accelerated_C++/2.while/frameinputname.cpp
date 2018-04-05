/*************************************************************************
	> File Name: frameinputname.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年03月31日 星期六 01时33分33秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main()
{

    cout << "Please enter your first name: ";

    string name;
    cin >> name;

    const string greeting = "Hello, " + name + "!";
    const int pad = 2;

    const int rows = pad * 2 + 3;
    
    //用人家的类型来记录字符串长度
    //每一行的长度 = 问候与+pad*2+两个*号
    const string::size_type cols = greeting.size() + pad * 2 + 2;

    cout << endl;

    for(int r = 0; r != rows; ++r)
    {
        string::size_type c = 0;

        while(c != cols)
        {
            if(r == pad + 1 && c == pad + 1)
            {
                cout << greeting;
                c += greeting.size();
            }
            else
            {
                if(r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
                    cout << "*";
                else
                    cout << " ";
                ++c;
            }
        }
        cout << endl;
    }
    return 0;
}
