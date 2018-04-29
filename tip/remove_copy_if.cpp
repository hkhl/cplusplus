#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



//remove_copy_if   ""删除""满足谓词条件的元素

int handle(int num)
{
    if (num >= 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int iszero(int num)
{
    if (num == 0) {
        return 1;
    }
    else {
        return 0;
    }
}



int main(int argc, char const* argv[])
{
    vector<int> v;
    vector<int> newv;

    v.push_back(-1);
    v.push_back(-2);
    v.push_back(-3);
    v.push_back(-4);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);


    //删除满足handle处理条件的
    remove_copy_if(v.begin(), v.end(), back_inserter(newv), iszero);

    for (int i = 0; i < newv.size(); i++) {
        cout << newv[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    std::cout << std::endl;


    //删除并给自己赋值   [remove_if]
    //将满足条件的删除掉. 将后续的数字放在前面被删除的位置
    //remove_if 返回最后一个没有被删除的元素的后一个位置
    //加上 v.erase(remove_if(), v.end()) 删除最后几个没用的数字
    v.erase(remove_if(v.begin(), v.end(),  iszero), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
