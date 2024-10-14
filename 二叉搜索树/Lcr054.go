//题目:把二叉搜索树转换为累加树
//题目描述:给定一个二叉搜索树，请将它的每个节点的值替换成树中大于或者等于该节点值的所有节点值之和。

//思路:
//我们只需要反序中序遍历该二叉搜索树，记录过程中的节点值之和，并不断更新当前遍历到的节点的节点值，即可得到题目要求的累加树。

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func convertBST(root *TreeNode) *TreeNode {
	sum := 0 //sum记录累加和
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root != nil {
			dfs(root.Right)
			//sum的更新会从最右侧的节点开始
			sum += root.Val
			//更新sum
			root.Val = sum
			//sum更新节点值
			dfs(root.Left)
		}
	}
	dfs(root)
	return root
}

/*时间复杂度：O(n)，其中 n 是二叉搜索树的节点数。每一个节点恰好被遍历一次。

空间复杂度：O(n)，为递归过程中栈的开销，平均情况下为 O(logn)，最坏情况下树呈现链状，为 O(n)
*/