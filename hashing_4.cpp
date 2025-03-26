#include<bits/stdc++.h>


using namespace std;

class hashTable{
    private:
    vector<list<string>>table;

    int hashfunc(const string& word){
        int hash = 0;
        int multiplier = 1;
        int mod = table.size();

        for(int i = word.size() - 1 ; i>=0; i--){
            hash = (hash + (word[i] * multiplier)) % mod;
            multiplier = (multiplier * 10) % mod;
        }
        return hash;
    }

    public: 
    hashTable(int size){
        table.resize(size);
    }

    void insert(const string& word){
        int index = hashfunc(word);
        table[index].push_back(word);
    }

    bool search(const string& word){
        int index = hashfunc(word);
        auto it = find(table[index].begin(), table[index].end(), word);

        if(it != table[index].end()){
            cout<<"found"<<endl;
            return true;
        }

        cout<<"not found"<<endl;
        return false;
    }

    void display(){
        cout<< "contents: " <<endl;
        for(int i = 0; i<table.size(); ++i){
            cout<< "bucket" << i <<" ";
            for(const string& word : table[i]){
                cout<< word << "->";
            }
            cout<<"NULL"<<endl;
        }
    }
};


int main() {
    hashTable hashTable(10);  // Create hash table with 10 buckets

    int opt;
    string key;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Element\n";
        cout << "2. Search Element\n";
        cout << "3. Display Table\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> opt;

        switch (opt) {
            case 1:
                cout << "\nEnter the element: ";
                cin >> key;
                hashTable.insert(key);
                break;
            case 2:
                cout << "\nEnter the element to search: ";
                cin >> key;
                hashTable.search(key);
                break;
            case 3:
                hashTable.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "\nPlease enter a correct option." << endl;
                break;
        }
    } while (true);

    return 0;
}