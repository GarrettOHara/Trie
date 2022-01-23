#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstring>

using namespace std;

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

      // if(mode=="insert"){
      //   insertme(tokens);
      // } else {
      //   searchme(tokens);
      // }
    }
    file.close();
  } else {
    throw("Cannot open file please check file path");
  }
  
  return;
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

void print_dic(vector<vector<string> > tokenized){
  for(int i = 0; i < tokenized.size(); i++){
      for(int j = 0; j < tokenized[i].size(); j++){
        cout << tokenized[i][j] << endl;
      }
    }
}