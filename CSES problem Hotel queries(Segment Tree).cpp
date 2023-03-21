#include<bits/stdc++.h>
using namespace std;
#define mx 200005
#define ll long long
ll a[mx];
ll tree[mx*3];
int indx;
void init(ll node,ll b,ll e)//creation segment tree
{
    if(b==e)
    {
        tree[node]=a[b];
        return;
    }
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=max(tree[left],tree[right]);
}
void query(ll node,ll b,ll e,ll k,ll n)//finding sum in range index i to j(i and j inclusive)
{
    if(b==e)
    {
        if(tree[node]>=k){indx=b;}
        else if(b+1<=n)
        {
           if(tree[node+1]>=k){indx=b+1;}
        }
        return;
    }
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;

    if(tree[left]>=k)
        {
            query(left,b,mid,k,n);
        }
    else
    {
        query(right,mid+1,e,k,n);
    }
}
void update(ll node,ll b,ll e,ll i,ll newvalue)//update in segment tree
{
    if(i>e||i<b)return;//out of range
    if(b>=i&&e<=i)//in segment (deiser index node)
    {
        tree[node]=tree[node]-newvalue;
        return;
    }
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;
    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    tree[node]=max(tree[left],tree[right]);


}
int main()
{
   ll n,q;cin>>n>>q;
   ll qq[q];
   for(ll i=1;i<=n;i++)cin>>a[i];
   for(ll i=0;i<q;i++)cin>>qq[i];
   init(1,1,n);
   for(int i=0;i<q;i++)
   {
       indx=-1;
       query(1,1,n,qq[i],n);
       if(indx==-1)cout<<0<<" ";
       else
       {
           cout<<indx<<" ";
           update(1,1,n,indx,qq[i]);
       }
   }

}
