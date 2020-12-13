#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
};

struct node *root = NULL;

void insert(int data) {

    struct node *tempNode = (struct node*) malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;

    //Inserting data into tempNode and making it's child NULL
    tempNode->data = data;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;

    //if tree is empty, create root node
    if(root == NULL) {
        root = tempNode;
    }else {
        current = root;
        parent = NULL;

        //Traversing to desire position
        while(1) {
            parent = current;
            //go to left of the tree if data is smaller than parent node
            if(data < parent->data) {
                current = current->leftChild;
                //insert to the left
                if(current == NULL) {
                    parent->leftChild = tempNode;
                    return;
                }
            }
            //go to right of the tree if data is bigger than parent node
            else {
                current = current->rightChild;
                //insert to the right
                if(current == NULL) {
                    parent->rightChild = tempNode;
                    return;
                }
            }
        }
    }
}

void inorderTraversal(struct node* root) { 

    if(root != NULL) {
        inorderTraversal(root->leftChild);
        printf("%d ",root->data);
        inorderTraversal(root->rightChild);
    }
}

void main() {
    int nodesNumber;
    int i;
    int data;

    printf("Enter number of nodes to enter in tree\n");
    scanf("%d", &nodesNumber);

    for (int i = 0; i < nodesNumber; i++) {
        printf("Enter data of %d node\n", (i + 1));
        scanf("%d",&data);
        insert(data);
    }

    printf("Printing values of Binary Tree in Inorder Fashion\n");
    inorderTraversal(root);

}