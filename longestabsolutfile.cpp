#include <iostream>
#include <string>
#include <stack>
#include <vector> 
#include <sstream>

using namespace std; 
 int lengthLongestPath(string input) {
     
        int res = 0;
        stack<int> s;
        s.push(0);
        string str;
        vector<string> path;
        istringstream in(input);
        while (getline(in, str, '\n')) {
            path.push_back(str);
        }
        for (auto a : path) {
            int level = a.find_last_of("\t") + 1;
            while (level + 1 < s.size()) {
                s.pop();
            }
            int len = s.top() + a.size() - level + 1;
            s.push(len);
            if (a.find(".") != string::npos) {
                res = max(res, len - 1);
            }
        }
        return res;
    
    }


    int main()
    {
    	string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1
    					\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
                        
    	int result = lengthLongestPath( input) ;
    	cout<<result;



    	return 0;
    }