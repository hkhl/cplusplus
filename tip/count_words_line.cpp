#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


//xref 缺省参数
//xref(cin)  //在输入流中使用split来查找单词
//xref(cin, find_urls) //使用find_urls的函数查找单词



bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

vector<string> split(const string &str)
{
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin();

    while(i != str.end())
    {
        i = find_if(i, str.end(), not_space);  //找到第一个不为空的位置

        iter j = find_if(i, str.end(), space); //找到字符串的结尾

        if(i != str.end())
        {
            ret.push_back(string(i, j));
        }
        i = j;
    }
    return ret;
}






map<string, vector<int> > xref(istream& in,
        vector<string> find_words(const string&) = split)
{
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    //读下一行
    while (getline(in, line)) {
        ++line_number;

        //把输入行分割成单词
        vector<string> words = find_words(line);

        //记住出现在当前的每一个单词
        for (vector<string>:: const_iterator it = words.begin();
                it != words.end(); ++it){
            ret[*it].push_back(line_number);
        }
    }
    return ret;
}



int main()
{
    map<string, vector<int>> ret = xref(cin);

    //输出结果
    for (map<string, vector<int> >::const_iterator it =ret.begin();
            it != ret.end(); it++) {
        //输出单词
        cout << it->first << " occurs on lins(s): ";

        //输出行号(一或者多个)
        vector<int>::const_iterator line_it = it->second.begin();
        cout << *line_it;
        ++line_it;
        while (line_it != it->second.end()) {
            cout << "," << *line_it;
            ++line_it;
        }
        cout << endl;
    }
    return 0;
}
