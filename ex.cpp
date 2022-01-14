#include <iostream>
#define Maxx 7
using namespace std;

struct stack{
    int data;
    int data2 = 0;
    stack * top;
    stack * next;
};

int banyak_angka(stack * r){
    return r->data2;
}

bool isFull(stack * r){
    return banyak_angka(r) == Maxx;

}

bool isEmpty(stack * r){
    if (banyak_angka(r) == 0){
        return true;
    }
    else{
        return false;
    }
}

stack *alokasi(stack * r){
    stack *NodeBaru;
    NodeBaru = new stack;
    return NodeBaru;
}

void push(stack * r, int angka){
        stack * NodeBaru;
        NodeBaru = alokasi(r);
        NodeBaru->data = angka;
        NodeBaru->next = NULL;
        if(isEmpty(r)){
            r->top = NodeBaru;
        }
        else{
            NodeBaru->next = r->top;
            r->top = NodeBaru;

        }
        r->data2++;
    
}

void pop(stack *r){
    stack *tamp;
    if(isEmpty(r)){
        cout << "data kosong" << endl;
    }
    else{
        tamp = r->top;
        r->top = tamp->next;
        delete tamp;
    }
}

void print(stack * r){
    if (isEmpty(r)){
        cout << "Data Masih kosong...!" << endl;
    }
    else{
        stack * temp;
        temp = r->top;
        while (temp != NULL){
            if (temp != NULL){
                cout << "DATA : " << temp->data << endl;
            }
            temp = temp->next;
        }
    }

}

int main(){
    stack r;
    // data terbawah
    push (&r, 7);
    // data tengah
    push (&r, 8);
    // data teratas
    push (&r, 1);
    pop (&r);
    print (&r);
}