//
// Created by Qiang Chen on 14/09/2017.
//

/*
 * 这道题很容易，但是在下面注释处有一个可能的bug，需要注意
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* smaller = new ListNode(0);
        ListNode* larger = new ListNode(0);

        ListNode* fakeS = smaller;
        ListNode* fakeL = larger;

        while(head) {
            if(head->val < x) {
                fakeS->next = head;
                fakeS = fakeS->next;
            } else {
                fakeL->next = head;
                fakeL = fakeL->next;
            }
            head = head->next;
        }
        // 一开始忘记将fake->next设为null导致了死循环。。。。。。。。
        // 这个bug极其难发现，使用链表的时候应该要注意处理收尾工作
        fakeL->next = nullptr;
        fakeS->next = larger->next;
        return smaller->next;

    }
};