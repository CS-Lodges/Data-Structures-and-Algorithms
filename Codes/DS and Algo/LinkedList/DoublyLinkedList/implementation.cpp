#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *previous; //this address part is extra in case of doubly!
};

//  Inserting
Node* insertAtEnd(Node *head , int value){
    Node *newNode = new Node;
    if(head == NULL){
        head = newNode;
        newNode->previous = NULL;
        newNode->data = value;
        newNode->next = NULL;
        return head;   
    }   
        Node *p  = head;
        while(p->next!=NULL){
            p = p->next;
        }

        p->next = newNode;
        newNode->previous = p;
        newNode->data = value;
        newNode->next = NULL;
        return head;
}
Node* insertAtStart(Node *head , int value){
    Node *newNode = new Node;
    if(head == NULL){
        head = newNode;
        newNode->previous = NULL;
        newNode->data = value;
        newNode->next = NULL;
        return head;
    }

    newNode->previous = NULL;
    newNode->data = value;
    newNode->next = head;
    return newNode;

}
void insertAtPosition(Node *head , int value , int position){
    Node *newNode = new Node;
    int i = 1;
    Node *p = head;
    while(i!=position-1){
        p = p->next;
        i++;
    }
    Node *q = p->next;
    p->next = newNode;
    newNode->data = value;
    newNode->previous = p;
    newNode->next = q;
    q->previous = newNode;


}
void insertAfterPosition(Node *head , int value , int position){
    Node *newNode = new Node;
    int i = 1;
    Node *p = head;
    while(i!=position){
        p = p->next;
        i++;
    }
    Node *q = p->next;
    p->next = newNode;
    newNode->data = value;
    newNode->previous = p;
    newNode->next = q;
    q->previous = newNode;


}
void insertBeforePosition(Node *head , int value , int position){
    Node *newNode = new Node;
    int i = 1;
    Node *p = head;
    while(i!=position-2){
        p = p->next;
        i++;
    }
    Node *q = p->next;
    p->next = newNode;
    newNode->previous = p;
    newNode->data = value;
    newNode->next = q;
    q->previous = newNode;

}


// deleting
Node* deleteFromFirst(Node *head){
    Node *p = head;
    Node *q = head->next;
    q->previous = NULL;
    delete(p);
    return q;
}
void deleteFromLast(Node *head){
    Node *p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    Node *q = p->previous;
    q->next = NULL;
    delete(p);
}
void deleteAtPosition(Node *head , int position){
    int i = 1;
    Node *p = head;
    while(i!=position-1){
        p = p->next;
        i++;
    }
    Node *f = p->next;
    Node *q = p->next->next;
    p->next = q;
    q->previous = p;
    // good practice is to diminish the links
    f->next = NULL;
    f->previous = NULL;
    delete(f);
}
Node* deleteWithKey(Node *head , int key){
    // if head is NULL;
    if(head == NULL){
        return head;
    }
    // delete at start logic
    if(head->data == key){
        Node *p = head;
        head = head->next;
        head->previous = NULL;
        p->next = NULL;
        p->previous = NULL;
        delete (p);
        return head;
    }
    // delete at end logic
    Node*p = head;
    while(p->next!= NULL){
        p = p->next;
    }
    if (p->data == key){

        Node *q = p->previous;
        q->next = NULL;
        p->previous = NULL;
        delete(p);
        return head;
    }
    // delete somewhere in between the nodes
    p = head->next;
    while(p->data!=key){
        p = p->next;
    }
    Node *q = p->previous;
    Node *r = p->next;
    q->next = r;
    r->previous = q;
    p->next = NULL;
    p->previous = NULL;
    delete(p);
    return head;

}

// Traversal
void normalTraversal(Node *head){
    Node *p = head;
    while(p!=NULL){
        cout<<p->data<<endl;
        p = p->next;
    }

}
void reverseTraversal(Node *head){
    Node *p = head;
    while(p->next!=NULL){
        p=p->next;
    }
    while(p!=NULL){
        cout<<p->data<<endl;
        p = p->previous;
    }
}
void twoWaysTraversal(Node *head){
    normalTraversal(head);
    reverseTraversal(head);
}

int main(){
    Node *head = NULL;
    head = insertAtEnd(head,45);
    head = insertAtEnd(head,47);
    head = insertAtEnd(head,49);
    head = insertAtEnd(head,1);
    head = insertAtEnd(head,2);
    head = insertAtEnd(head,3);
    head = insertAtEnd(head,4);
    head = insertAtEnd(head,5);
    // head = insertAtStart(head,12);
    // insertAtPosition(head,1,3);
    // insertAfterPosition(head,555,4);
    // insertBeforePosition(head,777,4);
    // head = deleteFromFirst(head);
    // deleteFromLast(head);
    // deleteFromLast(head);
    // deleteAtPosition(head,2);
// head = deleteWithKey(head,5);

    // normalTraversal(head);
    // reverseTraversal(head);
    twoWaysTraversal(head);





return 0;
}