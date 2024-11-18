#include <bits/stdc++.h>
using namespace std;
void cScanDisk(vector<int> &request,int head,int diskSize,string direction){
    sort(request.begin(),request.end());
    vector<int> left,right,order;
    int totalseek=0;
    for(int i:request){
        if(i<head) left.push_back(i);
        else right.push_back(i);
    }

    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    if(direction=="left"){
        order.insert(order.end(),left.rbegin(),left.rend());
        order.push_back(0);
        order.push_back(diskSize-1);
        order.insert(order.end(),right.rbegin(),right.rend());
    }else{
        order.insert(order.end(),right.begin(),right.end());
        order.push_back(diskSize-1);
        order.push_back(0);
        order.insert(order.end(),left.begin(),left.end());
    }
    
    cout<<"Order of Execution "<<endl;
    for(int i=0;i<order.size();i++){
        cout<<order[i]<<" ";
        totalseek+=abs(head-order[i]);
        head=order[i];
    }
    cout<<"Seek Time "<<totalseek<<endl;
    
}
int main()
{
    int n,head,diskSize;
    string direction;
    cin>>n;
    vector<int> request(n);
    for(int i=0;i<n;i++){
        cin>>request[i];
    }
    cin>>head>>diskSize;
    cin>>direction;
    cScanDisk(request,head,diskSize,direction);
    return 0;
}
