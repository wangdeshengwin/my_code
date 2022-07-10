/* ************************************************************************
> File Name:     20_Valid_Parentheses.cpp
> Author:        wangdesheng
> Mail:          wangdesheng2008@163.com
> Created Time:  2022年04月16日 星期六 21时34分56秒
> Description:
 ************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        int len = s.length();
        if(len == 0)
        {
            return true;
        }
        if(len % 2 != 0)
        {
            return false;
        }
        stack<char> stk;
        for(int i=0; i<len; ++i)
        {
            if(s[i] == '('|| s[i] == '[' || s[i] == '{')
            {
                stk.push(s[i]);
            }
            else
            {
                if(stk.empty())
                {
                    return false;
                }
                if(s[i] == ')' && (stk.top() != '('))
                {
                    return false;
                }
                if(s[i] == ']' && (stk.top() != '['))
                {
                    return false;
                }
                if(s[i] == '}' && (stk.top() != '{') )
                {
                    return false;
                }
                stk.pop();
            }
        }
        if(stk.empty())
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
    string input1 = "";
    string input2 = "()";
    string input3 = "([])";
    string input4 = "([{])";
    cout<<input1<<":" << so.isValid(input1)<<endl;
    cout<<input2<<":" << so.isValid(input2)<<endl;
    cout<<input3<<":" << so.isValid(input3)<<endl;
    cout<<input4<<":" << so.isValid(input4)<<endl;
    return 0;
}
