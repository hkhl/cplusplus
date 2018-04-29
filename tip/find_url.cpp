#include <iostream>
#include <algorithm>
using namespace std;

bool not_url_char(char c);
vector<string> find_urls(const string s);
string::const_iterator
url_end(string::const_iterator b, string::const_iterator e);
string::const_iterator
url_beg(string::const_iterator b, string::const_iterator e);


int main(int argc, char const* argv[])
{

    string strurl = "654asd521,.01https://www.baidu.com32/..";
    vector<string> str;
    str = find_urls(strurl);

    for (int i = 0; i < str.size(); i++) {
        cout << str[i] << endl;
    }

    return 0;
}



/*超找URL的后部分*/
string::const_iterator
url_end(string::const_iterator b, string::const_iterator e)
{
    return find_if(b, e, not_url_char);
}
bool not_url_char(char c)
{
    //除了字母数字以外,其他可能出现在一个URL中的字符
    static const string url_ch = "~;/?:@=&$-_.+!*;{},'";

    //看c是否能出现在一个URL中并返回求反的结果
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

/*查找URL的前部分*/
string::const_iterator
url_beg(string::const_iterator b, string::const_iterator e)
{
    static const string sep = "://";
    typedef string::const_iterator iter;

    //i标记了查找到的分隔符的位置
    iter i = b;
    while((i = search(i, e, sep.begin(), sep.end())) != e)
    {
        //确保分隔符不是本行中惟一的一个符号(确保分隔符的前后有字母)
        if (i != b && i + sep.size() != e) {
            //beg标记协议名称的开头
            iter beg = i;
            while (beg != b && isalpha(beg[-1])) {
                --beg;   //beg向前查找
            }
            //在分隔符前面和后面至少有一个字符吗?
            if (beg != i && i + sep.size() != e && !not_url_char(i[sep.size()])) {
                return beg;
            }
        }
        if (i != e) {
            i += sep.size();
        }
    }
    return e;
}

vector<string> find_urls(const string s)
{
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();

    //检查整个输入
    while (b != e) {
        //查找一个或者多个紧跟着://的字母
        b = url_beg(b, e);
        //如果查找成功
        if (b != e) {
            //获取此URL的其余部分
            iter after = url_end(b, e);

            //记录这个URL
            ret.push_back(string(b, after));

            //将b向前推进查找其他URL
            b = after;
        }
    }
    return ret;
}
