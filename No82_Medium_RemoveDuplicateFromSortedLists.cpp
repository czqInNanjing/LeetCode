//
// Created by Qiang Chen on 8/17/17.
//
//Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
//For example,
//        Given 1->2->3->3->4->4->5, return 1->2->5.
//Given 1->1->1->2->3, return 2->3.

// 一般吧，不考虑回收内存的问题也可以的。。。。。
// 本来还想一个一个删的，后来出现了bug就偷懒了

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(nullptr) {}
};
class No82_Medium_RemoveDuplicateFromSortedLists {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return nullptr;

        ListNode fakeHead(-1);
        fakeHead.next = head;
        ListNode *last = &fakeHead;

        ListNode *cur = head->next;
        int tempVal = head->val;
        bool duplicateCount = 0;
        while( cur ) {
            if(cur->val == tempVal ) {
                duplicateCount = true;
            } else {
                if(duplicateCount) {
                    last->next = cur;
                    duplicateCount = 0;
                } else {
                    last = last->next;
                }
                tempVal = cur->val;
            }

            cur = cur->next;
        }
        if(duplicateCount) {
            last->next = cur;
        }
        return fakeHead.next;

    }
};