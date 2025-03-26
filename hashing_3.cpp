#include <iostream>
using namespace std;

class HashTable
{
public:
    int arr[10][2]; // arr[i][0] = key, arr[i][1] = next index in chain

    HashTable()
    {
        for (int i = 0; i < 10; i++)
        {
            arr[i][0] = -1; // Initialize all keys to -1 (empty)
            arr[i][1] = -1; // Initialize all chain links to -1 (no chaining)
        }
    }

    int hash(int value)
    {
        return value % 10;
    }

    bool isFull()
    {
        for (int i = 0; i < 10; i++)
        {
            if (arr[i][0] == -1)
            {
                return false;
            }
        }
        return true;
    }

    void insert(int n)
    {
        if (isFull())
        {
            cout << "Table is full, cannot insert " << n << endl;
            return;
        }

        int loc = hash(n);

        // If the location is empty, insert directly
        if (arr[loc][0] == -1)
        {
            arr[loc][0] = n;
            cout << "Inserted " << n << " at index " << loc << endl;
            return;
        }

        // Find the last element in the chain
        int prevLoc = loc;
        while (arr[loc][1] != -1)
        {
            prevLoc = loc;
            loc = arr[loc][1]; // Move to next linked index
        }

        // Find an empty slot for new value
        for (int i = 1; i < 10; i++)
        {
            int newLoc = (loc + i) % 10; // Linear probing for next empty slot

            if (arr[newLoc][0] == -1) // Found empty slot
            {
                arr[newLoc][0] = n;      // Insert the value
                arr[loc][1] = newLoc;    // Update the chain of previous location
                cout << "Inserted " << n << " at index " << newLoc << " (chained from " << loc << ")" << endl;
                return;
            }
        }

        cout << "No empty slot found for " << n << endl;
    }

    void search(int n)
    {
        int loc = hash(n);

        while (loc != -1)
        {
            if (arr[loc][0] == n)
            {
                cout << "Element " << n << " found at index " << loc << endl;
                return;
            }
            loc = arr[loc][1]; // Move through the chain
        }

        cout << "Element " << n << " not found" << endl;
    }

    void display()
    {
        cout << "\nIndex | Key  | Chain\n";
        cout << "-------------------\n";
        for (int i = 0; i < 10; i++)
        {
            cout << "  " << i << "   |  " 
                 << (arr[i][0] == -1 ? -1 : arr[i][0]) << "   |  "
                 << (arr[i][1] == -1 ? -1 : arr[i][1]) << endl;
        }
        cout << "-------------------\n";
    }
};

int main()
{
    HashTable table;
    int choice, value;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert value\n";
        cout << "2. Search value\n";
        cout << "3. Display hash table\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            table.insert(value);
            break;
        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            table.search(value);
            break;
        case 3:
            table.display();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}
