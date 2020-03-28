#include <iostream>
#include "poo.h"
using namespace std;


int main(){
    coada_char Coada_1, Coada_2;
    Coada_1 >> 'a' >> 'n' >> 'a';
    Coada_2.push('a');
    Coada_2.push('r');
    Coada_2.push('e');
    Coada_2.push('m');
    Coada_2.push('e');
    Coada_2.push('r');
    Coada_2.push('e');
    cout << "Coada_1 = "<< Coada_1<<"\n";
    cout << "Coada_2 = "<< Coada_2<<"\n";
    cout << "Coada_1 + Coada_2 = ";
    cout << Coada_1 + Coada_2 << "\n";
    Coada_2.pop();
    Coada_2.pop();
    Coada_2.pop();
    cout << "Coada_2.pop *3 = ";
    cout << Coada_2<<"\n";
    cout << "Coada_1.push('x') = ";
    Coada_1.push('x');
    cout << Coada_1<<"\n";
    cout << "Coada_1 - Coada_2 = ";
    cout << Coada_1-Coada_2 << "\n";
    return 0;}
