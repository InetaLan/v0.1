#include <iostream>
#include <string>
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
float mediana(vector<float> paz);
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

void print(vector<studentas> Eil, int paz_sk) {
    std::ofstream output;
    output.open("rezultatai.txt");
    output
        << left << setw(15) << "Vardas"
        << left << setw(20) << "Pavarde"
        << left << setw(25) << "Egzamino rez."
        << left << setw(20) << std::setprecision(3) << "Galutinis(vid.)/"
        << left << "Galutinis(med.) " << endl
        << string(15 + 20 + 3 * 25, '-') << "\n";

    for (int i = 0; i < Eil.size; i++)
    {
        output
            << left << setw(15) << Eil[i].vardas
            << left << setw(20) << Eil[i].pavarde
            << left << setw(25) << Eil[i].egz
            << left << setw(20) << std::setprecision(3) << Eil[i].galut
            << mediana(Eil[i].paz) << endl;
    }

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
