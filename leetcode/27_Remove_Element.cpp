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
    int removeElement(vector<int>& nums, int val)
    {
        int len = nums.size();
        if(len == 0)
        {
            return 0;
        }
        int res = 0;
        for(int i=0; i<len; ++i)
        {
            if(nums[i] != val)
            {
                if(i != res)
                {
                    nums[res] = nums[i];
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
    int arr[] = {0,0,1,1,1,2,2,3,3,4};
    //int arr[] = {1,1,2};
    vector<int> nums(begin(arr),end(arr));
    int res = so.removeElement(nums, 1);
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
