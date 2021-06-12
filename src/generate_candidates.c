#include "generate_candidates.h"

void candidates_by_substitution(char *word, Tree *dictionary, Tree *suggestions) {
    // TO DO
    char *candidate;
    int l= strlen(word);
    char c;
    int i;
    for(i=0; i < l ; i++) {
        candidate = (char*)malloc((l)*sizeof(char));
        strcpy(candidate,word);
        for (c = 'a'; c <= 'z'; c++) {
            candidate[i]=c;
            if(find_in_tree(dictionary,candidate)) {
                insert_into_tree(suggestions,candidate);
            }
        }
    }
}


void candidates_by_insertion(char *word, Tree *dictionary, Tree *suggestions) {


    // TO DO

}


void candidates_by_swapping(char *word, Tree *dictionary, Tree *suggestions) {


    // TO DO

}

void candidates_by_deletion(char *word, Tree *dictionary, Tree *suggestions) {

    // TO DO
}

void generate_candidates(char *word, Tree *dictionary, Tree *substitutes) {
    init_tree(substitutes);
    candidates_by_substitution(word, dictionary, substitutes);
    candidates_by_insertion(word, dictionary, substitutes);
    candidates_by_swapping(word, dictionary, substitutes);
    candidates_by_deletion(word, dictionary, substitutes);
}