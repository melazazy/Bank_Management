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
                int temp;
                if(conType =="decript")
                    temp = (c ==' ')? temp = c:temp = (c - key);
                else
                    temp = (c ==' ')? temp = c:temp = (c + key);
                dstr+=(char)temp;
            }
            string space_char =" ";
            // int num;
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
