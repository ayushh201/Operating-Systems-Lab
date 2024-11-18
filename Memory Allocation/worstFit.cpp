#include <bits/stdc++.h>
using namespace std;

void worstFit(vector<int> &blocks,int m,vector<int> &processes,int n)
{
    vector<int> allocation(n,-1);
    for(int i=0;i<n;i++){
        int worstIdx=-1;
        int worstFitSize=-1;
        for(int j=0;j<m;j++){
            if(blocks[j]>=processes[i] && blocks[j]-processes[i]>worstFitSize){
                worstFitSize=blocks[j]-processes[i];
                worstIdx=j;
            }
        }
        if(worstIdx!=-1){
            allocation[i]=worstIdx;
            blocks[worstIdx]-=processes[i];
        }
    }
    cout<<"PROCESS NO. \t PROCESS SIZE \t BLOCK NO. \n";
    for(int i=0;i<n;i++){
        if(allocation[i]!=-1){
            cout<<i+1<<"\t"<<processes[i]<<"\t"<<allocation[i]+1<<endl;
        }else{
            cout<<i+1<<"\t"<<processes[i]<<"\t"<<"Not Allocated"<<endl;
        }
    }
}

int main()
{
    vector<int> blocks={100,500,200,300,600};
    int m=blocks.size();
    vector<int> processes={212,417,112,426};
    int n=processes.size();
    worstFit(blocks,m,processes,n);
    return 0;
}
