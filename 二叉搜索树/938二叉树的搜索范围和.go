//题目描述 给定二叉搜索树的根结点 root，返回值位于范围 [low, high] 之间的所有结点的值的和。
//思路 直接遍历整个节点即可 若当前节点值小于Low 只递归右子树 若当前节点值大于High 只递归左子树
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func rangeSumBST(root *TreeNode, low int, high int) int {
	var dfs func(*TreeNode)
	ans := 0
	dfs = func(node *TreeNode) {
		if node == nil {
			return
		}
		if node.Val < low {
			dfs(node.Right)
			return
		}
		if node.Val > high {
			dfs(node.Left)
			return
		}
		ans += node.Val
		dfs(node.Left)
		dfs(node.Right)
	}
	dfs(root)
	return ans

}