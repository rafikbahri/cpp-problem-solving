#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <string>

using namespace std;

class Solution {
    private:
        vector<int> heap;

        void heapify(vector<int>& arr){
            arr.push_back(arr[0]);
            arr[0] = INT_MAX;

            int n = arr.size();
            int curr = (n - 1) / 2;
            heap =  arr;

            while(curr > 0){
                int i = curr;
                // percolate down i
                while(2 * i < n){
                    if((2 * i + 1) < n && heap[2 * i + 1] > heap[i] && heap[2 * i + 1] > heap[2 * i]){
                        int tmp = heap[2 * i + 1];
                        heap[2 * i + 1] = heap[i];
                        heap[i] = tmp;
                        i = 2 * i + 1;
                    }  else if(heap[2 * i] > heap[i]){
                        int tmp = heap[2 * i];
                        heap[2 * i] = heap[i];
                        heap[i] = tmp;
                        i = 2 * i;
                    } else {
                        break;
                    }
                }
                curr--;
            }
        }

        int topAndPop(){
            int top = heap[1];

            // replace top with last elt in the list and percolate down
            heap[1] = heap[heap.size() - 1];
            // percolate down

            int i = 1;
            while(2 * i < heap.size()){
                if(2 * i + 1 < heap.size() && heap[2 * i + 1] > heap[i] && heap[2 * i + 1] > heap[2 * i]){
                    int tmp = heap[2 * i + 1];
                    heap[2 * i + 1] = heap[i];
                    heap[i] = tmp;
                    i = 2 * i + 1;
                } else if(heap[2 * i] > heap[i]){
                    int tmp = heap[2 * i];
                    heap[2 * i] = heap[i];
                    heap[i] = tmp;
                    i = 2 * i; 
                } else{
                    break;
                }
            }
            // pop last elt, since it got percolated down
            heap.pop_back();
            return top;
        }

        void push(int val){
            // add val to the end of the vector
            heap.push_back(val);

            // percolate up val
            int i = heap.size() - 1; // check this

            // while i still have a parent
            while(i / 2 > 0){
                if(heap[i] > heap[i / 2]){
                    int tmp = heap[i];
                    heap[i] = heap[i / 2];
                    heap[i / 2] = tmp;
                    i = i / 2;
                }else{
                    break;
                }
            }
        }

    public:
        int lastStoneWeight(vector<int>& stones) {
            if(stones.size() == 1)
                return stones[0];
            heapify(stones);
            
            // push(10);
            // cout<<"heap :: ";
            // for(int node : heap){
            //     cout<<node<<" ";
            // }
            // cout<<"\n";
            // cout<<"maxes :: ";
            // while(heap.size() > 1){
            //     cout<<topAndPop()<<", ";
            // }
            // cout<<"\n";
            while(heap.size() > 2){
                int max1 = topAndPop();
                int max2 = topAndPop();

                if(max1 - max2 > 0){
                    push(max1 - max2);
                }
            }
            if(heap.size() == 2)
                return topAndPop();
            return 0;
        }
    };

int main() {
    Solution sol;
    vector<int> t1 = {2,7,4,1,8,1};
    vector<int> t2 = {1};

    cout<<sol.lastStoneWeight(t1)<<endl;
    
    return 0;
}