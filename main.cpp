// #include <iostream>

// #include "redblack_tree.h"

// using namespace std;

// int main(){
//     rbTree tree;
//     tree.insert("Dave", 1);
//     tree.insert("Adam", 1);
//     tree.insert("Even", 1);
//     tree.insert("Ben", 1);
//     tree.insert("Fre", 1);
//     tree.insert("Cuz", 1);
//     tree.addFriend("Dob", "Ben");
//     tree.addFriend("Dave", "Fre");
//     //tree.ListFriendsInfo("Dave");
//     //tree.ListInfo("Adam", "Dave");
//     tree.printAll();
//     cout<<'\n';
//     return 0;
// }

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
        stringstream friends(value);
        string add;
        while(add != ""){
            getline(friends,add,',');
            name2 = add;
            net.addFriend(name, name2);
        }
        getline(linestream,value, '\"');
    };
    input.close();
    output.close();

    while (choice != 7) {
        cout << "Welcome to FriendNet! Please choose an option." << endl;
        cout << "1) Add a new user" << endl;
        cout << "2) Create a friendship" << endl;
        cout << "3) Get a user's profile" << endl;
        cout << "4) Get a user's friends' profiles" << endl;
        cout << "5) Get a range of user profiles" << endl;
        cout << "6) Print the entire network of friends" << endl;
        cout << "7) Exit FriendNet" << endl;

        cin >> choice;

        if(choice == 1) {
            string s;
            char name[20] = "";
            char age[3] = "";
            char occupation[30] = "";
            char temp1[21];
            char temp2[4];
            char temp3[31];
            cout << "Enter the user's name: " << endl;
            getline(cin, s);
            for(int i = 0; i < s.length(); i++){
                temp1[i] = s[i];
            }
            strncpy(name, temp1, 20);
            temp1[0] = '\0';                    //please explain
            cout << "Enter the user's age: " << endl;
            cin >> temp2;
            strncpy(age, temp2, 3);
            temp2[0] = '\0';                    //please explain
            cout << "Enter the user's occupation: " << endl;
            cin >> temp3;
            strncpy(occupation, temp3, 30);
    
            output.open("ProfileData.txt", ofstream::app);
            output << setfill(' ') << left
                << setw(20) << name
                << setw(3) << age 
                << setw(30) << occupation
                << endl;
            output.close();
            net.insert(name, index++);
        }
        else if(choice == 2) {

            cout << "Enter the first user's name:" << endl;
            getline(cin, name);
            cout << "Enter the second user's name:" << endl;
            getline(cin, name2);
            net.addFriend(name, name2);

        }
        else if(choice == 3) {
            cout << "Enter user's name for search:" << endl;
            getline(cin, name);
            net.ListUserInfo(name);
        }
        else if(choice == 4) {
            cout << "Enter user's name for search:" << endl;
            getline(cin, name);
            net.ListFriendsInfo(name);
        }
        else if(choice == 5) {
            cout << "Enter start name for range search:" << endl;
            getline(cin, name);
            cout << "Enter stop name for range search:" << endl;
            getline(cin, name2);
            net.ListInfo(name, name2);
        }
        else if(choice == 6) {
            net.printAll();
        }
        else if(choice == 7) {
            cout << "Thank you for using FriendNet. Goodbye." << endl;
            break;
        }
        else {
            cout << "Invalid option. Please enter a number between 1 and 7." << endl;
        }
    }
    return 0;
    
}