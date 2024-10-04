//Tristan Yan-Klassen and Noah Harman

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

float triangle_area(float base, float height)
{
    return 0.5 * base * height;
}

float polygon_area(float sides, float side_length, float cent_dist)
{
    return sides * triangle_area(side_length, cent_dist);
}

float polygon_peri(float sides, float side_length)
{
    return sides * side_length;
}

float price(float sides, float side_length, float cent_dist)
{
    return 3*polygon_peri(sides, side_length) + 12*polygon_area(sides, side_length, cent_dist);
}

void file_read_write(ifstream &inputfile, ofstream &outputfile)
{
    int job_number = 0;
    int num_sides = 0;
    float side_length = 0;
    float centre_dist = 0;

    int job_count = 0;
    float max_cost = 0;
    float total_cost = 0;
    float avg_cost = 0;

    outputfile<<setw(10)<<"Job Number"<<setw(10)<<"Cost"<<endl;

    while(inputfile>>job_number>>num_sides>>side_length>>centre_dist)
    {
        float cost = 0;
        cost = price(num_sides, side_length, centre_dist);
        outputfile<<fixed<<setprecision(2)<<setw(10)<<job_number<<setw(10)<<cost<<endl;
        total_cost += cost;
        if (cost > max_cost)
        {
            max_cost = cost;
        }
        job_count += 1;
    }
    avg_cost = total_cost/job_count;

    outputfile<<"The max cost of all jobs was $"<<max_cost<<endl;
    outputfile<<"The total cost of all jobs was $"<<total_cost<<endl;
    outputfile<<"The average cost of all jobs was $"<<avg_cost<<endl;
}



int main()
{
    ifstream inputfile;
    inputfile.open("jobs.txt");
    ofstream outputfile;
    outputfile.open("output5.txt");

    if(!inputfile.fail() && !outputfile.fail())
    {
        file_read_write(inputfile, outputfile);
        inputfile.close();
        outputfile.close();
    }else
    {
        cout<<"error: file failed to open"<<endl;
    }
}

/*
file output:


Job Number      Cost
      6304    464.64
      6305    351.12
      6306    544.70
      6307    591.15
      6308   1320.00
      6309    609.66
      6310    793.80
      6311    444.91
      6312    360.00
      6313    946.26
      6314     35.64
      6315 118262.70
      6316     61.97
The max cost of all jobs was $118262.70
The total cost of all jobs was $124786.53
The average cost of all jobs was $9598.96



*/