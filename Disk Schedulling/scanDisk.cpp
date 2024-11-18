#include <bits/stdc++.h>
using namespace std;
void scanDisk(vector<int> &request,int head,int diskSize,string direction){
    sort(request.begin(),request.end());
    vector<int> left,right,order;
    int totalseek=0;
    for(int i:request){
        if(i<head) left.push_back(i);
        else right.push_back(i);
    }
    if(direction=="left") left.push_back(0);
    else right.push_back(diskSize-1);
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    if(direction=="left"){
        reverse(left.begin(),left.end());
        order.insert(order.end(),left.begin(),left.end());
        order.insert(order.end(),right.begin(),right.end());
    }else{
        order.insert(order.end(),right.begin(),right.end());
        reverse(left.begin(),left.end());
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
    scanDisk(request,head,diskSize,direction);
    return 0;
}
