#ifndef ENTERING
#define ENTERING

#include"classContainer.h"
#include"checks.h"
#include <iostream>
#include <string>
#include<vector>
#include <algorithm>

std::vector<UsersInputContainer> savedInput;


double getDouble() {
	double x;
	std::cin >> x;
	// ver1: while( cin.fail() ) // or !cin.good()   no trailing char check.
	while (std::cin.fail() || (std::cin.peek() != '\r' && std::cin.peek() != '\n'))
	{
		std::cout << "Invalid Input! Please input a numerical value." << std::endl;
		std::cin.clear();
		while (std::cin.get() != '\n'); // or cin.ignore(1000, '\n');
		std::cin >> x;
	}
	return x;
}
int getInt() {
	int i;
	std::cin >> i;
	while ((std::cin.fail() || (std::cin.peek() != '\r' && std::cin.peek() != '\n') ) || !( i == 1 || i == 3))
	{
		std::cout << "Invalid Input! Please enter 1 or 3 :" << std::endl;
		std::cin.clear();
		while (std::cin.get() != '\n'); // or cin.ignore(1000, '\n');
		std::cin >> i;
	}
	return i;
}

std::string convertToUpper(std::string& incomingString) {
	std::string name = incomingString;
	for (size_t i = 0; i < incomingString.size(); i++) {
		name.at(i) = toupper(name.at(i));
	}
	return name;
}



void entering() {
	system("cls");

	std::string exitForLoop = "";


	while (exitForLoop != "BACK") {

		system("cls");

		std::cout << "Please insert how much is the consummer gonna drain current in A (ampers) :";
		double consumerInA = getDouble();

		std::cout << "Now please enter the electric consumer using coeficient :";
		double consumerDutyCoefficient = getDouble();

		std::cout << "Enter its cosinus (cosF) :";
		double cosF = getDouble();

		std::cout << "Please enter the wanted lenght of the wire (in kilometer) :";
		double wireLenght = getDouble();

		std::cout << "Please enter 1 if this consumer is gonna use one phase, or enter 3 if it's gonna use three phases :";
		int consumerPhases = getInt();

		UsersInputContainer endObject(consumerInA, consumerDutyCoefficient, cosF, wireLenght, consumerPhases);

		std::cout.setf(std::ios::fixed);
		std::cout.precision(3);
		std::cout << std::endl;
		std::cout << "The starting current (maximum current) of this consummer is : " << endObject.starterCurrent << std::endl << std::endl;
		std::cout << "The sinus of this consummer is :     " << endObject.sinF << std::endl;
		std::cout << "The tangens of this consummer is :   " << endObject.tgF << std::endl;
		std::cout << "The cotangens of this consummer is : " << endObject.cotgF << std::endl << std::endl;

		if (endObject.C60circuitBreaker[endObject.counterForCircuitBreakers] <= 63) {
			std::cout << "You are gonna need at least circuit breaker schneider :  " << endObject.C60circuitBreaker[endObject.counterForCircuitBreakers] << " C60 series.\n";
		}
		else {
			std::cout << "You are gonna need at least circuit breaker schneider :  " << endObject.C60circuitBreaker[endObject.counterForCircuitBreakers] << " C120 series.\n";
		}

			std::cout << "And you are gonna need at least wire with :              " << endObject.wireSection[endObject.counterForWires] << " section.\n\n";
		std::cout << "The voltage losses of this consummer with this wire section is :  " << endObject.voltageLosses << " Volts.\n" ;
		std::cout << "The voltage losses in percents is gonna be :                      " << endObject.voltagePercentLosses << "%\n\n" ;



		savedInput.push_back(endObject);
		std::cout << "Enter \"BACK\" to go back to the Main menu or just press Enter key to continue calculating :";
		std::cin.ignore();
		getline(std::cin, exitForLoop);
		exitForLoop = convertToUpper(exitForLoop);
		
	}

	system("cls");

}

void singleEntering() {

	system("cls");

	std::cout << "Please insert how much is the consummer gonna drain current in A (ampers) :";
	double consumerInA = getDouble();

	std::cout << "Now please enter the electric consumer using coeficient :";
	double consumerDutyCoefficient = getDouble();

	std::cout << "Enter its cosinus (cosF) :";
	double cosF = getDouble();

	std::cout << "Please enter the wanted lenght of the wire (in kilometers) :";
	double wireLenght = getDouble();

	std::cout << "Please enter 1 if this consumer is gonna use one phase, or enter 3 if it's gonna use three phases :";
	int consumerPhases = getInt();

	UsersInputContainer endObject(consumerInA, consumerDutyCoefficient, cosF, wireLenght, consumerPhases);

	std::cout.setf(std::ios::fixed);
	std::cout.precision(3);
	std::cout << std::endl;
	std::cout << "The starting current (maximum current) of this consummer is : " << endObject.starterCurrent << std::endl << std::endl;
	std::cout << "The sinus of this consummer is :     " << endObject.sinF << std::endl;
	std::cout << "The tangens of this consummer is :   " << endObject.tgF << std::endl;
	std::cout << "The cotangens of this consummer is : " << endObject.cotgF << std::endl << std::endl;

	if (endObject.C60circuitBreaker[endObject.counterForCircuitBreakers] <= 63) {
		std::cout << "You are gonna need at least circuit breaker schneider :  " << endObject.C60circuitBreaker[endObject.counterForCircuitBreakers] << " C60 series.\n";
	}
	else {
		std::cout << "You are gonna need at least circuit breaker schneider :  " << endObject.C60circuitBreaker[endObject.counterForCircuitBreakers] << " C120 series.\n";
	}

		std::cout << "And you are gonna need at least wire with :              " << endObject.wireSection[endObject.counterForWires] << " section.\n\n" ;
	std::cout << "The voltage losses of this consummer with this wire section is :  " << endObject.voltageLosses << " Volts.\n" ;
	std::cout << "The voltage losses in percents is gonna be :                      " << endObject.voltagePercentLosses << "%\n\n" ;

	savedInput.push_back(endObject);

	std::string forPausing;
	std::cin.ignore();
	std::cout << "Please press Enter :";
	getline(std::cin, forPausing);

	system("cls");

}



void printTheVector() {
	system("cls");

	if (savedInput.empty()) {
		std::cout << "So far you haven't entered a consumer !";
	}
	else {
		size_t k = 0;
		std::cout << "################################################################################################\n"
		 <<			 "### I[A]    #   k   #  l(km) # Phases #   cos  # Imax(A) # Breaker # Section # Uloss[V] # Uloss[%] #\n";
		std::cout.setf(std::ios::fixed);
		std::cout.precision(3);
		for (auto &i : savedInput) {
			k++;
			

			std::cout  << k << " # " << i.consumerInA << "  # " << i.consumerDutyCoefficient << " #  " << i.lenghtOfTheWire  << " #    " << i.howManyPhases << "   #  " 
				<< i.cosF << " #  " << i.starterCurrent << "  # " << i.C60circuitBreaker[i.counterForCircuitBreakers] 
				<< "  #  " << i.wireSection[i.counterForWires] << "  #  " << i.voltageLosses << "  #  " << i.voltagePercentLosses << "   #\n";


		}
	}


	std::string forPausing;
	std::cout << "\n\nPlease press Enter :";
	getline(std::cin, forPausing);

	system("cls");
}


void printInformation() {
	system("cls");


	std::cout << "\n\n### Program made by Georgi Todorov (georgi5481). ###\n\n\
This is my first ever personal program, created specifically for calculating electro-consummers \n\
 and picking the right wire section and protection they need. Feel free to use it. \n\n\
WARNING ! This is only for AC consumers and the used voltage for the calculations are 220[V] and 380[V] ! \n\
In the program I have included the Schneider circuit breakers series C60 and C120.\n\
Also I have included the wire sections from 1.5 to 240 and theirs coeficients needed for calculating the losses.\n\
All you need to do is add in the console \n\
- The average consumption of the consumer in ampers.\n\
- The consumers using coefficient - used for calculating the starter circuit (for engines ~ 7, coil ~ 4-5, resistors ~ 1)\n\
- The cosinus F of the AC consumer. (from 0 to 1)\n\
- How long is gonna be the wire lenght - the longer the conection, the bigger are the Voltage losses.\n\n\
";
	std::cout << "The starting current is calculated in case you have a consumer draining a lots of ampers for short amount of time.\n\
In schneider circuit breaker series C60 you can pick from 3 categories - B, C or D. The D category will break the circuit\n\
with the slowest reaction, which makes it perfect for engines. And the opposite applies to B category.\n\n";

	std::cout << "From the inputed cosF we can calculate all the sinF, tgF, cotgF. Which we need in our calculations.\n\n";

	std::cout << "The circuit breaker have to withstand the starter current and the average current of the consummer.\n\n ";

	std::cout << "The wire section is chosen to be able to withstand not only the consummer but the circuit breker as well.  \n\
When picking the section, it is set to have no more than 5% voltage losses. I have inserted every section\n\
from 1.5 to 240 and theirs constants needed for calculating the Voltage losses.\n\
The used formula for that is :\n\n\
2 * sqrt(3) * I * (rO * L)				--> for single phased.\n\
sqrt(3) * I * L * ((rO * cosF) + (xO * sinF))		--> for triple phased.\n\n\
I is the average current in ampers.\n\
L is the lenght of the wire in kilometers.\n\
rO is a coeficient for that section you are using.\n\
xO is also a coeficient for the section.\n\n";

	std::cout << "In the end of every calculation the voltage losses are printed for that section in Volts and percents.\n\n";


	std::cout << "You can print all the information so far you gathered from the third option from the menu.";



	std::string forPausing;
	std::cout << "\n\nPlease press Enter :";
	getline(std::cin, forPausing);

	system("cls");
}
#endif // !ENTERING
