//Tristan Yan-Klassen and Noah Harman

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    ifstream fileObject1;
    fileObject1.open("clients.txt");
    ofstream output;
    output.open("Assignment3Q2");

    string firstName = "";
    string lastName = "";
    double currentValue = 0;
    double interestRate = 0;
    double targetValue = 0;


    if(!fileObject1.fail() && !output.fail()){
        output<<setw(10)<<"First Name"<<setw(20)<<"Last Name"<<setw(20)<<"Years Required"<<endl;
        while(fileObject1>>firstName>>lastName>>currentValue>>interestRate>>targetValue){
            int years = 0;
            while(currentValue <= targetValue){
                currentValue = (1 + interestRate/100)*currentValue;
                years += 1;
            }

            output<<setw(10)<<fixed<<setprecision(2)<<firstName<<setw(20)<<lastName<<setw(20)<<years<<endl;
            
        }
        fileObject1.close();
        output.close();

    }else{
        cout<<"error opening file"<<endl;
    }
}

/*

First Name           Last Name      Years Required
     Count             Dracula                  11
    Muffin                 Man                   8
     Peter                 Pan                   6
     Tooth               Fairy                   9
     Daffy                Duck                   6
     Harry              Potter                  17
     Homer             Simpson                   7
      Bugs               Bunny                  11
    Albert            Einstein                   5
    Spider                 Man                   3
      Alan              Turing                   9
    Tinker                Bell                   7

*/
