//题目描述:给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
//如果树中有不止一个众数，可以按 任意顺序 返回

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var Max int = 0

func dfs(node *TreeNode, mp map[int]int) {
	if node == nil {
		return
	}
	dfs(node.Left, mp)
	mp[node.Val]++
	if mp[node.Val] > Max {
		Max = mp[node.Val]
	}
	dfs(node.Right, mp)
}

func findMode(root *TreeNode) []int {
	Max = 0                // 初始化 Max 为 0
	nums := make([]int, 0) // 初始化 nums 切片
	mp := make(map[int]int)
	dfs(root, mp)
	for i, j := range mp {
		if j == Max {
			nums = append(nums, i)
		}
	}
	return nums
}