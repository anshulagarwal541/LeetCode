/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void getAns(vector<int>& answer, Node* root)
    {
        if(root)
        {
            for(int x=0;x<root->children.size();x++)
            {
                getAns(answer, root->children[x]);
            }
            answer.push_back(root->val);
        }
    }
    vector<int> postorder(Node* root) {
        vector<int> answer;
        getAns(answer, root);
        return answer;
    }
};