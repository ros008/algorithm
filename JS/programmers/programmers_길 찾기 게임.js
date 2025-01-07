class Node {
  constructor(index, valueX) {
    this.index = index;
    this.valueX = valueX;
    this.leftChild = null;
    this.rightChild = null;
  }

  addChild(index, valueX) {
    if (valueX < this.valueX) this.addLeft(index, valueX);
    else this.addRight(index, valueX);
  }

  addLeft(index, valueX) {
    if (this.leftChild) this.leftChild.addChild(index, valueX);
    else this.leftChild = new Node(index, valueX);
  }

  addRight(index, valueX) {
    if (this.rightChild) this.rightChild.addChild(index, valueX);
    else this.rightChild = new Node(index, valueX);
  }
}

function preOrder(tree, arr) {
  if (tree !== null) {
    arr.push(tree.index);
    preOrder(tree.leftChild, arr);
    preOrder(tree.rightChild, arr);
  }
}

function postOrder(tree, arr) {
  if (tree !== null) {
    postOrder(tree.leftChild, arr);
    postOrder(tree.rightChild, arr);
    arr.push(tree.index);
  }
}

function solution(nodeinfo) {
  var answer = [[]];
  const node = nodeinfo
    .map((n, i) => [n[0], n[1], i + 1])
    .sort((a, b) => b[1] - a[1]);

  const binaryTree = new Node(node[0][2], node[0][0]);

  for (let i = 1; i < node.length; i++)
    binaryTree.addChild(node[i][2], node[i][0]);

  let pre = [];
  preOrder(binaryTree, pre);

  let post = [];
  postOrder(binaryTree, post);

  return [pre, post];
}
