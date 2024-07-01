#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* findMax(struct Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

int height(struct Node* node) {
    if (node == NULL) {
        return -1;
    } else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }
}

int countLeaves(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else if (root->left == NULL && root->right == NULL) {
        return 1;
    } else {
        return countLeaves(root->left) + countLeaves(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, element;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("3. Postorder\n");
        printf("4. Inorder\n");
        printf("5. Search\n");
        printf("6. Show the Largest Element\n");
        printf("7. Show the Smallest Element\n");
        printf("8. Get the height of a Node\n");
        printf("9. Count the Nodes\n");
        printf("10. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                root = insert(root, element);
                printf("Element added.\n");
                break;

            case 2:
                printf("Preorder: ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("Postorder: ");
                postorderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Inorder: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                struct Node* result = search(root, element);
                if (result != NULL) {
                    printf("Element %d found.\n", element);
                } else {
                    printf("Oops! Element %d not found.\n", element);
                }
                break;

            case 6:
                if (root != NULL) {
                    struct Node* maxNode = findMax(root);
                    printf("The Largest Element is: %d\n", maxNode->key);
                } else {
                    printf("Tree is empty.\n");
                }
                break;

            case 7:
                if (root != NULL) {
                    struct Node* minNode = findMin(root);
                    printf("The Smallest Element is: %d\n", minNode->key);
                } else {
                    printf("Tree is empty.\n");
                }
                break;

            case 8:
               printf("enter the element to find the height\n");
                scanf("%d", &element);
                struct Node* nodeToFind = search(root, element);
                if (nodeToFind != NULL) {
                    int nodeHeight = height(nodeToFind);
                    printf("The Height of Node %d is: %d\n", element, nodeHeight);
                } else {
                    printf("Node not found.\n");
                }
                break;


            case 9:
                printf("Number of Leaf Nodes: %d\n", countLeaves(root));
                break;

            case 10:
                printf("Exiting...\n");
                exit(0);

            default:
              printf("invalid choice\n");
        }
    }

    return 0;
}





