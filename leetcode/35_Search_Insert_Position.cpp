/* ************************************************************************
> File Name:     27_Remove_Element.cpp
> Author:        wangdesheng
> Mail:          wangdesheng2008@163.com
> Created Time:  2022年04月19日 星期二 22时24分06秒
> Description: 二分查找法
 ************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int len = nums.size();
        if(len == 0)
        {
            return 0;
        }
        int res = 0;
        int left = 0;
        int right = len-1;
        int mid = (left+right)/2;
        while(left <= right)
        {
            cout<<"before:"<< " left="<<left<<" right=" << right<<" mid=" << mid << endl;
            int mid_value = nums[mid];
            if(mid_value == target)
            {
                return mid;
            }
            else if(mid_value < target)
            {
                // 查找后面
                left = mid + 1;
            }
            else
            {
                // 查找前面
                right = mid - 1;
            }
            mid = (left+right)/2;
            cout<<"after:"<< " left="<<left<<" right=" << right<<" mid=" << mid << endl;
        }
        res = left;
        return res;
    }
};
int main()
{
    cout<<"--------------begin---------------"<<endl;
    Solution so;
    int arr[] = {1,3,5,6};
    vector<int> nums(begin(arr),end(arr));
    //int res = so.searchInsert(nums, 5);
    int res = so.searchInsert(nums, 2);
    //int res = so.searchInsert(nums, 7);
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
