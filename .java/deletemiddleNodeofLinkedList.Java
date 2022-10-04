// Problem Link - https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteMiddle(ListNode head) {
        ListNode tempNode = head;
        int count = 0;
        while (tempNode != null){
            count++;
            tempNode = tempNode.next;
        }
        int mid = count/2;
        tempNode = head;
        if (count == 2){
            tempNode.next = null;
        }
        else if (count == 1){
            head = null;
        }
        else {
            int temp = 1;
            while (temp != mid) {
                temp++;
                tempNode = tempNode.next;
            }
            tempNode.next = tempNode.next.next;
        }
        return head;
    }
}
