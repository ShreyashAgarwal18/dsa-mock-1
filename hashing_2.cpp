#include <bits/stdc++.h>
using namespace std;

void insert(int hash[][2], int key){
    int tempHash = key%10;
    int loc = tempHash;
    while(true){
        if(hash[loc][0] == -1){
            hash[loc][0] = key;
            break;
        }
        else if(hash[loc][1] != -1 && hash[loc][0]%10 == tempHash){
            loc = hash[loc][1];
        }
        else if(hash[loc][1] == -1 && hash[loc][0]% 10 == tempHash){
            int temploc = (loc + 1)%10;

            while(hash[temploc][0]!= -1){
                temploc = (temploc+1)%10;
                if(temploc == loc){
                    cout<<"table is full"<<endl;
                    return;
                }
            }
            hash[temploc][0] = key;
            hash[loc][1] = temploc;
            break;
        }
        else{
            loc = (loc + 1) % 10;
        } 
    }
}

void search(int hash[][2], int key){
    int loc = key % 10;

    while(loc != -1){
        if(hash[loc][0] == key){
            cout<< key << "found at" << loc <<endl;
            return;
        }
        loc = hash[loc][1];
    }
    cout<<"not found"<<endl;
}

bool isFull(int hash[][2]){
    for(int i = 0; i < 10; i++){
        if(hash[i][0] == -1){
            return false;
        }
    }
    return true;
}

void display(int hash[][2]){
    cout<< "Index key chain" <<endl;
    for(int i = 0; i<10; i++){
        cout<< i << "    " << (hash[i][0]== -1 ? "-1": to_string(hash[i][0]))
        << "      " << (hash[i][1] == -1 ? "-1" : to_string(hash[i][1]))<<endl;
    }
}

int main(){
    int hash[10][2];

    for(int i = 0; i<10; i++){
        hash[i][0] = -1;
        hash[i][1] = -1;
    }

    string menu = "Enter your choice: \n1. Add Element\n2. Search Element\n3. Display Table\n4. Exit";
    int opt, key;


    do{
        cout<<menu<<endl;
        cout<<"your choice: "<<endl;
        cin>>opt;

        switch(opt){
            case 1:
            if (isFull(hash)){
                cout<<"table full"<<endl;
                break;
            }
            cout<<"Enter element: "<<" ";
            cin>>key;
            insert(hash,key);
            break;

            case 2:
            cout<<endl;
            cout<<"enter element to search:"<<endl;
            cin>>key;
            search(hash, key);
            break;


            case 3:
            display(hash);
            break;


        case 4:
        exit(0);


        default:
        cout << endl;
        cout << "Please enter correct option."<<endl;
        break;
        }
    
        }while(true);

        return 0;
    }
 

