/*************************************************************************
	> File Name: 4-9.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月08日 星期日 21时04分14秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
/*
const_iterator 对象可以用于 const vector 或非 const vector，
因为不能改写元素值。const 迭代器这种类型几乎没什么用处：
一旦它被初始化后，只能用它来改写其指向的元素，但不能使它指向任何其他元素。
*/
/*
1、const_iterator需要注意：这个vector本身还是可变的，只不过对const_iterator类型解引用的对象不可变。
2、const迭代器也就是只能指向其所指向的元素，不能通过++等操作去指向其他元素。但是，所指向这个元素可以改变。
*/

    vector<int> v(2,5);

    const vector<int>::iterator cit = v.begin();
    //迭代器的指向永远是v.begin不能更改迭代器不可++操作.  其他无限制
    //cit++;   error
    cout << *cit << endl; //5
    *cit = 1;             //ok
    cout << *cit << endl; //1

    
    vector<int>::const_iterator iter = v.begin();
    //迭代器可以++, 但是内部的int类型数据值无法更改 只能对数据进行读操作


    //我们知道 v.begin返回类型是 iterator 
    //而iter是 const_iterator类型
    //系统会把iterator类型隐式转换为 const_iterator
    //但是反过来则不行(同普通const一样, non-const可以赋值给const)

    for(; iter != v.end(); iter++)
    {
        cout << *iter << " " << endl;  
        // 1
        // 5
        //*iter = 6;  error
    }


    return 0;
}
