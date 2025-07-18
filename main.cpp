
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstring>
#include "redblack_tree.h"

using namespace std;

int main(int argc, char *argv[]){
    ifstream input;
    ofstream output;
    int index = 0;
    int choice = 0;
    string name;
    string age;
    string occupation;
    string name2;

    rbTree net;
    output.open("ProfileData.txt");
    output.close();
    input.open(argv[1]);
    output.open("ProfileData.txt", ofstream::app);
    string line = "";
    while(getline(input, line)) {
        stringstream linestream(line);
        string value;
        getline(linestream,value,',');
        name = value;
        output << setw(20) << left << value;
        getline(linestream,value,',');
        output << setw(3) << left << value;
        getline(linestream,value,',');
        output << setw(30) << left << value;
        output << endl;

        net.insert(name, index++);
        getline(linestream,value, '\"');
        getline(linestream,value, '\"');
        stringstream friends(value);
        string add = ",";
        if(value == "")
            add == "";
        while(add != ""){
            getline(friends,add,',');
            if(add != "")
                name2 = add;
            net.addFriend(name, name2);
        }
    };
    input.close();
    output.close();

    while (choice != 8) {
        cout << "Welcome to FriendNet! Please choose an option." << endl;
        cout << "1) Add a new user" << endl;
        cout << "2) Create a friendship" << endl;
        cout << "3) Get a user's profile" << endl;
        cout << "4) Get a user's friends' profiles" << endl;
        cout << "5) Get a range of user profiles" << endl;
        cout << "6) Print the entire network of friends" << endl;
        cout << "7) Print the entire red black tree" << endl;
        cout << "8) Exit FriendNet" << endl;

        cin >> choice;

        if(choice == 1) {
            name = net.getString();
            net.insert(name, index++);
        }
        else if(choice == 2) {
            cout << "Enter the first user's name:" << endl;
            cin.ignore();
            getline(cin, name);
            cout << "Enter the second user's name:" << endl;
            getline(cin, name2);
            net.addFriend(name, name2);

        }
        else if(choice == 3) {
            cout << "Enter user's name for search:" << endl;
            cin.ignore();
            getline(cin, name);
            net.ListUserInfo(name);
        }
        else if(choice == 4) {
            cout << "Enter user's name for search:" << endl;
            cin.ignore();
            getline(cin, name);
            net.ListFriendsInfo(name);
        }
        else if(choice == 5) {
            cout << "Enter start name for range search:" << endl;
            cin.ignore();
            getline(cin, name);
            cout << "Enter stop name for range search:" << endl;
            getline(cin, name2);
            net.ListInfo(name, name2);
        }
        else if(choice == 6) {
            net.printAll();
        }
        else if(choice == 7) {
            net.printRbTree();
        }
        else if(choice == 8) {
            cout << "Thank you for using FriendNet. Goodbye." << endl;
            break;
        }
        else {
            cout << "Invalid option. Please enter a number between 1 and 8." << endl;
        }
    }
    return 0;
    
}
