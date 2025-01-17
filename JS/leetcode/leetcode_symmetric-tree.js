/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var symmetricCheck = function (left, right) {
  if (!left && !right) return true;
  if ((!left && right) || (left && !right)) return false;
  if (left && right && left.val !== right.val) return false;
  return (
    symmetricCheck(left.left, right.right) &&
    symmetricCheck(left.right, right.left)
  );
};

var isSymmetric = function (root) {
  if (!root) return true;
  return symmetricCheck(root.left, root.right);
};
