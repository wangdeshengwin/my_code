/* ************************************************************************
> File Name:     9_Palindrome_Number.cpp
> Author:        wangdesheng
> Mail:          wangdesheng2008@163.com
> Created Time:  2022年04月09日 星期六 22时33分45秒
> Description:
 ************************************************************************/
# include <iostream>
# include <vector>
# include <map>
# include <queue>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if(x == 0)
        {
            return true;
        }
        if(x <= 0)
        {
            return false;
        }
        if(x % 10 == 0)
        {
            return false;
        }
        int result = 0;
        while(x > result)
        {
            int tmp = x % 10;
            result = result * 10 + tmp;
            x = x / 10;
        }
        if(result == x)
        {
            return true;
        }
        else if(result / 10 == x)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution so;
    if(so.isPalindrome(121))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 1;
}
