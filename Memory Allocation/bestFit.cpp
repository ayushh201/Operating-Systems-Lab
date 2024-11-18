#include <bits/stdc++.h>
using namespace std;

void bestFit(vector<int> &blocks,int m,vector<int> &processes,int n)
{
    vector<int> allocation(n,-1);
    for(int i=0;i<n;i++){
        int bestIdx=-1;
        int bestFitSize=INT_MAX;
        for(int j=0;j<m;j++){
            if(blocks[j]>=processes[i] && blocks[j]-processes[i]<bestFitSize){
                bestFitSize=blocks[j]-processes[i];
                bestIdx=j;
            }
        }
        if(bestIdx!=-1){
            allocation[i]=bestIdx;
            blocks[bestIdx]-=processes[i];
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
    bestFit(blocks,m,processes,n);
    return 0;
}
