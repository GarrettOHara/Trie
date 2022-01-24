#ifndef TRIENODE_H                                /* INCLUDE GUARD */
#define TRIENODE_H 
#include <iostream>

class trie_node {
  private:                                       // PRIVATE FIELDS
    static const int size = 27;
    trie_node *character[size];
    bool isWord;

    int BFS(trie_node*);
    //int DFS(trie_node*, int);
    int DFS(trie_node*);
   
  public:                                        // PUBLIC FIELDS
    trie_node(bool isWord = false);              // CONSTRUCTOR
    ~trie_node();                                // DESCTRUCTOR    

    void setword(bool);
    bool  getword();
    void insertme(std::string);                  // FUNCTION PROTOTYPE
    int  searchme(std::string);                  // FUNCTION PROTOTYPE
};

#endif                                           // TRIENODE_H
