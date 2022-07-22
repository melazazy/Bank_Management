
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "date.h"

using namespace std;

struct client
{
    int id,amount;
    string client,transaction,emp,date;

};

vector< pair<string,vector<string> > > convert(string filename,int key,string conType)
{
    string user_file = filename;
    ifstream user_out;
    // opens an existing Usercsv and Transactions files 
    user_out.open(user_file);
    vector< pair<string,vector<string> > > encriptedUsers;
        // read file and decript and save to vector
        // read file line by line
        for(string str; getline(user_out,str);)
        {
            // string to save line after decripte
            string dstr="";
            // read line char by char and decript and save to decripted string
            for (size_t i = 0; i < str.length(); i++){
                char c;
                c = str[i];
                int temp = (conType =="decript")? (c ==' ')? c: (c - key):(c ==' ')? c:(c + key);
                dstr+=(char)temp;
            }
            string space_char =" ";
            pair<string,vector<string> > u;
            vector<string> userdata;
            vector<string> words;
            size_t pos = 0;
            // read all line string and split to words
            while ((pos = dstr.find(space_char)) != string::npos) {
                words.push_back(dstr.substr(0, pos));
                dstr.erase(0, pos + space_char.length());
            }
            u.first= words[0];
            for (size_t i = 1; i < words.size(); i++)
            {
                userdata.push_back(words[i]);
            }
            u.second= userdata;
            encriptedUsers.push_back(u);
        }
    return encriptedUsers;
}


void saveToFile(vector< pair<string,vector<string> > > users,string userFileName,string message,int key){
    // encrypte users vector
    ofstream temp;
    temp.open("temp.txt");
    // save it to file
    for (const auto &str : users) {
        temp<< str.first <<" ";
        for (int i = 0; i < str.second.size(); i++)
            temp<< str.second[i] << " ";
        temp<< endl;}
    vector< pair<string,vector<string> > > enUsers = convert("temp.txt", key,"incript");
    ofstream u;
    u.open(userFileName);
    for (const auto &str : enUsers) {
        u<< str.first <<" ";
        for (int i = 0; i < str.second.size(); i++)
            u<< str.second[i] << " ";
        u<< endl;}
    cout<<message<<endl;
}
void saveDelUser(vector< pair<string,vector<string> > > users,string userFileName,string user,string type,int key){
    int index=0;
    for (const auto &str : users) {
        if(str.first==user && str.second[1] ==type)
            break;
        index++;
        }
    if(index<users.size()){
        users.erase(users.begin()+index);
        saveToFile(users,userFileName,"User Is Deleted...",key);
    }
    else
        cout<< "No Account to Delete.... \n";
}

vector<client> convertClient(string filename,int key,string conType)
{
    string user_file = filename;
    ifstream user_out;
    user_out.open(user_file);
    vector<client > encriptedClient;
    int item=0;
    for(string str; getline(user_out,str);)
    {
        // add New Row To Vector
        encriptedClient.push_back(client());
        // string to save line after decripte
        string dstr="";
        // read line char by char and decript and save to decripted string
        for (size_t i = 0; i < str.length(); i++){
            char c;
            c = str[i];
            int temp = (conType =="decript")? (c ==' ')? c: (c - key):(c ==' ')? c:(c + key);
            dstr+=(char)temp;
        }
        // string space_char =" ";
        string strtemp="";
        int index = 1;
        for (int i = 0; i < dstr.size(); i++)
        {
            if (dstr[i]!=' '&& dstr[i]!='\n')
                strtemp.push_back(dstr[i]);
            else{
                if (index==1)
                {
                    stringstream id;
                    id<<strtemp;
                    id>>encriptedClient[item].id;
                }
                else if (index==2)
                    encriptedClient[item].client=strtemp;
                else if (index==3)
                    encriptedClient[item].transaction=strtemp;
                else if (index==4)
                    encriptedClient[item].emp=strtemp;
                else if (index==5)
                {
                    stringstream aa;
                    aa<<strtemp;
                    aa>>encriptedClient[item].amount;
                }
                else if(index==6)
                {
                    encriptedClient[item].date=strtemp;
                }

                strtemp="";
                index++;
            }
        }
        item++;
    }
    return encriptedClient;
}

void saveTransaction(client cl , string filename,int key,string conType){
    string user_file = filename;
    fstream user_out;
    user_out.open(user_file,ios::app);
    int item=0;
    cout<<"String: "<<endl;
    string n = to_string(cl.id)+" "+cl.client+" "+cl.transaction+" "+cl.emp+" "+to_string(cl.amount)+" "+cl.date+"\n";
    cout<<n<<endl;
    client newtrans;
    string strtemp="";
    int index = 1;
    for(int i =0;i<n.size();i++)
    {
            if (n[i]!=' '&&n[i]!='\n')
            {
                char c;
                c = n[i];
                int temp = (conType =="decript")? (c ==' ')? c: (c - key):(c ==' ')? c:(c + key);
                strtemp+=(char)temp;
            }
            else{
                if (index==1)
                    user_out <<strtemp << ' ';
                else if (index==2)
                    user_out <<strtemp << ' ';
                else if (index==3)
                    user_out <<strtemp << ' ';
                else if (index==4)
                    user_out <<strtemp << ' ';
                else if (index==5)
                    user_out <<strtemp << ' ';
                else if (index==6)
                    user_out <<strtemp << ' ';
                strtemp="";
                index++;
        }
    }
    user_out << endl;
    cout<<"String222: "<<endl;
    string sss = to_string(newtrans.id)+" "+newtrans.client+" "+newtrans.transaction+" "+newtrans.emp+" "+to_string(newtrans.amount)+" "+newtrans.date;
    cout<<sss<<endl;
    cout<<"End of newtrans Client\n";
    
}

client doTransaction(string userAccount,int amount,string trans,string emp){
    client t;
    srand(time(0));
    t.id =  rand();
    t.client=userAccount;
    t.transaction=trans;
    t.amount=amount;
    t.emp=emp;
    string time ="";
    vector<string> tt=date("time");
    for (int i = 0; i < tt.size(); i++)
    {
        time+=tt[i];
    }
    t.date=time;
    return t;

}