#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <ctime>
#include <string>
#include <ctype.h>


int main() {
  //initiate variables
  int price;
  std::string bors;
  long long dollars = 1000;
  long long buyCost;
  long long sellCost;
  long long shares = 0;
  long long days;
  long long dayCount;
  long long daysGoneWithoutSelling = 1;
  std::string skip;
  int finalChoice;
  int average = 0;
  int displayTip;
  using namespace std;


  std::cout << "How many days would you like to play the stock market for?: ";
  std::cin >> days;

  std::cout << "\033[2J\033[1;1H";
  system("clear");


  dayCount = days;
  

for(int i=0; i < days; i++){
  //changes in stock price
  srand((unsigned) time(0));
    int price = 10 + (rand() % 1000);

  //List of in game tips
  std::string tips[] = {"Buy Low and Sell High for MASSIVE GAINS!!!","'Stock Market Game is the best financial trainer out there'- Warren Buffet","5,000 Runs and Climbing! Possibly the best game on Repl.it?","Tell me in the comments how much you made, I love to here it!","If only this were possible in real life!","Did you hear about that hamster that outperformed the S&P 500!!!","Thank You for playing my game! :)","Best of luck out there!","I'm curious where are you guys from? Tell me in the comments!","What do you guys like about this game and are there any bugs that I need to fix, Tell me in the comments!","'The best trainer for all diamond holding apes'-r/wallstreetbets","Just a reminder, your the best!","Like the new update?","Notch!","As seen on TV!","SPLASH!"};
  


  displayTip = 0 + (rand() % 13);

  std::cout << " ____  _____ |||||| ______     __   __    ____\n";
  std::cout << "/        |   |    | |     |   | |  / /   /     \n";
  std::cout << "|        |   |    | |     |   | | / /    |     \n";
  std::cout << " ----    |   |    | |     |   | |/ /      ---- \n";
  std::cout << "     |   |   |    | |     |   | |_ _          |\n";
  std::cout << "    /    |   |    | |     |   | | _ _        / \n";
  std::cout << "----     |   |||||| |     |   | |  _ _   ----  ";
  std::cout << "\n(" << tips[displayTip] << ")\n\n";
  std::cout << "============================================================================================\n\n";


  
  //show your stats like dollars days and shares
  std::cout << "Days Left: " << dayCount << "       ";
  dayCount = dayCount - 1;
  std::cout << "Balance: $" << dollars << "       ";
  std::cout << "Shares: " << shares << "        ";
  std::cout << "Average Buy Cost: " << average << "\n\n";
  
  //give the option for 1 2 or 3
  std::cout << "\nTodays Stock Price: $" << price << "\n\nWhat would you like to do?    Buy(1)?   Sell(2)?    Or wait to the next day(3)?\n\nYour Choice?: ";
  std::cin >> bors;  


  //option 1 buying
  if(bors == "1" and dollars != 0){
    average = (average + price) / daysGoneWithoutSelling;
    daysGoneWithoutSelling++;
    std::cout << "The max amount of shares you can buy is: " << dollars / price << "\n";
    std::cout << "How many shares would you like to buy?: ";
    std::cin >> buyCost;
    
    if(buyCost > (dollars/price)){
      std::cout << "\n\nYou do not have enough money to buy those shares!\n\n";
      std::cout << "---------------------------------------------------------------------\n\n";
    }else if(buyCost <= (dollars/price)){
    std::cout << "---------------------------------------------------------------------\n\n";
    
    //account for bought shares
    shares = shares + buyCost;
    dollars = dollars - (price * buyCost);
    }

  }
  //option 2 sold shares
  else if(bors == "2" and shares != 0){
    daysGoneWithoutSelling = 1;
    std::cout << "\nThe max amount of shares you can sell is " << shares;
    std::cout << "\nHow many shares would you like to sell?: ";
    std::cin >> sellCost;
    if(sellCost > shares){
      std::cout << "\nYOU DO NOT HAVE THAT MANY SHARES TO SELL!!!";
      std::cout << "\n\n---------------------------------------------------------------------\n\n";
    }else if(sellCost <= shares){
    std::cout << "---------------------------------------------------------------------\n\n";
    
    //account for sold shares
    shares = shares - sellCost;
    dollars = dollars + (sellCost * price);
    }
    if(shares == 0){
      average = 0;
    }
  }
  //option 3 skipping to the next day
  else if(bors == "3"){
    std::cout << "Skipping to the next day.\n";
    std::cout << "---------------------------------------------------------------------\n";

  }else if(dollars == 0){
    std::cout << "You can't buy anymore because you are your balance is 0 so you have to sell";
    std::cout << "\nHow much would you like to sell?: ";
    std::cin >> sellCost;
    std::cout << "---------------------------------------------------------------------\n";
    shares = shares - (sellCost / price);
    dollars = dollars + sellCost;
  }  
  else if(bors == "2" and shares == 0){
    std::cout << "You do not have any shares to sell! And because either you weren't paying attention or you are trying to cheat you will lose a day!\n";
    
  }
  std::cout << "\033[2J\033[1;1H";
  system("clear");

  std::cout.imbue(std::locale(""));

	std::cout << std::fixed << std::showpoint << std::setprecision(3);

  if(dayCount == 0){
    if(shares > 0){
    std::cout << "Would you like me to convert your shares to dollars using the last share price? Yes(1) No(2): ";
    std::cin >> finalChoice;
    
    if(finalChoice == 1){
      std::cout << "\n\nYou have 0 days left to make money. Lets see how you did!\n";
      dollars = dollars + (shares * price);
      shares = 0;
      std::cout << "\nAfter "<< days << " days you have made $" << dollars << " dollars\n";
      std::cout << "\nYou own " << shares << " shares\n";
    }else if(finalChoice == 2){
      std::cout << "\n\nYou have 0 days left to make money. Lets see how you did!\n";
      std::cout << "\nAfter "<< days << " days you have made $" << dollars << " dollars\n";
      std::cout << "You own " << shares << " shares\n";
    }else{
      while(finalChoice != 1 && finalChoice != 2){
      std::cout << "\nInvalid responce!\n";
      std::cout << "\nWould you like me to convert your shares to dollars using the last share price? Yes(1) No(2): ";
      std::cin >> finalChoice;
      }
    }
    }else if(shares == 0){
      std::cout << "\n\nYou have 0 days left to make money. Lets see how you did!\n";
      std::cout << "\nAfter "<< days << " days you have made $" << dollars << " dollars\n";
      std::cout << "You own " << shares << " shares\n";
    }

    if(dollars > 1000000000000){
      std::cout << "\nVERY VERY Impresive!!! Now just do that in the real world and you will be set ;)";
    }else if(dollars > 1000000000){
      std::cout << "\nCan you teach me your ways? Because that was amazing!";
    }else if(dollars > 1000000){
      std::cout << "\nWOW WOW WOW, very good indeed. Very stonks";
    }else if(dollars >= 1000){
      std::cout << "\nPretty good but I think you can do better, maybe if you play for longer?!";
    }else if(dollars < 1000){
      std::cout << "\nYOU LOST THE MONEY!!! oh well.. back to McDonalds I guess";
    }
  }

}
}