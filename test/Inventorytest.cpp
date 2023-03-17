#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Inventory.h"
using ::testing::InSequence;

class MockInventory : public Inventory {
    public:
        MockInventory() : Inventory(2, 2) {};
        MOCK_METHOD(string, getName, ()); 
        MOCK_METHOD(string, getID, ()); 
        MOCK_METHOD(void, setID, (string)); 
        MOCK_METHOD(void, setName, (string)); 
};

TEST(InventoryTests, parameterConstructorTest) {
    EXPECT_NO_THROW(Inventory *testInventory = new Inventory(0,0));
}

// Inventory and Item classes are too tightly coupled and difficult to test 
TEST(InventoryTests, addItemTest) {
    Inventory testInventory(2 , 2);
    string testName = "testName";
    string testID = "testID";
    Stats testStats;
    Item testItem(testName, testID, testStats);
    testInventory.addItem(testItem);
    EXPECT_EQ(testInventory.items[0].getName(), testItem.getName());
}


TEST(InventoryTests, displayInventoryTest) {
    MockInventory testInventory;
    string testName = "testName";
    string testID = "testID";
    Stats testStats;
    Item testItem1(testName, testID, testStats);
    testInventory.items = {testItem1};
    //Item testItem2(testName, testID, testStats);
    //testInventory.items.at(0) = testItem1;
    //testInventory.items.at(1) = testItem2;
    string test = testInventory.items.at(0).getName();
    {
        InSequence sequence;
        EXPECT_EQ(test, testName);
        EXPECT_NO_THROW(testInventory.items.at(0).getName());
        EXPECT_NO_THROW(testInventory.items.at(0).getID());
        //EXPECT_CALL(testInventory, getName());
        //EXPECT_CALL(testInventory, getID());
    }
    //testInventory.displayInventory();
}