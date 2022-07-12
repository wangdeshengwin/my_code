/* ************************************************************************
> File Name:     26_Remove_Duplicates_from_Sorted_Array.cpp
> Author:        wangdesheng
> Mail:          wangdesheng2008@163.com
> Created Time:  2022年04月17日 星期日 12时01分20秒
> Description:
 ************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int haystack_len = haystack.length();
        int needle_len = needle.length();
        if(needle_len > haystack_len)
        {
            return -1;
        }
        if(haystack_len == 0 )
        {
            return -1;
        }
        for(int i=0; i<haystack_len; ++i)
        {
            int j=0;
            while(j < needle_len)
            {
                if(haystack[i+j] == needle[j])
                {
                    if(j == needle_len -1)
                    {
                        return i;
                    }
                    //cout<<j<<endl;
                    ++j;
                }
                else break;
            }
        }
        return -1;
    }
};
int main()
{
    cout<<"--------------begin---------------"<<endl;
    Solution so;
    //string haystack = "hello";
    //string needle = "ll";
    string haystack = "aaaaaa";
    string needle = "ab";
    //string haystack = "mississippi";
    //string needle = "mississippi";
    int ret = so.strStr(haystack,needle);
    cout<< "ret="<< ret;
    cout<<endl<<"---------------end----------------"<<endl;
}
