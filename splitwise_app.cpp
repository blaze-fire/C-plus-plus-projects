#include<bits/stdc++.h>
using namespace std;


//Comparator class for multiset
class comparator{

    public:
    bool operator()( pair<string ,int> p1, pair<string,int> p2){
        return p1.second < p2.second;
    }
};

int main(){

    int num_of_transactions, friends;
    cout<<"Enter number of Friends ";
    cin>>friends;
    cout<<"Enter total number of transactions ";
    cin>>num_of_transactions;
    string x,y;
    int amount;

    //maintaining the net amount for all friends present in a transaction

    map <string, int> net;
    int count = 0;
    while(num_of_transactions--){
        cout<<"The person that has to pay: ";
        cin>>x;
        cout<<"The person that gets the money: ";
        cin>>y;
        cout<<"Amount: ";
        cin>>amount;
        if(net.count(x) == 0){
            net[x]=0;

        }
        if(net.count(y) == 0){
            net[y]=0;
        }

        net[x] -= amount;
        net[y] += amount;

        // min transaction list

        multiset <pair<string , int>,comparator> m;
        for(auto p: net){
            string person = p.first;
            int amount = p.second;

            if(net[person] != 0){
                m.insert(make_pair(person,amount));
            }
        }

       

        while(!m.empty()){
            auto low = m.begin();
            auto high = prev(m.end());

            string debit_person = low->first;
            int debit = low->second;

            string credit_person = high->first;
            int credit = high->second;

            m.erase(low);
            m.erase(high);

            int settled_amount = min(abs(debit),abs(credit));
            debit += settled_amount;
            credit -= settled_amount;
            count +=1;

            cout<< debit_person <<" will pay " <<settled_amount <<" to " << credit_person <<endl;

            if(debit != 0){
                m.insert(make_pair(debit_person,debit));
            }
            if(credit !=0){
                m.insert(make_pair(credit_person,credit));
            }
            
        }
        
    }
    cout<<"Total number of transactions: "<<count;
   
}