/* ************************************************************************
> File Name:     14_Longest_Common_Prefix.cpp
> Author:        wangdesheng
> Mail:          wangdesheng2008@163.com
> Created Time:  2022年04月13日 星期三 22时46分30秒
> Description:
 ************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if(strs.size() == 0)
        {
            return "";
        }
        if(strs.size() == 1)
        {
            return strs[0];
        }
        if(strs.size() == 2)
        {
            return longestCommomStringPrefix(strs[0],strs[1]);
        }
        else
        {
            string res = longestCommomStringPrefix(strs[0],strs[1]);
            vector<string>::iterator iter = strs.begin();
            ++iter;
            ++iter;
            for(; iter!= strs.end(); ++iter)
            {
                res = longestCommomStringPrefix(res, *iter);
            }
            return res;
        }
    }
    string longestCommomStringPrefix(string str1, string str2)
    {
        string res="";
        for(int i =0 ; i < str1.length() && i<str2.length(); ++i)
        {
            if(str1[i] == str2[i])
            {
                res.append(1, str1[i]);
            }
            else
            {
                return res;
            }
        }
        return res;
    }
};
int main()
{
    Solution so;
    vector<string> strs;
    strs.push_back("dlower");
    strs.push_back("glow");
    strs.push_back("flight");
    cout<<so.longestCommonPrefix(strs)<<endl;
    return 1;
}
