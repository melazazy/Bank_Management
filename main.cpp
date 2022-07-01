#include "readFile.h"
#include <stdlib.h>
#include <list>

using namespace std;

#define KGRN  "\x1B[32m";
#define KWHT  "\x1B[37m";

const int key=753;
string user_file = "users.csv";
vector< pair<string,vector<string> > > users = convert(user_file, key);

void login();
void admin();
void employee();
void client();
bool checkUser(string user,string pass,string type);


int main()
{
    for (const auto &str : users) {
            cout<< str.first <<"\t";
            for (int i = 0; i < str.second.size(); i++)
            {
                cout<< str.second[i] << "\t";
            }
            cout<< endl;
        }
    
    int type;
    // cout<< KGRN;
    start:
    login();
    cin>>type;
    switch (type)
    {
    //Admins
    case 1 :{
        string user,pass;
        int choise;
        cout<<"Please Enter User Name: ";
        cin>>user;
        cout<<"Please Enter pass: ";
        cin>>pass;
        if(!checkUser( user, pass,"admin"))
        {
            cout<<"User name and/or Password incorrect\n";
            goto start;
        }
        admin();
        cin>>choise;
        switch (choise)
        {
        // manage Admins
        case 1:
            {            
            int aselect;
            cout<< "What do you want?"<<endl;   
            cout<< "1) Add Admin    2) Delete Admin     3)Exit ";
            cout<< "Your Choise:";
            cin>>aselect;
            if (aselect == 1)
            {
                string user;
                string pass;
                string conpass;
                cout<< "Admin Username: ";
                cin>>user;
                cout<< "Admin Password: "<<endl;  
                cin>>pass;
                cout<< "Repeat Password: "<<endl;  
                cin>>conpass;
                if (pass == conpass)
                {
                    cout<<"Add Admin To user File ....";
                }
                else{
                    cout<<"Not Match Password";
                }
                user ="";
                pass ="";
                conpass="";
                
            }
            else if (aselect==2)
            {
                string user;
                string sure;
                cout<< "Admin Username: ";
                cin>>user;
                cout<< "Are You Sure? yes/no";
                cin>>sure;
                if(sure =="yes" || sure =="y"){
                    cout<< "Deleting Account";
                    /* code */
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
            cout<< "What do you want?"<<endl;   
            cout<< "1) Add Employee    2) Delete Employee     3)Exit ";
            cout<< "Your Choise:";
            cin>>eselect;
            if (eselect == 1)
            {
                string user;
                string pass;
                string conpass;
                cout<< "Employee Username: ";
                cin>>user;
                cout<< "Employee Password: "<<endl;  
                cin>>pass;
                cout<< "Repeat Password: "<<endl;  
                cin>>conpass;
                if (pass == conpass)
                {
                    /* code */
                    cout<<"Add Employee To user File ....";
                }
                else{
                    cout<<"Not Match Password";
                }
                user ="";
                pass ="";
                conpass="";
                
            }
            else if (eselect==2)
            {
                string user;
                string sure;
                cout<< "Employee Username: ";
                cin>>user;
                cout<< "Are You Sure? yes/no";
                cin>>sure;
                if(sure =="yes" || sure =="y"){
                    cout<< "Deleting Account";
                    /* code */
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
        // Add or View Cash for Employee Account
        case 3:
            {           
            string user;
            int cselect;
            int cash;
            int found=0;
            vector<string> users = {"mustafa","azaz"};
            cout<<"1) Start day     2) End day      3)Exit" <<endl;
            cout<<" : ";
            cin>>cselect;
            if (cselect !=1 || cselect !=2)
            {
                break;
            }
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
        case 4:
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
        default:
            cout<<"ERROR .........";
            break;
        }
        break;
    }
    //Employee
    case 2:{
            string user,pass;
            int choise;
            cout<<"Please Enter User Name: ";
            cin>>user;
            cout<<"Please Enter pass: ";
            cin>>pass;
            if(!checkUser( user, pass,"employee"))
            {
                cout<<"User name and/or Password incorrect\n";
                goto start;
            }
            employee();
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
            string user,pass;
            int choise;
            cout<<"Please Enter User Name: ";
            cin>>user;
            cout<<"Please Enter pass: ";
            cin>>pass;
            if(!checkUser( user, pass,"asd"))
            {
                cout<<"User name and/or Password incorrect\n";
                goto start;
            }
            client();
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

void login(){
    cout<< "Please , Select Login Type:"<<endl;   
    cout<< "1) Admin    2) Employee     3) Client   4) Exit"<<endl;
    cout<< "Your Choise:";
}

void admin(){
    cout<< "Adminstration Panal"<<endl;   
    cout<< "What do you want?"<<endl;   
    cout<< "1) Manage Admin    2) Manage Employee     3) Cash   4) Reports     5) Exit"<<endl;
    cout<< "Your Choise:";
}
void employee(){
    cout<< "Employee Panal"<<endl;   
    cout<< "What do you want?"<<endl;   
    cout<< "1) Transactions   2) client Reports     3) End-Day      4) Exit"<<endl;
    cout<< "Your Choise:";
}
void client(){
    cout<< "Client Panal"<<endl;   
    cout<< "What do you want?"<<endl;   
    cout<< "1) Transfer  2) Reports     3) Exit"<<endl;
    cout<< "Your Choise:";
}

bool checkUser(string user,string pass,string type){
    int index=0;
    for (const auto &str : users) {
            if(str.first==user)
                break;
            index++;
        }
    if(index==users.size())
        return false;

    if(pass == users[index].second[0] && type == users[index].second[1])
        return true;
    
    return false;
}