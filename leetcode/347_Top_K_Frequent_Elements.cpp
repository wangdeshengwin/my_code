/* ************************************************************************
> File Name:     347_Top_K_Frequent_Elements.cpp
> Author:        wangdesheng
> Mail:          wangdesheng2008@163.com
> Created Time:  2022年04月09日 星期六 16时48分54秒
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
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> m_value2count;
        for(vector<int>::iterator  iter = nums.begin(); iter != nums.end(); ++iter)
        {
            int value = *iter;
            if(m_value2count.count(value))
            {
                m_value2count[value] += 1;
            }
            else
            {
                m_value2count[value] = 1;
            }
        }
        priority_queue<pair<int, int> > pq_count2value;
        for(map<int, int>::iterator iter = m_value2count.begin(); iter != m_value2count.end(); ++iter)
        {
            pq_count2value.push(make_pair(iter->second, iter->first));
        }
        vector<int> res;
        for(int i = 0; i < k; ++i)
        {
            res.push_back(pq_count2value.top().second);
            pq_count2value.pop();
        }
        return res;
    }
};

int main()
{
    Solution so;
    int k = 2;
    vector<int> num_vec;
    num_vec.push_back(1);
    num_vec.push_back(1);
    num_vec.push_back(1);
    num_vec.push_back(2);
    num_vec.push_back(2);
    num_vec.push_back(3);
    vector<int> result =  so.topKFrequent(num_vec, k);
    for(int i = 0; i < result.size(); ++i)
    {
        std::cout << result[i] << std::endl;
    }
    return 1;
}
