/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function (head) {
  let slow = head;
  let fast = head;

  while (fast && fast.next) {
    slow = slow.next;
    fast = fast.next.next;

    if (slow === fast) {
      return true;
    }
  }
  return false;
};
// var hasCycle = function (head) {
//   const set = new Set();

//   while (head) {
//     if (set.has(head)) {
//       return true;
//     }
//     set.add(head);
//     head = head.next;
//   }
//   return false;
// };
