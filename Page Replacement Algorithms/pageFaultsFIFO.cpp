#include <bits/stdc++.h>
using namespace std;

int pageFaultsFIFO(int pages[],int n,int capacity){
    unordered_set<int> pageSet;
    queue<int> pageQueue;
    int pageFaults=0;
    for(int i=0;i<n;i++){
        if(pageSet.find(pages[i])==pageSet.end()){
            if(pageSet.size()==capacity){
                int oldest=pageQueue.front();
                pageQueue.pop();
                pageSet.erase(oldest);
            }
            pageSet.insert(pages[i]);
            pageQueue.push(pages[i]);
            pageFaults++;
        }
    }
    return pageFaults;
}

int main()
{
    int pages[]={1,3,0,3,5,6,3};
    int n=sizeof(pages)/sizeof(pages[0]);
    int capacity=3;
    cout<<"FIFO PageFaults : "<<pageFaultsFIFO(pages,n,capacity);
    return 0;
}
