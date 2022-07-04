#include "readFile.h"

void printVector(vector< pair<string,vector<string> > > x){
    for (const auto &str : x) {
    cout<< str.first <<"\t";
    for (int i = 0; i < str.second.size(); i++)
        cout<< str.second[i] << "\t";
    cout<< endl;}
}

pair<string,string>login(){
        pair<string,string> u;
        cout<<"Please Enter User account: ";
        cin>>u.first;
        cout<<"Please Enter pass: ";
        cin>>u.second;
        return u;
}

vector<string>userData(string type){
        vector<string> u;
        string n,p,rp;
        cout<< type <<" account: ";
        cin>>n;
        u.push_back(n);
        cout<< type << " Password: "<<endl;  
        cin>>p;
        u.push_back(p);
        cout<< "Repeat Password: "<<endl;  
        cin>>rp;
        u.push_back(rp);
        return u;
}


void printChoise(int t,vector<string> options){
    if(t==1)
        cout<< "Adminstration Panal"<<endl;   
    if(t==2)
        cout<< "Employee Panal"<<endl;   
    if(t==3)
        cout<< "Client Panal"<<endl;   
    cout<< "What do you want?"<<endl;   
    for (int i = 0; i < options.size(); i++)
    {
        cout<< i+1 << ") " <<options[i]<<" \t";
    }
    cout<<endl;
    cout<< "Your Choise: ";
}
