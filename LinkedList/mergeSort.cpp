// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
#include"linkedList.cpp"
using namespace std;
void printList(node* a)
{
    while (a != NULL) {
        cout << a->data << " ";
        a = a->next;
    }
}
 

void push(node** head_ref, int new_data)
{
    /* allocate node */
    node* new_node = new node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

void frontBackSplit(node *head, node **frontRef, node **backRef)
{
    node *fast;
    node *slow;
    slow = head;
    fast = head->next;
    while (fast != NULL )
    {
        fast = fast -> next;
        if(fast != NULL)
        {
            slow = slow -> next;
            fast = fast->next;
        }
        cout<<slow->data<<endl;
    }
    // SLOW IS ONE INDEX BEFORE THE MIDPOINT OF THE LIST
    *frontRef= head;
    *backRef = slow->next;
    // cout<<slow->data<<endl;
    slow->next = NULL;
}
node* sortedMerge(node *a, node *b)
{
    node *result = NULL;
    //BASE CASES
    if(a == NULL)
    {
        return(b);
    }
    else if(b == NULL)
    {
        return(a);
    }
    //RECURSIVE CASES
    if(a->data <= b->data)
    {
        result = a;
        result->next = sortedMerge(a->next,b);
    }
    else
    {
        result = b ;
        result->next = sortedMerge(a,b->next);
    }
    return result;
}
void mergeSort(node **head_ref)
{   
    node *head = *head_ref;
    //LENGTH 0 OR 1 ARRAY
    if((head == NULL) || (head->next == NULL))
    {
        return;
    }
    node *a;
    node *b;

    frontBackSplit(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    // MERGE TWO SORRTED ARRAYS
      

    *head_ref = sortedMerge(a,b);
}

int main()
{
	
    /* Start with the empty list */
    node* res = NULL;
    node* a = NULL;
 
    /* Let us create a unsorted linked lists to test the functions
Created lists shall be a: 2->3->20->5->10->15 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);
 
    mergeSort(&a);
    printList(a);
    return 0;
}
