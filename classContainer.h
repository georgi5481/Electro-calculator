#ifndef CLASS_CONTAINER
#define CLASS_CONTAINER
#include"checks.h"
#include<math.h>
#include <limits>

class UsersInputContainer {
private:

	void triplePhased() {

		if (this->consumerInA <= 125) {
		int i = 0;

		for (int k = 0; k < (sizeof(this->C60circuitBreaker) / sizeof(this->C60circuitBreaker[0])); k++) {
			if (this->consumerInA < C60circuitBreaker[k]) {
				this->counterForCircuitBreakers = k;
				break;
			}
		}

		do {
			this->voltageLosses = (sqrt(3) * this->consumerInA * this->lenghtOfTheWire * ((rO[i] * this->cosF) + (xO[i] * this->sinF)));
			this->voltagePercentLosses = (this->voltageLosses / 380) * 100;
			this->counterForWires = i;
			i++;
		} while ((this->voltagePercentLosses > 5) || (Imax[i] <= this->consumerInA) || (Imax[i] <= C60circuitBreaker[counterForCircuitBreakers]));
		}
		else {
			std::cout << "\n\n\nTHE CONSUMMER YOU ENTERED (IN AMPERS) IS WAY TOO BIG !\n\n\n";

			this->starterCurrent = 0;
			this->sinF = 0;
			this->tgF = 0;
			this->cotgF = 0;
			this->counterForCircuitBreakers = 0;
			this->voltageLosses = 0;
			this->voltagePercentLosses = 0;
			this->counterForWires = 0;

		}
	}


	void singlePhased() {


		
		if (this->consumerInA <= 125) {
		int i = 0;
	
			for (int k = 0; k < (sizeof(this->C60circuitBreaker) / sizeof(this->C60circuitBreaker[0])); k++) {
				if (this->consumerInA < C60circuitBreaker[k]) {
					this->counterForCircuitBreakers = k;
					break;
				}
			}

			do {
				this->voltageLosses = 2 * sqrt(3) * this->consumerInA * (rO[i] * lenghtOfTheWire);
				this->voltagePercentLosses = (this->voltageLosses / 220) * 100;
				this->counterForWires = i;
				i++;
			} while ((this->voltagePercentLosses > 5) || (Imax[i] <= this->consumerInA) || (Imax[i] <= C60circuitBreaker[counterForCircuitBreakers]));

		}
		else {
			std::cout << "THE CONSUMMER YOU ENTERED (IN AMPERS) IS WAY TOO BIG !";

			this->starterCurrent = 0;
			this->sinF = 0;
			this->tgF = 0;
			this->cotgF = 0;
			this->counterForCircuitBreakers = 0;
			this->voltageLosses = 0;
			this->voltagePercentLosses = 0;
			this->counterForWires = 0;

		}
	}


public:

	double wireSection[15]{ 1.5, 2.5, 4, 6, 10, 16, 25, 35, 50, 70, 95, 120, 150, 185, 240 };
	double rO[15]{ 11.92, 7.16, 4.47, 2.98, 1.786, 1.116, 0.714, 0.51, 0.357, 0.255, 0.188, 0.149, 0.119, 0.097, 0.0074 };
	double xO[15]{ 0.096, 0.092, 0.092, 0.088, 0.082, 0.078, 0.078, 0.075, 0.069, 0.069, 0.069, 0.066, 0.066, 0.066, 0.066 };
	double Imax[15]{ 19, 25, 34, 43, 60, 81, 107, 133, 160, 204, 256, 285, 328, 374, 440 };


	double C60circuitBreaker[17] = { 0.5,1,2,3,4,6,10,16,20,25,32,40,50,63,80,100,125};

public:


	double starterCurrent;
	double sinF;
	double tgF;
	double cotgF;
	double voltageLosses;
	double voltagePercentLosses;
	int counterForWires;
	int counterForCircuitBreakers;


	double consumerInA;
	double consumerDutyCoefficient;
	double cosF;
	double lenghtOfTheWire;
	int howManyPhases;
	UsersInputContainer(double consumer, double coefficient, double cosF, double lenght, int thePhases) :  consumerInA(consumer), consumerDutyCoefficient(coefficient),
		cosF(cosF), lenghtOfTheWire(lenght), howManyPhases(thePhases), voltageLosses(DBL_MAX), voltagePercentLosses(DBL_MAX), counterForWires(0)
	{

		this->starterCurrent = consumerInA * consumerDutyCoefficient;
		this->sinF = sqrt(1 - (this->cosF * this->cosF));
		this->tgF = sinF / this->cosF;
		this->cotgF = 1 / tgF;

		if (howManyPhases == 1) {
			singlePhased();
		}
		else if (howManyPhases == 3) {
			triplePhased();
		}
		else {
			throw "There has been an error. Probably with seting the number of phases.";
		}
	}

	
};




#endif // !CLASS_CONTAINER
