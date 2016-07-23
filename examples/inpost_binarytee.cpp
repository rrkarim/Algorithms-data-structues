/**
    Inorder and postorder to the Binary tree
    Rasul Kerimov
*/

typedef vector<int> vi;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void build(int l1, int r1, int l2, int r2, TreeNode*& n, vi& inorder, vi& postorder) {
    if(l1 > r1) return;
    int root_value = postorder[r2];
    if(l1 == r1) {
        n = new TreeNode(root_value);
        return;
    }

    int m = -1;
    for(int i = l1; i <= r1; ++i) {
        if(inorder[i] == root_value) {
            m = i;
            break;
        }
    }
    int d = m - l1;
    n = new TreeNode(root_value);
    build(l1, m - 1, l2, l2 + d - 1, n->left, inorder, postorder);
    build(m + 1, r1, l2 + d, r2 - 1, n->right, inorder, postorder);
}


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    TreeNode * root;
    int l = 0, r = inorder.size() - 1;
    build(l, r, l, r, root, inorder, postorder);
    return root;
}