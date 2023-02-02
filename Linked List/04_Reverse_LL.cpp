////////////////////////////////-- BRUTE FORCE SOLUTION ---//////////////////////////////////
#include <bits/stdc++.h> 
#include <bits/stdc++.h> 


LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int>* curr=head;
    LinkedListNode<int>* prev=NULL;
    LinkedListNode<int>* forward=NULL;

    while(curr != NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        
    }
    return prev;
}

////////////////////////////////////---RECURSIVE SOLUTION---///////////////////////////////////

void reverse(LinkedListNode<int>* &head , LinkedListNode<int> *curr , LinkedListNode<int> *prev){
    //base case
     if(curr == NULL){
         head=prev;
         return;
     } 

     LinkedListNode<int> *forward=curr->next;
     reverse(head , forward , curr);
     curr->next=prev;
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int>* curr=head;
    LinkedListNode<int>* prev=NULL;
    reverse(head , curr , prev);
    return head;
}
