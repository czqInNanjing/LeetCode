//
// Created by Qiang Chen on 8/15/17.
//

//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//
//Only constant memory is allowed.
//
//For example,
//        Given this linked list: 1->2->3->4->5
//
//For k = 2, you should return: 2->1->4->3->5
//
//For k = 3, you should return: 3->2->1->4->5


// 这道题应该就是链表里面最难得题型了吧，然而我一次AC，强的一笔
// 说技巧也没啥技巧，就是假头部，递归，考虑转换之后原来的结构要怎么保证链表不断裂就可以了，稳如老狗
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class No25_Hard_ReverseKGroupLists {


public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *tail = head;
        ListNode fakeHead(-1);
        fakeHead.next = head;
        ListNode *lastTail = &fakeHead;
        int count = 0;
        while(tail) {
            count++;
            if(count == k) {
                reverseList(lastTail->next, tail);
                ListNode *temp = lastTail->next;
                lastTail->next = tail;
                lastTail = temp;
                tail = temp;
                count = 0;
            }

            tail = tail->next;

        }
        return fakeHead.next;


    }

    void reverseList(ListNode* head, ListNode* tail) {
        if( head == tail )
            return;
        reverseList(head->next, tail);
        ListNode *newNextTail = head->next;
        head->next = newNextTail->next;
        newNextTail->next = head;
    }




};
