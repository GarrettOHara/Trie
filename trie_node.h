#ifndef TRINODE_H                      /* INCLUDE GUARD */
#define TRINODE_H 

namespace trie {
  class trie_node {
  private:                             // PRIVATE FIELDS
    static const int size = 27;

  public:                              // PUBLIC FIELDS
    bool isWord;
    trie_node* character[size];

    trie_node(){                       // CONSTRUCTOR
      this->isWord = false;
      for(int i = 0; i < size; i++){
        character[i] = NULL;
      }
    }

    bool insertme(std::string);        // FUNCTION PROTOTYPE
    int  searchme(std::string);        // FUNCTION PROTOTYPE
  };
}

#endif                                 // TRINODE_H