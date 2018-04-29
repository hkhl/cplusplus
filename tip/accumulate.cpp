#include <iostream>
#include <vector>
#include <numeric>      //该头文件可以使用accumulate求和
using namespace std;

int main(int argc, char const* argv[])
{

    vector<double> v;
    v.push_back(1.1);
    v.push_back(1.1);
    v.push_back(1.1);
    v.push_back(1.1);
    v.push_back(1.1);


    //从1.1 开始求和   答案6.6
    double sum = accumulate(v.begin(), v.end(), 1.1);

    cout << sum << endl;

    return 0;
}
