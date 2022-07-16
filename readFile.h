#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
            if (dstr[i]!=' ')
                strtemp.push_back(dstr[i]);
            else{
                if (index==1)
                    encriptedClient[item].id =stoi(strtemp);
                else if (index==2)
                    encriptedClient[item].client=strtemp;
                else if (index==3)
                    encriptedClient[item].transaction=strtemp;
                else if (index==4)
                    encriptedClient[item].emp=strtemp;
                else if (index==5)
                    encriptedClient[item].amount=stoi(strtemp);
                else
                    encriptedClient[item].date=strtemp;
                strtemp="";
                index++;
            }
        }
        item++;
    }
    return encriptedClient;
}

void saveTransaction(vector<client>cl , string filename,int key,string conType){
    string user_file = filename;
    fstream user_out;
    user_out.open(user_file,ios::app);
    vector<client> vec;
    int item=0;
    for(string str; getline(user_out,str);)
    {
        // add New Row To Vector
        vec.push_back(client());
        // string to save line after decripte
        string strtemp="";
        int index = 1;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i]!=' ')
                strtemp.push_back(str[i]);
            else{
                if (index==1)
                    vec[item].id =stoi(strtemp);
                else if (index==2)
                    vec[item].client=strtemp;
                else if (index==3)
                    vec[item].transaction=strtemp;
                else if (index==4)
                    vec[item].emp=strtemp;
                else if (index==5)
                    vec[item].amount=stoi(strtemp);
                else
                    vec[item].date=strtemp;
                strtemp="";
                index++;
            }
            item++;
        }
    }
    
    
    for(const client & c : cl)
        {
            user_out <<c.id << ' ';
            user_out <<c.client << ' ';
            user_out <<c.transaction << ' ';
            user_out <<c.emp << ' ';
            user_out <<c.amount << ' ';
            user_out <<c.date << ' ';
            user_out << endl;
        }
    user_out.close();
}