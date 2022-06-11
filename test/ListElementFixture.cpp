#include <gtest/gtest.h>
#include "../Task.h"
#include "../List.h"

class ListSuite : public ::testing::Test {

protected:
    virtual void SetUp(){
        Task element("Test1");
        element.toggle();
        list.setNameList("UnitTest");
        list.addElement(element);
        Task element2("Test2");
        list.addElement(element2);
    }

    List list;
};

TEST_F(ListSuite, TestDateAttivita){
    tm data {0,0,0,1,1,2022};
    Task element_data("TestData", data);
    list.addElement(element_data);
    Task element_data1("TestData2", data);
    list.addElement(element_data1);

    EXPECT_EQ(list.countTaskToDoDay(data) , 2);

    tm data2 {0,0,0,2,1,2022};

    Task element_data3("TestData3", data2);
    list.addElement(element_data3);

    EXPECT_EQ(list.countTaskToDoDay(data) , 2);
    EXPECT_EQ(list.countTaskToDoDay(data2) , 1);


}

TEST_F(ListSuite, TestContoAttivita){

    EXPECT_EQ(list.countTaskToDo(), 1);
    Task element2 ("Test2");
    list.removeElement(element2);
    EXPECT_EQ(list.countTaskToDo(),0);
}
Edit Distance e N-gram
Tommaso Vannozzi
6356306
15/06/2022
Laboratorio di Algoritmi
Ingegneria Informatica
Universit`a degli Studi di Firenze
1
1 Edit Distance e N-Grams
L’esercitazione consiste nel creare un programma che esegua il calcolo della distanza e della
similirit`a tra una stringa in input e un dataset di stringhe, tramite l’algoritmo di Edit-Distance
e confronta il risultato ottenuto con la misurazione della similarit`a delle medesime stringhe
calcolata tramite N-grams e Jaccard (in particolare 2-Grams e 3-Grams).
2 Edit-Distance
Date due sequenze di caratteri X,Y l’algoritmo di Edit-Distance permette di trovare un alli-
neamento ottimo delle due che corrisponda alla minima distanza tra X e Y, dove la distanza `e
definita secondo le regole seguenti:
• si ammette che nelle due sequenze possano essere inseriti spazi e che, per ogni posizione
nelle due sequenze, il carattere o lo spazio che appare nella X sia posto in corrispondenza
(allineato) con il carattere o lo spazio nella stessa posizione della Y;
• la distanza `e la somma delle distanze tra coppie di caratteri o spazi, uno in X e l’altro
in Y, in posizioni corrispondenti nell’allineamento: caratteri uguali hanno distanza zero,
caratteri diversi hanno distanza 1.
La edit distance tra X e Y `e la distanza relativa agli allineamenti, cio`e tutte quelle operazioni
di edit (inserimento, sostituzione e cancellazione) che minimizza tale distanza.
3 N-Grams
Nei campi della linguistica computazionale e probabilit`a, un n -gram (a volte chiamato anche
Q-grammo ) `e una sequenza contigua di n elementi da un determinato campione di testo o
discorso. Gli elementi possono essere fonemi, sillabe, lettere, parole o coppie di basi a seconda
dell’applicazione.
3.1 Jaccard Similarity
Per valutare la somiglianza tra le stringhe, `e necessario usare alcune espressioni matematiche
che possono valutare e dare come risposta un unico valore numerico.
Tra le misure di somiglianza pi`u conosciute c’`e sicuramente il coefficiente di Jaccard.
Il coefficiente di Jaccard misura la similarit`a tra insiemi campionari, ed `e definito come la di-
mensione dell’intersezione divisa per la dimensione dell’unione degli insiemi campionari:
J(A, B) = |X ∩ Y |
|X ∪ Y | (1)
La distanza di Jaccard si ottiene sottraendo ad uno il coefficiente calcolato nella formula 1.
DJ(A, B) = 1 − J(A, B)
1


TEST_F(ListSuite, TestOperazioniNonEseguibili){

    EXPECT_EQ(list.find("Elemento Non Esistente"), list.getElements().end()) << "La ricerca di un elemento inesitente non dà risultati";

    auto el = list.find("Lista Non Esistente");
    EXPECT_EQ(el, list.getElements().end()) << "La ricerca in una lista corrente inesistente non dà risultati";

}


TEST_F(ListSuite, IOTest){
    auto el = list.find("Test1");
    ASSERT_NE(el, list.getElements().end());

    list.writeFile();
    list.loadFile("UnitTest");
    el = list.find("Test1");
    ASSERT_NE(el, list.getElements().end());
    EXPECT_TRUE(el->isChecked());

    el = list.find("Test2");
    ASSERT_NE(el, list.getElements().end());

    list.removeElement(*el);
    list.addElement(Task("Test3"));
    list.writeFile();
    list.loadFile("UnitTest");
    el = list.find("Test2");
    ASSERT_EQ(el, list.getElements().end());
    el = list.find("Test3");
    ASSERT_NE(el, list.getElements().end());
    EXPECT_FALSE(el->isChecked());
}

