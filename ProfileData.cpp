#include "redblack_tree.h"

#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstring>
#include <iostream>

using namespace std;

string rbTree::getString(){
    ofstream output;
    string s = "";
    string getname;
    char name[21] = "";
    char age[4] = "";
    char occupation[31] = "";
    char temp1[21];
    char temp2[4]; 
    char temp3[31];
    int spot = 0;
    for(int i = 0; i < 21; i++){
        temp1[i] = '\0';
    }
    for(int j = 0; j < 4; j++){
        temp2[j] = '\0';
    }
    for(int k = 0; k < 31; k++){
        temp3[k] = '\0';
    }
    cout << "Enter the user's name: " << endl;
    cin.ignore();
    s = "";
    getline(cin, s);
    for(int i = 0; i < 21; i++){
        temp1[i] = s[i];
    }
    strncpy(name, temp1, 20);
    for(int i = 0; i < 20; i++){
        getname += name[i];
    }
    cout << "Enter the user's age: " << endl;
    cin >> temp2;
    strncpy(age, temp2, 3);
    temp2[0] = '\0';                    //please explain
    cout << "Enter the user's occupation: " << endl;
    cin.ignore();
    s = "";
    getline(cin, s);
    for(int x = 0; x < s.length(); x++){
        temp3[x] = s[x];
    }
    strncpy(occupation, temp3, 30);
    temp2[0] = '\0'; 
    output.open("ProfileData.txt", ofstream::app);
    output << setfill(' ') << left
        << setw(20) << name
        << setw(3) << age 
        << setw(30) << occupation
        << endl;
    output.close();
    return getname;
}

void rbTree::printRecord(int index, string rootName){
    //string name; 
    string age, occupation;
    // char *buffer= new char[20];
    char *buffer2 = new char[3];
    char *buffer3 = new char[30];
    ifstream output;
    output.open("ProfileData.txt", ios::app);
    // output.seekg(index*54);
    // output.read(buffer, 20);
    output.seekg(index*54 + 20);
    output.read(buffer2, 3);
    output.seekg(index*54 + 23);
    output.read(buffer3, 30);
    output.close();
    // for(int i = 0; i < 20; i++){
    //     if(buffer[i] != '\0'){
    //         if(!(i == 19 && buffer[i] == ' ' || (buffer[i] == ' ' && i < 19 && (buffer[i + 1] == ' ' || buffer[i + 1] == '\0'))))
    //             name += buffer[i];
    //     }
    // }
    for(int j = 0; j < 3; j++){
        if(buffer2[j] != '\0'){
            if(!(j == 2 && buffer2[j] == ' ' || (buffer2[j] == ' ' && j < 2 && (buffer2[j + 1] == ' ' || buffer2[j + 1] == '\0'))))
                age += buffer2[j];
        }
    }
    for(int k = 0; k < 30; k++){
        if(buffer3[k] != '\0'){
            if(!(k == 29 && buffer3[k] == ' ' || (buffer3[k] == ' ' && k < 29 && (buffer3[k + 1] == ' ' || buffer3[k + 1] == '\0'))))
                occupation += buffer3[k];
        }
    }
    //cout<< name << ",";
    cout << rootName << ",";
    cout<< age << ",";
    cout<< occupation << ",";

    //delete[] buffer;
    delete[] buffer2;
    delete[] buffer3;
}
