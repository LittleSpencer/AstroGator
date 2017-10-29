#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int numberOfStages = 0;
	double deltaV = 0;
	int counter = 0;
	double totalDeltaV = 0;
	double mofStruct[] = { 0,0,0 };
	double mofprop[] = { 0,0,0 };
	double stageIsp[] = { 0,0,0 };
	double totalStrucM = 0;
	double totalPropM = 0;
	double massAtEngineStart = 0;
	double massAtStaging = 0;
	double mOfPay = 0;
	int stageToOrbit = 1;
		
		cout << " How many stages is the vehicle? ";
		cin >> numberOfStages;
		cout << "-----------------Payload------------------\n";
		cout << " what is the mass (kg) of the payload? ";
		cin >> mOfPay;
	while (numberOfStages > counter) {
		cout << "-----------------Stage " << counter + 1 << "------------------\n";
		cout << " What is the mass (kg) of stage " << counter + 1 << "'s fuel? ";
		cin >> mofprop[counter];
		cout << " What is the mass (kg) of stage " << counter + 1 << "'s structure? ";
		cin >> mofStruct[counter];
		cout << " What is the Specific Impulse (s) of the engines on Stage " << counter + 1 << "? ";
		cin >> stageIsp[counter];

		counter++;
	}

	counter = 0;

	while (counter < numberOfStages) {
		for (int x = 0; x < numberOfStages; x++) {
			totalPropM += mofprop[x];
			totalStrucM += mofStruct[x];
		}

		massAtEngineStart = totalPropM + totalStrucM + mOfPay;
		massAtStaging = massAtEngineStart - mofprop[counter];
		 

		deltaV = log(massAtEngineStart / massAtStaging) * (stageIsp[counter] * 9.80665);
		totalDeltaV = totalDeltaV + deltaV;

		if (totalDeltaV < 10000)
			stageToOrbit++;

		cout << "------Stage " << counter + 1 << "------\n";
		if (deltaV >= 1000)
			cout << deltaV / 1000 << " km/s\n";
		else
			cout << deltaV << " m/s\n";



		mofprop[counter] = 0;
		mofStruct[counter] = 0;
		totalPropM = 0;
		totalStrucM = 0;
		counter++;
	}
	cout << "------TOTAL------\n";
	if (totalDeltaV >= 1000)
		cout << totalDeltaV / 1000 << " km/s\n";
	else
		cout << totalDeltaV << " m/s\n";

	if (totalDeltaV >= 9400) {
		cout << "*******LEO Achieved********\n";
		totalDeltaV -= 9400;
		if (totalDeltaV >= 1000)
			cout << (totalDeltaV) / 1000 << " km/s remmaining in stage " << stageToOrbit << endl << endl;
		else
			cout << (totalDeltaV)<< " m/s remaining in stage " << stageToOrbit << endl << endl;
	}
	else {
		cout << endl << "*******Sub-Orbital Flight********\n\n";
	}
	system("pause");
	return 0;

}
