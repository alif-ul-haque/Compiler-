#include <bits/stdc++.h>
using namespace std;
#define granite_state ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define line cout << "\n"
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define vsb (v).begin(),(v).end()
#define vse (v).rbegin(),(v).rend()
#define spc " "
#define pb push_back
#define pf push_front;

#define last_digit 6
#define sum_id 27

class symbol_info{
     public:
      string symbol;
      string type;
      symbol_info()
      {

      }
      symbol_info(string A,string B)
      {
          symbol = A;
          type = B;
      }
};

class symbol_Table{
     public:
    vector<symbol_info>symbol_table[10];
    symbol_Table()
    {
         
    }
    int hash_cal(string symbol)
    {
         int s = 0;
         if(symbol.size()>3)
         {
              int n = symbol.size();
              s+=symbol[0]+symbol[1]+symbol[n-1]+symbol[n-2];
              s = ((s<<last_digit)*sum_id)%10;
         }
         else
         {
              for(int i=0;i<symbol.size();i++)
              s+=symbol[i];
              s = ((s<<last_digit)*sum_id)%10;
         }
         return s;
    }
    void insert(string symbol,string type)
    {
          int idx = hash_cal(symbol);
          for(int i=0;i<symbol_table[idx].size();i++)
          {
               if(symbol_table[idx][i].symbol==symbol)
               {
                    cout<<"Already exists"<<endl;
                    return;
               }
          }
          symbol_table[idx].push_back(symbol_info(symbol,type));
          cout<<"Inserted at position "<<idx<<","<<symbol_table[idx].size()-1<<endl;
          cnt = max(idx,cnt);
    }
    void Lookup(string symbol)
    {
         int idx = hash_cal(symbol);
        for(int i=0;i<symbol_table[idx].size();i++)
        {
            if(symbol_table[idx][i].symbol==symbol)
            {
                cout<<"Found at "<<idx<<","<<i<<endl;
                return;
            }
        }
        cout<<"Not found"<<endl;
    }
    void Delete(string symbol)
    {
         int idx = hash_cal(symbol);
         for(int i=0;i<symbol_table[idx].size();i++)
         {
              if(symbol_table[idx][i].symbol==symbol)
              {
                   symbol_table[idx].erase(symbol_table[idx].begin()+i);
                   cout<<"Deleted from "<<idx<<","<<i<<endl;
                   return;
              }
         }
         cout<<"Not found"<<endl;
    }
    void print()
    {
        for(int i=0;i<10;i++)
        {
             if(!symbol_table[i].empty())
             {
                 cout<<i<<" -> ";
                   for(int j=0;j<symbol_table[i].size();j++)
                   {
                      cout<<"<"<<symbol_table[i][j].symbol<<", "<<symbol_table[i][j].type<<"> ";
                   }
                   cout<<endl;
             }
        }
    }
};
signed main()
 {
    granite_state
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    streambuf* backup = cout.rdbuf();
    cout.rdbuf(outfile.rdbuf());
    symbol_Table symTable;
    string cmd,symbol,type;
    while (infile>>cmd) 
    {
        if (cmd == "I") 
        {
            infile>>symbol>> type;
            symTable.insert(symbol,type);
        } 
        else if (cmd == "L") 
        {
            infile>>symbol;
            symTable.Lookup(symbol);
        } 
        else if (cmd == "D") 
        {
            infile>>symbol;
            symTable.Delete(symbol);
        } 
        else if (cmd == "P") 
        {
            symTable.print();
        }
    }

    cout.rdbuf(backup);
    infile.close();
    outfile.close();

}

    ////////////////////////////////////////////////////
    //                                                 //
    //                 A                               //
    //                                                 //
    //                 L                               //
    //                                                 //
    //                 I                               //
    //                                                 //
    //                 F                               //
    /////////////////////////////////////////////////////
//think simply, it's always easier than it seems at first
    //PEN AND PAPER instead of ms paint
    //keep at it even if it feels exhausting(we're not doing this for fun anymore)
    //2 GHONTAR AGER EDITORIAL DHORBI NA