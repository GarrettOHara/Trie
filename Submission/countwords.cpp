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
#include "dicttree.h"

using namespace std;

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
      char delimiters[] = " \n\r !\"#$%&()*+,-./0123456789:;<=>?@[\\]^_`{|}~";
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

/* VERY WEIRD INSTANCE WITH AND WITHOUT THE AS VECTOR */
void build_trie(dicttree &root, vector<string>tokens){
  
  //vector<string> as;
  
  for(int i = 0; i < tokens.size(); i++){
    
    /* 6817 WITHOUT 6816 WITH */
    //char check = tokens[i][0];
    
    // if(tolower(check)=='a')
    //   as.push_back(tokens[i]);

    root.insertme(tokens[i]);
  }
  // for(int i = 0; i < as.size(); i++){
  //   cout << as[i] << endl;
  // }
  // cout << as.size() << endl;
  return;
}

void count_words(dicttree &root, vector<string>tokens){
  for(int i = 0; i < tokens.size(); i++){
    //cout << "FINDING: " << tokens[i] << endl;
    int count = root.searchme(tokens[i]);
    cout << tokens[i] << " " << count << endl;
  }
  return;
}

int main(int argc, char *argv[]){
  const string err = "\n\nExiting program...\n";
  try{

    if(argc != 3)
      throw("Invalid amount of arguments");
    
    const char *dict_path = argv[1];
    const char *text_path = argv[2];

    vector<string> dict;
    vector<string> text;

    dict = read_file(dict_path);
    text = read_file(text_path);
    
    dicttree root;
    build_trie(root, dict);    
    count_words(root, text);

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
