#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <vector> 
using namespace std;
 
 /*
vector <string> Validip(vector<string> &ip) {

    vector<string> result;
    string parsed;
    size_t pos;
    bool ipv4;
    int base;
    char delim;
    int num;
    int max_num;
    int i ;
    int max_i ;
    bool valid;
    string s;

    for(int l=0; l<ip.size(); l++)
    {
        stringstream input_stringstream(ip[l]);
        pos = 0;
     
        ipv4 = ip[l].find(".") != -1;
        base = ipv4 ? 10 : 16;
        delim = ipv4 ? '.' : ':';
        max_num = ipv4 ? pow(2, 8) : pow(2, 16);
        i = 0;
        max_i = ipv4 ? 4 : 8;
        valid =true;
        s= ipv4 ? "IPv4" : "IPv6"; 

     
        try {
            while(true) {
                if(getline(input_stringstream, parsed, delim)) {
                    num = stoi(parsed, &pos, base);
                    if (pos != parsed.length() || num < 0 || num >= max_num) valid = false;
                }
                else break;
                i++;
            }
        }
        catch(...) {
            valid = false;
        }

        if(valid && i == max_i){
            result.push_back(s);
            
        }
        else
        {
            result.push_back("Neither");
        }
    }
    return result;
}
 */
vector <string> Validip(vector<string> &ip) {
string str = "211";
    unsigned int ip[4];
    int num;
    int temp;
    int j =1; 
    int count =1; 
    int index = 0;
    for(int i=str.size()-1; i>=0; i--)
    {
        if(str[i]!='.' ){
            num += j* (str[i]-'0');
            j = pow(10, count); 
            count++;
        }
        if(str[i]=='.' )
        {
            if(num>=0 && num<=255)
            {
                ip[index]=num;
                index++;
            }
            num=0;
            j=1;
            count =1;
        }
        if(num>=0 && num<=255)
            {
                ip[index]=num;
            }
    }

    return ip;

}





int main() {

    vector<string> v;

    vector<string> v1;
    v.push_back("2001:0db8:0000:0000:0000:ff00:0042:8329");
    v.push_back("192.168.0.1");
    v.push_back("This is a test string.");
    v.push_back("192.168.0.1 is a test string.");
    v.push_back("192.168:0.1 is a test string.");

    v1=Validip(v);
    

   for(int i=0; i<v1.size(); i++)
   {
    cout<<v1[i]<<endl;
   }


    return 0;
} 
