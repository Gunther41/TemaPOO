#include <iostream>
using namespace std;

class nod{
private:
    char litera;
    nod *urmator;
public:
    nod(); //constructor normal
    nod(char litera_citita); //constructor pentru push
    nod* litera_urmator(); // returneaza urmatoarea litera
    void replace_urmator(nod* point); //util pt a inlocui poz nodului urmator
    char return_litera();}; //util pentru a primi litera de pe o anumita pozitie

nod::nod(){ //constructor normal
    cin>>litera;
    urmator=NULL;}

nod::nod(char litera_citita){ //constructor pentru push
        litera=litera_citita;
        urmator=NULL;}

nod* nod::litera_urmator(){
        return urmator;}

void nod::replace_urmator(nod* point){
    urmator=point;}

char nod::return_litera(){
    return litera;}

class coada_char{
private:
    nod *primul; //salvam in clasa coada pozitia primului si ultimului caracter
	nod *ultimul;

public:
    coada_char();
    void push(char litera_citita);//adaugare caracter la coada
    void pop();//scos caracter
    bool isempty();//verifica daca este goala coada
    coada_char operator + (const coada_char &coada_2);//supraincarcare operator concatenare
    coada_char operator - (coada_char &coada_2);//supraincarcare operator pentru diferenta
    ~coada_char();//destructor.
    friend ostream &operator << (ostream& scriere,const coada_char &coada);//supraincarcare operator afisare coada
    friend istream &operator >> (istream& citire,coada_char &coada);};//supraincarcare operator scriere in coada

coada_char::coada_char(){  //constructor coada
        primul=NULL;
        ultimul=NULL;}

void coada_char::push(char litera_citita){
        nod* index_nod=new nod(litera_citita);
        if (primul==NULL){//daca coada este goala, poz primului si ultimului devine poz literei citite
            primul=index_nod;
            ultimul=index_nod;}
        else{
            ultimul->replace_urmator(index_nod);//daca coada nu este goala, poz ultimei litere creste, noul caracter devine ultima litera, pozitia urmatoare este declarata NULL
            ultimul=index_nod;}
        ultimul->replace_urmator(NULL);}

void coada_char::pop(){
        nod* index_nod=primul;
        if (index_nod==ultimul){//daca este numai un caracter in lista, setam poz lui null
            primul=NULL;
            ultimul=NULL;}
        else{
            primul=primul->litera_urmator();//daca nu, distrugem ce este pe prima pozitie si pozitia literei urmatoare devine pozitia primei litere
            delete index_nod;}}

bool coada_char::isempty(){//daca ultimul caracter din coada este null, coada este goala
        return ultimul==NULL;
    }

coada_char::~coada_char(){//cat timp coada este goala, scoatem fiecare caracter din coada unul cate unul pana ajungem la ultimul si setam valorile primul si ultimul nule.
while(!isempty()){pop();}}

coada_char coada_char::operator + (const coada_char &coada_2)
{
        coada_char rezultat;
        nod* point_coada1=primul;//ma duc la pozitia primei litere din coada1
        while(point_coada1!=NULL)//cat timp mai am litere in coada, le adaug la rezultat si trec la urmatoarea pozitie
        {
            rezultat.push(point_coada1->return_litera());
            point_coada1=point_coada1->litera_urmator();
        }
        nod* point_coada2=coada_2.primul;//ma duc la pozitia primei litere din coada2
        while(point_coada2!=NULL)//cat timp mai am litere in coada, le adaug la rezultat si trec la urmatoarea pozitie
        {
            rezultat.push(point_coada2->return_litera());
            point_coada2=point_coada2->litera_urmator();
        }
        return rezultat;}

coada_char coada_char::operator - (coada_char &coada_2){
        coada_char rezultat;
        nod* point_coada1=primul;//iau poz primelor litere din ambele cozi
        nod* point_coada2=coada_2.primul;
        char x;//doua char temporare pt comparare ascii
        char y;

        while(point_coada1!=NULL && point_coada2!=NULL){//verific una dintre cozi s-a terminat mai repede, cat timp mai am litere, merg inainte
            x=point_coada1->return_litera();//x ia valoarea literei de pe prima pozitie a coizi 1
            y=point_coada2->return_litera();//y ia valoarea literei de pe prima pozitie a coizi 2

            if(x>y){rezultat.push(x);}//daca x>y, adaugam x la rezultat
            else{rezultat.push(y);}//daca nu, adaugam y

            point_coada1=point_coada1->litera_urmator();//trecem la urmatoarea litera
            point_coada2=point_coada2->litera_urmator();}
        return rezultat;}

ostream& operator << (ostream& scriere,const coada_char &coada) { //fara const nu am reusit sa il fac, variabila "primul" este privat
    nod* index_nod=coada.primul;
    while(index_nod!=NULL){//trecem prin toate pozitiile si adunam continutul lor in "scriere"
        scriere<<index_nod->return_litera();
        index_nod=index_nod->litera_urmator();}
        return scriere;}

coada_char& operator >> (coada_char &coada,char litera_citita){//adaugam litera (una singura) la "coada" folosind push()
    coada.push(litera_citita);
    return coada;}

