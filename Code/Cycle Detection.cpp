/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) 
{
    // Complete this function
    // Do not write the main method
    if(head == NULL)
    	return false;
 	Node* slowPtr = head;
 	Node* fastPtr = head;
 	while(slowPtr->next != NULL && fastPtr->next != NULL && fastPtr->next->next != NULL)
 	{
 		slowPtr = slowPtr->next;
 		fastPtr = fastPtr->next->next;
 		if(slowPtr == fastPtr)
 			return true;
 	}
 	return false;  
}
