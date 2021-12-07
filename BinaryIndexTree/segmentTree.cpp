#include<bits/stdc++.h>
using namespace std;

const int N=1e5+2;

int a[N],tree[4*N];

// building  segment tree
void build(int node,int start,int end){

       if(start==end){
           tree[node]=a[start];
           return;
       }   
       else{


           int mid=(start+end)/2;
           build(2*node,start,mid);
           build(2*node+1,mid+1,end);
           tree[node]=tree[2*node]+tree[2*node+1];
       }
}



int query(int node,int start,int end,int l,int r){

         if(start>r or end<l){
             return 0;
         }

         if(l<=start and end<=r){
             return tree[node];
         }

         int mid=(start+end)/2;

         int q1=query(2*node,start,mid,l,r);
         int q2=query(2*node+1,mid+1,end,l,r);

         return (q1+q2);

}

void update(int node,int start,int end,int idx,int val){


    if(start==end){
           a[idx]=val;
           tree[node]=val;
           return;
    }
 
    else{

            int mid=(start+end)/2;

            if(start<=idx and idx<=mid){
                update(2*node,start,mid,idx,val);
            }else{

                update(2*node+1,mid+1,end,idx,val);
            }
            tree[node]=tree[2*node]+tree[2*node+1];
    }
}
int main(){

       int n;
       cin>>n;

       for(int i=0;i<n;i++){
           cin>>a[i];
       }
       build(1,0,n-1);

    //    for(int i=1;i<2*n;i++){
    //        cout<<tree[i]<<"\n";
    //    }
    // int giveSum=query(1,0,n-1,1,2);
    // cout<<giveSum<<"\n";
       update(1,0,7,2,7);
      for(int i=1;i<2*n;i++){
           cout<<tree[i]<<"\n";
       }

       
    return 0;
}