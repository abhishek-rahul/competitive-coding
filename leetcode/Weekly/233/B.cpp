class Solution {
public:
    struct node 
    {
        long long int price;
        long long int amount;
        int type; // 0 == buy  ,  1 == sell
    };
    struct maxprice{
	bool operator()( node p1,  node p2)
{
	return p1.price < p2.price;
}
};
    struct minprice{
	bool operator()( node p1,  node p2)
{
	return p1.price > p2.price;
}
};
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
      long long int modu = 1000000007;
      priority_queue<node,vector<node>,maxprice> buy;
      priority_queue<node,vector<node>,minprice> sell;
      int vsize = orders.size();
      long long int p,amt,t;
      node temp, top; 
      for(int i=0;i<vsize;i++)
      {
          p = orders[i][0];
          amt = orders[i][1];
          t = orders[i][2];
          if(t==0)//buy
          {
              while(!sell.empty())
              {
                  if(amt==0)
                      break;
                  top = sell.top();
                  if(p>=top.price)
                  {
                      if(amt>=top.amount)
                      {
                          amt = amt - top.amount;
                          sell.pop();
                      }
                      else
                      {
                          temp = sell.top();
                          sell.pop();
                          temp.amount = temp.amount-amt ;
                          sell.push(temp);
                          amt = 0;
                      }
                  }
                  else
                      break;
              }
              if(amt>0)
              {
                  temp.price = p;
                  temp.amount = amt;
                  temp.type = 0;
                  buy.push(temp);
              }
          }
          else if(t==1)//sell
          {
              while(!buy.empty())
              {
                  if(amt==0)
                      break;
                  top = buy.top();
                  if(p<=top.price)
                  {
                      if(amt>=top.amount)
                      {
                          amt = amt - top.amount;
                          buy.pop();
                      }
                      else
                      {
                          temp = buy.top();
                          buy.pop();
                          temp.amount = temp.amount-amt ;
                          buy.push(temp);
                          amt = 0;
                      }
                  }
                  else
                      break;
              }
              if(amt>0)
              {
                  temp.price = p;
                  temp.amount = amt;
                  temp.type = 1;
                  sell.push(temp);
              }
          }
      }
      long long int sum = 0;
        //cout<<"sell amounts"<<endl;
        while(!sell.empty())
        {
            //cout<<sell.top().amount<<endl;
            sum = sum + sell.top().amount;
            sell.pop();
        }
        //cout<<"buy amounts"<<endl;
        while(!buy.empty())
        {
           // cout<<buy.top().amount<<endl;
            sum = sum + buy.top().amount;
            buy.pop();
        }
       return (sum%modu);
    }
};
