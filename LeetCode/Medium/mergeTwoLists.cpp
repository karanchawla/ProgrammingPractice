#include <iostream>

using namespace std; 

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode* result;
    if(l1==nullptr)
        return result;
    else if(l2==nullptr)
        return result;
    
    if(l1->val <= l2->val)
    {
        result = l1;
        result->next = mergeTwoLists(l1->next, l2);
    }
    else 
    {
        result = l2;
        result->next = mergeTwoLists(l1, l2->next);
    }

    return result;
}