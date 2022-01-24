// SOURCE FILE

#include "trie_node.h"
#include <ios>
#include <iostream>
//#define size = 27

using namespace std;

/* CONSTRUCTOR */
trie_node::trie_node(bool isWord) {
    for(int i = 0; i < size; i++){
        this->character[i] = nullptr;
    }
}

/* DECONSTRUCTOR */
trie_node::~trie_node() {
    //cout << "DECONSTRUCTING NODE" << endl;
    for(int i = 0; i < size; i++){
        if(character[i]!=nullptr)
            delete character[i];
    }
}

/* SETTER */
void trie_node::setword(bool isWord){
    this->isWord = isWord;
}

/* GETTER */
bool trie_node::getword(){
    return this->isWord;
}

// trie_node trie_node::getnode(char ch){
//     return this->character[ch];
// }

/* INSERT WORD */
void trie_node::insertme(string token){
    trie_node* node = this;
    for(int i = 0; i < token.length(); i++){
        
        /* PROCESS CHARACTER */
        char tmp = token[i];
        if(tmp == 39){
            tmp = size-1;
        } else {
            tmp = tolower(token[i])-'a';
        }

        /* CONSTRUCT NEW NODE IF NULL */
        if(node->character[tmp] == nullptr){
            node->character[tmp] = new trie_node();
        }
        
        /* MOVE TO NEW NODE */
        node = node->character[tmp];
    }
    
    /* SET END OF WORD */
    node->setword(true);
}

/* COUNT WITH DEPTH FIRST SEARCH */
int trie_node::DFS(trie_node root, char ch, int count){

    if(root.getword())
        count++;
    
    for(int i = 0; i < 27; i++){
        char ch = i;
        if(root.character[ch]!=nullptr){
            root = root.character[ch];
            trie_node::DFS(root, ch, count);
        }
    }

    return count;

    // /* BASE CASE */
    // if(root == nullptr) return count;

    // /* WORD FOUND... CONTINUE */
    // else if(root.getword())
    //     return trie_node::DFS(root.getnode(ch), ch, count+1);
    
    // /* NO WORD... CONTINUE SEARCH */
    // else
    //     return trie_node::DFS(root.getnode(ch), ch, count);
}

/* SEARCH OCCURANCES OF PREFIX IN TREE */
int trie_node::searchme(string token){
    trie_node* node = this;
    int count = 0;
    
    /* CRAWL T0 END OF PREFIX */
    for(int i = 0; i < token.length(); i++){
        cout << "NODE AT: " << token[i];
        /* IF IT DOESN'T EXIST RETURN COUNT OF 0 */
        if(node->character[token[i]]==nullptr)
            return count;
        
        /* GO TO NEXT CHARACTER IN PREFIX */    
        node = node->character[token[i]];
    }

    /* USE DFS TO COUNT WORDS WITH PREFIX */
    for(int i = 0; i < size; i++){
        count += DFS(node, i, count);
    }

    /* RETURN COUNT OF PREFIX */
    return count;
}
