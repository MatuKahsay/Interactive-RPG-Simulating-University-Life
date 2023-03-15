#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "inventory.h"
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
    Item testItem(testName, testID);
    testInventory.addItem(testItem);
    EXPECT_EQ(testInventory.items[0], testItem);
}


TEST(InventoryTests, displayInventoryTest) {
    MockInventory testInventory;
    {
        InSequence sequence;
        EXPECT_CALL(testInventory, getName());
        EXPECT_CALL(testInventory, getID());
        EXPECT_CALL(testInventory, getName());
        EXPECT_CALL(testInventory, getID());
        
    }
    testInventory.displayInventory();
}