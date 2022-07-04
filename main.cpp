// #include "readFile.h"
#include "print.h"
#include <stdlib.h>
#include <list>

using namespace std;

#define KGRN  "\x1B[32m";
#define KWHT  "\x1B[37m";
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
    // print decripted vector
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
                    saveAddUser(users,"users.csv","Add Admin To user File ....",key);
                }
                else{
                    cout<<"Not Match Password";
                }
                data.clear();
            }
            else if (aselect==2)
            {
                string user;
                string sure;
                cout<< "Admin Username: ";
                cin>>user;
                cout<< "Are You Sure? yes/no : ";
                cin>>sure;
                if(sure =="yes" || sure =="y"){
                    saveDelUser(users,"users.csv",user,"admin",key);
                }                
                
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
                    saveAddUser(users,"users.csv","Add Employee To user File ....",key);
                }
                else{
                    cout<<"Not Match Password";
                }
                data.clear();
            }
            else if (eselect==2)
            {
                string user;
                string sure;
                cout<< "Employee Username: ";
                cin>>user;
                cout<< "Are You Sure? yes/no : ";
                cin>>sure;
                if(sure =="yes" || sure =="y"){
                    saveDelUser(users,"users.csv",user,"employee",key);
                }                
                
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
                    saveAddUser(users,"users.csv","Add Client To user File ....",key);
                    
                }
                else{
                    cout<<"Not Match Password";
                }
                data.clear();
                
            }
            else if (eselect==2)
            {
                string user;
                string sure;
                cout<< "Client Username: ";
                cin>>user;
                cout<< "Are You Sure? yes/no : ";
                cin>>sure;
                if(sure =="yes" || sure =="y")
                    saveDelUser(users,"users.csv",user,"client",key);
                
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
        // Add or View Cash for Employee Account
        case 4:
            {  
            vector<string> users = {"mustafa","azaz"};         
            string user;
            int cselect;
            int cash;
            int found=0;
            cout<<"1) Start day     2) End day      3)Exit" <<endl<<" : ";
            cin>>cselect;
            cout<<cselect<<endl;
            if (cselect!= 1 && cselect!= 2){
                cout<< "break Account: ";
                break;}
            cout<< "Employee Account: ";
            cin>>user;
            for (int i = 0; i < users.size(); i++)
            {
                if (users[i] == user)
                {
                    found=1;
                    break;
                }                
            }
            if (found ==1)
            {
                if (cselect ==1)
                {
                    cout<< "Cash Amount: ";
                    cin>>cash;
                    cout<< "Add Cash To Employee  ......."<<endl;
                }
                else if (cselect ==2)
                {
                    cout<< "View End Day Cash For Employee";
                }
            }
            else{
                cout<< "User Account Error...... "<<endl;
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
                int tselect;
                cout<<"1) Debit     2) Withdraw     3) Transfer     4) Exit \n";
                cout<<" : ";
                cin>>tselect;
                if (tselect ==1 ||tselect ==2 ||tselect ==3)
                {
                    int userAccount;
                    cout<<" Account Number: ";
                    cin >>userAccount;
                    switch(tselect)
                    {
                        // Debit  
                        case 1:
                        {
                            int balance = 2500;
                            int amount;
                            cout<<"Amount: ";
                            cin>>amount;
                            if (amount <=0)
                            {
                                cout<<"Cant Add this Value ...";
                            }else{
                                cout<<"Add "<<amount <<" To "<< balance << " Total Balance = "<< amount+balance<<"\n";
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
                                cout<<"Cant Withdraw this Value ...";
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

    if(pass == users[index].second[0] && type == users[index].second[1])
        return true;
    
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