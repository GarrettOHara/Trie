/**
 * This Program was written by:
 * 
 * Garrett O'Hara cssc3724 RedId: 822936303
 * 
 * CS 480 | Professor Shen | January 2022
 **/
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstring>
#include "trie_node.h"

using namespace std;

// void insertme(trie_node, string);                // FUNCTION PROTOTYPE
// int  searchme(string);                           // FUNCTION PROTOTYPE

// bool insertme(vector<string> tokens){
//   return false;
// }

// bool searchme(vector<string> tokens){
//   return false;
// }

void print_tokens(vector<string> tokens){
  for(int i = 0; i < tokens.size(); i++){
    cout << tokens[i] << endl;
  }
}

vector<string> read_file(const char* path){

  ifstream file(path);
  
  vector<string> tokenized;
  string line;
  string temp = "";

  if(file.is_open()){
    while (getline(file,line)){
      char delimiters[] = " ,./<>?;:\"`1234567890-=~!@#$%^&*()_+[]\\{}|";
      char* token = strtok (&line[0], delimiters);
      while(token != NULL){
          tokenized.push_back(token);
          token = strtok (NULL, delimiters);
      }
    }
    file.close();
  }
  return tokenized;
}

void build_trie(vector<string>tokens){
  trie_node *root = new trie_node();
  for(int i = 0; i < tokens.size(); i++){
    cout << tokens[i] << endl;
    string str = tokens[i];
    root->insertme(str);
  }
}

int main(int argc, char *argv[]){
  const string err = "\n\nExiting program...\n";
  try{

    if(argc != 3)
      throw("Invalid amount of arguments");
    
    const char *path = argv[1];
    vector<string> tokenized;
    tokenized = read_file(path);
    print_tokens(tokenized);
    cout<<"STARTING INSERT"<<endl;
    build_trie(tokenized);
    


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
  } catch ( const exception& e ) {
    cerr << "ERROR: " << e.what() << err << endl;
  } catch (...) {
    cout << "Exception occurred";
  }
  return 0;
}