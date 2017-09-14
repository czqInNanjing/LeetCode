//
// Created by Qiang Chen on 8/14/17.
//

#include <vector>
using namespace std;
//https://leetcode.com/problems/merge-k-sorted-lists/description/
//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(nullptr) {}
};
class No23_Hard_MergeKSortedLists {
    // 通过 简单的优化，可以使时间复杂度大幅下降， 归并排序的技巧   ， 使用优先队列会更快
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;

        return mergeWithPartion(lists, 0, lists.size() - 1);
    }
private:
    ListNode* mergeWithPartion(vector<ListNode*>& lists, int start, int end) {
        if(start == end )
            return lists[start];
        else {
            int mid = start + (end - start) / 2;
            ListNode *leftPart = mergeWithPartion(lists, start, mid);
            ListNode *rightPart = mergeWithPartion(lists, mid + 1, end);
            return mergeTwoLists(leftPart, rightPart);
        }
    }


    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(-1);
        ListNode* tail = &head;

        while( l1 && l2 ) {
            if( l1->val < l2->val )  {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return head.next;
    }

// 比较慢的方法 AC 249ms
//public:
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        if(lists.empty())
//            return nullptr;
//
//        ListNode* result = lists[0];
//
//        for(int i = 1 ; i < lists.size() ; ++i ) {
//            result = mergeTwoLists(result, lists[i]);
//        }
//
//        return result;
//    }
//private:
//    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//        ListNode head(-1);
//        ListNode* tail = &head;
//
//        while( l1 && l2 ) {
//            if( l1->val < l2->val )  {
//                tail->next = l1;
//                l1 = l1->next;
//            } else {
//                tail->next = l2;
//                l2 = l2->next;
//            }
//            tail = tail->next;
//        }
//
//        tail->next = l1 ? l1 : l2;
//        return head.next;
//    }
};