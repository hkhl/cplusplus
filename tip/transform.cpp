#include <iostream>
#include <algorithm>
using namespace std;



int change(char ch)
{
    ch = ch - 'A' + 'a';
    return ch;
}



//transform函数的作用是: 将某操作应用于指定范围的每个元素
//前两个参数是范围(迭代器)
//第三个参数是插入在哪里
//最后一个参数是一个函数
int main(int argc, char const* argv[])
{

    string s = "Welecome Todo Code!\n";
    string newstr;

    cout << s << endl;

    transform(s.begin(), s.end(), s.begin(), ::tolower); //小写字母转大写
    cout << s << endl;
    transform(s.begin(), s.end(), s.begin(), ::toupper); //大写->小写
    cout << s << endl;

    transform(s.begin(), s.end(), back_inserter(newstr), ::tolower); //小写字母转大写
    cout << newstr << endl;
    transform(s.begin(), s.end(), back_inserter(newstr), change); //大写->小写
    cout << newstr << endl;
    return 0;
}
