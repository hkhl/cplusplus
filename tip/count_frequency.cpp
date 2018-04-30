#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    map<string, int> count_words;
    map<int, vector<string> > count_frequency;

    while (cin >> str)
    {
        ++count_words[str];
    }

    map<string, int>::iterator it = count_words.begin();

    for (; it != count_words.end(); ++it)
    {
        count_frequency[it->second].push_back(it->first);
    }

    map<int, vector<string> >::iterator iit = count_frequency.begin();
    for (; iit != count_frequency.end(); ++iit)
    {
        cout << "frequency: " << iit->first << endl;
        for (int i = 0; i < iit->second.size(); ++i)
        {
            cout << iit->second[i] << " ";
        }
        cout << endl << endl;
    }


    return 0;
}
