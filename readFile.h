#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
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