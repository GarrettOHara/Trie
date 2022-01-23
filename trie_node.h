#ifndef TRIENODE_H                                /* INCLUDE GUARD */
#define TRIENODE_H 
#include <iostream>

class trie_node {
  private:                                       // PRIVATE FIELDS
    static const int size = 27;
    trie_node *character[size];
    bool isWord;
    //trie_node *children[size];

  public:                                        // PUBLIC FIELDS
    trie_node(bool isWord = false);              // CONSTRUCTOR
    ~trie_node();                                // DESCTRUCTOR
    
    //struct trie_node *next[size];

    void setword(bool);
    void insertme(std::string);                  // FUNCTION PROTOTYPE
    int  searchme(std::string);                  // FUNCTION PROTOTYPE
};

#endif                                           // TRIENODE_H
