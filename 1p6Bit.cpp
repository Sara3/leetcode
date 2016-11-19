#include <iostream>
#include <string>
#include <vector>
#include <math.h> 

using namespace std; 

int convertFromHex(char hex, int position)
{
    int offset;
    if (hex >= '0' && hex <= '9') {
        offset = '0';
    } else if (hex >= 'a' && hex <= 'f') {
        offset = 'a' - 10;
    } else if (hex >= 'A' && hex <= 'F') {
        offset = 'A' - 10;
    } else {
        return -1;
    }
    return (hex - offset) * (1 << (4 * position));
}

bool isipv6(string ipString){
    
    uint16_t ip[8] = {0};
    int ipPart = 7;
    int subPosition = 0;
    int sum = 0;
    bool isIP6 = true;

    for (int i = ipString.size() - 1; i >= 0; i--) {
        if (ipPart < 0) {
            return false;
            
        }
        if (ipString[i] == ':') {
            ip[ipPart] = sum;
            sum = 0;
            ipPart--;
            subPosition = 0;
        } else {
            int number = convertFromHex(ipString[i], subPosition);
            if (number == -1) {
                return false;
            }
            sum += number;
            if (sum > 0xFFFF) {
                return false;
            }
            subPosition++;
        }
    }

    ip[ipPart] = sum;

  return true;

}


/*
bool ipv4 (string str){
    uint8_t ip[4] = {0};
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

}
*/


bool ip4(string str)
{
    unsigned int ip[4] = {0};
    int ipPart =3;
    int num =0;
    int pow =1; 
    int dot_count =0;
  
    for(int i=str.size()-1; i>=0; i--){

        if(str[i]=='.' ){       
               if(num>=0 && num<=255) {
                    ip[ipPart] =num;
                    pow=1;
                    num =0;
                    ipPart--; 
                    dot_count ++;

               }
               else{ return false;}
        }
        else{
            num +=pow*(str[i]-'0'); 
            pow*=10;
        }
        if(num>=0 && num<=255){
            ip[ipPart] =num;
        }else{ return false;}

        if(ipPart<0){return false;}
     }
     if(dot_count!=3){return false;}
    return true;
}



int main()
{
    string str = "233.222.232.223";

    if(ip4(str))
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

   



    return 0;
}