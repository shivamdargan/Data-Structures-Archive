// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
#include "linkedList.cpp"
using namespace std;
node *head = NULL;

int createHead()
{
      cout<<"---------"<<endl;
    if(head == NULL)
    {
        head = new node;
        cout<<"Enter Head Node"<<endl;
        cin>>head->data;
        head->next=NULL;
    }
    else
    {
        cout<<"Head Node Already Created !"<<endl;
    }

}

int midPoint()
{
    node *slow=head;
    node *fast = head;
    while(fast!= NULL && fast -> next  != NULL){
        slow = slow->next;
        fast = (fast->next)->next;
    }
    cout<<"Mid Point Of Linked List Is :"<<slow->data<<endl;
}

int insertAtPosition()
{
    if(head != NULL)
    {
            node *p,*q;
            p = head;
            int i=0,pos=0;
            cout<<"Enter The Position Where You Want To Enter The Number"<<endl;
            cin>>pos;
            while(i !=(pos-1))
            {
                p=p->next;
                ++i;
            }
     
            q= new node;
            cout<<"Enter The Number"<<endl;
            cin>>q->data;
            q->next=(p->next);
            p->next=q;
    }
    else{
        cout<<"LIST IS EMPTY"<<endl;
    }

}
int addToEnd()
{
      cout<<"---------"<<endl;
    if(head == NULL)
    {
        cout<<"List is empty, creating Head Node First ..."<<endl;
        createHead();
    }
    else
    {   
        node *p,*end;
        p=head;
        while (p->next !=NULL)
        {
            p=p->next;
        }
        end = new node;
        cout<<"Enter Element"<<endl;
        cin>>end->data;
        end->next= NULL;
        p->next= end;
    }
}
int deleteAtPosition()
{
    if(head != NULL)
    {
            node *p,*q;
            p = head;
            int i=0,pos=0;
            cout<<"Enter The Position Of The Number You Want To Delete"<<endl;
            cin>>pos;
            while(i !=(pos-1))
            {
                p=p->next;
                ++i;
            } 
            (p->next) = (p->next)->next;
    }
    else{
        cout<<"LIST IS EMPTY"<<endl;
    }

}
int addToBeg()
{
      cout<<"---------"<<endl;
      if(head == NULL)
      {
          cout<<"Head Is Not Created, Creating HEAD..."<<endl;
      }
      else
      {
          node *p,*q;
          q = new node;
          p=head;
          cout<<"Enter Element"<<endl;
          cin>>q->data;
          q->next=head;
          head=q;
      }
}
int print(node *ele=head)
{
      cout<<"---------"<<endl;
    if(head == NULL)
    {
        cout<<"List Is Empty"<<endl;
    }
    else
    {
        node *p;
        p= ele ;
        while(p != NULL)
        {
            cout<<p->data<<endl;
            p=p->next;
        }
    }
}
node* insertRecursive(node *head, int data, int pos)
{
    if(head == NULL || pos == 0)
    {
        node *newNode;
        newNode= new node;
        newNode->next = head;
        newNode->data= data;
        head = newNode;
    }
    else
    {
        insertRecursive(head->next , data, pos-1);
    }
    return head;
}

int main()
{
    int pos,ele;
    while(1)
    {
        cout<<"---------"<<endl;
        cout<<" 1. Create Head Node \n 2. Add Node To End \n 3. Add Node To Beginning \n 4. Print Linked List \n 5. Exit \n 6. Insert At N'th Position \n 7. Delete At i'th Position \n 8. Insert Recursively At i'th Position \n 9. MidPoint Of Linked List"<<endl;
        int ch;
        cin>>ch;
        switch (ch)
        {
        case 1:
            createHead();
            break;
        case 2:
            addToEnd();
            break;
        case 3:
            addToBeg();
            break;
        case 4: 
            print();
            break;
        case 5:
            exit(0);
        case 6:
            insertAtPosition();
            break;
        case 7:
            deleteAtPosition();
            break;
        case 8:
            cout<<"Enter Position"<<endl;
            cin>>pos;
            cout<<"Enter ELement"<<endl;
            cin>>ele;
            insertRecursive(head,ele, pos);
            break;
        case 9:
            midPoint();
            break;
        default:
            cout<<"Invalid Choice !!!!!"<<endl;
            break;
        }
    }
	
    return 0;
}
