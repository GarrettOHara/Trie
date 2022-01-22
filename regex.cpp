#include <iostream>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(int argc, char * argv[]) {
    string line;
    string temp = "";

    cout << "Enter a string: ";
    getline(cin, line);
    for (int i = 0; i < line.size(); ++i) {
        if (line[i] == ' ' || 
            line[i] == '\'' || 
            (line[i] >= 'a' && line[i] <= 'z') || 
            (line[i] >= 'A' && line[i] <= 'Z')) {
                temp = temp + line[i];
        }
    }
    cout << temp << endl;
    cout << "TOKENIZE: " << endl;
    char* token = strtok (&temp[0], " \n");
    while(token != NULL){
        printf ("%s\n",token);
        token = strtok (NULL, " ");
    }
    return 0;
}