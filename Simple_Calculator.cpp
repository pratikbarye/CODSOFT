/* A Simple Calculator program that performs Basic Arithmetic Operations 
   such as Addition, Subtraction, Multiplication, and Division. It also 
   allow the user to input two numbers and choose operation to perform   */


#include<bits/stdc++.h>
using namespace std;
int main()
{

    double num1,num2;
    char operation_number;
    cout<<"Enter two numbers:"<<endl;
    cin>>num1>>num2;
    
    
       cout<<"1st no:"<<num1<<"  "<<"2nd no:"<<num2<<endl;
     //cout<<"+ for Addition,  - for Subtraction  * for Multiplication  4-Division "<<endl;
       cout<<"Enter an operator (+, -, *, /): for which You want to perform operation for these two numbers"<<endl;
       cout<<"for e.g. enter + for Addition,etc."<<endl;
       cin>>operation_number;

       switch(operation_number)
       {
          case '+': cout<<"Addition: "<<(num1+num2)<<endl;
          break;
          case '-': cout<<"Subtraction: "<<(num1-num2)<<endl;
          break;
          case '*': cout<<"Multiplication: "<<(num1*num2)<<endl;
          break;
          case '/': if(num2!=0)
                   {
                     cout<<"Division: "<<(num1/num2)<<endl;
                   }
                  else
                   {
                     cout<<"Error! Division by zero is not allowed."<<endl; 
                   }
           break;

           default: cout<<"Invalid Operator!"<<endl;
           break;
    
        }
    
   return 0;
}