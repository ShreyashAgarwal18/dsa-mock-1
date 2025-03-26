#include<iostream>
#include<queue>
using namespace std;

class Node{
    public: 
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this -> left = NULL;
        this->right = NULL;
    }

};

Node* insertIntoBst(Node* &root, int d){
    //base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data){
        root->right = insertIntoBst(root->right, d);
    }
    else{
        root -> left = insertIntoBst(root->left, d);
    }

    return root;

}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data!= -1){
        insertIntoBst(root, data);
        cin>>data;
    }


}

void levelOrderTraversal(Node* &root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
 }

 void inorder(Node* &root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* &root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* &root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

bool searchInBst(Node* root, int x){


    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }

    if(root->data>x){
        return searchInBst(root->left, x);
    }
    else{
        return searchInBst(root->right, x);
    }
}


Node* minVal(Node* root){
    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left; 
    }
    return temp;
}

Node* maxVal(Node* root){
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp->right; 
    }
    return temp;
}

Node* deleteBst(Node* root, int val){
    //base case
    if(root == NULL){
        return root;
    }

    if(root->data == val){
        //0 child
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }
        //1 child
        //leftchild
    if(root ->left != NULL && root->right == NULL){
        Node* temp = root->left;
        delete root;
        return temp;
    }
    if(root ->left == NULL && root->right != NULL){
        Node* temp = root->right;
        delete root;
        return temp;
    }

    //2 child
    if(root->left != NULL && root->right != NULL){
         int mini = minVal(root->right)->data;
         root->data = mini;
         root->right = deleteBst(root->right,mini);
         return root;

    }
    }

    else if(root->data>val){
       root->left = deleteBst(root->left, val); 
     
    }
    else{
        root->right = deleteBst(root->right, val);
       
    }
    return root;
}

int main(){
    
    Node* root = NULL;
    cout<<"Enter data to create BST"<<endl;
    takeInput(root);


    root  = deleteBst(root,30);
    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);

   

    cout<<"Printing inorder"<<endl;
    inorder(root);
    
    cout<<endl;

    cout<<"Printing preorder"<<endl;
    preorder(root);
    
    cout<<endl;

    cout<<"Printing postorder"<<endl;
    postorder(root);

    cout<<endl;

    cout<<"searching for x:"<<endl;
    int x;
    cin>>x;
    if(searchInBst(root,x)){
        cout<<"element found"<<endl;
    }
    else{
        cout<<"element not found"<<endl;
    }
     
    cout<<endl;

    cout<<"min value is: "<< minVal(root)->data<<endl;
    cout<<"max value is: "<< maxVal(root)->data<<endl;

  

    

    return 0;

    


}
