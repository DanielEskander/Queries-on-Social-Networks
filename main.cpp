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
#include "ProfileData.h"

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

    input.open(argv[1]);
    output.open("/ProfileData.txt", ofstream::app);

    // string line = "";
    // while(getline(input, line)) {
    //     stringstream linestream(line);
    //     string value;
    //     getline(linestream,value,',');
    //     name = value;
    //     output << setw(20) << left << value;
    //     getline(linestream,value,',');
    //     output << setw(3) << left << value;
    //     getline(linestream,value,',');
    //     output << setw(20) << left << value;
    //     output << endl;

    //     net.insert(name, index++);
    //     do {
    //         getline(linestream,value,',');
    //         name2 = value;
    //         if(name2 == "") {
    //             break;
    //         }
    //         net.addFriend(name, name2);
    //     } while (name2 != "");
    // };
    input.close();
    output.close();
    // INITIALIZE END

    while (choice != 7) {

        cout << "Welcome to FriendBook! Please select an action." << endl;
        cout << "1) Add a new user" << endl;
        cout << "2) Add a friendship" << endl;
        cout << "3) Get a user's friends' profiles" << endl;
        cout << "4) Get a range of user profiles" << endl;
        cout << "5) Print the entire net" << endl;
        cout << "6) Exit FriendBook" << endl;

        cin >> choice;

        if(choice == 1) {

            cout << "Enter new user's name:" << endl;
            cin >> name;
            cout << "Enter new user's age:" << endl;
            cin >> age;
            cout << "Enter new user's occupation:" << endl;
            cin >> occupation;
            net.addRecord(name, age, occupation);
            net.insert(name, index++);
        }

        else if(choice == 2) {

            cout << "Enter the first user's name:" << endl;
            cin >> name;
            cout << "Enter the second user's name:" << endl;
            cin >> name2;

            net.addFriend(name, name2);

        }

        else if(choice == 3) {
            cout << "Enter user's name for search:" << endl;
            cin >> name;

            net.ListFriendsInfo(name);
        }

        else if(choice == 4) {
            cout << "Enter start name for range search:" << endl;
            cin >> name;
            cout << "Enter stop name for range search:" << endl;
            cin >> name2;
            net.ListInfo(name, name2);
        }

        else if(choice == 5) {
            net.printAll();
        }

        else if(choice == 6) {
            cout << "Thank you for using FriendBook. Goodbye." << endl;
            break;
        }

        else {
            cout << "Command not recognized. Please enter a number between 1 and 6." << endl;
        }
    }
    return 0;
    
}