#include<bits/stdc++.h>
using namespace std;
struct node
{
	string str;
	int val;
};
int bfs(string beginWord, string endWord, vector<string>& wordList,map<string,int>& mp)
 {
     node temp;
     string front,tempstr;
     int value;
     temp.str = beginWord;
     temp.val = 1;
     queue<node> q;
     q.push(temp);
     mp.insert({beginWord,1});
     //mp[front]=1;
     
     while(!q.empty())
     {
         temp = q.front();
         front = temp.str;
         value = temp.val;
         q.pop();
         int len  = front.length();
         for(int i=0;i<len;i++)
         {
             for(int j=0;j<26;j++)
             {
             	 tempstr = front ;
                 tempstr[i] = 'a'+j;
                 //cout<<front<<endl;
                 if( mp.find(tempstr)!=mp.end()  && mp[tempstr]==-1 )
                 {
                 	 //cout<<front<<endl;
                     temp.str = tempstr;
                     temp.val = value + 1 ;
                     q.push(temp);
                     mp[tempstr]=value+1;
                 }
             }
         }
     }
     return mp[endWord];
 }
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
     map<string,int> mp;
     //map<string,int>::iterator it;
     for(int i=0;i<wordList.size();i++)
     {
         mp.insert({wordList[i],-1});
     }
     int ans = bfs(beginWord,endWord,wordList,mp);
    /*for(int i=0;i<wordList.size();i++)
    {
    	cout<<wordList[i]<<" "<<mp[wordList[i]]<<endl;
	}
	*/
     return ans;
}

int main()
{
	string beginword,str;
	string endword;
	vector<string> vc;
	cin>>beginword;
	cin>>endword;
	int n ;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>str;
		vc.push_back(str);
	}
	cout<<ladderLength(beginword,endword,vc)<<endl;
	return 0;
}
/*
hit
cog
6
hot
dot
dog
lot
log
cog
*/
