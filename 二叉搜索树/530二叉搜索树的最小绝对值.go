//题目描述:给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。差值是一个正数，其数值等于两值之差的绝对值。
//这题被判错了但是我不觉得我错了
// min 函数用于比较两个整数并返回较小的一个
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func dfs(node *TreeNode, Min *int) {
	if node == nil {
		return
	}
	if node.Left == nil && node.Right == nil {
		return
	}
	if node.Left == nil {
		node.Val = node.Right.Val - node.Val
		*Min = min(*Min, node.Val)
		dfs(node.Right, Min)
		return
	}
	if node.Right == nil {
		node.Val = node.Val - node.Left.Val
		*Min = min(*Min, node.Val)
		dfs(node.Left, Min)
		return
	}
	node.Val = min(node.Right.Val-node.Val, node.Val-node.Left.Val)
	*Min = min(*Min, node.Val)
	dfs(node.Left, Min)
	dfs(node.Right, Min)
}

func getMinimumDifference(root *TreeNode) int {
	Min := 100001 // 初始化 Min 为一个较大的数
	dfs(root, &Min)
	return Min
}