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
    // cout << "DECONSTRUCTING NODE" << endl;
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

int static proccesschar(char ch, int size){
    char tmp = ch;
    if(tmp == 39){
        tmp = size-1;
    } else {
        tmp = tolower(ch)-'a';
    }
    return tmp;
}

/* INSERT WORD */
void trie_node::insertme(string token){
    trie_node* node = this;
    for(int i = 0; i < token.length(); i++){
        
        /* PROCESS CHARACTER */
        //int tmp = proccesschar(token[i],size);
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

        // for(int i = 0; i < size; i++){
        //     cout << node->character[tmp] << endl;
        // }
        // cout << node->character[tmp] << " " << token[i] << " : " << int(tmp) << endl;        
        //cout << token[i] << " : " << tmp << endl;
        /* MOVE TO NEW NODE */
        node = node->character[tmp];

    }
    
    /* SET END OF WORD */
    node->setword(true);
    // cout << "INSERTED: " << token << "\n" << endl;
}

/* COUNT WITH DEPTH FIRST SEARCH */
int trie_node::DFS(trie_node* root, int count, int size){
    if(root->getword()){
        // cout << "END WORD" << endl;
        count++;
    }
    
    for(int i = 0; i < size; i++){
        // cout << "COUNT: " << count << " SEARCHING: " << i <<  " ADDY: " << root->character[i] << endl;
        if(root->character[i]!=nullptr){
            // cout << "SEARCHING" << endl;
            root = root->character[i];
            // count+=trie_node::DFS(root, count, size);
            return trie_node::DFS(root, count, size);
        }
    }

    return count;
}

/* SEARCH OCCURANCES OF PREFIX IN TREE */
int trie_node::searchme(string token){
    trie_node* node = this;
    int count = 0;
    
    /* CRAWL T0 END OF PREFIX */
    for(int i = 0; i < token.length(); i++){
        // cout << "NODE AT: " << token[i] << " ";

        int tmp = proccesschar(token[i],size);

        // cout << tmp << endl;


        /* IF IT DOESN'T EXIST RETURN COUNT OF 0 */
        if(node->character[tmp]==nullptr)
            return count;
        
        /* GO TO NEXT CHARACTER IN PREFIX */    
        node = node->character[tmp];
    }
    // cout << "\n\nSTARTING DFS\n\n" << endl;

    /* USE DFS TO COUNT WORDS WITH PREFIX */
    // for(int i = 0; i < size; i++){
    //     int words = 0;
    //     if(node->character[i] != nullptr)
    //         count += DFS(node->character[i], words, size);
    // }

    /* RETURN COUNT OF PREFIX */
    //return count;
    return DFS(node, count, size);
}
