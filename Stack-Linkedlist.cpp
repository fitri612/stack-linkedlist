#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node(void) {
        data = 0;
        next = nullptr;
    }
}; // declare top

struct stack{
    node *top;
    int count;
    stack(void) {
        top = nullptr;
        count = 0;
    }
};

// declare Node
typedef struct node *Node; // no prob
// define maxx 5
// bool isfull(stack *s){
//     return (s->top == maxx)
// }

bool isEmpty(stack *s){
    return (s->top == nullptr);
}

// start stack
void push(stack *s, int value){
    Node TempNode;
    // Node CurNode;
    // node baru menambah secara dinamik
    TempNode = new node();
    TempNode->data = value;
    TempNode->next = nullptr;
    
    if (isEmpty(s))
        s->top = TempNode;
    else {
        TempNode->next = s->top;
        s->top = TempNode;
    }
}


// // start stack
// void push(stack *s, int value){
//     Node TempNode;
//     Node CurNode;
//     // int pushElement;

//     // node baru menambah secara dinamik
//     TempNode = new node();
    
//     // s->top == head
//     TempNode->data = value;
//     TempNode->next = nullptr;
    
//     if (isEmpty(s))
//         s->top = TempNode;
//     else {
//         // CurNode = s->top;
//         // while (CurNode->next != nullptr)
//         //     CurNode = CurNode->next;
//         // CurNode->next = TempNode;
//         TempNode->next = s->top;
//         s->top = TempNode;
//     }
// }
void pop(stack *s){
    Node TempNode;
    if (isEmpty(s))
        printf("\nYour stack is empty, Please create your stack ! \n");
    else{
        TempNode = s->top;
        s->top = TempNode->next;
        delete(TempNode);
    }    
}

void peek(stack *s){
    cout << "Top : " << s->top->data;
}

void showDisplay(stack *s){
    Node swap;
    cout << s->count;
    if(isEmpty(s))
        printf("\nYour stack is empty, Please create your stack ! \n");

    else{
        node* copy = s->top;
        printf("\nYour element stack is : \n");
        while(copy != nullptr){
            if(copy != nullptr){
                cout << "\n" << "| " << copy->data << " |";

            }
            copy = copy->next;
        }
        cout << "\n______\n";
        
    }
}

int main(){
    stack *s;
    s = new stack();
    // s = new stack();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 60);
    push(s, 23);
    push(s, 203);
    pop(s);
    // showDisplay(s);
    showDisplay(s);
    peek(s);
    return 0;
}