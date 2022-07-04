//*************************************************************
// Program: Coffee Shop Application
//This program calculates a total for a coffee order
//Then it keeps the data and calculates the amount of ounces that were sold
//How much revenue was made and
//How many cups were sold as well.
//*************************************************************




#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

///global varibles
const double largeCup = 2.0;
const double mediumCup = 1.9;
const double smallCup =  1.75;
const double largeOunce = 15.0;
const double mediumOunce = 12.0;
const double smallOunce = 9.0;

//function prototypes
void showMainMenu();
void cupsSold(double totSml , double totMed ,double  totLrg);
void coffeeSold(double totSml , double totMed ,double  totLrg);
void totalAmount(double totSml , double totMed , double totLrg);
int buyCoffee(double& totSml , double& totMed , double& totLrg);
int orderMode(double& totSml , double& totMed , double& totLrg);
void coffeeMenu();



//MAIN FUNCTION
int main() {

  //Varibles
  double totSml = 0, totMed = 0 , totLrg = 0;
  int choice;


  //switch case loop
  do
    {
      choice = 0;
      //menu prompt functionk
      showMainMenu();

      //getting choice from user
      cin >> choice;
      cout << "______________________" << endl;

      switch (choice)
        {
          
        //buy coffee  
        case 1:
           buyCoffee(totSml , totMed , totLrg);
            break;   
        //show cups sold  
        case 2:
          		cupsSold(totSml , totMed , totLrg);
              break;
        //show coffee sold
          case 3:
            		coffeeSold(totSml , totMed , totLrg);
                break;
        //show money made
          case 4:
                totalAmount(totSml , totMed , totLrg);
                break;
        //Quit(program end)
          case 5:
            break;

        //number error catch
          default:
            cout << "Invalid input." << endl;
          
        }

      
    }
  //end value
  while(choice != 5);
  
  return 0;
}

//main menu function
void showMainMenu()
{
  cout << endl <<"--Enter one of the followin1g--" << endl <<endl;
  cout <<  "1: Receipt calculator " << endl;
  cout <<  "2: Cups sold " << endl;
  cout <<  "3: Coffee Sold " << endl;
  cout << "4: Total Revenue" << endl;
  cout <<  "5: Quit" << endl;
}

//total cups data function
void cupsSold(double totSml , double totMed , double totLrg)
{
  cout << "______________________" << endl;
  cout <<  "Cups sold:" << totLrg + totMed + totSml << endl;
  cout <<  "-->" << "Large:    " <<  totLrg << endl;
  cout <<  "-->" << "Medium:   " << totMed << endl;
  cout <<  "-->" << "Small:    " << totSml <<endl;

}

//total coffee ounces sold data function
void coffeeSold(double totSml , double totMed , double totLrg)
{
  cout << "______________________" << endl;
  cout << "Total amount of ounces of coffee sold" << endl << "-->" << totSml + totMed + totLrg << endl;
}

//total revenue function
void totalAmount(double totSml , double totMed , double totLrg)
{

  cout << "______________________" << endl;
  cout << "Total revenue" << endl << endl << "-->" <<"$";
  cout << (totSml * smallCup) + (totMed * mediumCup) + (totLrg * largeCup) << endl;

  }

//main menu and order function buffer
int buyCoffee(double& totSml , double& totMed , double& totLrg)
{
  //varibles
  int choiceSellFunction;

  //switch case loop

  do
    {
      choiceSellFunction = 0;

      //prompt
      cout << "______________________" << endl;
      cout << "1: Next order" << endl << "2: Back to main menu" << endl;
      cin >> choiceSellFunction;
      cout << endl;

      switch(choiceSellFunction)
        {
          case 1:
              //menu and getting input function
              orderMode(totSml , totMed , totLrg);
              break;
          
          case 2:
              //return 0 and going back to main
              break;
          
          //number error catch
          default:
              cout << "Invalid input." << endl;

        }

    }
  while(choiceSellFunction != 2);

  return 0;
}

//The coffee order function
int orderMode(double& totSml , double& totMed , double& totLrg)
{
  //varibles
  double orderSml = 0 ,orderMed = 0,orderLrg = 0, amount;
  int switchOrderMode;

  //switch case function
  do{
    //set up for repeating loo
    switchOrderMode = 0;
    amount = 0;

    //1 small
    //2 medium
    //3 large
    //4 receipt

    //Menu function prompt
    coffeeMenu();

    cin >> switchOrderMode;
    cout << endl;

    switch(switchOrderMode)
      {
        case 1:
            //small
            cout << "Amount of small: ";
            cin >> amount;
            cout << endl;

            orderSml += amount;
            break;

        case 2:
            //medium
            cout << "Amount of medium:  ";
	          cin  >> amount;
		        cout << endl;
		
		        orderMed += amount;
            break;

        case 3:
        		//large
		        cout <<  "Amount of large:  ";
		        cin  >>  amount;
		        cout << endl;
		 
		        orderLrg += amount;
            break;

        case 4:
		          //receipt
		          cout << "______________________" << endl;
		          cout << "RECEIPT" << endl << endl;
		          cout << "Small(s):      " << orderSml << endl;
		          cout << "Medium(s):     " << orderMed << endl;
		          cout << "Large(s):      " << orderLrg << endl << endl;
		
		          cout << "Your total will be $" << (orderSml *  smallCup) + (orderMed * mediumCup) + (orderLrg * largeCup) << endl << endl;
		
		
		          //adding these function values to main values
		          totSml += orderSml;
		          totMed +=  orderMed;
		          totLrg += orderLrg;
              break;
        
        //number errors
        default:
              cout << "Invalid input." << endl; 
      }
    
  }//exit loop value
  while(switchOrderMode != 4);

  //return (end of function)
  return 0;
}

//coffee menu funtion
void coffeeMenu()
{
  //prompt
  cout << "______________________" << endl;
  cout << "Input one of the following numbers" << endl << endl;
  cout << "1: Small Coffee"  << endl << "price: $" << smallCup << endl;
	cout << "2: Medium Coffee"  << endl << "price: $" << mediumCup << endl;
	cout << "3: Large Coffee"  << endl << "price: $" << largeCup << endl;
	cout << "4: End of order ---> receipt" << endl << endl;
  }
