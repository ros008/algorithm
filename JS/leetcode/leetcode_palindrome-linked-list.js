/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */

var reverseLinkedList = function (head) {
  let newHead = null;
  let pointer = head;
  while (pointer) {
    const tmp = pointer.next;
    pointer.next = newHead;
    newHead = pointer;
    pointer = tmp;
  }
  return newHead;
};

var isPalindrome = function (head) {
  if (!head || !head.next) return true;

  let slow = head;
  let fast = head;

  while (fast && fast.next) {
    slow = slow.next;
    fast = fast.next.next;
  }

  let reversed = reverseLinkedList(slow);

  while (reversed) {
    if (head.val !== reversed.val) return false;
    head = head.next;
    reversed = reversed.next;
  }

  return true;
};
