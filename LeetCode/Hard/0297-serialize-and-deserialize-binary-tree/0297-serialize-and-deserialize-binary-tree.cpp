/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        build(root, s);
        return s;
    }
    void build(TreeNode* node, string& s) {
        if (!node) {
            s += "# ";
            return;
        }
        s += to_string(node->val) + " ";
        build(node->left, s);
        build(node->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return build(ss);
    }

    TreeNode* build(istringstream& ss) {
        string tok;
        ss >> tok;
        if (tok == "#")
            return nullptr;
        TreeNode* node = new TreeNode(stoi(tok));
        node->left = build(ss);
        node->right = build(ss);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));