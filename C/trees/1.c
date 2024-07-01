/*creation and traversal using trees*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
} *root;
/*creation of node*/
struct node *create(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
}
/*preorder traversal*/
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right); 
    }
}
/*postorder traversal*/
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->data);
    }
}
/*inorder traversal*/
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}
/*searching*/
struct node *search(struct node *root, int key)
{
    while (root != NULL)
    {
        {
            if (key == root->data)
            {
                printf("found:%d\n", key);
                break;
            }
            else if (key < root->data)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
    }
}
int main()
{
    struct node *p = create(5);
    struct node *p1 = create(3);
    struct node *p2 = create(6);
    struct node *p3 = create(2);
    struct node *p4 = create(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    int choice, value;
    do
    {
        printf("MENU\n");
        printf("1.PREORDER\n");
        printf("2.POSTORDER\n");
        printf("3.INORDER\n");
        printf("4.SEARCH\n");
        printf("enter ur choice:\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            preorder(p);
            printf("\n");
            break;

        case 2:
            postorder(p);
            printf("\n");
            break;

        case 3:
            inorder(p);
            printf("\n");
            break;

        case 4:
            printf("enter number u want to search\n");
            scanf("%d", &value);
            search(p, value);
            break;
        }

    } while (choice != 7);
}