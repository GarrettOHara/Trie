// SOURCE FILE

#include "trie_node.h"
#include <ios>
#include <iostream>

using namespace std;

/* CONSTRUCTOR */
trie_node::trie_node(bool isWord) {
    for(int i = 0; i < size; i++){
        this->character[i] = nullptr;
    }
}

/* OUT OF SCOPE HEAP ALLOCATION DELETION */
trie_node::~trie_node() {
    delete[] character;
}

/* SETTER */
void trie_node::setword(bool isWord){
    this->isWord = isWord;
}

void trie_node::insertme(string token){
    trie_node* node = this;
    for(int i = 0; i < token.length(); i++){
        if(node->character[token[i]] == NULL)
            node->character[token[i]] = new trie_node();
        
        node = node->character[token[i]];
    }
    node->setword(true);
}

int searchme(string token){
    return 0;
}
