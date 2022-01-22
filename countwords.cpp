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

using namespace trie;
using namespace std;

int insertme(string);                             // FUNCTION PROTOTYPE
int searchme(string);                             // FUNCTION PROTOTYPE

bool insertme(vector<string> tokens){
  return false;
}

bool searchme(vector<string> tokens){
  return false;
}

void print_dic(vector<vector<string> > tokenized){
  for(int i = 0; i < tokenized.size(); i++){
      for(int j = 0; j < tokenized[i].size(); j++){
        cout << tokenized[i][j] << endl;
      }
    }
}
void print_tokens(vector<string> tokens){
  for(int i = 0; i < tokens.size(); i++){
    cout << tokens[i] << endl;
  }
}

/**
 * @brief Splits the input string by deliminator
 * 
 * @param str   input to be split
 * @param delim what to split input by
 * @return vector<string> return split string
 */
vector<string> split(const string str, char delim) {
  vector<string> result;
  istringstream ss(str);
  string token;

  while (getline(ss, token, delim)) {
    if (!token.empty()) {
      result.push_back(token);
    }
  }
  return result;
}


/**
 * @brief Read the file in from the argument path
 * MODES:
 *  - insertme: insert the tokens into the 
 *      trie structure
 *  - searchme: serach frequency of tokens and 
 *      print to standard out
 * 
 * @param path path of input text
 * @param mode which mode to use 
 */
void read(const char* path, const string mode){

  ifstream file(path);
  string line;

  if(file.is_open()){
    while(getline(file,line)){
      vector<string> tokens;
      tokens = split(line, ' ');

      if(mode=="insert"){
        insertme(tokens);
      } else {
        searchme(tokens);
      }
    }
    file.close();
  }
  
  return;
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

int main(int argc, char *argv[]){
  const string err = "\n\nExiting program...\n";
  try{

    if(argc != 3)
      throw("Invalid amount of arguments");
    
    const char *path = argv[1];
    vector<string> tokenized;
    tokenized = read_file(path);
    print_tokens(tokenized);


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