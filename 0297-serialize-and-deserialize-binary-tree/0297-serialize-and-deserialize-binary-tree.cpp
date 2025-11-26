class Codec {
public:

    // Helper function for serialization
    void serializeHelper(TreeNode* root, string &result) {
        if (!root) {
            result += "# ";
            return;
        }
        result += to_string(root->val) + " ";
        serializeHelper(root->left, result);
        serializeHelper(root->right, result);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        serializeHelper(root, result);
        return result;
    }

    // Helper function for deserialization
    TreeNode* deserializeHelper(istringstream &ss) {
        string val;
        ss >> val;

        if (val == "#") return NULL;

        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(ss);
        node->right = deserializeHelper(ss);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return deserializeHelper(ss);
    }
};
