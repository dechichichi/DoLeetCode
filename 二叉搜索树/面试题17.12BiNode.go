//题目描述:
//二叉树数据结构TreeNode可用来表示单向链表（其中left置空，right为下一个链表节点）。实现一个方法，把二叉搜索树转换为单向链表，要求依然符合二叉搜索树的性质，转换操作应是原址的，也就是在原始的二叉搜索树上直接修改。
//返回转换后的单向链表的头节点。

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type Tree struct {
	node *TreeNode
	prt  *TreeNode
}

func convertBiNode(root *TreeNode) *TreeNode {
	var tree = &Tree{}
	tree.node = &TreeNode{}
	// tree.prt =tree.node;
	tree.TreeTo(root)
	return tree.node.Right
}
func (t *Tree) TreeTo(next *TreeNode) {
	if next == nil {
		return
	}
	t.TreeTo(next.Left)
	if t.prt == nil {
		t.prt = next
		t.node.Right = next
	} else {
		t.prt.Right = next
		t.prt = next
	}
	next.Left = nil
	t.TreeTo(next.Right)
}
