//
// Created by Qiang Chen on 02/08/2017.
//
//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}

};

class AddTwoInteger {

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0;
        ListNode* first = l1;
        int temp;
        ListNode* lastPointer = nullptr;
        while (l1 != nullptr && l2 != nullptr) {

            temp = l1->val + l2->val + carry;
            if(temp >= 10) {
                l1->val = temp - 10;
                carry = 1;
            } else {
                l1->val = temp;
                carry = 0;
            }
            lastPointer = l1;
            l1 = l1->next;
            l2 = l2->next;


        }

        l1 = lastPointer;
        int* carryPointer = &carry;
        if(l1->next != nullptr) {
            l1 = addTheRemainValue(l1, carryPointer);
        } else if (l2 != nullptr) {
            l1->next = l2;
            l1 = addTheRemainValue(l1, carryPointer);
        }

        if(*carryPointer) {
            l1->next = new ListNode(1);
        }

        return first;
    }

private:
    ListNode* addTheRemainValue(ListNode *l1, int* carryPointer) {
        int temp;
        while (l1->next != nullptr) {
            temp = *carryPointer + l1->next->val;
            if(temp >= 10) {
                l1->next->val = 0;
                *carryPointer = 1;
            } else {
                l1->next->val = l1->next->val + *carryPointer;
                *carryPointer = 0;
            }
            l1 = l1->next;
        }
        return l1;
    }

};