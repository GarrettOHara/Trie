#include "trie_node.h"
#include <iostream>

using namespace std;

trie_node::trie_node(){                       // CONSTRUCTOR
    this->isWord = false;
    for(int i = 0; i < size; i++){
        character[i] = NULL;
    }
}

void trie_node::insertme(string token){
    trie_node* node = this;
    for(int i = 0; i < token.length(); i++){
        if(node->character[token[i]] == NULL)
            node->character[token[i]] = new trie_node();
        
        node = node->character[token[i]];
    }
    node->isWord = true;
}

int trie_node::searchme(string token){
    if(this==NULL)
        return 0;
    
    int count = 0;    
    trie_node* node = new trie_node();

    return 0;

}
