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
}

bool insert_into_tree(Tree *t, char *word) {
    // TO DO
    if (findNode(t->root,word) ==NULL){
        insertNode(t->root,word);
        return true;
    }
    return false;
}

void printPreOrder(Node *node) {
     // TO DO
}

void printPostOrder(Node *node) {
    // TO DO
}


void printInOrder(Node *node) {
    // TO DO
}

char *find_in_tree(Tree *t, char *word) {

    Node *elem = findNode(t->root, word);
    return &elem->data;
}

Node* deleteNode(Node *root, char *word){

     // TO DO
}

int size_tree(Tree *t) {
    printf("Printing size...\n");
    return t->size;
}

void print_tree(Tree *t) {

    // TO DO
}

