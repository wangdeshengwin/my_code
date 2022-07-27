/* ************************************************************************
> File Name:     27_Remove_Element.cpp
> Author:        wangdesheng
> Mail:          wangdesheng2008@163.com
> Created Time:  2022年04月19日 星期二 22时24分06秒
> Description:
 ************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int len = s.length();
        if(len == 0)
        {
            return 0;
        }
        int res = 0;
        int flag = 1;
        for(int i =0 ; i < len ; ++i)
        {
            if(s[i] == ' ')
            {
                flag = 1;
            }
            else
            {
                if(flag == 1)
                {
                    res = 0;
                    flag = 0;
                }
                ++res;
            }
        }
        return res;
    }
};
int main()
{
    cout<<"--------------begin---------------"<<endl;
    Solution so;
    int res = so.lengthOfLastWord("luffy is still joyboy");
    cout<<"[res]="<<res<<endl;
    cout<<endl<<"---------------end----------------"<<endl;
}
