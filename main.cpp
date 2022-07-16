// #include "readFile.h"
#include "print.h"
#include "date.h"
#include <stdlib.h>
#include <cstdlib>
#include <list>

using namespace std;

#define KGRN  "\x1B[32m";
#define KWHT  "\x1B[37m";

string appUser="";
string appType="";
// cout<< KGRN;
const int key=753;
string user_file = "users.csv";
vector< pair<string,vector<string> > > users = convert(user_file, key,"decript");

// prototype
void home();
bool checkUser(string user,string pass,string type);
void addUser(string user,string pass,string type);

int main()
{
    srand(time(0));
    int r =  rand();
    cout<< r << "\n";
    vector<client> c =  convertClient("empTrans.csv", key,"decript");
    cout<< "Clients: \n";
    for (const auto &str : c) {
        cout<< str.id <<"id\t"
            << str.client<<"cl\t"
            <<str.transaction<<"te\t"
            <<str.emp<<"em\t"
            <<str.amount<<"am\t"
            <<str.date<<"da\t"
            <<endl;
}
    // print decripted vector
    cout<<appUser<<"\t"<<appType<<"\n";
    printVector(users);
    int type;
    start:
    home();
    cin>>type;
    switch (type)
    {
    //Admins
    case 1 :{
        string userType="admin";
        int choise;
        // login Function
        pair<string,string> data=login();
        if(!checkUser( data.first, data.second,userType))
        {
            cout<<"User name and/or Password incorrect\n";
            goto start;
        }
        cout<<appUser<<"\t"<<appType<<"\n";
        vector<string> d{"Manage Admin","Manage Employee","manage Client","Cash","Reports","Exit"};
        printChoise(1,d);
        cin>>choise;
        switch (choise)
        {
        // manage Admins
        case 1:
            {            
            int aselect;
            vector<string> d{"Add Admin","Delete Admin","Exit"};
            printChoise(1,d);
            cin>>aselect;
            if (aselect == 1)
            {
                vector<string> data=userData("Admin");
                if (data[1] == data[2])
                {
                    addUser(data[0],data[1],userType);
                    // encrypte users vector
                    saveToFile(users,"users.csv","Add Admin To user File ....",key);
                }
                else{
                    cout<<"Not Match Password";
                }
                data.clear();
            }
            else if (aselect==2)
            {
                string type="admin";
                vector<string> data =sure(type);
                if(data[1] =="yes" || data[1] =="y")
                    saveDelUser(users,"users.csv",data[0],type,key);
            }
            else if (aselect==3)
            {
                cout<< "Exiting  ......";
                /* code */
            }
            else{
                cout<<"Error"<<endl;
            }        
            break;
        }
        // manage Employee
        case 2:
            {    
            int eselect;
            vector<string> d{"Add Employee","Delete Employee","Exit"};
            printChoise(2,d);
            cin>>eselect;
            if (eselect == 1)
            {
                vector<string> data=userData("Admin");
                if (data[1] == data[2])
                {
                    addUser(data[0],data[1],"employee");
                    // encrypte users vector
                    saveToFile(users,"users.csv","Add Employee To user File ....",key);
                }
                else{
                    cout<<"Not Match Password";
                }
                data.clear();
            }
            else if (eselect==2)
            {
                string type="employe";
                vector<string> data =sure(type);
                if(data[1] =="yes" || data[1] =="y")
                    saveDelUser(users,"users.csv",data[0],type,key);
            }
            else if (eselect==3)
            {
                cout<< "Exiting  ......";
                /* code */
            }
            else{
                cout<<"Error"<<endl;
            }        
            break;
        }
        // manage client
        case 3:
            {    
            int eselect;
            vector<string> d{"Add Client","Delete Client","Exit"};
            printChoise(3,d);
            cin>>eselect;
            if (eselect == 1)
            {
                vector<string> data=userData("Client");
                if (data[1] == data[2])
                {
                    addUser(data[0],data[1],"Client");
                    // encrypte users vector
                    saveToFile(users,"users.csv","Add Client To user File ....",key);
                    
                }
                else{
                    cout<<"Not Match Password";
                }
                data.clear();
                
            }
            else if (eselect==2)
            {
                string type="client";
                vector<string> data =sure(type);
                if(data[1] =="yes" || data[1] =="y")
                    saveDelUser(users,"users.csv",data[0],type,key);
            }
            else if (eselect==3)
            {
                cout<< "Exiting  ......";
                /* code */
            }
            else{
                cout<<"Error"<<endl;
            }        
            break;
        }          
        // Add or review Cash for Employee Account
        case 4:
            {
            vector< pair<string,vector<string> > > emp = convert("empTrans.csv", key,"decript");
            vector<string> currentDay = date("date");
            string user,day="";
            for (int i = 0; i < currentDay.size(); i++)
                day+=currentDay[i];
            int cselect,cash,found=0;
            more:
            cout<<"1) Start day     2) End day      3)Exit" <<endl<<" : ";
            cin>>cselect;
            cout<<cselect<<endl;
            if (cselect!= 1 && cselect!= 2){
                cout<< "break Account: ";
                break;}
            cout<< "Employee Account: ";
            cin>>user;
            for (int i = 0; i < users.size(); i++){
                if (users[i].first == user && users[i].second[1]=="employee"){
                    found=1;
                    break;}}
            if (found ==1){
                if (cselect ==1)
                {
                    cout<< "Cash Amount: ";
                    cin>>cash;
                    pair<string,vector<string> > p;
                    vector<string> v;
                    v.push_back(user);
                    v.push_back(to_string(cash));
                    p.first= day;
                    p.second=v;
                    emp.push_back(p);
                    saveToFile(emp,"empTrans.csv","Add Cash To Employee ....",key);
                }
                else if (cselect ==2)
                {
                    int cash =0;
                    for (int i = 0; i < emp.size(); i++)
                        if (emp[i].first== day && emp[i].second[0]==user)
                            cash+=stoi(emp[i].second[1]);
                    cout<< " End Day Cash For Employee " << user<<" is: "<< cash<<endl;
                }
            }
            else{
                cout<< "User Account Error...... "<<endl;
                goto more;
                }
            break;
            }        
        // Reports
        case 5:
        {
            int rselect;
            cout<<"1) Total Bank Report     2) Time Limt Report     3) Client Report    4) Exit" <<endl;
            cout<<" : ";
            cin>>rselect;
            switch (rselect)
            {
            case 1:
            {
                cout<<"Total Bank Report "<<endl;
                /* code */
                break;
            }
            case 2:
            {
                cout<<"Time Report "<<endl;
                /* code */
                break;
            }
            case 3:
            {
                cout<<"Client Report "<<endl;
                /* code */
                break;
            }
            case 4:
            {
                cout<<"Exit  ......... "<<endl;
                /* code */
                break;
            }
            default:
                break;
            }
            break;
        }
        case 6:
            return 0;
        default:
            cout<<"ERROR .........";
            break;
        }
        break;
    }
    //Employee
    case 2:{
            string userType="employee";
            int choise;
            pair<string,string> data=login();
            if(!checkUser( data.first, data.second,userType))
            {
                cout<<"User name and/or Password incorrect\n";
                goto start;
            }
            vector<string> d{"Transactions","client Reports","End-Day","Exit"};
            printChoise(2,d);
            cin>>choise;
            switch (choise)
            {
            // Transaction
            case 1:
            {
                vector<client> c =  convertClient("empTrans.csv", key,"decript");
                // vector<int> clients;
                int tselect;
                int balance = 0;  
                cout<<"1) Deposit     2) Withdraw     3) Transfer     4) Exit \n";
                cout<<" : ";
                cin>>tselect;
                if (tselect ==1 ||tselect ==2 ||tselect ==3)
                {                      
                    string userAccount;
                    cout<<" Account Number: ";
                    cin >>userAccount;
                    string arr[6];
                    for (int i = 0; i < c.size(); i++)
                    {
                        cout<<c[i].client<<"\t"<< c[i].emp<<"\t"<< i <<"\n";
                        if(c[i].client == userAccount)
                            balance +=c[i].amount ;
                    }
                    cout<<"Balance Is "<< balance<<"\n";
                    switch(tselect)
                    {
                        // deposit  
                        case 1:
                        {
                            int amount;
                            cout<<"Amount: ";
                            cin>>amount;
                            if (amount <=0)
                            {
                                cout<<"Cant Add this Value ...";
                            }else{
                                cout<<"Add "<<amount <<" To "<< balance << " Total Balance = "
                                << amount+balance<<"\n";
                            }
                            break;
                        }
                        // Withdraw  
                        case 2:
                        {
                            int balance = 2500;
                            int amount;
                            cout<<"Amount: ";
                            cin>>amount;
                            if (amount <=0 || amount>balance)
                            {
                                cout<<"Can Not Withdraw this Value ...";
                            }else{
                                cout<<"Withdraw "<<amount <<" From "<< balance << " Total Balance = "<< balance-amount<<"\n";
                            }
                            break;
                        }
                        // Transfer  
                        case 3:
                        {
                            int balance = 2500;
                            int traccount;
                            int amount;
                            cout<<"Account To Transfer: ";
                            cin>>traccount;
                            cout<<"Amount: ";
                            cin>>amount;
                            if (amount <=0 || amount>balance)
                            {
                                cout<<"Can Not Transfer this Value ...";
                            }else{
                                cout<<"Transfer "<<amount <<" From "<< balance << " Your Balance = "<< balance-amount<<"\n";
                            }
                            break;
                        }
                        case 4:
                        {
                            break;
                        }
                        default:
                            break;
                    }
                }
                
                else{
                    break;
                }
                break;
            }
            // Client Report
            case 2:
            {
                int userAccount;
                cout<<" Account Number: ";
                cin >>userAccount;
                cout<<"Last 10 Transaction For Your Account Is: \n";
                break;
            }
            // End Day Report
            case 3:
            {
                int startcash = 10000;
                int endcash;
                cout<<" Cash: ";
                cin >>endcash;
                cout<<"Your Strater Is "<< startcash << " And Finished Is  " <<endcash <<" \n";
                break;
            }
            // Exit
            case 4:
            {
                break;
            }
            default:
                break;
            }
            break;
        }
    // client
    case 3:{
            string userType="client";
            int choise;
            pair<string,string> data=login();
            if(!checkUser( data.first, data.second,userType))
            {
                cout<<"User name and/or Password incorrect\n";
                goto start;
            }
            vector<string> d{"Transfer","Reports","Exit"};
            printChoise(3,d);
            cin>>choise;
            switch (choise)
            {
            // transfer
            case 1:
            {
                int tracount;
                int amount;
                cout<<"Account To Transfer: ";
                cin>> tracount;
                cout<<"Amount To Transfer: ";
                cin>> amount;
                break;
            }
            // Reports
            case 2:
            {
                cout<<"Last 10 Transaction For Your Account Is: \n";
                break;
            }
            case 3:
            {
                break;
            }
            default:
                break;
            }

            break;
        }
    // Exit
    case 4:{
        cout<< "Exit  ....... "<<endl;
        break;
    }
    default:{
        cout<< "Error"<<endl;
        break;
    }
    }
    return 0;
}

void home(){
    cout<< "Please , Select Login Type:"<<endl;   
    cout<< "1) Admin    2) Employee     3) Client   4) Exit"<<endl;
    cout<< "Your Choise:";
}

bool checkUser(string user,string pass,string type){
    int index=0;
    for (const auto &str : users) {
            if(str.first==user)
                break;
            index++;
        }
    if(index>=users.size())
        return false;
    if(pass == users[index].second[0] && type == users[index].second[1]){
        appUser = user;
        appType = type;
        return true;
        }
    return false;
}

void addUser(string user,string pass,string type){
    //vector< pair<string,vector<string> > > users
    if(!checkUser(user,pass,type))
    {
        pair<string,vector<string> >acc;
        vector<string> passType;
        passType.push_back(pass);
        passType.push_back(type);
        acc.first=user;
        acc.second=passType;
        users.push_back(acc);
    }else{
        cout<<"user already register!!\n";
    }

}