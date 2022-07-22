#include <ctime>
using namespace std;

vector <string> date(string datetype) {
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    if(datetype=="date"){
        vector <string> d{};
        d.push_back(to_string(now->tm_year + 1900));
        if((now->tm_mon + 1)<10)
            d.push_back("0"+to_string(now->tm_mon + 1));
        else
            d.push_back(to_string(now->tm_mon + 1));
        if((now->tm_mday)<10)
            d.push_back("0"+to_string(now->tm_mday));
        else
            d.push_back(to_string(now->tm_mday));
        return d;
    }
    else{
        vector <string> d{};
        d.push_back(to_string(now->tm_year + 1900));
        if((now->tm_mon + 1)<10)
            d.push_back("0"+to_string(now->tm_mon + 1));
        else
            d.push_back(to_string(now->tm_mon + 1));
        if((now->tm_mday)<10)
            d.push_back("0"+to_string(now->tm_mday));
        else
            d.push_back(to_string(now->tm_mday));

        if((now->tm_hour)<10)
            d.push_back("0"+to_string(now->tm_hour));
        else
            d.push_back(to_string(now->tm_hour));

        if((now->tm_min)<10)
            d.push_back("0"+to_string(now->tm_min));
        else
            d.push_back(to_string(now->tm_min));

        if((now->tm_sec)<10)
            d.push_back("0"+to_string(now->tm_sec));
        else
            d.push_back(to_string(now->tm_sec));
        return d;
    }
    
}

void printDate(string da){
    for (int i = 0; i < 4; i++)
        cout<<da[i];
    cout<<"-";
    for (int i = 4; i < 6; i++)
        cout<<da[i];
    cout<<"-";
    for (int i = 6; i < 8; i++)
        cout<<da[i];
    if(da.size()>8){
        cout<<"-";
        for (int i = 8; i < 10; i++)
            cout<<da[i];
        cout<<"-";
        for (int i = 10; i < 12; i++)
            cout<<da[i];
        cout<<"-";
        for (int i = 12; i < 14; i++)
            cout<<da[i];
    }
}
    // vector<int> x= date("date");
    // for (int i = 0; i < x.size(); i++)
    //     i<x.size()-1?cout<<x[i]<<"-":cout<<x[i]<<" ";
