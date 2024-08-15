//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    // Node* reverse(Node*head)
    // {
    //     Node*curr=head;
    //     Node*prev=NULL;
    //     while(curr)
    //     {
    //         Node*next=curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=next;
    //     }
    //     return prev;
    // }
    int helper(Node*temp)
    {
        if(temp==NULL)
        {
            return 1;
        }
        int carry=helper(temp->next);
        temp->data=temp->data+carry;
        if(temp->data<10)
        return 0;
        else
        {
            temp->data=0;
            return 1;
        }
    }
    
    Node* addOne(Node *head) 
    {
        int carry=helper(head);
        if(carry==1)
        {
            Node*temp=new Node(1);
            temp->next=head;
            return temp;
        }
        return head;
        
        
    //     if(head==NULL)
    //     return head;
        
    //     head=reverse(head);
        
    //     Node*curr=head;
    //     int carry=1;
    //     while(curr!=NULL)
    //     {
    //       curr->data=curr->data+carry;
    //       if(curr->data<10)
    //       {
    //           carry=0;
    //           break;
    //       }
    //       else
    //       {
    //           curr->data=0;
    //           carry=1;
    //       }
    //       curr=curr->next;
    //     }
    //     if(carry==1)
    //     {
    //         Node*n=new Node(1);
    //         head=reverse(head);
    //         n->next=head;
    //         head=n;
    //         return head;
    //     }
        
    //   head= reverse(head);
    //     return head;
        
        // Your Code here
        // return head of list after adding one
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends