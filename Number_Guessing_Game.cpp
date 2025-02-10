/* Program that generates a random number and asks the user to guess
   it. It also Provide feedback on whether the guess is too
   high or too low until the user guesses the correct number. */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    srand( time(0));  // To ensure that number generated is always unique

    int random_number= rand();  // this will generate any random number 
 
   //  We can also Limit the range of the random number by
   //  int random_number= rand() % 100 + 1;  // it will generate random number between 1 to 100

   int user_guess;

   cout<<"Welcome to the  NUMBER GUESSING GAME!"<<endl;
   cout<<"I have Generated a Random Number. Can you guess it!"<<endl;

   while(true)
   {
    cout<<"Enter Your Guess: "<<endl;
    cin>>user_guess;
    if(user_guess > random_number)
    {
        cout<<"guess is too high "<<endl;
    }
    else
    {
        if(user_guess < random_number)
       {
        cout<<"guess is too Low "<<endl;
       }
       else
       {
        cout<<"Congratulations your Guess is Correct."<<endl;
        break;
       }
    }
   }
  
   return 0;
}