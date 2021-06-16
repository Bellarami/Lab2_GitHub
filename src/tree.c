#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "utils.h"
#include "commons.h"
#include "tree.h"


void init_tree(Tree *t) {
    t->root = NULL;
    t->size = 0;
//    printf("Initialized...\n");
}

void clearPostOrder(Node *node) {
    //TODO: esto
    if (node==NULL){
        return;
    }else{
        clearPostOrder(node->left);
        clearPostOrder(node->right);
        free(node);
    }
   // TO DO
}

void clear_tree(Tree *t) {
    clearPostOrder(t->root);
    init_tree(t);
}

Node *createNode(char *word) {

    Node *newNode = (Node *) malloc(sizeof(Node));
    strcpy(newNode->data, word);
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


Node *insertNode(Node *node, char *word) {
    if (node == NULL) {
        node = createNode(word);
    } else {

        if (strcmp(word, node->data) > 0) {

            Node *new_node = insertNode(node->right,word);
            node->right = new_node;

        } else if (strcmp(word, node->data) < 0) {
            Node *new_node = insertNode(node->left,word);
            node->left = new_node;
        }
    }

    return node;
}

Node *findNode(Node *node, char *word) {
       // TO DO
    if (node == NULL) {
        return node;
    } else {

        if(node->data== word){
            return node;
        }else if (strcmp(word, node->data) > 0) {
            node = findNode(node->right,word);

        } else if (strcmp(word, node->data) < 0) {
            node = findNode(node->left,word);

        }
    }
    return node;
}

bool insert_into_tree(Tree *t, char *word) {
    // TO DO

    if (findNode(t->root,word) ==NULL){
        t->root = insertNode(t->root,word);
        t->size++;
        return true;
    }
    return false;
}

void printPreOrder(Node *node) {
     // TO DO
     if (node==NULL){
         return;
     } else{
         printf("%s \n", node->data);
         printPreOrder(node->left);
         printPreOrder(node->right);
     }
}

void printPostOrder(Node *node) {
    // TO DO
    if (node==NULL){
        return;
    }else{
        printPostOrder(node->left);
        printPostOrder(node->right);
        printf("%s \n",node->data);
    }
}


void printInOrder(Node *node) {
    // TO DO

    if (node==NULL){
        return;
    }else{
        printInOrder(node->left);
        printf("%s \n",node->data);
        printInOrder(node->right);
    }
}

char *find_in_tree(Tree *t, char *word) {

    Node *elem = findNode(t->root, word);
    return (char *) elem->data;
    //TODO: Mirar si esta modificacion no afecta
}

Node* deleteNode(Node *root, char *word){
     // TO DO



    Node* new_node=NULL;
    if (root == NULL) {
        printf("It doesn't belong to this dictionary");

    } else {

        if (strcmp(word, root->data) > 0) {

            new_node = deleteNode(root->right,word);
            root->right = new_node;
            return root;

        } else if (strcmp(word, root->data) < 0) {
            new_node = deleteNode(root->left,word);
            root->left = new_node;
            return root;
        } else{  // lo ha encontrado

            if (root->right==NULL && root->left==NULL){ //Leaf
                free(root);
                new_node = NULL;
            } else if (root->right!=NULL && root->left==NULL){ //ARBOL SOLO EN LA DERECHA
                new_node= root->right;
                free(root);

            } else if (root->left!=NULL && root->right==NULL) { //ARBOL SOLO EN LA IZQUIERDA
                new_node = root->left;
                free(root);
            } else if (root->right!=NULL && root->left!=NULL){ //TIENE DOS HIJOS ROOT

                printf("\n CUIDADO BRO ahi vienee!!!\n");
                Node *temp=getMinimum(root->left);

                new_node= createNode(temp->data);
                new_node->left=root->left;
                new_node->right=root->right;


                deleteNode(root,temp->data);
                free(root);
            }

        }
    }

    return new_node;

}
Node* getMinimum(Node* node ){
    char * curr=node->data;
    char* next= node->right->data;
    if (node->right==NULL){
        return node;
    } else{
        return getMinimum(node->right);
    }


}
int size_tree(Tree *t) {
    printf("Printing size...\n");
    return t->size;
}

void print_tree(Tree *t) {
    // TO DO
    if (t->size>0){
        printInOrder(t->root);
    }else{
        printf("The dictionary is empty!\n");
    }
}

