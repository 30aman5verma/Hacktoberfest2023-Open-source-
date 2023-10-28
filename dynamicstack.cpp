using namespace std;
#include<iostream>
#include<limits.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *top;
void push(int item)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->info = item;
    ptr->next = top;
    top = ptr;
}

int pop()
{
    int v = INT_MIN;
    struct node *ptr;
    if(top!=NULL)
    {
        v = top->info;
        ptr = top;
        top = top->next;
        free(ptr);
    }
    return v;
}

void display()
{
    struct node *ptr;
    ptr = top;
    while(ptr!=NULL)
    {
        cout<<ptr->info<<"->";
        ptr = ptr->next;
    }
}

void add()
{
    int num;
    cout<<"Enter the number to be added : ";
    cin>>num;
    push(num);
    cout<<"Number added";
}

void del()
{
    int num;
    num = pop();
    if(num!=INT_MIN)
    {
        cout<<"Deleted node : "<<num;
    }
    else
    {
        cout<<"Stack is empty";
    }
}

void show()
{
    cout<<"Stack is : ";
    cout<<"Top->";
    display();
    cout<<"NULL";
}

int main()
{
    int op;
    do
    {
        cout<<"\n\nStack Operations";
        cout<<"\n0. Exit";
        cout<<"\n1. Push";
        cout<<"\n2. Pop";
        cout<<"\n3. display";
        cout<<"\nEnter Choice : ";
        cin>>op;
        if(op==0) break;
        else if(op==1) add();
        else if(op==2) del();
        else if(op==3) show();
    }while(op!=0);
    return 0;
}
