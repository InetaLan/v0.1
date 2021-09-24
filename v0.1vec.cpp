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

float mediana(vector<float> paz);
void print(vector<studentas> Eil, int paz_sk);
unsigned int countWordsInString(std::string const& str);
void read_from_file(std::vector<studentas>& Eil, int* paz_sk);

int main()
{
    int paz_sk;
    char temp;
    vector<studentas> Eil;
    read_from_file(Eil &paz_sk);
    print(Eil, paz_sk);
    system("pause");
    return 0;
}

void print(vector<studentas> Eil, int paz_sk) {
    std::ofstream output;
    output.open("kursiokai.txt");
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

unsigned int countWordsInString(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}

void read_from_file(std::vector<studentas>& Eil, int* paz_sk)
{
    int student_counter = 0;
    int temp;
    std::ifstream fileRead;
    string buff;
    fileRead.open("kursiokai.txt");
    if (fileRead.is_open())
    {
        getline(fileRead >> std::ws, buff);
        *paz_sk = countWordsInString(buff) - 3;
        while (true)
        {

            Eil.resize(Eil.size() + 1);
            fileRead >> Eil.at(student_counter).vardas;
            if (fileRead.eof()) { Eil.pop_back(); break; }
            fileRead >> Eil.at(student_counter).pavarde;
            for (int i = 0; i < *paz_sk; i++)
            {
                fileRead >> temp;
                Eil.at(student_counter).paz.push_back(temp);
            }
            fileRead >> Eil.at(student_counter).egz;
            Eil.at(student_counter).galut = Eil.at(student_counter).galut / *paz_sk;
            Eil.at(student_counter).galut = Eil.at(student_counter).galut * 0.4 + 0.6 * Eil.at(student_counter).egz;
            student_counter++;
        }
    }
    else {cout << "-\n"; }
    
