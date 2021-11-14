#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <vector>

using namespace std;

//Liste
vector<string> q;
vector<string> qf;
vector<string> a;
vector<string> t;


void afisareTranzitii(vector<string > t, vector<string > q, vector<string> a)
{
	cout << "      ";
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " | ";
	cout << endl;
	for (int i = 0; i <q.size(); i++)
	{
		cout << q[i] << '|'<<"   ";
		vector<string> tp;
		for (int j = 0; j < t.size(); j++)
		{
			string test = t[j].substr(0, 2);
			if (test.find(q[i]) != std::string::npos)
			{
				tp.push_back(t[j]);
				cout<<tp[tp.size()-1].substr(6, 7)<<' ';

				
				

			}
			
		}
		cout << endl;

	}

}


void citire_afisare(vector<string> &q, vector<string> &qf, vector<string> &a)
{
	fstream file;
	file.open("auto.txt", ios::in);
	
	string tp;
	getline(file, tp);//prima linie
	getline(file, tp);//multimea starilor

	stringstream ss(tp);
	string token;

	while (getline(ss, token, ','))
		q.push_back(token);
	
	cout << "Multimea starilor Q:" << endl;
	for (int i = 0; i < q.size(); i++) 
		cout << q[i] << endl;
	cout << endl;

	getline(file, tp);
	getline(file, tp);
	getline(file, tp);//alfabetul initial

	stringstream sa(tp);
	while (getline(sa, token, ','))
		a.push_back(token);

	cout << "Alfabetul de intrare :" << endl;
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << endl;
	cout << endl;

	getline(file, tp);
	getline(file, tp);
	getline(file, tp);//functia de tranzitie

	cout << "Functia de tranzitie :" << endl;
	cout << tp<<endl<<endl;
	getline(file, tp);
	stringstream st(tp);
	while (getline(st, token, ';'))
		t.push_back(token);
	cout << "Tabelul de tranzitie :\n";
	cout << "------------------" << endl;
	afisareTranzitii(t,q,a);
	cout << "------------------" << endl;

	getline(file, tp);
	getline(file, tp);
	getline(file, tp);//starile finale

	stringstream sf(tp);
	while (getline(sf, token, ','))
		qf.push_back(token);

	cout<<"Multimea starilor finale F:" << endl;
	for (int i = 0; i < qf.size(); i++)
		cout << qf[i] << endl;
	cout << endl;

}

string verificareSecventa(vector<string > t, vector<string > q, vector<string> a)
{
	cout << "Dati secventa :";
	string str;
	
	cin >> str;
	cout << endl;

	
	int ok = 0;
	for (int i = 0; i < q.size(); i++)
		if (q[i] == str.substr(0, 2))ok++;
	if (ok == 0)return "Secventa este gresita!";
	else ok = 0;
	for (int i = 0; i < a.size(); i++)
	{
		stringstream geek(a[i]);
		int g = 0;
		geek >> g;
		int g2 = (int)str[3] - '0';

		if (g==g2)ok++;
	}

	if (ok == 0)return "Secventa este gresita!";
	else ok = 0;
	for (int i = 0; i < q.size(); i++)
		if (q[i] == str.substr(6, 8))ok++;
	if (ok == 0)return "Secventa este gresita!";
	else ok = 0;

	return "Secventa este corecta!";
}


void verificareSecventa2(vector<string > t)
{

	cout << "Dati starea si secventa de pe banda :";
	string str;

	cin >> str;
	cout << endl;
	for (int i = 0; i < t.size(); i++)
		if (t[i].find(str) != std::string::npos)
			cout << t[i] << endl;
}

int main()
{
	citire_afisare(q,qf,a);
	cout<<verificareSecventa(t,q ,a);
	cout << endl;
	verificareSecventa2(t);
	return 0;
}