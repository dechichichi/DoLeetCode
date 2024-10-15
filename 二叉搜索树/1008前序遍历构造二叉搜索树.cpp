//��Ŀ����:����һ���������飬����ʾBST(�� ���������� )�� ������� �������������������

//��֤ ���ڸ����Ĳ��������������п����ҵ����и�������Ķ�����������

//���������� ��һ�ö�����������ÿ���ڵ㣬 Node.left ���κκ����ֵ �ϸ�С�� Node.val, Node.right ���κκ����ֵ �ϸ���� Node.val��

//�������� ǰ����� ������ʾ�ڵ��ֵ��Ȼ�����Node.left��������Node.right

/*˼·:�������������еݹ顣
�������ڷ�Χ����ֵΪ�����ĸ���
��һ������ֵ�����ֵ�����Ϊ����������ǰΪ������*/
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return fun(preorder, 0, preorder.size() - 1);
    }
    TreeNode* fun(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;
        int root = preorder[left];
        int mid = left;
        //Ѱ�ҵ�һ������ֵ�����ֵmid
        for (; mid <= right; mid++) {
            if (preorder[mid] > root) break;
        }
        TreeNode* node = new TreeNode(root);
        //mid֮ǰ����ֵΪ������
        node->left = fun(preorder, left + 1, mid - 1);
        //mid����֮�����ֵΪ������
        node->right = fun(preorder, mid, right);
        return node;
    }
};
