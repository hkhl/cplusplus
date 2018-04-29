#include <iostream>
using namespace  std;

bool is_pailndrome(const string &s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}

int main()
{
    string str = "abcdfdcba";

    printf("%d", is_pailndrome(str));

    return 0;
}


