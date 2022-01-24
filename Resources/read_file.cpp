#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

// int read_file(const char* str){
//   regex reg ("s[a-zA-Z']+");
//   vector<vector<string> > myvec;
//   ifstream file(str);
//   if(file.is_open()){
//     string line; 
//     while(getline(file,line)){
//       // printf("%s",line.c_str());
//       line = line.c_str();
      
//       cout << regex_replace(line, reg, " ") << endl;
//     }
//     file.close();
//   }

// }

int main(int argc, char *argv[]){
  // const string err = "\n\nExiting program...\n";


  // if(argc != 3)
  //   throw("Invalid amount of arguments");
  
  // const char *path = argv[1];
  // vector<vector<string> > tokenized;
  //read_file(path);



  regex reg ("s[a-zA-Z']+");
  string str = "Remo&*(*& ve ";
  cout << regex_replace(str, reg, "") << endl;
    
}