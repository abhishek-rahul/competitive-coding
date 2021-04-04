#include<bits/stdc++.h>
using namespace std;
    bool isPossible(int n,int index,int val,int maxSum)
    {
        int lsum =0 , rsum = 0 , lelements , relements;
        relements = n - index - 1;
        lelements = index ; 
        cout<<" if this value is possible "<<val<<endl;
        cout<<lelements<<" "<<relements<<endl;
        if(lelements >= val-1)
        {
            lsum = ((val-1)*val)/2+(lelements - val + 1);
        }
        else
        {
            lsum = ((val-1)*val)/2 - ((val - 1 - lelements)*(val - lelements))/2;
        }
        if(relements >= val-1)
        {
            rsum = ((val-1)*val)/2+(relements - val + 1);
        }
        else
        {
            rsum = ((val-1)*val)/2 - ((val - 1 - relements)*(val - relements))/2;
        }
        if(val+lsum+rsum <= maxSum)
            return true;
        return false;
    }
    int maxValue(int n, int index, int maxSum) {
        int maxans = 0,mid;
        int left = 1;
        int right = maxSum;
        while(left<=right)
        {
            mid = (left+right)/2;
            if(isPossible(n,index,mid,maxSum))
            {
                maxans = mid;
                left = mid +1 ;
            }
            else
                right = mid -1 ;
        }
        return maxans;
    }
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,index,maxsum ;
		cin>>n>>index>>maxsum;
		cout<<maxValue(n,index,maxsum);
	}
	return 0;
}
