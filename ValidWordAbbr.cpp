#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string abr (string str)
{
    int midsize;
    string s;
    string compstr;
    stringstream out;
    midsize = str.size()-2; 
    out<<midsize;
    s=out.str();
    compstr = str[0]+s+str[str.size()-1];
    return compstr;   
}


    
vector<string> ValidWordAbbr(vector<string> &dictionary) {
        vector<string> words; 
         string str;
        for(int i=0; i<dictionary.size(); i++)
        {   
            str = abr(dictionary[i]);
            words.push_back(str);
        }
        return words;
    }

    bool isUnique(string word ) {
        string word1 = abr (word);
        vector<string> v;
        vector<string> v1;
        v.push_back("cook");
        v.push_back("look");
        v.push_back("Englishok");

         v1 = ValidWordAbbr(v);
         

         return find(v1.begin(), v1.end(), word1) !=v1.end(); 
    }


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");

int main()
{
    

      int curry = 2;
      while(curry)
      {
        cout<<curry<<endl;
        curry--;
      } 
     /*
     if(isUnique(firststr)){
        cout<<"Yes"<<endl;
     }
     else
     {
        cout<<"No"<<endl;
     }
*/
    return 0;
}