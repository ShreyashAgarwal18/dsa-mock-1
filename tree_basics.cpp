 #include<bits/stdc++.h>
 #include<queue>
 using namespace std;

 class node{
    public: 
    int data;
    node* left;
    node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
 };

 node* buildTree(node* root){
    cout<< "Enter the data: "<< endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in the left of the tree: "<< endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in the right of the tree: "<< endl;
    root->right = buildTree(root->right);
    return root;
 }

 void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
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


void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void inorder_iter(node* root){
    if(root == NULL){
        return;
    }

    stack<node*> st;
    node* temp = root;
    st.push(temp);
    temp = temp->left;

    while(temp!=NULL || !st.empty()){
        while(temp!=NULL){
            st.push(temp);
            temp = temp->left;
        }
        temp = st.top();
        st.pop();
        cout<<temp->data<<" ";
        temp = temp->right;
    }

    cout<<endl;

}


void preorder(node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


void preorder_iter(node* root){
    if(root == NULL){
        return;
    }
    
    stack<node*> st;
    node* temp = root;
    while(temp!=NULL || !st.empty()){
        while(temp != NULL){
            st.push(temp);
            cout<<temp->data<<" ";
            temp = temp->left;
        }
        temp = st.top();
        st.pop();
        temp = temp->right;
    }
    cout<<endl;
}

void postorder(node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void postorder_iter(node* root){
    if(root == NULL){
        return;
    }

    stack<node*> st1,st2;
    if(root != NULL){
        st1.push(root);
        while(!st1.empty()){
            node* top = st1.top();
            st1.pop();
            st2.push(top);
            if(top->left!= NULL) st1.push(top->left);
            if(top->right=NULL) st1.push(top->right);
        }
        while(!st2.empty()){
            cout<<st2.top()<<" ";
            st2.pop();
        }
        cout<<endl;
    }
}

void buildFromlevelOrder(node* root){
    queue<node*>q;
    cout<<"enter the data for root:"<<" ";
    int data;
    cin>>data;
    root = new node(data);

    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter left node for: "<<temp->data<<endl;
        int leftdata;
        cin>> leftdata;

        if(leftdata!=-1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter right node for: "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata!= -1){
            temp->right = new node(rightdata);
            q.push(temp->right);

        }
    }
}

node* clone(node* root){
    if(root == NULL){
        return NULL;
    }
    node* temp = new node(root->data);
    temp->left = clone(root->left);
    temp->right = clone(root->right);
    return temp;
}

bool check_equal(node* root1, node* root2){
    bool a1;
    bool a2;
    bool a3;
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL || root2 == NULL){
        return false;
    }
    else{
        a1 = root1->data ==root2->data;
        a2 = check_equal(root1->left, root2->left);
        a3 = check_equal(root1->right, root2->right);
    }
    if(a1==true && a2==true && a3==true){
        return true;
    }
    else{
        return false;
    }
}

node* mirror(node* root){
    if(root == NULL){
        return NULL;
    }
    node* temp = new node(root->data);
    temp->left = mirror(root->right);
    temp->right = mirror(root->left);
    return temp;
}





int main(){

    node* root = NULL;
    // buildFromlevelOrder(root);
    // levelOrderTraversal(root);

   
    root = buildTree(root);

    cout<<"Printing level order traversal: "<<endl;
    levelOrderTraversal(root);

    cout<<"inorder traversal is: ";
    inorder(root);

    cout<<endl << "preorder traversal is: ";
    preorder(root);

    cout<<endl<<"postorder traversaL is: ";
    postorder(root);

    return 0;

}
