#include<stdio.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int val)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->left=ptr->right=NULL;
    return ptr;
}
struct node *insert(struct node *root,int val)
{
    if(root == NULL)
    {
        return create(val);
    }
    if(val < root->data)
    {
        root->left = insert(root->left,val);
    }else if(val > root->data)
    {
        return insert(root->right,val);
    }
    return root;
}
void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(struct node* root)
{
    if (root != NULL)
        {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
void postOrder(struct node* root)
 {
    if (root != NULL)
        {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
void display(struct node* root) {
    printf("Elements in the tree: ");
    inOrder(root);
    printf("\n");
}
int main() {
    struct node* root = NULL;
    int choice, value;

    do {
        printf("\nBinary Search Tree Menu:\n");
        printf("1. Insert element\n");
        printf("2. Display elements\n");
        printf("3. In-order traversal\n");
        printf("4. Pre-order traversal\n");
        printf("5. Post-order traversal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                display(root);
                break;
            case 3:
                printf("In-order traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Pre-order traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Post-order traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

