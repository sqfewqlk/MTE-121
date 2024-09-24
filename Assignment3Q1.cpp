//Tristan Yan-Klassen and Noah Harman

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    ifstream fileObject1;
    fileObject1.open("taxi.txt");
    ofstream output;
    output.open("Assignment3Q1");

    double sumDist = 0;
    double sumMoney = 0;
    double longestTrip = 0;
    double cheapTrip = INT_MAX;
    
    int tripCounter = 0;

    bool vip = 0;
    int stops = 0;

    if(!fileObject1.fail() && !output.fail()){
        output<<setw(10)<<"Trip #"<<setw(10)<<"VIP"<<setw(10)<<"stops"<<setw(10)<<"tripDist"
            <<setw(10)<<"tripCost"<<setw(10)<<"totalDist"<<setw(10)<<"totalCost"<<endl;
        while(fileObject1>>vip>>stops){
            double tripLength = 0;
            double tripCost = 0;

            double xpos = 0;
            double ypos = 0;

            for(int i = 1; i <= stops; i++){
                double xnew = 0;
                double ynew = 0;
                fileObject1>>xnew>>ynew;
                tripLength += pow(pow(xnew - xpos, 2) + pow(ynew - ypos, 2), 0.5);
                xpos = xnew;
                ypos = ynew;

                if(i == stops){
                    tripLength += pow(pow(xpos, 2) + pow(ypos, 2), 0.5);
                }
            }
            tripCounter += 1;
            tripCost = (15*stops + 2.60 * tripLength)*(1 - vip*0.25);
            sumDist += tripLength;
            sumMoney += tripCost;

            if(tripLength > longestTrip){
                longestTrip = tripLength;
            }

            if(tripCost < cheapTrip){
                cheapTrip = tripCost;
            }

            if(tripCounter <= 4 || tripCounter % 10 == 4){
                output<<setw(10)<<fixed<<setprecision(2)<<tripCounter<<setw(10)<<vip
                    <<setw(10)<<stops<<setw(10)<<tripLength<<setw(10)<<tripCost<<setw(10)
                    <<sumDist<<setw(10)<<sumMoney<<endl;
            }
        }

        output<<"Cumulative Distance for August: "<<sumDist<<" km"<<endl;
        output<<"Cumulative Money Collected: $"<<sumMoney<<endl;
        output<<"Longest Trip: "<<longestTrip<<" km"<<endl;
        output<<"Cheapest Trip: $"<<cheapTrip<<endl;

        fileObject1.close();
        output.close();

    }else{
        cout<<"error opening file"<<endl;
    }
}

/*
    Trip #       VIP     stops  tripDist  tripCost totalDist totalCost
         1         0         1     20.40     68.04     20.40     68.04
         2         1         2     13.07     47.98     33.47    116.02
         3         0         4     40.72    165.86     74.18    281.88
         4         0         3     25.83    112.16    100.02    394.05
        14         0         4     26.46    128.79    410.38   1636.09
        24         1         2     25.01     71.27    752.64   2900.09
        34         0         3     21.75    101.55   1053.62   4052.71
        44         0         2     19.87     81.66   1307.69   4972.96
        54         0         5     33.90    163.14   1597.49   6030.68
        64         0         2     19.57     80.89   1874.82   7079.54
        74         1         2     13.53     48.88   2142.17   8064.27
Cumulative Distance for August: 2244.10 km
Cumulative Money Collected: $8435.45
Longest Trip: 51.39 km
Cheapest Trip: $38.95
*/