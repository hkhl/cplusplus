#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string target = "";

void cat(string s)
{
    target += s;
}
int main()
{
    vector<string> words = {"asd", "zxc", "123"};

    //连接字符串
    for_each(words.begin(), words.end(), cat);

    cout << target << endl;
    return 0;
}
