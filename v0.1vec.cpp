#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iterator>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::left;
using std::setw;
using std::setprecision;
using std::istream;
using std::vector;

struct Studentas {
    string vardas, pavarde;
    vector <int> paz;
    int egz;
    float galut = 0;
};

void pildymas(vector <Studentas>& duom);
float vidurkis(vector <float> paz);
float mediana(vector<float> paz);

float galutinisPaz(Studentas stud);;
void print(vector<studentas> Eil, int paz_sk);

int main()
{
    cout << "Iveskite studentu skaiciu: " << endl;
    int n; ///studentu skaicius
    cin >> n;
    vector<Studentas> studentas;
    Studentas tempas;
    studentas.reserve(n);
    pildymas(studentas);
   /* for (int i = 0; i<n; i++)
        pildymas(studentas);*/
    if (studentas.size() > 0)
    {
        for (int i = 0; i < studentas.size(); i++)
        {
            studentas.at(i).galutinis = galutinisPaz(studentas.at(i));
        }
        cout
            << "\n"
            << left << setw(15) << "Vardas"
            << left << setw(20) << "Pavarde"
            << left << setw(25) << "Egzamino ivertinimas"
            << left << setw(20) << "Galutinis balas"
            << endl
            << string(15 + 20 + 2 * 20, '-') << "\n";
        for(int i = 0; i < n; i++)
            print(studentas[i]);
    }

}

void print(Studentas& kin)
{
    cout
        << left << setw(15) << kin.vardas
        << left << setw(20) << kin.pavarde
        << left << setw(25) << kin.egz
        << left << setw(20) << std::setprecision(3) << kin.galutinis
        << endl;
}

void pildymas(vector <Studentas>& duom)
{
    Studentas studentas; // lokalus kintamasis

    cout << "Iveskite studento varda ir pavarde: "; cin >> studentas.vardas >> studentas.pavarde;

    int n; //Namų darbų skaičius
    cout << "Kiek ivesite namu darbu? (1-10) ";
    while (!(cin >> n) || n < 1 || n>10)
    {
        cout << "Ivesta negalima reiksme - patikslinkite." << endl;
        cout << "Kiek ivesite namu darbu?" << endl;
        cin.clear();
        cin.ignore();
    }

    cout << "Iveskite pazymius: " << endl;
    int sum = 0;
    for (int i = 0; i < n; i++) {

        while (!(cin >> studentas.paz[i]) || studentas.paz[i] < 1 || studentas.paz[i] > 10)
        {
            cout << "Ivesta negalima reiksme - patikslinkite." << endl;
            cout << "Iveskite pazymius: " << endl;
            cin.clear();
            cin.ignore();
        }

        sum += studentas.paz[i];
    };

    cout << "Iveskite egzamino pazymi: ";
    while (!(cin >> studentas.egz) || studentas.egz < 1 || studentas.egz>10)
        {
        cout << "Ivesta negalima reiksme - patikslinkite." << endl;
        cout << "Iveskite egzamino pazymi: ";
        cin.clear();
        cin.ignore();
    }
}
       
float vidurkis(vector <float> paz)
{
    int sum = 0;
    if (paz.size() < 1) { return 0; }
    for (int i = 0; i < paz.size(); i++) {sum += paz[i];}
    return sum / paz.size();
}
    
float mediana(vector<float> paz)
{
    typedef vector<float>::size_type vecSize;
    vecSize size = paz.size();
    if (size == 0) // jei nėra ivesta namu darbu - medianos skaiciuoti negalima
        throw std::domain_error("negalima skaičiuoti medianos tuščiam vektoriui");
    sort(paz.begin(), paz.end()); // surūšiuojame vektorių į variacinę eilutę
    vecSize vid = size / 2; // vidurinis vektoriaus elementas
    return size % 2 == 0 ? (paz[vid] + paz[vid - 1]) / 2 : paz[vid];
}
   
float galutinisPaz(Studentas stud) {
    float rez1, rez2;

    rez1 = vidurkis(stud.paz) * 0.4 + stud.egz * 0.6;
    rez2 = mediana(stud.paz) * 0.4 + stud.egz * 0.6;

    cout << rez1 << " / " << rez2;
}
    
int generate_random() //funkcija generuojanti atisitikitnius skaicius nuo 1 iki 10
{
    srand(time(NULL));
    return rand() % 10 + 1;
}
    
void autoIvedimas(studentas Eil[], int i, int n) //funckija automatiskai generuoja namu darbu pazymius ir egz. ivertinima
{
    Eil[i].egz = generate_random();
    for (int x = 0; x < n; x++)
    {
        Eil[i].nd[x] = generate_random();
    }
    
    Eil[i].galut = Eil[i].galut / n;
    Eil[i].galut = Eil[i].galut * 0.4 + Eil[i].egz * 0.6;
}
