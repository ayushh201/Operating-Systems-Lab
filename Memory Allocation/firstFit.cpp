#include <bits/stdc++.h>
using namespace std;

void firstFit(int block[],int m,int process[],int n)
{
    int allocation[n];
    vector<int> blockcopy(m,-1);
    memset(allocation,-1,sizeof(allocation));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(block[j]>=process[i] && blockcopy[j]==-1){
                allocation[i]=j;
                block[j]-=process[i];
                blockcopy[j]=0;
                break;
            }
        }
    }
    cout<<"Process no. \t Process size \t Block no.\n";
    for(int i=0;i<n;i++){
        cout<<" "<<i+1<<"\t"<<process[i]<<"\t";
        if(allocation[i]!=-1){
            cout<<allocation[i]+1;
        }else{
            cout<<"Not allocated ";
        }
        cout<<endl;
    }
}
int main()
{
    int block[]={100,500,200,300,600};
    int process[]={212,417,112,426};
    int m=sizeof(block)/sizeof(block[0]);
    int n=sizeof(process)/sizeof(process[0]);
    firstFit(block,m,process,n);
    return 0;
}
