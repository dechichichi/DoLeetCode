//题目描述:给你一个整数数组nums ,其中元素已经按升序排列，请你将其转换为一棵平衡二叉树
//思路 将中间的点作为根节点 左边的为左子树 右边的为右子树 递归处理左右子树

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sortedArrayToBST(nums []int) *TreeNode {
	if len(nums) == 0 {
		return nil
	}
	if len(nums) == 1 {
		return &TreeNode{Val: nums[0]}
	}
	Left, Right := 0, len(nums)
	Mid := Left + (Right-Left)/2
	node := &TreeNode{Val: nums[Mid]}
	node.Val = nums[Mid]
	node.Left = sortedArrayToBST(nums[Left:Mid])
	node.Right = sortedArrayToBST(nums[Mid+1 : Right])
	return node
}