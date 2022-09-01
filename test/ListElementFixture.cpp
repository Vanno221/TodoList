#include <gtest/gtest.h>
#include <list>
#include "../Task.h"
#include "../List.h"

class ListSuite : public ::testing::Test {

protected:
    virtual void SetUp(){
        Task element("Test1");
        element.toggle();
        lista.setNameList("UnitTest");
        lista.addElement(element);
        Task element2("Test2");
        lista.addElement(element2);


    }
    List lista;
    list<Task>::iterator ls;

};

TEST_F(ListSuite, TestDateAttivita){
    tm data {0,0,0,1,1,2022};
    Task element_data("TestData", data);
    lista.addElement(element_data);
    Task element_data1("TestData2", data);
    lista.addElement(element_data1);

    EXPECT_EQ(lista.countTaskToDoDay(data) , 2);

    tm data2 {0,0,0,2,1,2022};

    Task element_data3("TestData3", data2);
    lista.addElement(element_data3);

    EXPECT_EQ(lista.countTaskToDoDay(data) , 2);
    EXPECT_EQ(lista.countTaskToDoDay(data2) , 1);


}

TEST_F(ListSuite, TestContoAttivita){

    EXPECT_EQ(lista.countTaskToDo(), 1);
    Task element2 ("Test2");
    lista.removeElement(element2);
    EXPECT_EQ(lista.countTaskToDo(),0);
}


TEST_F(ListSuite, TestOperazioniNonEseguibili){

    ls = lista.find("Elemento non esistente");
    EXPECT_EQ(lista.find("Elemento Non Esistente"), ls) << "La ricerca di un elemento inesitente non dà risultati";

    ls = lista.find("Test1");
    Task elementTest("Test1");
    EXPECT_EQ(lista.find("Test1")->getName(), elementTest.getName()) << "La ricerca di un elemento esistente dà risultati";

}


TEST_F(ListSuite, IOTest){
    auto el = lista.find("Test1");
    ASSERT_NE(el, lista.getElements().end());

    lista.writeFile();
    lista.loadFile("UnitTest");
    el = lista.find("Test1");
    ASSERT_NE(el, lista.getElements().end());
    EXPECT_TRUE(el->isChecked());

    el = lista.find("Test2");
    ASSERT_NE(el, lista.getElements().end());

    lista.removeElement(*el);
    lista.addElement(Task("Test3"));
    lista.writeFile();
    lista.loadFile("UnitTest");
    el = lista.find("Test2");
    ASSERT_EQ(el, lista.getElements().end());
    el = lista.find("Test3");
    ASSERT_NE(el, lista.getElements().end());
    EXPECT_FALSE(el->isChecked());
}

