#include <fstream>
#include <iostream>
#include "trie_node.h"

using namespace trie;
using namespace std;

int insertme(string);                             // FUNCTION PROTOTYPE
int searchme(string);                             // FUNCTION PROTOTYPE


int read_file(char *arg){
  const char *path = &arg[1];
  cout << "THIS IS THE PATH: " << path << endl;
  ifstream file(path);
  
  if(file.is_open()){
    string line; 
    while(getline(file,line)){
      printf("%s",line.c_str());
    }
    file.close();
  }

}

int main(int argc, char *argv[]){
  const string err = "\n\nExiting program...\n";
  try{

    if(argc != 3)
      throw("Invalid amount of arguments");
    
    cout << argv[1] << " " << argv[2] << endl;

    read_file(argv[1]);

    // HEAP INSTANTIATION
    trie_node* A = new trie_node();

    // STACK INSTANTIATION
    trie_node B = trie_node();
    
    // FREE HEAP SPACE
    delete A;

  } catch(const char* msg){
    cout << msg << 
    "\n\nPlease supply 2 exceptions:" <<
    "\n  - Path to dictionary"  <<
    "\n  - Path to sample text" <<
    err << endl;
  }
  return 0;
}