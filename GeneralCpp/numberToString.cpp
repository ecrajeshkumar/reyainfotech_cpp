#include<iostream>
#include <sstream>  // for string streams
#include <string>  // for string
//#include <boost/lexical_cast.hpp>

using namespace std;

int main(){
int num = 125;
char ch[100];

cout<<"ist Method... ";
sprintf(ch,"%d",num);
cout<<ch<<endl; 

cout<<"2nd Method... ";
string str = to_string(num);
cout<<str<<endl;

/*cout<<"3rd Method... ";
str = boost::lexical_cast<string>(num);
cout<<str<<endl;*/

cout<<"4th Method... ";
// declaring output string stream
    ostringstream oStr;
 
// Sending a number as a stream into output string
    oStr << num;
// the oStr() converts number into string
    string geek = oStr.str();
    cout<<geek<<endl;

}
    
