#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int EleType;
typedef struct node
{
EleType data;
struct node *next;
struct node *previous;
}Node;

typedef struct node* List;

int Construct(List *L,EleType x);
void Destroy(List *L);
void display(List L);
int IsEmpty(List L);
Node* Advance(Node *p);
EleType Retrieve(Node* p);
Node* Return(Node *p);
int Delete(List *L ,EleType x);
int Insert(List *L, EleType x);
int Search (List L , EleType x);
int IsLast(List L);
int IsFirst(List L);

int main(void)
{
List L;
int x; int key=1;
while(key==1){
cout<<"enter your choice \n1.create list \n2.add element \n3.delete element \n4.print data \n5.search";
cin>>x;
switch(x){
case(1):
    cout<<"enter element\n";
    int y;
    cin>>y;
    Construct(&L , y);

cout<<"press 1 to repeat operation or any key to continue";
cin>>key;
break;

case(2):
    cout<<"enter element\n";
    int z;
    cin>>z;
    Insert(&L ,z);

cout<<"press 1 to repeat operation or any key to continue";
cin>>key;
break;

case(3):
    cout<<"enter element\n";
    int g;
    cin>>g;
    Delete(&L,g);
if(Delete(&L,g))
cout<<"not found";
else
cout<<"deleted";
cout<<"press 1 to repeat operation or any key to continue";
cin>>key;
break;

case(4):
    display(L);

cout<<"press 1 to repeat operation or any key to continue";
cin>>key;

break;

case(5):
    cout<<"enter element\n";
    cin>>g;
    Search(L,g);


cout<<"press 1 to repeat operation or any key to continue";
cin>>key;

break;

default:
cout<<"enter proper choice";
break;
}
}




}


int Construct(List *L,EleType x)
{
Node* P;
P=(Node*)malloc(sizeof(Node));
if(IsEmpty(P)){
cout<<"Error\n";
return 0;
}
else {
P->data=x;
P->next=NULL;
P->previous=NULL;
*L=P;
return 1;
}
}
void Destroy(List *L)
{
Node *P, *Tmp;
P = *L;
while(!IsEmpty(P)) {
Tmp = P->next;
free(P);
P = Tmp;
}
}
void display(List L)
{
    Node* P;
P=L;
if (IsEmpty(P)){
cout<<"[Empty list]\n";
}
else {
while(!IsEmpty(P))
{
    cout<<" "<<Retrieve(P);
    P=P->next;
}
}
}
int IsLast(List L)
{
Node *P;
P=L;
return P->next==NULL;
}
int IsFirst(List L)
{
Node *P ;
P=L;
return P->previous==NULL;
}
int IsEmpty(List L)
{
Node *P;
P=L;
return P==NULL;
}
Node* Advance(Node *P)
{
return P->next;
}
Node* Return(Node *p)
{
    return p->previous;
}
EleType Retrieve(Node* P)
{
return P->data;
}
int Insert(List *L, EleType x)
{
    Node *p ,*q; p=*L;
    q=(Node*)malloc(sizeof(Node));
if (IsEmpty(p)){
cout<<"Error\n";
return 0;
}
else {
        if(x>p->data){
        while(x>p->data){
         Advance(p);
}
if(!IsLast(q)){
q->data=x;
q->next=q->next;
p->next=q;
q->previous=p;
}
else if (IsLast(q)){
q->data=x;
q->next=NULL;
p->next=q;
q->previous=p;
}}
else if(x<p->data)
{
    q->data=x;
    q->next=p;
    q->previous=NULL;
    *L=q;
}


return 1;}

}
int Search (List L , EleType x)
{
    Node* p;
    p= L;
while(p != NULL && p->data != x) {
p = Advance(p);
}
return p->data;
}

int Delete(List *L ,EleType x)
{Node* p, *tmp;
p=*L;
if (IsEmpty(p)){
cout<<"Error\n";
}
else {
       if(p->data==x)
    {
        tmp=p;
        p=p->next;
        p->previous=NULL;
        free(tmp);
        return 1;
    }
    else if(p->data!=x)
    {
        while(p->data!=x)
            Advance(p);
        if(IsLast(p))
        {
            tmp=p;
        p=p->previous;
        p->next=NULL;
        free(tmp);
        return 1;
        }
        tmp=p;
        p=p->next;
        p->previous=tmp->previous;
        free(tmp);
        return 1;

    }
}
return 0;
}


















