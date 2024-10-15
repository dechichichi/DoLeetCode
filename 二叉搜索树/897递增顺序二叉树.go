//解题思路:当我们遍历到一个节点时，把它的左孩子设为空，并将其本身作为上一个遍历到的节点的右孩子

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func increasingBST(root *TreeNode) *TreeNode {
	dummyNode := &TreeNode{} //答案的头节点 他的右孩子为递增序列的头节点
	resNode := dummyNode
	var dfs func(*TreeNode)
	dfs = func(node *TreeNode) {
		if node == nil {
			return
		}
		dfs(node.Left)
		resNode.Right = node
		node.Left = nil
		resNode = node
		dfs(node.Right)
	}
	dfs(root)
	return dummyNode.Right
}