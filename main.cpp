#include <iostream>
#include <list>
#include "Task.h"
#include "List.h"

using namespace std;

int main() {

    List lista = List("test");
    string nome, nameList;
    tm data;
    list<Task>::iterator ls;


    int scelta = -1;
    
    do{
        cout << "1) Crea lista \n"
                "2) Stampa lista \n"
                "3) Aggiungi elemento \n"
                "4) Elimina elemento \n"
                "5) Completa/Decompleta un elemento \n"
                "6) Salva su file \n"
                "7) Carica da file \n"
                "8) Numero attività totali \n"
                "9) Check Day \n"
                "10) Modifica Task \n"

                "0) Esci \n " << endl;

        cin >> scelta;
        cin.ignore();

        switch (scelta)
        {
            case 1:
                cout << "Inserire il nome della nuova lista" << endl;
                getline(cin, nameList);
                if(!lista.getNameList().empty()) {
                    lista.setNameList(nameList);
                }
                break;

            case 2:
                if(!lista.getNameList().empty()) {
                    cout << "lista: " + lista.getNameList() << endl;
                    cout << lista.toString() << endl;
                }
                else
                    cout <<"Nessuna Lista presente";
                break;

            case 3:
                cout << "Inserire il nome dell' elemento: ";
                getline(cin, nome);
                if(!lista.getNameList().empty()) {

                    cout << "Inserisci la data di termine dell'attivita. \n";
                    cout << "Giorno: ";
                    cin >> data.tm_mday;

                    cout << "Inserisci la data di termine dell'attivita. \n";
                    cout << "Mese: ";
                    cin >> data.tm_mon;

                    cout << "Inserisci la data di termine dell'attivita. \n";
                    cout << "Anno: ";
                    cin >> data.tm_year;

                    Task element = Task(nome, data);

                    lista.addElement(element);
                }
                else
                    cout << "Nessuna Lista selezionata. \n";
                break;

            case 4:
                if(!lista.getNameList().empty()){
                    cout << "Inserire il nome dell' elemento da rimuovere: ";
                    getline(cin, nome);
                    ls = lista.find(nome);
                    if (ls->getName() == nome)
                        lista.removeElement(*ls);
                    else
                        cout << "Elemento non trovato" << endl;
                }
                break;

            case 5:
                if(!lista.getNameList().empty()) {
                    cout << "Scrivi il nome dell'elemento da completare/decompletare" << endl;
                    getline(cin, nome);
                    Task element {nome};
                    ls = lista.find(nome);
                    if (ls->getName() == nome)
                        lista.toggleElement(element);
                    else
                        cout << "Elemento non trovato" << endl;
                }
                else
                    cout << "Nessuna lista selezionata" << endl;

                break;

            case 6:
                if(!lista.getNameList().empty())
                    lista.writeFile();
                else
                    cout << "Nessuna lista selezionata" << endl;
                break;

            case 7:
                cout << "Inserire nome del file da cui caricare la lista" << endl;
                cin >> nome;
                lista.loadFile(nome);
                break;

            case 8:
                cout << " Le attivita da svolgere sono: " + to_string(lista.countTaskToDo()) << endl;
                break;

            case 9:
                if(!lista.getNameList().empty()) {

                    cout << "Inserisci una data. \n";
                    cout << "Giorno: ";
                    cin >> data.tm_mday;

                    cout << "Inserisci la data di termine dell'attivita. \n";
                    cout << "Mese: ";
                    cin >> data.tm_mon;

                    cout << "Inserisci la data di termine dell'attivita. \n";
                    cout << "Anno: ";
                    cin >> data.tm_year;

                    cout << "\n Le attività da svolgere in tale data sono: \n" + lista.getTaskToDoDay(data) << endl;

                }
                break;

            case 10:

                if(!lista.getNameList().empty()){
                    cout << "Inserire il nome dell' elemento da modificare: ";
                    getline(cin, nome);
                    ls = lista.find(nome);

                    if (ls->getName() == nome) {
                        string newName;
                        tm dataUpdate;

                        cout << "Aggiorna il nome: ";
                        getline(cin, newName);

                        lista.find(nome)->setName(newName);
                        cout << "Aggiorna la data: \n";


                        cout << "Giorno: ";
                        cin >> dataUpdate.tm_mday;

                        cout << "Inserisci la data di termine dell'attivita. \n";
                        cout << "Mese: ";
                        cin >> dataUpdate.tm_mon;

                        cout << "Inserisci la data di termine dell'attivita. \n";
                        cout << "Anno: ";
                        cin >> dataUpdate.tm_year;

                        lista.find(newName)->setDateTime(dataUpdate);
                    }
                    else {
                        cout << "Elemento non trovato" << endl;
                    }
                }
                break;

            default:
                break;
        }

    }while(scelta != 0);
    return 0;
}
