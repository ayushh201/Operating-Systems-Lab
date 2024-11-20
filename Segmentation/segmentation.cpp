#include <bits/stdc++.h>
using namespace std;

const int NUM_SEGMENTS=2;
const int CODE_SEGMENT=0;
const int DATA_SEGMENT=1;

struct Segment{
    int baseAddress;
    int limit;
};
vector<int> codeSegment;
vector<int> dataSegment;
vector<Segment> segmentTable(NUM_SEGMENTS);

void initializeSegments(){
    codeSegment={101,102,103,104,105};
    dataSegment={10,20,30,40,50};
    segmentTable[CODE_SEGMENT]={0,static_cast<int>(codeSegment.size())};
    segmentTable[DATA_SEGMENT]={static_cast<int>(codeSegment.size()),static_cast<int>(dataSegment.size())};
}
void switchSegment(int segmentNumber){
    if(segmentNumber<0 || segmentNumber>=NUM_SEGMENTS) cout<<"Out of range ";
    cout<<"Switched to segment : "<<segmentNumber<<endl;
    cout<<segmentTable[segmentNumber].baseAddress<< " "<<segmentTable[segmentNumber].limit;
}
int retrieveData(int segmentNumber, int offset){
    int base = segmentTable[segmentNumber].baseAddress;
    if (segmentNumber==CODE_SEGMENT) {
        return codeSegment[base+offset];
    } else if (segmentNumber==DATA_SEGMENT) {
        return dataSegment[base+offset];
    }
}
int main()
{
    initializeSegments();
    switchSegment(CODE_SEGMENT);
    cout<<"Instruction at offset 2: "<<retrieveData(CODE_SEGMENT,2)<<endl;
    switchSegment(DATA_SEGMENT);
    cout<<"Data at offset 3: "<<retrieveData(DATA_SEGMENT,3)<<endl;

    return 0;
}
