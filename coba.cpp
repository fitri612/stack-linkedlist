#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
typedef struct node Node;

struct List{
    node *Top;
};
typedef struct List Stack;


bool isEmpty(Stack *s){
    if (s->Top == NULL){
        return true;
    } // kosong
    else{
        return false;
    } //ada isinya
}


node *alokasi(int x){
    Node *temp;
    temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void push(Stack *s, int x){
    Node *temp;
    temp = alokasi(x);
    if (isEmpty(s)==true){
        s-> Top= temp;
    }
    else{
        temp-> next= s->Top;
        s->Top = temp;
    }
}

void pop(Stack *s){
    Node *hapus;
    hapus = s-> Top;
    if (isEmpty(s)==false){ //Stack tidak kosong
        cout<<"Element yang didapus: "<< hapus->data <<endl;
        s->Top = s->Top->next; //Top Mundur
        delete hapus;
    }
    else{
        cout<<"Stack Kosong"<<endl;
    }
}

void cetak(Stack *s){
    Node *temp;
    temp = s-> Top;
    int count = 0;
    while (temp != nullptr){ //list tidak kosong
        if (temp != nullptr){
            cout<< temp->data;
            cout<<" -> ";
            // break;
        }
        else{
            cout<<endl;
        }
        count++;
        temp = temp -> next;
    }
    // cout << "\nCount : \n" << count;
}

void numberOfElement(Stack *s){
    Node *temp;
    temp = s-> Top;
    int count = 0;
    while (temp != nullptr){ //list tidak kosong
        count++;
        temp = temp -> next;
    }
    cout << "\nCount : \n" << count;
}

int main(){
    Stack *s;
    s = new Stack();
    // s = new stack();
    push(s, 10);
    push(s, 20);
    push(s,7);
    // pop(s);
    cetak(s);
    numberOfElement(s);
    return 0;
}