#include <iostream>
#include<string>
using namespace std;

class Bst{
/****************tree defination*/////////////////////////
public:
    int data;
    Bst* left;
    Bst* right;
    Bst(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
/********************function for inserting into tree*///////////////////////////
void insertIntoBinaryTree(Bst* &root,int data)
{
    if(!root||root->data==data)
    {
        root=new Bst(data);
    }else
    if(data<root->data)
       insertIntoBinaryTree(root->left,data);
    else
      insertIntoBinaryTree(root->right,data);


}
/*************************************code for finding maximum element in bst*/////////////////////
Bst* findMaxNodeInBst(Bst* root)
{
    if(!root->right)
        return root;
    else
        return findMaxNodeInBst(root->right);
}
/******************code to delete an element in an bst*/////////
void deleteNodeInBst(Bst* &root,int data)
{
    if(!root)
        return;
    else
        if(!root->left&&!root->right)
    {
        if(root->data==data)
       {
            free(root);
        root=NULL;
       }
       return;
    }
    else
        if(root->data==data)
        {
            if(root->left&&root->right)
            {
                Bst* maxleft=findMaxNodeInBst(root->left);
                root->data=maxleft->data;
                deleteNodeInBst(root->left,maxleft->data);
            }
            else
            {
                Bst* temp=root;
                if(!root->right)
                {
                    root=root->left;
                    free(temp);
                }
                else
                     if(!root->left)
                {
                    root=root->right;
                    free(temp);
                }
            }

        }
        else
        {
            deleteNodeInBst(root->left,data);
            deleteNodeInBst(root->right,data);
        }
}
void inOrderTraversal(Bst* root)
{
    if(!root)
        return;
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}
int main()
{

    int *arr,n,k;
    cin>>n>>k;
    arr=new int[n]();
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Bst *root,*max;
    root=new Bst(arr[0]);
    for(int i=1;i<k;i++)
        insertIntoBinaryTree(root,arr[i]);
  //  inOrderTraversal(root);
    for(int i=k;i<n;i++)
    {
        max=findMaxNodeInBst(root);
        if(arr[i]<max->data)
        {    //cout<<arr[i]<<endl;
            deleteNodeInBst(root,max->data);
            insertIntoBinaryTree(root,arr[i]);
        }
    }
    cout<<findMaxNodeInBst(root)->data;
    delete[] arr;
    return 0;
}













