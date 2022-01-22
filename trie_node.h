#ifndef TRINODE_H                      /* INCLUDE GUARD */
#define TRINODE_H 

class trie_node {
  private:                             // PRIVATE FIELDS
    static const int size = 27;

  public:                              // PUBLIC FIELDS
    bool isWord;
    trie_node* character[size];

    trie_node();                       // CONSTRUCTOR

    void insertme(std::string);        // FUNCTION PROTOTYPE
    int  searchme(std::string);        // FUNCTION PROTOTYPE
};


#endif                                 // TRINODE_H