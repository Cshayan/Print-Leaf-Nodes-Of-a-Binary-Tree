#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};
void showLeaf(struct node *root)
{
    if(root == NULL)
        return;
    if(root->left == NULL && root->right==NULL)
    {
        printf("%d\t",root->data);
        return;
    }

    showLeaf(root->left);
    showLeaf(root->right);
}
struct node* newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{

    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(8);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    // print leaf nodes of the given tree
   showLeaf(root);

    return 0;
}
