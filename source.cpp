#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <sstream>



using namespace std;
/// fetching data to enter from user
vector<vector<string> > readFile(fstream& file) {

	vector< vector<string> > data;
	char delimiter = ',';	string line;
	int counter = 0;
	int counter2 = 0;


	while (getline(file, line) && counter < 91)
	{
		vector<string> vec;
		string temp;
		istringstream ss(line);

		while (getline(ss, temp, delimiter) && counter2 < 12) {

			if (temp == "")	vec.push_back("0");

			else	vec.push_back(temp);
			counter2 += 1;

		}
		data.push_back(vec);
		counter += 1;
		counter2 = 0;

	}
	file.close();
	data.erase(data.begin(), data.begin() + 2);




	return data;

}

///sorting data on basis of aggregate
void sort(vector< vector<string> > &myVector) {

	for (int i = 0; i < myVector.size() - 1; i++) {
		for (int p = i + 1; p < myVector.size(); p++) {

			if (atof(myVector[i][0].c_str()) < atof(myVector[p][0].c_str())) {

				swap(myVector[i], myVector[p]);

			}

		}
	}

}

void swap(vector<string> &firstVector, vector<string> &secondVector) {

	vector<string> tempVector = firstVector;
	firstVector = secondVector;
	secondVector = tempVector;

}

/// aggregate formula
vector<vector <string> > aggCalc(vector<vector<string> > data) {

	stringstream ss;

	double aggregate;
	vector<vector <string> > aggregates;
	for (int i = 0; i < data.size(); i++) {
		vector <string> array;


		aggregate = ((atof(data[i][3].c_str()) + atof(data[i][7].c_str()) + atof(data[i][8].c_str())) / 30) * 10 +
			((atof(data[i][4].c_str()) + atof(data[i][5].c_str()) + atof(data[i][6].c_str())) / 30) * 10
			+ ((atof(data[i][9].c_str()) + atof(data[i][10].c_str())) / 100) * 40 +
			(atof(data[i][11].c_str()) / 100) * 40;



		ss << aggregate;

		array.push_back(ss.str());

		ss.str("");

		///cout << aggregate << endl;
		array.push_back(data[i][0]);
		array.push_back(data[i][1] + " " + data[i][2]);
		aggregates.push_back(array);

	}
	return aggregates;
}

/// awarding a and F to 10% students

void awardA(vector<vector <string> > &v, int a, string name) {

	ofstream aGrade(name + "A.csv");

	for (int i = 0; i < a; i++) {
		aGrade << v[0][0] + "," + v[0][1] + "," + v[0][2] << endl;
		v.erase(v.begin());
	}

	aGrade.close();

}

void awardF(vector<vector <string> > &v, int a, string name) {
	ofstream fGrade(name + "F.csv");
	int last = v.size() - 1;
	//cout << last;

	for (int i = 0; i < a; i++) {
		int last = v.size() - 1;
		//cout << v[last][1];
		fGrade << v[last][0] + "," + v[last][1] + "," + v[last][2] << endl;

		v.erase(v.begin() + last);

	}
	fGrade.close();

}

/// awarding others grades with comparison to average aggregate
void awardBplus(vector<vector< string> > &v, double a, string name) {
	ofstream BplusGrade(name + "Bplus.csv");
	for (int i = 0; i < v.size(); i++) {


		if ((atof(v[i][0].c_str())) >(a + 5)) {
			BplusGrade << v[i][0] + "," + v[i][1] + "," + v[i][2] << endl;

		}
	}

	BplusGrade.close();
}


void awardB(vector<vector< string> > &v, double a, string name) {
	ofstream BGrade(name + "B.csv");
	for (int i = 0; i < v.size(); i++) {


		if ((atof(v[i][0].c_str())) < (a + 5) && (atof(v[i][0].c_str())) > (a - 5)) {
			BGrade << v[i][0] + "," + v[i][1] + "," + v[i][2] << endl;

		}
	}

	BGrade.close();
}

void awardCplus(vector<vector< string> > &v, double a, string name) {
	ofstream CplusGrade(name + "Cplus.csv");
	for (int i = 0; i < v.size(); i++) {


		if ((atof(v[i][0].c_str())) < (a - 5) && (atof(v[i][0].c_str())) > (a - 15)) {
			CplusGrade << v[i][0] + "," + v[i][1] + "," + v[i][2] << endl;

		}
	}

	CplusGrade.close();
}
void awardC(vector<vector< string> > &v, double a, string name) {
	ofstream CGrade(name + "C.csv");
	for (int i = 0; i < v.size(); i++) {


		if ((atof(v[i][0].c_str())) < (a - 15) && (atof(v[i][0].c_str())) > (a - 25)) {
			CGrade << v[i][0] + "," + v[i][1] + "," + v[i][2] << endl;

		}
	}

	CGrade.close();
}
void awardDplus(vector<vector< string> > &v, double a, string name) {
	ofstream DplusGrade(name + "Dplus.csv");
	for (int i = 0; i < v.size(); i++) {


		if ((atof(v[i][0].c_str())) < (a - 25) && (atof(v[i][0].c_str())) > (a - 35)) {
			DplusGrade << v[i][0] + "," + v[i][1] + "," + v[i][2] << endl;

		}
	}

	DplusGrade.close();
}

void awardD(vector<vector< string> > &v, double a, string name) {
	ofstream DGrade(name + "d.csv");
	for (int i = 0; i < v.size(); i++) {


		if ((atof(v[i][0].c_str())) < (a - 35) && (atof(v[i][0].c_str())) > (a - 45)) {
			DGrade << v[i][0] + "," + v[i][1] + "," + v[i][2] << endl;

		}
	}

	DGrade.close();
	cout << "succesfully written all files" << endl;
}








int main(int argc, char **argv) {

	cout << "write file name to calculate grades" << endl;


	string fN(argv[1]);
	string fileName = fN.substr(0, fN.length() - 4);
	fstream file(fN);


	vector<vector<string> > t = readFile(file);

	vector<vector <string> > s = aggCalc(t);

	double sumAgg = 0;

	for (int i = 0; i < s.size(); i++) {

		sumAgg += atof(s[i][0].c_str());

	}

	double average = sumAgg / s.size();

	int numOfAandF = s.size() / 10;

	sort(s);

	/// other function calls

	awardA(s, numOfAandF, fileName);
	awardF(s, numOfAandF, fileName);
	awardBplus(s, average, fileName);
	awardB(s, average, fileName);
	awardCplus(s, average, fileName);
	awardC(s, average, fileName);
	awardD(s, average, fileName);
	awardDplus(s, average, fileName);

	getchar();
	return 0;
}
