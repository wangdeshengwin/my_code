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
    int removeDuplicates(vector<int>& nums)
    {
        int n_size = nums.size();
        if(n_size == 0 || n_size == 1)
        {
            return n_size;
        }
        int i_front = 0;
        for(int i = 1; i < n_size; ++i)
        {
            if(nums[i_front] !=  nums[i])
            {
                ++i_front;
                nums[i_front] = nums[i];
            }
        }
        return ++i_front;
    }
};
int main()
{
    cout<<"--------------begin---------------"<<endl;
    Solution so;
    //int arr[] = {0,0,1,1,1,2,2,3,3,4};
    int arr[] = {1,1,2};
    vector<int> nums(begin(arr),end(arr));
    int res = so.removeDuplicates(nums);
    cout<<"[res]="<<res<<endl;
    for(int i=0; i< nums.size(); ++i)
    {
        if(i< res)
        {
            cout<< nums[i]<<" ";
        }
        else
        {
            cout<<"_ ";
        }
    }
    cout<<endl<<"---------------end----------------"<<endl;
}
