#include <iostream>
#include <stack>
using namespace std;


struct BiTree{
    int val;
    BiTree* left;
    BiTree* right;
    BiTree(int v=0, BiTree* l=NULL, BiTree* r = NULL):val(v),left(l),right(r){}
};

/**
 * 前序遍历
 *
 * 使用一个stack，先把右孩子入栈，然后左孩子入栈，
 */
void preorder(BiTree* root)
{
    stack<BiTree*> stk;
    stk.push(root);
    while( ! stk.empty()){
        BiTree* cur = stk.top();
        stk.pop();

        cout<<cur->val;
        if(cur->right!= NULL)
            stk.push(cur->right);
        if(cur->left!= NULL)
            stk.push(cur->left);
    }
}

/**
 * 中序遍历
 *
 * 使用栈，保存一个当前节点指针cur，如果cur不为空，入栈并移动到左孩子
 *
 * 如果cur为空，则输出栈顶元素，并将cur移动到右孩子
 *
 */
void inorder(BiTree* root)
{
    stack<BiTree*> stk;
    BiTree* cur = root;
    while( cur != NULL || ! stk.empty())
    {
        if(cur != NULL){
            stk.push(cur);
            cur = cur->left;
        }
        else{
            cur = stk.top();
            stk.pop();
            cout<<cur->val;
            cur = cur->right;
        }

    }
}

/**
 * 使用两个stack，
 *
 * 首先将根入栈，然后stack 1 按照 左孩子，右孩子入栈，将每次出栈的元素依次压入stack 2中
 * 这样在stack 2中的顺序就是 跟，右孩子，左孩子
 *
 * 最后依次输出stack 2中元素
 */
void postorder(BiTree* root)
{
    stack<BiTree*> stk1, stk2;
    stk1.push(root);
    while( ! stk1.empty())
    {
        BiTree* cur = stk1.top();
        stk1.pop();

        stk2.push(cur);

        if(cur->left != NULL)
            stk1.push(cur->left);
        if(cur->right != NULL)
            stk1.push(cur->right);


    }

    while( !stk2.empty())
    {
        BiTree* cur = stk2.top();
        stk2.pop();
        cout<<cur->val;
    }
}

