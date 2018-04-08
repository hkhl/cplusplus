/*************************************************************************
	> File Name: graph_frame.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月08日 星期日 23时33分36秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

//找出向量中最长的字符串的长度
string::size_type width(const vector<string>& v);
vector<string> frame(const vector<string>& v);
//连接操作  纵向
vector<string> vcat(const vector<string>& top, const vector<string>& bottom);
//横向连接
vector<string> hcat(const vector<string>& left, const vector<string>& right);

/*分割*/
vector<string> split_a(const string &s);

int main()
{
    string str;
    //getline 读入一行  str也接收一行
    while(getline(cin, str))
    {
        vector<string> v = split_a(str);

        cout << endl;
        for(vector<string>::size_type i = 0; i != v.size(); i++)
        {
            cout << v[i] << endl;
        }


        vector<string> newv = frame(v);
        for(vector<string>::size_type i = 0; i != newv.size(); i++)
        {
            cout << newv[i] << endl;
        }

        vector<string> s1 = hcat(v, newv);
        for(vector<string>::size_type i = 0; i != s1.size(); i++)
        {
            cout << s1[i] << endl;
        }

    }

    return 0;
}



string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    for(vector<string>::size_type i = 0; i != v.size(); ++i)
    {
        maxlen = max(maxlen, v[i].size());
    }
    return maxlen;
}

vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    //输出顶部边框
    ret.push_back(border);
    
    //输出内部的行, 每一行都用一个星号号一个空格框起
    for(vector<string>::size_type i = 0; i != v.size(); ++i)
    {
        ret.push_back("* " + v[i] + string(maxlen-v[i].size(), ' ') + " *");
    }

    //输出底部边框
    ret.push_back(border);
    return ret;
}


//连接操作  纵向
vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
    //复制顶部图案
    vector<string> ret = top;

    //复制整个底部图案
    /*
    for(vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it)
        ret.push_back(*it);
    */
    //等价
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    return ret;
}


//横向连接
vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;

    //对width<left>加1 两幅图中间留个空格
    vector<string>::size_type width1 = width(left) + 1;

    //用来遍历left和right的索引
    vector<string>::size_type i = 0, j = 0;

    //循环操作直到我们查看完了两幅图案的所有行
    while(i != left.size() || j != right.size())
    {
        //构造新字符串保存字符, 这些字符来自两幅图案
        string s;

        //如果右侧图案还有待复制的行, 那就复制一行
        if(i != left.size())
            s += left[i++];

        //填充适当长度
        s += string(width1 - s.size(), ' ');

        //如果左侧图案还有待复制的行, 那就复制一行
        if(j != right.size())
            s +=right[j++];

        //把s添加到我们正在创建的图案中

        ret.push_back(s);
    }
    return ret;
}

vector<string> split_a(const string &s)
{
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    while(i != s.size())
    {
        //忽略前端空白
        while(i != s.size() && isspace(s[i]))
            ++i;

        //找出下一个单词终结点
        string_size j = i;
        while(j != s.size() && !isspace(s[j]))
            ++j;

        //如果找到了一些非空白字符
        if(i != j)
        {
            //从i开始赋值s的j-i个字符
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}

