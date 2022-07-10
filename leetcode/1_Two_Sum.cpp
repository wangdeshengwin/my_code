/* ************************************************************************
> File Name:     1_Two_Sum_mx.cpp
> Author:        wangdesheng
> Mail:          wangdesheng2008@163.com
> Created Time:  2022年04月09日 星期六 11时13分16秒
> Description:
 ************************************************************************/
#include <iostream>
#include <vector>
#include <map>

using std::vector;
using  std::map;


class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> m_value2index;
        for(int i = 0; i < nums.size(); ++i)
        {
            m_value2index[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(m_value2index.count(target - nums[i]) && (i != m_value2index[target - nums[i]]))
            {

                return { i, m_value2index[target - nums[i]]};
            }
        }
        return {};
    }
};


int main()
{
    Solution so;
    vector<int> num_vec;
    num_vec.push_back(3);
    num_vec.push_back(2);
    num_vec.push_back(4);
    //num_vec.push_back(1);
    int target = 6;
    vector<int> result =  so.twoSum(num_vec, target);
    for(int i = 0; i < result.size(); ++i)
    {
        std::cout << result[i] << std::endl;
    }
    return 1;
}
