//{ Driver Code Starts
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


// } Driver Code Ends
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

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        vector<Node*> ans;
        if(head == NULL )
        {
            ans.push_back(NULL);
            ans.push_back(NULL);
            return ans;
        }
        else if(head->next == NULL)
        {
            ans.push_back(head);
            ans.push_back(NULL);
            return ans;
        }
        
        else {
        
        Node* list1 = new Node(-1);
        Node*list2 = new Node(-1);
        Node*temp = head;
        Node*ans1 = list1;
        Node* ans2 = list2;
        
        
        
        int cnt = 0;
        while(temp != NULL)
        {
            if(cnt % 2 == 0)
            {
             Node* n = new Node(temp->data);
             list1->next = n;
             list1 = list1->next;
            }
            else if(cnt % 2 == 1)
            {
            Node* n = new Node(temp->data);
             list2->next = n;
             list2 = list2->next;
            }
            temp = temp->next;
            cnt++;
        }
        
        ans.push_back(ans1->next);
        ans.push_back(ans2->next);
        }
        return ans;
        
        
        
        
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

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

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends
