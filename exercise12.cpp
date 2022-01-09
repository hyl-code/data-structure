#include <iostream>
using namespace std;

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTNode* buildTreePI(int preorder[], int inorder[], int pre_start, int pre_end, int in_start, int in_end){
    if(pre_start > pre_end){
        return NULL;
    }
    BiTree T = new BiTNode;
    T->data = preorder[pre_start];
    int root_index = in_start;
    for(int i = in_start; i <= in_end; i++){
        if(inorder[i] == preorder[pre_start]){
            root_index = i;
            break;
        }
    }
    int leftNum = root_index - in_start;
    T->lchild = buildTreePI(preorder, inorder, pre_start + 1, pre_start + leftNum, in_start, root_index-1);
    T->rchild = buildTreePI(preorder, inorder, pre_start + leftNum + 1, pre_end, root_index+1, in_end);
    return T;
}

void showpreorder(BiTree T){
    if(T){
        cout << T->data << " ";
        showpreorder(T->lchild);
        showpreorder(T->rchild);
    }   
}

int main(){
    int preorder[9] = {1,2,4,5,8,3,6,9,7};
    int inorder[9] = {4,2,8,5,1,6,9,3,7};
    BiTree T = new BiTNode;
    T->lchild = NULL;
    T->rchild = NULL;
    T = buildTreePI(preorder, inorder, 0, 8, 0, 8);
    showpreorder(T);
}
