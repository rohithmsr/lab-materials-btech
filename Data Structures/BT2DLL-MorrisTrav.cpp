// https://www.codingninjas.com/codestudio/problems/893106
// Convert A Given Binary Tree To Doubly Linked List
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void flatten(BinaryTreeNode<int>* root, BinaryTreeNode<int>*& prev){
    if(root == NULL)
        return;
    BinaryTreeNode<int>* curr = root;
    
    while(curr){
        if(curr->left == NULL){
            prev->right = curr;
            curr->left = prev;
            prev = prev->right;
            
            curr = curr->right;
        }
        else{
            BinaryTreeNode<int>* temp = curr->left;
            while(temp->right != NULL && temp->right != curr){
                temp = temp->right;
            }
            
            if(temp->right == NULL){
                temp->right = curr;
                curr = curr->left;
            }
            else{
                temp->right = NULL;
                
                prev->right = curr;
                curr->left = prev;
                prev = prev->right;

                curr = curr->right;
            }
        }
    }
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* head = new BinaryTreeNode<int>(-1);
    BinaryTreeNode<int>* prev = head;
    
    flatten(root, prev);
    
    return head->right;
}
