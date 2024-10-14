//题目描述:给定二叉搜索树（BST）的根节点 root 和一个整数值 val。
//你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null
//直接深搜即可
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func searchBST(root *TreeNode, val int) *TreeNode {
	var dfs func(node *TreeNode) *TreeNode
	dfs = func(node *TreeNode) *TreeNode {
		if node == nil {
			return nil
		}
		if node.Val == val {
			return node
		}
		if node.Val > val {
			if node.Left != nil {
				return dfs(node.Left)
			} else {
				return nil
			}
		}
		if node.Val < val {
			if node.Right != nil {
				return dfs(node.Right)
			} else {
				return nil
			}
		}
		return nil
	}
	return dfs(root)
}