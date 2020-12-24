#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

void leakyBucket(int pktSize,int op_rate,int bucketSize)
{
    if(pktSize>bucketSize){
        cout<<" Bucket overflow !!"<<endl;
        return;
    }
    
    while(pktSize>op_rate)
    {
        sleep(5);
        cout<<op_rate<<" bytes output"<<endl;
        pktSize-=op_rate;
    }

    if(pktSize<op_rate)
    {
        cout<<pktSize<<" bytes output"<<endl;
    }
    cout<<"Output successful!!"<<endl;
    cout<<endl;
}
int main()
{
    int pktSize;int op_rate;
    cout<<"Enter output Rate : "<<endl;
    cin>>op_rate;
    for(int i=0;i<5;i++)
    {
        pktSize=rand()%1000;
        cout<<i+1<<"th pkt size is "<<pktSize<<endl;
        leakyBucket(pktSize,op_rate,800);
    }
}