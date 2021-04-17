/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    newHead = head->next;
    head->next = swapPairs(head->next->next);
    newHead->next = head;

    return newHead;
}