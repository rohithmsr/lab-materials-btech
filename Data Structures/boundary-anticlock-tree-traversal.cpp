// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    bool isLeaf(Node* root){
        if(root->left == NULL && root->right == NULL)
            return true;
        return false;
    }
    
    void addLeftNodes(vector<int>& res, Node* root)
    {
        Node* curr = root->left;
        
        while(curr){
            if(!isLeaf(curr))
                res.push_back(curr->data);
            
            if(curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }
    
    void addRightNodes(vector<int>& res, Node* root)
    {
        Node* curr = root->right;
        int start = res.size();
        
        while(curr){
            if(!isLeaf(curr))
                res.push_back(curr->data);
            
            if(curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        
        reverse(res.begin() + start, res.end());
    }
    
    void addBottomNodes(vector<int>& res, Node* root){
        if(root == NULL)
            return;
            
        if(root->left == NULL && root->right == NULL)
            res.push_back(root->data);
            
        addBottomNodes(res, root->left);
        addBottomNodes(res, root->right);
    }
    
public:
    vector <int> boundary(Node *root)
    {
        if(root == NULL)
            return {};
        if(isLeaf(root))
            return {root->data};
            
        vector<int> res;
        
        res.push_back(root->data);
        addLeftNodes(res, root);
        addBottomNodes(res, root);
        addRightNodes(res, root);
        
        return res;
    }
};
