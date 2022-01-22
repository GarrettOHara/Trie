#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int read_file(const char* str){
  vector<vector<string> > myvec;
  ifstream file(str);
  if(file.is_open()){
    string line; 
    while(getline(file,line)){
      // printf("%s",line.c_str());
      line = line.c_str();
      line = line.replaceAll("[^a-zA-Z]","");
      cout << line << endl;
    }
    file.close();
  }

}

int main(int argc, char *argv[]){
  const string err = "\n\nExiting program...\n";


  if(argc != 3)
    throw("Invalid amount of arguments");
  
  const char *path = argv[1];
  vector<vector<string> > tokenized;
  read_file(path);

}