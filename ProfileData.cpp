#include "redblack_tree.h"

#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstring>
#include <iostream>

using namespace std;

void rbTree::addRecord(string name, string age, string occupation){
        ofstream output;
        output.open("/ProfileData.txt", ofstream::app);
        output << setfill(' ')
        << setw(20) << left << name
        << setw(3) << left << age
        << setw(20) << left << occupation
        << endl;
        output.close();
}

string rbTree::printRecord(int index){
    if(index < 0)
        return "";
    fstream output;
    string result;
    output.open("/ProfileData.txt", ofstream::app);

    output.seekg(index*52);
    char name[20];
    output.read(name, 20);
    for(int i = 0; i < 20; i++){
        if(name[i] != NULL)
            result += name[i];
    }

    output.seekg(index*52 + 20);
    char age[3];
    output.read(age, 3);
    result += age;
    for(int i = 0; i < 3; i++){
        if(age[i] != NULL)
            result += age[i];
    }

    output.seekg(index*52 + 23);
    char occupation[20];
    output.read(occupation, 30);
    result += occupation;
    for(int i = 0; i < 30; i++){
        if(occupation[i] != NULL)
            result += occupation[i];
    }

    output.close();
    return result;
}
