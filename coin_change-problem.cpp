#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

int Coin_Change(int* V,int n,int N,int* dp)
{
    if(dp[N]!=-1) return dp[N];
    
    if(N==0) return 1;
    
    if(N<0) return 0;
    
    int s=0;
    for(int i=0;i<n;i++)
    {
        s+=Coin_Change(V,n,N-V[i],dp)+Coin_Change(V,n-1;
    }
    return s;
    
    return Coin_Change(V,n-1,N,dp)+Coin_Change(V,n,N-V[n-1],dp);
}

/*int main()
{
    int n,N;
    cin>>N>>n;
    int V[n],dp[N+1];
    memset(dp,-1,N+1);
    for(int i=0;i<n;i++) cin>>V[i];
    
    cout<<Coin_Change(V,n,N,dp)<<endl;
}*/

int fibo(int t,int* dp)
{
    if(dp[t]!=-1) return dp[t];
    
    //if(t==2) return dp[2]=1;
    if(t<=1) 
    {
        dp[0]=0;
        return dp[1]=1;
    }
        
    //cout<<dp[t]<<":"<<t<<endl;
        
    return (dp[t]=fibo(t-1,dp)+fibo(t-2,dp));
}

/*int main()
{
    int n;
    cin>>n;
    int dp[n+1];
    //memset(dp,-1,n+1);
    for(int i=0;i<n+1;i++) dp[i]=-1;
    cout<<fibo(n,dp)<<endl;
    cout<<dp[n]<<endl;
}*/
/*
int LIS(int* A,int n,int m)
{
    if(n==1) return 1;
    
    int res,m_e=1;
    for(int i=1;i<n;i++)
    {
        res=LIS(A,i,res);
        if(A[i-1]<A[n-1] && res+1 > m_e)
            m_e=res+1;
    }
    
    if(m < m_e)  res=m_e;
    
    return m_e;
}

int main()
{
    int n;
    cin>>n;
    int V[n];
    
    for(int i=0;i<n;i++) cin>>V[i];
    
    int res=0;
    cout<<LIS(V,n,res);
}*/
/*
int edit_dist(string s1,string s2,int m,int n)
{
    if(n==0 || m==0) return max(n,m);
    
    int r=0;
    if(s1[m-1]==s2[n-1]) r=edit_dist(s1,s2,m-1,n-1);
    else
    {
        int a,b,c;
        a=1+edit_dist(s1,s2,m,n-1);
        b=1+edit_dist(s1,s2,m-1,n-1);
        c=1+edit_dist(s1,s2,m-1,n);
        r=min(a,min(b,c));
    }
    return r;
}
*/
/*
int edit_dist(string s1,string s2,int m,int n,int dp[][1000])
{
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 && j==0) dp[i][j]=0;
            else if(i==0) dp[i][j]=j;
            else if(j==0) dp[i][j]=i;
            else if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));            
        }
    }
    return dp[m][n];
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
   
    int dp[s1.length()+1][1000]={0};
    
    cout<<edit_dist(s1,s2,s1.length(),s2.length(),dp)<<endl;
}*/

int doer(int r,int c,int A[][1000],int a[][1000],int lr,int lc)
{
    if(lr>=r || lc>=c) return 0;
    if(lr==0 && lc==0)
    {
        if(A[lr][lc]==0) 
        {
            a[0][0]=1;
            //return 1;
        }
        else 
        {
            a[0][0]=0;
            //return 0;
        }
    }
    
    //static int count=0;
    //cout<<count++<<endl;
    
    if(A[lr][lc]==1) a[lr][lc]=0;
    else
    {
        int k1=a[lr-1][lc-1],k2=a[lr-1][lc],k3=a[lr][lc-1];
        a[lr][lc]=min(k1,min(k2,k3))+1;
    }
    
    return max(a[lr][lc],max(doer(r,c,A,a,lr+1,lc),max(doer(r,c,A,a,lr,lc+1),doer(r,c,A,a,lr+1,lc+1))));
}

int main()
{
    int n,m;
    cin>>n>>m;
    int input[n][1000];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>input[i][j];
            
    int a[n][1000]={0};
    cout<<doer(n,m,input,a,0,0)<<endl;
    
    
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<a[i][j]<<" ";
            
        cout<<endl;
    }*/
        
}
                                                 
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int biggie = arr[n-1];
    int count[biggie]={0};
    for(int j=0; j<biggie; j++){
        count[arr[j]]++;
    }
    int max=count[0],wins;
    for(int k=1; k<biggie; k++){
        if(count[k-1]<count[k]){
            max=count[k];
            wins=k;
        }
    }
    if(max>static_cast<double>(n)/2){
        cout<<wins;
    }
    else{
        cout<<"no majority";
    }

