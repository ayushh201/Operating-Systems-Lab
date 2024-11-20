#include <bits/stdc++.h>
using namespace std;

bool isFinished(vector<bool> &finished){
    for(bool status:finished){
        if(!status) return false;
    }
    return true;
}

bool canAllocate(vector<int> &need,vector<int> &available){
    for(int i=0;i<need.size();i++){
        if(need[i]>available[i]) return false;
    }
    return true;
}

void detectAndRecovery(vector<vector<int>> &allocation,vector<vector<int>> &maxNeed,vector<int> &available){
    int process=allocation.size();
    int resources=allocation[0].size();
    vector<vector<int>> need(process,vector<int>(resources,0));
    for(int i=0;i<process;i++){
        for(int j=0;j<resources;j++){
            need[i][j]=maxNeed[i][j]-allocation[i][j];
        }
    }
    queue<int> safeSequence;
    vector<bool> finished(process,false);
    cout<<"Initial State : ";
    cout<<"Available Resources : ";
    for(int res:available) cout<<res<<" ";
    cout<<endl;
    while(!isFinished(finished)){
        bool progress=false;
        for(int i=0;i<process;i++){
            if(!finished[i] && canAllocate(need[i],available)){
                for(int j=0;j<resources;j++){
                    available[j]+=allocation[i][j];
                }
                finished[i]=true;
                progress=true;
                safeSequence.push(i);
                break;
            }
        }
        if(!progress){
            cout<<"The system is in unsafe state ";
            cout<<"Deadlock detected recovery needed ";
            for(int i=0;i<process;i++){
                if(!finished[i]){
                    cout<<"Terminating process P "<<i<<" to release resources";
                    for(int j=0;j<resources;j++){
                        available[j]+=allocation[i][j];
                        allocation[i][j]=0;
                        need[i][j]=0;
                    }
                    finished[i]=true;
                    break;
                }
            }
        }
    }
    cout<<"The system is now in safe state ";
    while(!safeSequence.empty()){
        cout<<"P"<<safeSequence.front()<<" ";
        safeSequence.pop();
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
    detectAndRecovery(allocation,maxNeed,available);
    return 0;
}
