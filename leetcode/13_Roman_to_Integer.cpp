/* ************************************************************************
> File Name:     13_Roman_to_Integer.cpp
> Author:        wangdesheng
> Mail:          wangdesheng2008@163.com
> Created Time:  2022年04月11日 星期一 22时40分11秒
> Description:
 ************************************************************************/
# include <iostream>
# include <string>
# include <map>
using namespace std;
class Solution
{
public:
    int romanToInt(string s)
    {
        int result = 0;
        int len = s.length();
        map<char, int> m_roman2int;
        m_roman2int['I'] = 1;
        m_roman2int['V'] = 5;
        m_roman2int['X'] = 10;
        m_roman2int['L'] = 50;
        m_roman2int['C'] = 100;
        m_roman2int['D'] = 500;
        m_roman2int['M'] = 1000;

        if(len== 0)
        {
            return result;
        }
        if(len == 1)
        {
            if(m_roman2int.count(s[0]))
            {
                return m_roman2int[s[0]];
            }
            else
            {
                return result;
            }
        }
        int i = 0;
        while(i<len)
        {
            if(i+1 < len)
            {
                int now_value = m_roman2int[s[i]];
                int next_value = m_roman2int[s[i+1]];
                if(now_value < next_value )
                {
                    result = result + next_value - now_value;
                    i += 2;
                }
                else
                {
                    result = result + now_value;
                    ++i;
                }
            }
            else
            {
                result = result + m_roman2int[s[i]];
                ++i;
            }
        }
        return result;
    }
};

int main()
{
    Solution so;
    string s = "MCMXCIV";
    cout<<so.romanToInt(s)<<endl;
    return 1;
}
