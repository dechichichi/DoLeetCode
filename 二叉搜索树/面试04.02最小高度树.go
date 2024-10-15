//题目描述:给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，创建一棵高度最小的二叉搜索树
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sortedArrayToBST(nums []int) *TreeNode {
	var merge func(int, int) *TreeNode
	merge = func(Left int, Right int) *TreeNode {
		if Left > Right {
			return nil
		}
		if Left == Right {
			return &TreeNode{Val: nums[Left]}
		}
		Mid := Left + (Right-Left)/2
		node := &TreeNode{Val: nums[Mid]}
		node.Left = merge(Left, Mid-1)
		node.Right = merge(Mid+1, Right)
		return node
	}
	return merge(0, len(nums)-1)
}