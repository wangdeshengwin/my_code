/* ************************************************************************
> File Name:     21_Merge_Two_Sorted_Lists.cpp
> Author:        wangdesheng
> Mail:          wangdesheng2008@163.com
> Created Time:  2022年04月16日 星期六 11时29分06秒
> Description:
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
 * Definition for singly-linked list.
**/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if(list1 == nullptr && list2 == nullptr)
        {
            return nullptr;
        }
        else if(list1 == nullptr)
        {
            return list2;
        }
        else if(list2 == nullptr)
        {
            return list1;
        }
        else
        {
            if(list1->val < list2->val)
            {
                list1->next = mergeTwoLists(list1->next, list2);
                return list1;
            }
            else
            {
                list2->next = mergeTwoLists(list1, list2->next);
            }
            return list2;
        }
    }
};


int main()
{
    ListNode *list1_now, *list2_now, *list1_head, *list2_head;
    int list1_length, list2_length;
    Solution so;
    //////////list1/////////////
    cin >> list1_length;
    list1_head = list1_now = new ListNode(0);
    for (int i = 0; i < list1_length; i++)
    {
        list1_now->next = new ListNode(0);
        list1_now = list1_now->next;
        scanf("%d", &(list1_now->val));
    }
    //////////list2/////////////
    cin >> list2_length;
    list2_head = list2_now = new ListNode(0);
    for (int i = 0; i < list2_length; i++)
    {
        list2_now->next = new ListNode(0);
        list2_now = list2_now->next;
        scanf("%d", &(list2_now->val));
    }
    //////////result/////////////
    ListNode *result = so.mergeTwoLists(list1_head->next, list2_head->next);
    while (result != NULL)
    {
        cout << result->val << ' ';
        result = result->next;
    }
    return 0;
}
