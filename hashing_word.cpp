#include <bits/stdc++.h>

using namespace std;

class hashTable {
private:
    vector<list<pair<string, string>>> table; // Each bucket stores (word, meaning) pairs

    // Hash function
    int hashfunc(const string& word) {
        int hash = 0;
        int multiplier = 1;
        int mod = table.size();

        for (int i = word.size() - 1; i >= 0; i--) {
            hash = (hash + (word[i] * multiplier)) % mod;
            multiplier = (multiplier * 10) % mod;
        }
        return hash;
    }

public:
    hashTable(int size) {
        table.resize(size);
    }

    // Insert word with meaning
    void insert(const string& word, const string& meaning) {
        int index = hashfunc(word);
        for (auto& pair : table[index]) {
            if (pair.first == word) {
                cout << "Word already exists. Updating meaning." << endl;
                pair.second = meaning;
                return;
            }
        }
        table[index].push_back({word, meaning});
    }

    // Search for a word and print its meaning
    bool search(const string& word) {
        int index = hashfunc(word);
        for (const auto& pair : table[index]) {
            if (pair.first == word) {
                cout << "Found: " << word << " -> " << pair.second << endl;
                return true;
            }
        }
        cout << "Word not found." << endl;
        return false;
    }

    // Display entire hash table
    void display() {
        cout << "\nHash Table Contents:\n";
        for (int i = 0; i < table.size(); ++i) {
            cout << "Bucket " << i << ": ";
            for (const auto& pair : table[i]) {
                cout << "[" << pair.first << " -> " << pair.second << "] -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    hashTable dictionary(10);  // Create hash table with 10 buckets

    int opt;
    string word, meaning;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Word & Meaning\n";
        cout << "2. Search Word\n";
        cout << "3. Display Dictionary\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> opt;

        cin.ignore(); // To handle newline issues

        switch (opt) {
            case 1:
                cout << "\nEnter the word: ";
                getline(cin, word);
                cout << "Enter the meaning: ";
                getline(cin, meaning);
                dictionary.insert(word, meaning);
                break;

            case 2:
                cout << "\nEnter the word to search: ";
                getline(cin, word);
                dictionary.search(word);
                break;

            case 3:
                dictionary.display();
                break;

            case 4:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "\nPlease enter a valid option." << endl;
                break;
        }
    } while (true);

    return 0;
}
