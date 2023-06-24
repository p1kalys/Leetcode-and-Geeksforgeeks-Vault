//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

// } Driver Code Ends
class Solution{
    public:
    //You need to complete this fucntion
    long long fexp(long long x,long long y)
    {
        if(x==0)return 0;
        if(y==0)return 1;
       long long ans;
       if(y%2==0)
       {
           // 3^4->(3*3)^2->3^2 * 3^2
           ans=fexp(x,y/2);
           ans=(ans%mod*ans%mod)%mod;
       }
       else{
        //   y is odd so x^y-> x*(x^(y-1))
        ans=((x)%mod*fexp(x,y-1)%mod)%mod;
       }
       return ((ans+mod)%mod);
        
    }
    long long power(int N,int R)
    {
       //Your code here
       return fexp(N,R);
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends