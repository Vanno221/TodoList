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

