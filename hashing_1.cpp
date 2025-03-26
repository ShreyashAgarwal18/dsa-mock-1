#include <bits/stdc++.h>
using namespace std;

void insert(int hash[], int key) {
    int loc = key % 10;
    int start = loc; // To track if we've looped back
    while (true) {
        if (hash[loc] == -1 || hash[loc] == -2) {
            hash[loc] = key;
            break;
        } else {
            loc = (loc + 1) % 10;
            if (loc == start) { // If we complete one full cycle
                cout << "Hash table is full, cannot insert " << key << endl;
                break;
            }
        }
    }
}

void search(int hash[], int key) {
    int loc = key % 10;
    int start = loc; // To track if we've looped back

    while (true) {
        if (hash[loc] == key) {
            cout << key << " found at index " << loc << endl;
            return;
        } else if (hash[loc] == -1) {
            cout << key << " not found" << endl;
            return;
        } else {
            loc = (loc + 1) % 10;
            if (loc == start) { // If we complete one full cycle
                cout << key << " not found" << endl;
                return;
            }
        }
    }
}

void display(int hash[]) {
    cout << "Index  Key" << endl;
    for (int i = 0; i < 10; i++) {
        cout << i << "      " << (hash[i] == -1 ? "-1" : to_string(hash[i])) << endl;
    }
}

int main() {
    int hash[10];
    for (int i = 0; i < 10; i++) {
        hash[i] = -1; // Initialize with -1 (empty)
    }

    string menu = "Enter one of the choices:\n1. Add element\n2. Search element\n3. Display\n4. Exit";
    int opt, data;

    do {
        cout << menu << endl;
        cout << "Your choice: ";
        cin >> opt;
        switch (opt) {
            case 1:
                cout << "Enter element to add: ";
                cin >> data;
                insert(hash, data);
                break;
            case 2:
                cout << "Enter element to search: ";
                cin >> data;
                search(hash, data);
                break;
            case 3:
                display(hash);
                break;
            case 4:
                exit(0);
            default:
                cout << "Please enter a correct option" << endl;
        }
    } while (true);

    return 0;
}
