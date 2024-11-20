#include <bits/stdc++.h>
using namespace std;

int pageFaultsLFU(int pages[],int n,int capacity){
    unordered_map<int,int> freq;
    unordered_map<int,int> index;
    int pageFaults=0;
    for(int i=0;i<n;i++){
        if(freq.find(pages[i])==freq.end()){
            if(freq.size()==capacity){
                int lfuPage=-1,minFreq=INT_MAX;
                for(auto it=freq.begin();it!=freq.end();it++){
                    if(it->second<minFreq){
                        minFreq=it->second;
                        lfuPage=it->first;
                    }
                }
                freq.erase(lfuPage);
                index.erase(lfuPage);
            }
            freq[pages[i]]=1;
            index[pages[i]]=i;
            pageFaults++;
        }else{
            freq[pages[i]]++;
            index[pages[i]]=i;
        }
    }
    return pageFaults;
}

int main()
{
    int pages[]={1,3,0,3,5,6,3};
    int n=sizeof(pages)/sizeof(pages[0]);
    int capacity=3;
    cout<<"LFU PageFaults : "<<pageFaultsLFU(pages,n,capacity);
    return 0;
}
