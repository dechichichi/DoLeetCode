//题目内容:给定一个整数数组，它表示BST(即 二叉搜索树 )的 先序遍历 ，构造树并返回其根。

//保证 对于给定的测试用例，总是有可能找到具有给定需求的二叉搜索树。

//二叉搜索树 是一棵二叉树，其中每个节点， Node.left 的任何后代的值 严格小于 Node.val, Node.right 的任何后代的值 严格大于 Node.val。

//二叉树的 前序遍历 首先显示节点的值，然后遍历Node.left，最后遍历Node.right

/*思路:按左右子树进行递归。
数组所在范围的首值为子树的根。
第一个比首值大的数值及其后为右子树，其前为左子树*/
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return fun(preorder, 0, preorder.size() - 1);
    }
    TreeNode* fun(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;
        int root = preorder[left];
        int mid = left;
        //寻找第一个比首值大的数值mid
        for (; mid <= right; mid++) {
            if (preorder[mid] > root) break;
        }
        TreeNode* node = new TreeNode(root);
        //mid之前的数值为左子树
        node->left = fun(preorder, left + 1, mid - 1);
        //mid及其之后的数值为右子树
        node->right = fun(preorder, mid, right);
        return node;
    }
};
