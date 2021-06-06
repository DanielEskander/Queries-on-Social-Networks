#include "redblack_tree.h"

#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstring>
#include <iostream>

using namespace std;


void rbTree::printRecord(int index){
    string name, age, occupation;
    char *buffer= new char[20];
    char *buffer2 = new char[3];
    char *buffer3 = new char[30];
    ifstream output;
    output.open("ProfileData.txt", ios::app);
    output.seekg(index*54);
    output.read(buffer, 20);
    output.seekg(index*54 + 20);
    output.read(buffer2, 3);
    output.seekg(index*54 + 23);
    output.read(buffer3, 30);
    output.close();
    for(int i = 0; i < 20; i++){
        if(buffer[i] != '\0')
            name += buffer[i];
    }
    for(int j = 0; j < 3; j++){
        if(buffer2[j] != '\0')
            age += buffer2[j];
    }
    for(int k = 0; k < 30; k++){
        if(buffer3[k] != '\0')
            occupation += buffer3[k];
    }
    cout<< name << ",";
    cout<< age << ",";
    cout<< occupation;

    delete[] buffer;
    delete[] buffer2;
    delete[] buffer3;
}
