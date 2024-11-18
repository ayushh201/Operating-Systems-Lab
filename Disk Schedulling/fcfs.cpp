
#include <bits/stdc++.h>
using namespace std;
void fcfs(vector<int> &request,int head){
    int seek_count=0;
    int distance,curr_track;
    for(int i=0;i<request.size();i++){
        curr_track=request[i];
        distance=abs(head-curr_track);
        seek_count+=distance;
        head=curr_track;
    }
    cout<<"Seek count "<<seek_count<<endl;
}
int main()
{
    int n,head;
    cin>>n;
    vector<int> request(n);
    for(int i=0;i<n;i++){
        cin>>request[i];
    }
    cin>>head;
    fcfs(request,head);
    return 0;
}
