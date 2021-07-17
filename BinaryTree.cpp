#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    Node* left;
    Node* right;
    int data;
 
    
    Node (int val){
        data=val;
        left=NULL;
        right=NULL;
    }
    

};
 queue<Node*> q;

void PreOrder(Node* head)
{
    if(head == NULL)
    {
        return;
    }
    cout<<head->data<<" ";
    PreOrder(head->left);
    PreOrder(head->right);
}

void PostOrder(Node* head)
{
    if(head == NULL)
    {
        return;
    }

    PostOrder(head->left);
    PostOrder(head->right);
    cout<<head->data<<" ";
}

void InOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);

}
void LevelOrder(Node* head){
    q.push(head);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";

        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }

}


int SumAtKLevel(Node* head,int k){
    if(head==NULL){
        return 0;
    }
    if(head!=NULL && k==0){
        return head->data;
    }

    q.push(head);
    int level=0;
    int sum=0;
    int flag=0;
    //int node =1;
    while(!q.empty()){
        
        int size = q.size();
        while(size--)
        {
            Node* temp = q.front();
            q.pop();

            if(level == k)
            {
               flag=1;
               sum+=temp->data;
            }
            else
            {
                if(temp->left!=NULL)
                {
                    //node++;
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    //node++;
                    q.push(temp->right);
                }                                        
                
            }
            
        }
        level++;
        if(flag==1)
        {
            break;
        }
        
    }
    //cout<<"The total nodes present is "<<node<<endl;
    return sum;
}
int CountNodes(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return 1 + CountNodes(root->left) + CountNodes(root->right);
}

int SumOfNodes(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return root->data + SumOfNodes(root->left) + SumOfNodes(root->right);
}
int HeightOfTree(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftHeight = HeightOfTree(root->left);
    int rightHeight = HeightOfTree(root->right);

    if(leftHeight > rightHeight){
        return leftHeight + 1;
    }
    else{
        return rightHeight + 1;
    }
}

int Diameter(Node* root)
{
    if(root == NULL){
        return 0;
    }
    int lheight = HeightOfTree(root->left);
    int rheight = HeightOfTree(root->right);

    int ldiameter = Diameter(root->left);
    int rdiameter = Diameter(root->right);


    return max(1+lheight+rheight,max(ldiameter,rdiameter));
}

int main()
{
    Node* root = new Node(1);
    root->right = new Node(3);
    root->left=new Node(2);
    root->right->right = new Node(7);
    root->right->left=new Node(6);
    root->left->right = new Node(5);
    root->left->left=new Node(4);

    //Preorder Traversal
    cout<<"Preorder Traversal"<<endl;
    PreOrder(root);
    cout<<endl;

    //Inorder Traversal
    cout<<"Inorder Traversal"<<endl;
    InOrder(root);
    cout<<endl;

    //PostOrder Traversal
    cout<<"Postorder Traversal"<<endl;
    PostOrder(root);
    cout<<endl;

     //LevelOrder Traversal
    cout<<"LevelOrder  Traversal"<<endl;
    LevelOrder (root);
    cout<<endl;

    cout<<"Sum of elements at Kth level is "<<endl;
    cout<< SumAtKLevel(root,2)<<endl;

    //Count the total number of Nodes

    cout<<"The total nodes present are"<<endl;
    cout<<CountNodes(root)<<endl;

    cout<<"The sum of node values are"<<endl;
    cout<<SumOfNodes(root)<<endl;

    //Height Of a Binary Tree
    cout<<"The height of the binary tree is"<<endl;
    cout<<HeightOfTree(root)<<endl;

    cout<<"Diameter is "<<Diameter(root)<<endl;

}