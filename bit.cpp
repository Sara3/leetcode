#include <iostream>
#include <string> 
#include <algorithm>
#include <vector>
#include <math.h> 
#include <cstdlib>

using namespace std; 
/*
vector < string > checkIP(vector < string > ip) 
{


}

*/
int main()
{
  
   /*
   //string str = "211";
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

*/
 	 string str = "2001:0db8:0000:0000:0000:ff00:0042:8329";
 	 int num;
 	 int count =1;
 	 int j=1;
 	 char temp ="";
 	 for(int i=str.size(); i>=0; i--)
 	 {
 	 	if(str[i]!=':' && isxdigit(str[i]))
 	 	{
 	 		temp += str[i];
 	 		
 	 	}
 	 	else if(str[i]==':')
 	 	{
 	 		num = strtoul(temp, 0, 16); //this does not work but dont want to use this either
 	 		cout<<num;

 	 		//cout<<endl;
 	 	}
 	 	
 	 }

 	


/*
 	for(int i=0; i<4; i++)
 	{
 		cout<<ip[i]<<endl;
 	}
 	*/
	
    return 0;

}