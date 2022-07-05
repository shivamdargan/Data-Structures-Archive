// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
#include "linkedList.cpp"
using namespace std;
void print(node *head_ref)
{
   
    node *p=head_ref;
    while(p != NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
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
node* sortedMerge(node* &Head_a, node* &Head_b)
{
    node *p1=Head_a;
    
    node *p2=Head_b;
    
    node *dummyNode = new node;
    dummyNode->data = -1;
    node *p3=dummyNode;
    
    while(p1 !=NULL && p2 != NULL)
    {
      // cout<<p1->data<<endl;
        if(p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;

        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3=p3->next;
        
    }
   
   
    
    while(p1 !=NULL)
    {
        p3->next = p1;
        p3=p3->next;
        p1=p1->next;
    }
    
    while(p2 !=NULL)
    {
        p3->next = p2;
        p3=p3->next;
        p2=p2->next;
    }
    return dummyNode->next;
}


int main()
{
    node *res = NULL;
    node *a=NULL;
    node *b=NULL;
    //First Linked List
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    //Second Linked List
    push(&b, 20);
    push(&b, 3);
    push(&b, 2);
    cout<<a->data<<endl;
    cout<<b->data<<endl;
    res = sortedMerge(a,b);
    // print(res);
    return 0;
}
