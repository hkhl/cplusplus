/*************************************************************************
	> File Name: find.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月05日 星期四 11时35分40秒
 ************************************************************************/

/*
* find 查找
* rfind 反向查找
* find_first_of 查找包含子串中的任何字符 返回第一个位置
* find_first_not_of 查找不包含子串的任何字符 返回第一个个位置
* find_last_of 查找包含子串中的任何字符 返回最后一个位置
* find_last_not_of 查找不包含子串中的任何字符 返回最后一个位置
*
* */
/* 以上函数都是被重载了4次，以下是以find_first_of
 * 函数为例说明他们的参数，其他函数和其参数一样，也就是说总共有24个函数 
 * 
size_type find_first_of(const basic_string& s, size_type pos = 0)
size_type find_first_of(const charT* s, size_type pos, size_type n)
size_type find_first_of(const charT* s, size_type pos = 0)
size_type find_first_of(charT c, size_type pos = 0)
* */

/*
 *所有的查找函数都返回一个size_type类型，这个返回值一般都是所找到字符串的位置，如果没有找到，则返回string::npos。有一点需要特别注意，所有和string::npos的比较一定要用string::size_type来使用，不要直接使用int 或者unsigned int等类型。其实string::npos表示的是-1
* */
#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*过滤一行开头和结尾的所有非英文字符*/
int main1()
{

    string strinfo = "129387*//*//****/ Hello world 1230912830*/*";

    string strset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string::size_type first = strinfo.find_first_of(strset);
    if(first == string::npos)
    {
        cout << "no first "<< endl;
    }
    string::size_type last = strinfo.find_last_of(strset);
    if(last == string::npos)
    {
        cout << "no last " << endl;
    }
    cout << strinfo << endl;
    cout << strinfo.substr(first, last - first + 1) << endl;

    return 0;
}

/* "|" "," 为分隔符, 把每行分成对应的字段 过滤空格*/


//删除字符串
//str.erase(5);     从下标为5的地方删除之后元素
//str.erase(5, 3);  从下标为5的地方删除3个元素
int main()
{
    vector<string> vec;

    vec.push_back("张三|3456123,   湖南");
    vec.push_back("李四,6455725, 湖南");
    vec.push_back("王五, 4455253|湖南");
    
    string::size_type pos;
    for(int i = 0; i < vec.size(); i++)
    {
        while(1)
        {
            pos = vec[i].find(" ");    
            if(pos == string::npos)
                break;
            vec[i].erase(pos, 1);
        }

        while(1)
        {
            pos = vec[i].find("|");    
            if(pos == string::npos)
                break;
            vec[i][pos] = ' ';
        }

        while(1)
        {
            pos = vec[i].find(",");    
            if(pos == string::npos)
                break;
            vec[i][pos] = ' ';
        }
    }

    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }

    return 0;
}
