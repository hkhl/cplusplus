#include <iostream>
#include <vector>
//#include <algorithm>

using namespace std;


//search 查找子元素
template <class In1, class In2>
In1 search(In1 abegin, In1 aend, In2 bbegin, In2 bend)
{
    while (abegin != aend)
    {
        if (equal(bbegin, bend, abegin))
            return abegin;
        abegin++;


/*     或者
 *        In1 s = abegin;
 *        In2 t = bbegin;
 *
 *        while( t != bend )
 *        {
 *            if (*t != *s)
 *                break;
 *            t++;
 *            s++;
 *        }
 *        if(t == bend)
 *            return abegin;
 *        abegin++;
 */
    }
    return aend;
}


int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(6);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(7);
    v.push_back(123);

    vector<int> vserc;
    vserc.push_back(6);
    vserc.push_back(4);

    //search  找到元素存在于vsearch中的元素
    cout << *(search(v.begin(), v.end(), vserc.begin(), vserc.end())) << endl;
    return 0;
}
