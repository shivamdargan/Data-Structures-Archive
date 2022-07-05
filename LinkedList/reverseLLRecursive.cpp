// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
#include "linkedList.cpp"
using namespace std;
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

node* reverseLL(node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    node *smallAns = reverseLL(head->next);
    node *temp = smallAns;
    while(temp->next != NULL)
    {
        temp = temp -> next;
    }
    temp->next = head;
    temp -> next = NULL;
    return smallAns;
}

void print(node *head_ref)
{
   
    node *p=head_ref;
    while(p != NULL)
    {
        // cout<<p->data<<endl;
        p=p->next;
    }
} 
int main()
{
	node *a=NULL;
    node *head = a;
    int n;
    cout<<"Enter The Number Of Elements"<<endl;
    cin>>n;
    int ele;
    for(int i=0;i< n; i++)
    {
        cin>>ele;
        push(&a,ele);
    }
    cout<<"________________"<<endl;
    node *q;
    cout<<head->data<<endl;
    q = reverseLL(a);
    cout<<"Reverse Linked List is :"<<endl;
    print(q);
    return 0;
}
