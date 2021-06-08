#include<bits/stdc++.h>
using namespace std;
int gcd(int n)
{ int el;
  ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  int m[1000001]={};
  int high=0;
  for(int i=0;i<n;i++)
     { cin>>el;
       high=max(high,el);
         m[el]++;}

    for(int i=high;i>=2;i--)
    {   if(m[i]>=2) return i;
        int c=0;
       for(int j=i;j<=high;j+=i)
       { c+=m[j];
         if(c>=2)
           return i;
         }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  int n;
  cin>>n;
    cout<<gcd(n);
      }
