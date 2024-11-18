
#include <bits/stdc++.h>
using namespace std;
void sstf(vector<int> &request,int head){
    int seek_count=0;
    vector<int> seekSequence;
    while(!request.empty())
    {
        auto closest=min_element(request.begin(),request.end(),[head](int a,int b){return abs(a-head)<abs(b-head);});
        seek_count+=abs(*closest-head);
        head=*closest;
        seekSequence.push_back(*closest);
        request.erase(closest);
    }
    for(int i=0;i<seekSequence.size();i++){
        cout<<seekSequence[i]<<" ";
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
    sstf(request,head);
    return 0;
}
