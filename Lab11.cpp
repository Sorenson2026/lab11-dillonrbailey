//Dillon Bailey
//31 March 2028
//ENGR 1405
//Garth Sorensen

//Number Analysis Program that will read up to 100 numbers from an inputed file.
// After the highest number, lowest number, total, average and standard deviation will be outputted.


#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

const int ARRAY_SIZE = 100;

int readfile(int array[]);
void analyzeArray(int[], int count);

//Work as a contractor to gather all informations of Number Analysis Program
int main()
{
	int numbers[ARRAY_SIZE];
	int count = 0;

	//Greeting
	cout << "Thank you for using the Number Analysis Program.\n\n";

	count = readfile(numbers);

	analyzeArray(numbers, count);

	return 0;
}

//Open File, Read File, Close File
int readfile(int array[])
{
	
	int count = 0;
	ifstream inputFile;
	string filename;

	cout << "What is your file Name? ";
	cin >> filename;
	cout << endl;

	inputFile.open(filename);

	while (count < ARRAY_SIZE && inputFile >> array[count])
		count++;

	inputFile.close();

	return count;
}

//Do maths
void analyzeArray(int data[], int size)
{
	int min=0;
	int max=0;
	int total=0;
	int mean = 0;
	int variance = 0;
	int standardDev=0;
		

	min = data[0];
	max = data[0];

		for (int i = 0; i < size; i++)
		{
			total += data[i];
			if (data[i] < min)
			{
				min = data[i];
			}
			if (data[i] > max)
			{
				max = data[i];
			}
		}

		//Find Mean
		mean = total / size;
			
		//Calculate variance and Standard Dev
		for (int i = 0; i < size; i++)
		{
			variance += pow(data[i] - mean, 2);
		}

		variance /= size;

		standardDev = sqrt(variance);

	cout << "Highest Number is: " << max << endl;
    cout << " Lowest Number is: " << min << endl;
	cout << "  Standard Dev is: " << standardDev << endl;
	cout << "       Average is: " << total/size << endl;
    cout << "         Total is: " << size << endl;
}