#include <iostream>

using namespace std;

class BrowserHistory {
public:
    string homepage;
    int currentPageIndex;
    BrowserHistory* prev;
    BrowserHistory* next;
    int historySize;
    BrowserHistory(string homepage) {
        this->homepage = homepage;
        this->historySize = 1;
        this->currentPageIndex = 0;
        this->prev = nullptr;
        this->next = nullptr;
    }
    
    void visit(string url) {
        BrowserHistory* visitUrl = new BrowserHistory(url);
        // go to current page
        BrowserHistory* currentPage = this;
        int i = 0;
        while(i<this->currentPageIndex){
            i++;
            currentPage = currentPage->next;
        }
        currentPage->next=visitUrl;
        visitUrl->prev=currentPage;
        this->currentPageIndex++;
        this->historySize = this->currentPageIndex + 1;
    }
    
    string back(int steps) {
        if(this->currentPageIndex<steps){
            this->currentPageIndex = 0;
            return this->homepage;
        }
        // go to currentPageIndex
        BrowserHistory* currentPage = this;
        int i = 0;
        while(i<this->currentPageIndex){
            i++;
            currentPage = currentPage->next;
        }
        // A B C D 
        // back(1) -> 4 - 1 - 1 = 2 
        // A B C D
        int j = 0;
        BrowserHistory* iterator = currentPage;
        while(j<steps){
            j++;
            iterator = iterator->prev;
        }
        this->currentPageIndex = this->currentPageIndex - steps;
        return iterator->homepage;
    }
    
    string forward(int steps) { // h = 5 ; current = 2 ; 3
        if(this->currentPageIndex + steps >= this->historySize){
            this->currentPageIndex = this->historySize - 1;
            BrowserHistory* iterator = this;
            while(iterator->next){
                iterator = iterator->next;
            }
            return iterator->homepage;
        }
        // go to currentPageIndex
        BrowserHistory* currentPage = this;
        int i = 0;
        while(i<this->currentPageIndex){
            i++;
            currentPage = currentPage->next;
        }
        int j = 0;
        BrowserHistory* iterator = currentPage;
        while(j<steps){
            j++;
            iterator = iterator->next;
        }
        this->currentPageIndex = this->currentPageIndex + steps;
        return iterator->homepage;
    }

    void print(){
        cout<<"==== Browser History ===="<<endl;
        BrowserHistory* iterator = this;
        int i = 0;
        while(iterator){
            cout<<"Index "<<i<< " - "<<iterator->homepage<<endl;
            iterator = iterator->next;
            i++;
        }
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main(){
    BrowserHistory* obj = new BrowserHistory("leetcode.com");
    obj->visit("google.com");
    obj->visit("facebook.com");
    obj->visit("youtube.com");
    obj->print();
    cout<<"Back 1: "<<obj->back(1) <<" - Current page index: "<<obj->currentPageIndex<<endl;
    cout<<"Forward 1: "<<obj->forward(1)<<" - Current page index: "<<obj->currentPageIndex<<endl;
    cout<<"Back 1: "<<obj->back(1) <<" - Current page index: "<<obj->currentPageIndex<<endl;
    cout<<"Back 2: "<<obj->back(2) <<" - Current page index: "<<obj->currentPageIndex<<endl;
    cout<<"Forward 1: "<<obj->forward(1)<<" - Current page index: "<<obj->currentPageIndex<<endl;
    cout<<"Forward 1: "<<obj->forward(1)<<" - Current page index: "<<obj->currentPageIndex<<endl;
    cout<<"Forward 1: "<<obj->forward(1)<<" - Current page index: "<<obj->currentPageIndex<<endl;
    cout<<"Forward 5: "<<obj->forward(5)<<" - Current page index: "<<obj->currentPageIndex<<endl;
    cout<<"Forward 2: "<<obj->back(2)<<" - Current page index: "<<obj->currentPageIndex<<endl;
    obj->visit("reddit.com");
    obj->visit("a.com");
    obj->visit("b.com");
    obj->visit("c.com");
    obj->print();
    cout<<"History size: "<<obj->historySize<<endl;
    // cout<<"Back 2: "<<obj->back(2) <<" - Current page index: "<<obj->currentPageIndex<<endl;
    // cout<<"Back 1: "<<obj->back(1) <<" - Current page index: "<<obj->currentPageIndex<<endl;
    // cout<<"Back 1: "<<obj->back(1) <<" - Current page index: "<<obj->currentPageIndex<<endl;
    return 0;
}