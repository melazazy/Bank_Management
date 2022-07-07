#include <ctime>
vector <string> date(string datetype) {
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    if(datetype=="date"){
        vector <string> d{};
        d.push_back(to_string(now->tm_year + 1900));
        d.push_back(to_string(now->tm_mon + 1));
        d.push_back(to_string(now->tm_mday));
        return d;
    }
    else{
        vector <string> d{};
        d.push_back(to_string(now->tm_year + 1900));
        d.push_back(to_string(now->tm_mon + 1));
        d.push_back(to_string(now->tm_mday));
        d.push_back(to_string(now->tm_hour));
        d.push_back(to_string(now->tm_min));
        d.push_back(to_string(now->tm_sec));
        return d;
    }
    
}
    // vector<int> x= date("date");
    // for (int i = 0; i < x.size(); i++)
    //     i<x.size()-1?cout<<x[i]<<"-":cout<<x[i]<<" ";
