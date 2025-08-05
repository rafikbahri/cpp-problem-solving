#include <iostream>

using namespace std;


class MyLinkedList {
public:
    int val;
    int length;
    MyLinkedList* prev;
    MyLinkedList* next;

    MyLinkedList() {
        this->val = 0;
        this->length = 0;
        this->prev = nullptr;
        this->next = nullptr;
    }

    MyLinkedList(int v) {
        this->val=v;
        this->length = 1;
        this->prev=nullptr;
        this->next=nullptr;
    }

    int get(int index) {
        if(index == 0){
            if (this->length == 0) {
                return -1;
            }
            return this->val;
        }
        if(index >= this->length || this->length == 0){
            return -1;
        }
        int i=0;
        MyLinkedList* current = this;
        while(i<index && current->next){
            i++;
            current = current->next;
        }
        return current->val;
    }

    void addAtHead(int val) {
        if(this->prev == nullptr && this->next==nullptr && this->val==0){
            this->val = val;
        }else{
            MyLinkedList* newNode = new MyLinkedList(val);
            int aux = this->val;
            this->val = newNode->val;
            newNode->val = aux;
            MyLinkedList* newNext = this->next;
            this->next = newNode;
            newNode->prev = this;
            newNode->next = newNext;
        }
        this->length++;
    }

    void addAtTail(int val) {
        if(this->length==0){
            this->val = val;
        }else{
            MyLinkedList* newNode = new MyLinkedList(val);
            MyLinkedList* current = this;
            while(current->next){
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
        this->length++;
    }

    void addAtIndex(int index, int val) {
        if(index == this->length){
            addAtTail(val);
        } else if (index == 0){
            addAtHead(val);
        } else if (index < this->length){
            int i = 0;
            MyLinkedList* current = this;
            MyLinkedList* previous = current->prev;
            // cout << "Start val: " << current->val << endl;
            while(i<index && current->next){
                i++;
                MyLinkedList* aux = current;
                current = current->next;
                current->prev = aux;
                previous = current->prev;
            }
            // cout<< "Current val: " << current->val << endl;
            MyLinkedList* newNode = new MyLinkedList(val);
            // cout<< "Previous val: " << previous->val << endl;
            newNode->next = current;
            newNode->prev = previous;
            current->prev = newNode;
            previous->next = newNode;
            this->length++;
        }
    }

    void deleteAtIndex(int index) {
        // first element
        if(index == 0){
            if(this->next == nullptr){
                this->val = 0;
                this->prev = nullptr;
                this->length--;
            }else{
                MyLinkedList* newHead = this->next;
                this->next = newHead->next;
                this->val = newHead->val;
                this->prev = nullptr;
                this->length--;
            }
        } // last element
        else if(index == length - 1){
            MyLinkedList* current = this;
            MyLinkedList* previous = current->prev;
            while(current->next){
                MyLinkedList* aux = current;
                current = current->next;
                current->prev = aux;
                previous = current->prev;
            }
            previous->next = nullptr;
            this->length--;
        } else if(index < this->length){
            // cout << "here" << endl;
            int i = 0;
            MyLinkedList* current = this;
            MyLinkedList* previous = current->prev;
            while(i<index && current->next){
                i++;
                MyLinkedList* aux = current;
                current = current->next;
                current->prev = aux;
                previous = current->prev;
            }
            if(i == index){
                MyLinkedList* nextToCurrent = current->next;
                previous->next = current->next;
                nextToCurrent->prev = previous;
                this->length--;
            }
        }
    }

    void print(){
        cout<<"print"<<endl;
        MyLinkedList* current = this;
        while(current){
            cout<< current->val << " ";
            current = current->next;
        }
        cout << endl;
        // cout << "Length of list: " << this->length <<endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    obj->print();
    cout<<obj->get(1)<<endl;
    obj->deleteAtIndex(1);
    obj->print();
    cout<<obj->get(1)<<endl;
    obj->print();
    cout<<obj->get(3)<<endl;
    obj->deleteAtIndex(3);
    obj->deleteAtIndex(0);
    obj->print();
    cout<<obj->get(0)<<endl;
    obj->deleteAtIndex(0);
    obj->print();
    cout<<obj->get(0)<<endl;
    return 0;
}