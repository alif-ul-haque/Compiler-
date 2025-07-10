#include<bits/stdc++.h>
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


class SymbolInfo{
        string type,symbol;
        SymbolInfo(string A)
        {
              
        }
        
};
class SymbolTable{
        //vector<vector<SymbolInfo>>table;
        vector<SymbolInfo>table[100];
        int hash_func(string A)
      {
            int s = 0;
            for(int i=0;i<A.size();i++)
         {
              s+=(A[i]<<2);
         }
           return s%100;
      }
      SymbolTable(string A)
      {
           
      }
};

signed main()
 {
    granite_state
    string A;
    cin>>A;
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