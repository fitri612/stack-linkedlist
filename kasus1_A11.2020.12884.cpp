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

// declare node baru dari struct node
typedef struct node *Node;

node* allocate(stack *s, int value){
    node *TempNode;
    TempNode = new node;
    TempNode->data = value;
    TempNode->next = nullptr;
    return TempNode; 
}

bool isEmpty(stack *s){
    return (s->top == nullptr);
}

// start stack
void push(stack *s, int value){
    Node Temp;
    Temp = allocate(s, value);
    if (isEmpty(s))
        s->top = Temp;
    else {
        Temp->next = s->top;
        s->top = Temp;
    }
    s->count++;
}

void pop(stack *s){
    Node TempNode;
    if (isEmpty(s))
        printf("\nYour stack is empty, Please create your stack ! \n");
    else{
        TempNode = s->top;
        s->top = TempNode->next;
        delete(TempNode);
    }    
    s->count--;
}

int NumberOfElement(stack *s){
    return s->count;
}

void showDisplay(stack *s){
    // Node swap;
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
    // declare stack pass by reference
    stack s;
    int option, inputdata;
    do{
        cout<<"Metode tersedia :"<<endl;
		cout<<"1. Push Stack"<<endl;
		cout<<"2. Pop Stack"<<endl;
		cout<<"3. Print Stack"<<endl;
		cout<<"4. Keluar Program"<<endl;
		cout<<"Pilih metode : "; 
        cin>>option;

        if(option == 1){
            cout << "Insert your data : ";
            cin >> inputdata;
            push(&s, inputdata);
        }
        else if(option == 2)
            pop(&s);
        else
            showDisplay(&s);
    }
    while(option != 4);
    return 0;
}