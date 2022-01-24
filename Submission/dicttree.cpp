/**
 * This Program was written by:
 * 
 * Garrett O'Hara cssc3724 RedId: 822936303
 * 
 * CS 480 | Professor Shen | January 2022
 **/
#include <ios>
#include <stack>
#include <queue>
#include <iostream>
#include "dicttree.h"

using namespace std;

/* CONSTRUCTOR */
dicttree::dicttree(bool isWord) {
    for(int i = 0; i < size; i++){
        this->character[i] = nullptr;
    }
}

/* DECONSTRUCTOR */
dicttree::~dicttree() {
    for(int i = 0; i < size; i++){
        if(character[i]!=nullptr)
            delete character[i];
    }
}

/* SETTER */
void dicttree::setword(bool isWord){
    this->isWord = isWord;
}

/* GETTER */
bool dicttree::getword(){
    return this->isWord;
}

int static proccesschar(char ch, int size){
    char tmp = ch;
    if(tmp == '\''){
        tmp = size-1;
    } else {
        tmp = tolower(ch)-'a';
    }
    return tmp;
}
int static proccesscharin(char ch, int size){
    char tmp = ch;
    if(tmp == '\''){
        tmp = size-1;
    } else {
        tmp = ch -'a';
    }
    return tmp;
}

/* INSERT WORD */
void dicttree::insertme(string token){
    dicttree* node = this;
    for(int i = 0; i < token.length(); i++){
        
        /* PROCESS CHARACTER */
        int tmp = proccesscharin(token[i],size);
        
        
        /* CONSTRUCT NEW NODE IF NULL */
        if(node->character[tmp] == nullptr){
            node->character[tmp] = new dicttree();
        }

        /* MOVE TO NEW NODE */
        node = node->character[tmp];

    }
    
    /* SET END OF WORD */
    node->setword(true);
}

/* RECURSIVE DEPTH FIRST SEARCH */
int dicttree::DFS(dicttree* root){
    if(root==nullptr)
        return 0;
    int sum = 0;
    if(root->getword())
        sum++;

    int words = 0;
    for(int i = 0; i < size; i++){        
        if(root->character[i]!=nullptr){
            sum += DFS(root->character[i]);
        }
    }
    return sum;
}

/* ITERATIVE DEPTH FIRST SEARCH */
int dicttree::DFS(dicttree* root, int count){
    
    stack<dicttree*> stack;
    stack.push(root);
    // for(int i = 0; i < size; i++){
    //     if(root->character[i]!=nullptr)
    //         stack.push(root->character[i]);
    // }
    while(!stack.empty()){
        dicttree* root = stack.top();
        //root = stack.top();
        if(root->isWord)
            count++;

        for(int i = 0; i < size; i++){
            cout << "COUNT: " << count << " SEARCHING: " << i <<  " ADDY: " << root->character[i] << endl;
            if(root->character[i]!=nullptr)
                stack.push(root->character[i]);
        }
        stack.pop();
    }
    return count;
}

/* ITERATIVE BREADTH FIRST SEARCH USING A QUEUE */
int dicttree::BFS(dicttree* root){
    int count = 0;
    queue<dicttree*> q;
    q.push(root);
    while(!q.empty()){
        root = q.front();
        if(root->isWord)
            count++;
        
        for(int i = 0; i < size; i++){
            if(root->character[i] != nullptr)
                q.push(root->character[i]);
        }
        q.pop();
    }
    return count;
}


/* SEARCH OCCURANCES OF PREFIX IN TREE */
int dicttree::searchme(string token){
    dicttree* node = this;
    int count = 0;
    
    /* CRAWL T0 END OF PREFIX */
    for(int i = 0; i < token.length(); i++){
        //cout << "NODE AT: " << token[i] << " ";
        int tmp = proccesschar(token[i],size);
        //cout << tmp << endl;

        /* IF IT DOESN'T EXIST RETURN COUNT OF 0 */
        if(node->character[tmp]==nullptr)
            return count;
        
        /* GO TO NEXT CHARACTER IN PREFIX */    
        node = node->character[tmp];
    }
    
    return DFS(node);
    //return BFS(node);
}
