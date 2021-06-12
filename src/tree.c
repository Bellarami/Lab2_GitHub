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
        printPostOrder(node->left);
        printf("%s \n",node->data);
        printPostOrder(node->right);
    }
}

char *find_in_tree(Tree *t, char *word) {

    Node *elem = findNode(t->root, word);
    return (char *) elem->data;
    //TODO: Mirar si esta modificacion no afecta
}

Node* deleteNode(Node *root, char *word){
     // TO DO
    printf("putiisimo ansu");

     Node * node_to_delete = findNode(root,word);
     if (node_to_delete== NULL){
         return NULL;
     } else{

         if (node_to_delete->right==NULL && node_to_delete->left==NULL){ //Leaf

             free(node_to_delete);
         }
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

