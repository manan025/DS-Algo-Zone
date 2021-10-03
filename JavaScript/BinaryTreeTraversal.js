/**
 * @description Tree Traversal (Preorder, Inorder, Postorder)
 * @author prasanna kale
 * @language Javascript
 */
class TreeNode {
    constructor(val, left, right) {
        this.val = (val === undefined) ? 0 : val;
        this.left = (left === undefined) ? null : left;
        this.right = (right === undefined) ? null : right;
    }
}

/**
 * @order root -> left -> right
 * @param {TreeNode} root 
 */
function preorder(root){
    if (root){
        console.log(root.val)
        preorder(root.left)
        preorder(root.right)
    }
}

/**
 * @order left -> root -> right
 * @param {TreeNode} root
 */
function inorder(root){
    if (root){
        inorder(root.left)
        console.log(root.val)
        inorder(root.right)
    }
}


/**
 * @order left -> right -> root
 * @param {TreeNode} root
 */
function postorder(root){
    if (root){
        postorder(root.left)
        postorder(root.right)
        console.log(root.val)
    }
}

/**
 * @example
 */
let myTree = new TreeNode(1)
myTree.left = new TreeNode(2)
myTree.right = new TreeNode(3)
myTree.left.left = new TreeNode(4)
myTree.left.right = new TreeNode(5)
myTree.right.left = new TreeNode(6)
myTree.right.right = new TreeNode(7)

/**                 Tree Structure
 *                      1
 *                  |       |
 *                  2       3
 *                |   |   |   |     
 *                4   5   6   7
 */


preorder(myTree)
/**
 * @output preorder
 * 1 2 4 5 3 6 7
 */

inorder(myTree)
/**
 * @output for inorder
 * 4 2 5 1 6 3 7
 */

postorder(myTree)
/**
 * @output for postorder
 * 4 5 2 6 7 3 1
 */


/**
 * @Complexity-analysis
 * Time-complexity = O(n)   // for visiting all nodes  
 * Space-complexity = O(n)  // recursion stack space
 */
