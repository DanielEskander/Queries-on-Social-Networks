//main.cpp

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

int foo(){
    string s;
    char name[20];
    char age[3];
    char occupation[30];
    char temp[21];
    char temp2[4];
    char temp3[31];
    cout << "Input name: " << endl;
    cin >> temp;
    strncpy(name, temp, 20);
    cout << "Input age: " << endl;
    cin >> temp2;
    strncpy(age, temp2, 3);
    cout << "Input occupation: " << endl;
    cin >> temp3;
    strncpy(occupation, temp3, 30);
    
    ofstream outfile("test.txt", std::ios::app);
    outfile << std::setfill(' ') << std::left
            << std::setw(20) << name
            << std::setw(3) << age 
            << std::setw(30) << occupation
            << endl;
    outfile.close();
    return 0;
}

int main(){
    char *buffer= new char[20];
    char *buffer2 = new char[3];
    char *buffer3 = new char[30];
    // read will only read starting from most recent seekg
    ifstream infile("test.txt", ios::binary);
    //infile.seekg(54);
    infile.read(buffer, 20);
    infile.seekg(54);
    infile.seekg(20);
    infile.read(buffer2, 3);
    infile.seekg(23);
    infile.read(buffer3, 30);
    infile.close();
    cout << "Name: " << buffer << endl;
    cout << "Age: " << buffer2 << endl;
    cout << "Occupation: " << buffer3 << endl;
    /*
    bool check = 1;
    while (check == 1){
        foo();
        cout << "input another user? (1 for yes, 0 otherwise)" << endl;
        cin >> check;
    }
    */
    delete[] buffer;
    delete[] buffer2;
    delete[] buffer3;
    return 0;
}
