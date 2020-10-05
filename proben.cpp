#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	string close = "start";

	while (close != "exit")
	{
	double konsumator = 0;
	cout << "vyvedi konsumatora In [A] = ";
	cin >> konsumator;

	double kratnost = 0;
	cout << endl << "vyvedi kratnost na puskoviq tok Tk (za dvigateli ~ 7, transformatori ~ 5 , za nagrevateli i krushki ~ 1): ";
	cin >> kratnost;

	if (konsumator != 0 && kratnost != 0)
	{
		double puskovTok = konsumator * kratnost;
		cout.setf(ios::fixed);
		cout.precision(2);

		cout << endl << "puskoviqt tok Ip na konsumatora e = " << puskovTok << " [A] ." << endl;

		double cosF = 0;
		cout << endl << "vyvedi kosinus fi cosF = ";
		cin >> cosF;

		if (cosF != 0)
		{
			double sinF = sqrt(1 - (cosF * cosF));
			cout << "sinF = " << sinF << endl;
			double tgF = sinF / cosF;
			cout << "tgF = " << tgF << endl;
			double cotgF = 1 / tgF;
			cout << "cotgF = " << cotgF << endl;


			int prekysvach[13] = { 1,2,3,4,6,10,16,20,25,32,40,50,63 };
			/*int prekysvachC120[11] = { 10,16,20,25,32,40,50,63,80,100,125 };*/


			int pekysvachBroqcha = -1;

			if (konsumator < 64)
			{
					do {
						pekysvachBroqcha++;
					} while (prekysvach[pekysvachBroqcha] <= konsumator);

				int kriva = 1;
				char krivi = 'O';
				while ((1.0 * kriva * prekysvach[pekysvachBroqcha]) <= (1.2 * puskovTok))
				{
					kriva++;
				}
				if (kriva <= 5)
				{
					krivi = 'B';
				}
				else if (kriva > 5 && kriva <= 10)
				{
					krivi = 'C';
				}
				else {
					krivi = 'D';
				}
					cout << endl << "shte ti trqbva pone  C60N  " << prekysvach[pekysvachBroqcha] << "   amperov prekysvach, s pone   " << krivi << " = " << kriva << "   kriva na zarabotvane za da moje da izdyrji."
						<< endl << "I za  da e spazeno uslovieto za malko prezapasqvane pri puskoviq tok. (1.2 * Ip <= It * B)"
						<< endl
						<< endl << "Prepory4itelnite krivi sa :"
						<< endl << "B = za byrzodejstvie i konsumatori s malyk puskov tok, primerno pri osvetlenie;"
						<< endl << "C = standartna kriva za pove4eto konsumatori "
						<< endl << "D = za konsumatori s golqm puskov tok primerno dvigateli i transformatori"
						<< endl
						<< endl << "vyvedi broqt na provodnicite koito shte izpolzvash "
						<< endl << " 3 - za monofazen kosumator"
						<< endl << " 4 - za trifazen kosumator"
						<< endl;
			}/*
			else if ((konsumator >= 64) || (konsumator < 126))
			{
				do {
					pekysvachBroqcha++;
				} while (prekysvachC120[pekysvachBroqcha] <= konsumator);

						cout << endl << "shte ti trqbva pone  C120N  " << prekysvach[pekysvachBroqcha] << "   amperov prekysvach. Kato krivata na tazi seriq e zavodski nastroena i ne se izbira."
							<< endl
							<< endl << "vyvedi broqt na provodnicite koito shte izpolzvash "
							<< endl << " 3 - za monofazen kosumator"
							<< endl << " 4 - za trifazen kosumator"
							<< endl;
			}*/
			else
			{
				cout << "stanala e nqkakva greshka ! ";
			}

			int provodnici = 0;
			cout << endl << "vyvedi broq na provodnicite : ";
			cin >> provodnici;

			double sechenie[15]{ 1.5, 2.5, 4, 6, 10, 16, 25, 35, 50, 70, 95, 120, 150, 185, 240 };
			double lenght = 0;
			cout << "vyvedi dyljinata na kabela [km] = " << endl;
			cin >> lenght;

			double rO[15]{ 11.92, 7.16, 4.47, 2.98, 1.786, 1.116, 0.714, 0.51, 0.357, 0.255, 0.188, 0.149, 0.119, 0.097, 0.0074 };
			double ArO[15]{ 20, 12.12, 7.57, 5.05, 3.03, 1.894, 1.212, 0.866, 0.606, 0.433, 0.319, 0.253, 0.202, 0.164, 0.126 };

			double xO[15]{ 0.096, 0.092, 0.092, 0.088, 0.082, 0.078, 0.078, 0.075, 0.069, 0.069, 0.069, 0.066, 0.066, 0.066, 0.066 };

			int Idop[15]{ 19, 25, 34, 43, 60, 81, 107, 133, 160, 204, 256, 285, 328, 374, 440 };
			double IdopAlumin[15]{ 10, 20, 27, 34, 47, 63, 84, 103, 125, 159, 192, 223, 255, 292, 343 };

			double voltajzagubaAlumin = 0;
			double procentZagubaAlumin = 0;

			double procentZaguba = 0;
			double voltajZaguba = 0;
			
			if (provodnici <= 1)
			{
				cout << "provodnika ne moje da po-malyk ot 2" << endl;
			}
			else if (provodnici <= 3)
			{
				int i = -1;
				int k = -1;
				do {
					i++;
					voltajZaguba = (sqrt(3) * 2 * konsumator * (lenght * rO[i]));
					procentZaguba = (voltajZaguba / 220) * 100;
				} while (((procentZaguba > 5) || (Idop[i] <= konsumator) || (Idop[i] <= prekysvach[pekysvachBroqcha])) && (i < 15));


				do {
					k++;
					voltajzagubaAlumin = (sqrt(3) * 2 * konsumator * (lenght * ArO[k]));
					procentZagubaAlumin = (voltajzagubaAlumin / 220) * 100;
				} while (((procentZagubaAlumin > 5) || (IdopAlumin[k] <= konsumator) || (IdopAlumin[k] < prekysvach[pekysvachBroqcha])) && (k < 15));

				cout.setf(ios::fixed);
				cout.precision(2);

				if (i >= 15)
				{
					cout << "Dadenite secheniq za medni provodnici ne stigat ili imash greshka." << endl;
				}
				else {
					cout << endl << "Na monofazniq konsumator mu trqbva pone: " 
						 << endl << " sechenie   " << sechenie[i]<< "   kato shte ima " << procentZaguba << " % na zaguba na naprejenie."
						 << endl 
						 << endl << "I e spazeno uslovieto za dopustimiq tok na provodnika Idop = " << Idop[i] << " >= " << konsumator << " na konsumatora. "
						 << endl << "Kakto i Idop  = " << Idop[i] << " >= " << prekysvach[pekysvachBroqcha] << " ot prekysvacha. "
						 << endl;
				}

				if (k >= 15) {
					cout << "Dadenite secheniq za aluminieviq provodnik ne stigat." << endl;
				}
				else {
					cout << endl << "A aluminieviqt provodnik trqbva da e pone :"
						 << endl << " sechenie   " << sechenie[k] << "  kato shte ima   " << procentZagubaAlumin << " % na zaguba na naprejenie " 
						 << endl << " s dopustim tok na trite provodnika  Idop = " << IdopAlumin[k] << " >= " << konsumator << " na konsumatora. " 
						 << endl << "kakto i Idop = " << IdopAlumin[k] << " >= " << prekysvach[pekysvachBroqcha] << " ot prekysvacha. "
						 << endl;
				}
			}
			else
			{
				int i = -1;
				int k = -1;
				do {
					i++;
					voltajZaguba = (sqrt(3) * konsumator * lenght * (rO[i] * cosF + xO[i] * sinF));
					procentZaguba = (voltajZaguba / 380) * 100;
				} while ((procentZaguba > 5 || Idop[i] <= konsumator || Idop[i] <= prekysvach[pekysvachBroqcha]) && i < 15);


				do {
					k++;

					voltajzagubaAlumin = (sqrt(3) * konsumator * lenght * (ArO[k] * cosF + xO[k] * sinF));
					procentZagubaAlumin = (voltajzagubaAlumin / 380) * 100;
				} while ((procentZagubaAlumin > 5 || IdopAlumin[k] <= konsumator || IdopAlumin[k] < prekysvach[pekysvachBroqcha]) && k < 15);

				cout.setf(ios::fixed);
				cout.precision(2);

				if (i >= 15)
				{
					cout << "Dadenite secheniq za medni provodnici ne stigat ili imash greshka." << endl;
				}
				else {
					cout << endl << "Na trifazniq konsumator mu trqbva pone sechenie   " << sechenie[i]
						<< "   kato shte ima " << procentZaguba << " % na zaguba na naprejenie."
						<< endl << "kato e spazeno uslovieto za dopustimiq tok na provodnika Idop = "
						<< Idop[i] << " >= " << konsumator << " na konsumatora. "
						<< endl << "Kakto i Idop  = " << Idop[i]
						<< " >= " << prekysvach[pekysvachBroqcha] << " ot prekysvacha. " << endl;
				}

				if (k >= 15) {
					cout << "Dadenite secheniq za aluminieviq provodnik ne stigat." << endl;
				}
				else {
					cout << endl << "A aluminieviqt provodnik trqbva da e s pone sechenie   " << sechenie[k] << "  kato shte ima   " << procentZagubaAlumin << " % na zaguba na naprejenie " << endl << " s dopustim tok na trite provodnika  Idop = " << IdopAlumin[k] << " >= " << konsumator << " na konsumatora. " << endl << "kakto i Idop = " << IdopAlumin[k] << " >= " << prekysvach[pekysvachBroqcha] << " ot prekysvacha. " << endl;
				}
			}
		}
		else
		{
			cout << "imate greska pri vyvejdaneto na cosF";
		}
	}
	else {
		cout << "imate greshka pri v1vejdaneto";
	}
		cout << endl << "Ako iskash da prodyljish da vyvejdash konsumatori" << endl << "natistni kojto i da e klavish i enter, a ako iskash da izlezesh napishi prosto 'exit' ." << endl << endl;
		cin >> close;
}
	return 0;
}