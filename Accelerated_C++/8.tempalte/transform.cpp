#include <iostream>
#include <vector>
using namespace std;

int change(char ch)
{
    ch = ch - 'A' + 'a';
    return ch;
}

template <class In, class Out, class Predict>
Out transform(In begin, In end, Out dest, Predict p)
{
    while (begin != end)
    {
        *dest++ = p(*begin);
        begin++;
    }
    return dest;
}

int main()
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
    return 0;
}

