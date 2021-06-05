#include "redblack_tree.h"

#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstring>
#include <iostream>

using namespace std;


void rbTree::printRecord(int index){
    char *buffer= new char[20];
    char *buffer2 = new char[3];
    char *buffer3 = new char[30];
    ifstream output;
    output.open("ProfileData.txt", ios::binary);
    output.seekg(index*54);
    output.read(buffer, 20);
    output.seekg(index*54 + 20);
    output.read(buffer2, 3);
    output.seekg(index*54 + 23);
    output.read(buffer3, 30);
    output.close();
    cout<< buffer << ",";
    cout<< buffer2 << ",";
    cout<< buffer3;

    delete[] buffer;
    delete[] buffer2;
    delete[] buffer3;
}
