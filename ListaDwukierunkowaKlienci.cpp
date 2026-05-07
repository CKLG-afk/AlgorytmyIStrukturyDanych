#include <iostream>
using namespace std;

// Struktura Klient
struct Klient {
    int id;
    string imie;
    string email;
    Klient* next;
    Klient* prev; // drugi kierunek

    // Konstruktor
    Klient(int _id, const string& _imie, const string& _email) : id(_id), imie(_imie), email(_email), next(NULL), prev(NULL) {}
};

class ListaKlientDwukierunkowa {
public:
    Klient* head;
    Klient* last;

public:
    ListaKlientDwukierunkowa() : head(NULL), last(NULL) {}

    void printListaKlient() {
        if (head != NULL) {
            cout << "Klienci :" << endl;
            Klient* temp = head;
            do {
                cout << "id=" << temp->id << ", " << temp->imie << ", " << temp->email << endl;
                temp = temp->next;
            } while (temp != NULL);
        } else {
            cout << "Klienci : nie ma nikogo na liscie" << endl;
        }
    }

    void addHead(Klient* ka) {
        if (head != NULL) {
            ka->prev=NULL;
            ka->next = head;
            head->prev = ka;
            head = ka;
        } else {
            ka->next =NULL;
            ka->prev =NULL;
            head = ka;
            last = ka;
        }
    }

    void addLast(Klient* ka) {
        if (head != NULL) {
            ka->next=NULL;
            ka->prev = last;
            last->next = ka;
            last = ka;
        } else {
            ka->next =NULL;
            ka->prev =NULL;
            head = ka;
            last = ka;
        }
    }

    void removeLast() {
        if (head != NULL) {
            if (head->next == NULL) {
                delete head;
                head = last = NULL;
            } else {
                Klient* temp = last->prev;
                delete last;
                last = temp;
                last->next = NULL;
            }
        }
    }
};

int main() {
    ListaKlientDwukierunkowa* listaK = new ListaKlientDwukierunkowa();
    listaK->printListaKlient();

    Klient* k1 = new Klient(1, "Kris", "kris@kristoferson.com");
    listaK->addHead(k1);
    listaK->printListaKlient();

    Klient* k2 = new Klient(2, "Jacoco", "jacoco@jacobson.com");
    Klient* k3 = new Klient(3, "LJ", "lj@ljson.com");
    listaK->addHead(k3);
    listaK->printListaKlient();
    listaK->addLast(k2);
    listaK->printListaKlient();

    listaK->removeLast();
    listaK->printListaKlient();

    return 0;
}
