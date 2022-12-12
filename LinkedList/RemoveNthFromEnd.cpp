#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
}head;

class Linkedlist {
public:
    ListNode* head;
 
public:
    // Default constructor
    Linkedlist() { head = NULL; }
 
    // Function to insert a
    // node at the end of the
    // linked list.
    void insertNode(int);
 
    // Function to print the
    // linked list.
    void printList();
 
    // Function to delete the
    // node at given position
    void deleteNode(int);
};

// Function to insert a new node.
void Linkedlist::insertNode(int data)
{
    // Create the new Node.
    ListNode* newNode = new ListNode(data);
 
    // Assign to head
    if (head == NULL) {
        head = newNode;
        return;
    }
 
    // Traverse till end of list
    ListNode* temp = head;
    while (temp->next != NULL) {
 
        // Update temp
        temp = temp->next;
    }
 
    // Insert at the last.
    temp->next = newNode;
}

class Solution {
public:
    void printList(ListNode* head) {
        ListNode* temp = head;
 
	    // Check for empty list.
	    if (head == NULL) {
	        cout << "List empty" << endl;
	        return;
	    }
	 
	    // Traverse the list.
	    while (temp != NULL) {
	        cout << temp->val << " ";
	        temp = temp->next;
	    }
    }
    
    ListNode* middleNode(ListNode* &head) {
        ListNode* l1 = head;
        ListNode* l2 = head;
        
        while(l2 != NULL and l2->next != NULL)
        {
            l1 = l1->next;
            l2 = l2->next->next;
        }
        head = l1;
        return l1;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++) fast = fast->next;
        if (!fast) return head->next;
        while (fast->next) fast = fast->next, slow = slow->next;
        slow->next = slow->next->next;
        return head;
    }
};


int main(){
	
	Linkedlist list;
	list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);
    list.insertNode(5);
    
 	Solution sol;
 	sol.removeNthFromEnd(list.head, 2);
	sol.printList(list.head);
	
}
