#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> u;
    u.push_back(1);
    u.push_back(2);
    u.push_back(3);
    u.push_back(4);
    u.push_back(5);
    //u.insert(u.begin(), 1);         //头部插入元素

    vector<int> v(1);
    v[0] = 9;

    //copy(u.begin(), u.end(), v);   //失败, v并没有空间
    //copy(u.begin(), u.end(), back_inserter(v));       //结果912345
    //copy(u.begin(), u.end(), inserter(v, v.begin())); //结果123459
    //copy(u.begin(), u.end(), front_inserter(v));      //向量不支持fron_inserter 否则结果为543219

    /*
    //inserter是迭代器版本的insert(底层调用insert)  insert是插入元素
     * back_inserter(container);   //从尾巴插入元素
     * front_inserter(container);  //从头部插入元素
     * inserter(continer, pos);    //在pos位置插入元素
     */

    vector<int>::iterator it = v.begin();

    for (; it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}
