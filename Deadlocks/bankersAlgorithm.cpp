#include <bits/stdc++.h>
using namespace std;

bool canAllocate(vector<int> &need,vector<int> &available){
    for(int i=0;i<need.size();i++){
        if(need[i]>available[i]) return false;
    }
    return true;
}

void bankersAlgorithm(vector<vector<int>> &allocation,vector<vector<int>> &maxNeed,vector<int> &available){
    int process=allocation.size();
    int resources=allocation[0].size();
    vector<vector<int>> need(process,vector<int>(resources,0));
    for(int i=0;i<process;i++){
        for(int j=0;j<resources;j++){
            need[i][j]=maxNeed[i][j]-allocation[i][j];
        }
    }
    vector<int> safeSequence;
    vector<bool> finished(process,false);
    
    while(safeSequence.size()<process){
        bool progress=false;
        for(int i=0;i<process;i++){
            if(!finished[i] && canAllocate(need[i],available)){
                for(int j=0;j<resources;j++){
                    available[j]+=allocation[i][j];
                }
                finished[i]=true;
                safeSequence.push_back(i);
                progress=true;
                break;
            }
        }
        if(!progress){
            cout<<"The system is in unsafe state ";
            return;
        }
    }
    cout<<"The system is in safe state ";
    for(int process : safeSequence){
        cout<<"P"<<process<<" ";
    }
    cout<<endl;
}

int main()
{
    int process,resources;
    cout<<"Enter no. of process ";
    cin>>process;
    cout<<"Enter no. of resources ";
    cin>>resources;
    vector<vector<int>> allocation(process,vector<int>(resources,0));
    vector<vector<int>> maxNeed(process,vector<int>(resources,0));
    vector<int> available(resources,0);
    cout<<"Enter Allocation matrix \n";
    for(int i=0;i<process;i++){
        for(int j=0;j<resources;j++){
            cin>>allocation[i][j];
        }
    }
    cout<<"Enter Maximum matrix \n";
    for(int i=0;i<process;i++){
        for(int j=0;j<resources;j++){
            cin>>maxNeed[i][j];
        }
    }
    cout<<"Enter Available matrix \n";
    for(int i=0;i<resources;i++){
        cin>>available[i];
    }
    bankersAlgorithm(allocation,maxNeed,available);
    return 0;
}
