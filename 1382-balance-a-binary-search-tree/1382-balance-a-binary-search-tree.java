/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    private void traverse(TreeNode root , List<Integer> inorder){
        if(root.left == null && root.right == null) {
            inorder.add(root.val);
            return;
        }
        
        if(root.left != null) traverse(root.left, inorder);
        inorder.add(root.val);
        if(root.right != null) traverse(root.right, inorder);
    }
    
    private TreeNode createBTree(int left , int right , List<Integer> inorder){
        if(left > right) {
            return null;
        }
        
        int mid = left + (right - left) / 2;
        TreeNode newNode = new TreeNode(inorder.get(mid));
        
        newNode.left = createBTree(left , mid - 1, inorder);
        newNode.right = createBTree(mid + 1, right, inorder);
        
        return newNode;
    }
    
    
    public TreeNode balanceBST(TreeNode root) {
        List<Integer> inorder = new ArrayList();
        traverse(root , inorder);
        
        return createBTree(0, inorder.size() - 1, inorder);
    }
}