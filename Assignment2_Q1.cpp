#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  float money = 0;
  float remaining = 0;
  string coffee = "no";
  string treat = "no treat";
  
  cout<<"How much money do you want to spend?"<<endl;
  
  cin >> money;

  if(money >= 1.75){
    coffee = "regular";
    remaining = money - 1.75;
    if(remaining >= 1.25){
      treat = "slice of cake";
    }
    else if(remaining >= 1){
      treat = "donut";
    }
  }
  else if(money >= 1){
    coffee = "small";
    remaining = money - 1;
    if(remaining >= 0.6){
      treat = "mini tart";
    }
    else if(remaining >= 0.5){
      treat = "chocolate";
    }  
  }
  else if(money >= 0.50){
      treat = "chocolate";
    }
  cout<<"You can have "<<coffee<<" coffee and a "<<treat<<"."<<endl;
  return 0;
}

/*
Test cases (run in VSCode)

How much money do you want to spend?
0.25
You can have no coffee and a no treat.
PS C:\Users\trist\MTE121> 

How much money do you want to spend?
0.5
You can have no coffee and a chocolate.
PS C:\Users\trist\MTE121> 

How much money do you want to spend?
0.55
You can have no coffee and a chocolate.
PS C:\Users\trist\MTE121> 

How much money do you want to spend?
1
You can have small coffee and a no treat.
PS C:\Users\trist\MTE121> 

How much money do you want to spend?
1.05
You can have small coffee and a no treat.
PS C:\Users\trist\MTE121> 

How much money do you want to spend?
1.50
You can have small coffee and a chocolate.
PS C:\Users\trist\MTE121> 

How much money do you want to spend?
1.57
You can have small coffee and a chocolate.
PS C:\Users\trist\MTE121> 

How much money do you want to spend?
1.60
You can have small coffee and a mini tart.
PS C:\Users\trist\MTE121> 

How much money do you want to spend?
1.71
You can have small coffee and a mini tart.
PS C:\Users\trist\MTE121> 

How much money do you want to spend?
1.75
You can have regular coffee and a no treat.
PS C:\Users\trist\MTE121> 

How much money do you want to spend?
2
You can have regular coffee and a no treat.
PS C:\Users\trist\MTE121> 

How much money do you want to spend?
2.75
You can have regular coffee and a donut.
PS C:\Users\trist\MTE121> 

How much money do you want to spend?
2.98
You can have regular coffee and a donut.
PS C:\Users\trist\MTE121> 

How much money do you want to spend?
3
You can have regular coffee and a slice of cake.
PS C:\Users\trist\MTE121> 

How much money do you want to spend?
3.1
You can have regular coffee and a slice of cake.
PS C:\Users\trist\MTE121> 
*/