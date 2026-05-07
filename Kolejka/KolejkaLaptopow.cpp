/*
Laptop
a.	nazwa – typu string
b.	ramGB -  typu int
c.	dyskTB – typu double
d.	ekran – typu double (przekątna)
e.	cena – typu double
*/

#include <iostream>
using namespace std;

struct Laptop{
    string nazwa;
    int ramGB;
    double dyskTB;
    double ekran;
    double cena;

    Laptop *next;
    Laptop(){
    nazwa = "bez nazwy";
    }
    Laptop(string nazwa,int ramGB,
             double dyskTB, double cena, double ekran){
    this->nazwa = nazwa;
    this->ramGB = ramGB;
    this->dyskTB = dyskTB;
    this->cena= cena;
    this->ekran= ekran;
    next = NULL;
    }

     void print(){
     cout << nazwa<<", ramGB= "<<ramGB<<", dysk= "<< dyskTB;
     cout<<", ekran="<<ekran<<", cena="<<cena<<endl;
     }

};//Laptop

struct KolejkaLaptop{
    Laptop *first;
    Laptop *last;
    int rozmiar_kolejki;
    KolejkaLaptop(){
        first = NULL;
        last = NULL;
        rozmiar_kolejki = 0;
    }
    void push(Laptop *komp){
        if (komp!=NULL){
            if(last!=NULL){
            last->next = komp;
            last = komp;
            }
            else{
            komp->next = NULL;
            first = last = komp;
            }
            rozmiar_kolejki++;
        }
    }

    string pop(){
      Laptop *temp = first;
      string zwrot= "";
        if(temp!=NULL){
            zwrot = temp->nazwa;
            first = first->next;
            if(first==NULL) last =NULL;
            delete temp;
            rozmiar_kolejki--;
        }
       return zwrot;
    }//pop

    void printKolejkaLaptop(){
    Laptop *temp = first;
    cout <<"Kolejka :"<<endl;
    while(temp!=NULL){
        temp->print();
        temp = temp->next;
    }
      cout <<"------"<<endl;
    }
    bool empty_k() {
        return (first == NULL);
    }
    int size_k()
    {
        return rozmiar_kolejki;
    }
    string front_k() {
        if (first != NULL) {
            return first->nazwa;
        } else {
            return "Kolejka jest pusta";
        }
    }

    string back_k() {
        if (last != NULL) {
            return last->nazwa;
        } else {
            return "Kolejka jest pusta";
        }
    }
};

int main(){
KolejkaLaptop kolejka;
Laptop *k1 = new Laptop("Lapek 1",
                    32, 4.0, 2999.99, 15.6);
kolejka.printKolejkaLaptop();
kolejka.push(k1);
kolejka.printKolejkaLaptop();


Laptop *k2 = new Laptop("Lapek 2", 64, 4.0, 3999.99, 14);
kolejka.push(k2);
kolejka.printKolejkaLaptop();

Laptop *k3 = new Laptop("Lapek 3", 4, 0.5, 1999.99, 17);
kolejka.push(k3);
kolejka.printKolejkaLaptop();
cout << "Front: " << kolejka.front_k() << endl;
cout << "Back: " << kolejka.back_k() << endl;
cout << "Rozmiar kolejki to: " << kolejka.rozmiar_kolejki << endl;
kolejka.pop();
kolejka.printKolejkaLaptop();
kolejka.pop();
kolejka.printKolejkaLaptop();
kolejka.pop();
kolejka.printKolejkaLaptop();
kolejka.pop();
kolejka.printKolejkaLaptop();
cout << "Rozmiar kolejki to: " << kolejka.rozmiar_kolejki << endl;
if (kolejka.empty_k()==true)
{
    cout << "kolejka jest pusta" << endl;
}
else
{
    cout << "kolejka nie jest pusta" << endl;
}
cout << "Front: " << kolejka.front_k() << endl;
cout << "Back: " << kolejka.back_k() << endl;
return 0;
}
