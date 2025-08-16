#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Represents a single ordered food item
class OrderItem
{
private:
    int foodID;
    string foodName;
    int quantity;
    int Price;
    public:
    // Constructors
    OrderItem() {};
    OrderItem(int id, int qty, int pri, const string &name)
    {
        foodID = id;
        foodName = name;
        quantity = qty;
        Price = pri;
    }
    //setter
    void setFoodID(int id) { foodID = id; }
    void setFoodName(string name) { foodName = name; }
    void setQuantity(int qty) { quantity = qty; }
    void setPrice(int pri) { Price = pri; }
 // Getters
    int getFoodID() const { return foodID; }
    string getFoodName() const { return foodName; }
    int getQuantity() const { return quantity; }
    int getPrice() const { return Price; }
// Increase quantity
    void addQuantity(int qty) { quantity += qty; }

    // Calculate total price for this item
    int getTotalPrice() const { return quantity * Price; }

    // Display item details
    void print() const
    {
        cout << foodName << "\t" << Price << "\t" << quantity << "\t" << getTotalPrice() << "\n";
    }
};
// Represents a customer's complete order
class CustomerOrder
{
private:
    vector<OrderItem> items;

public:
    // Add new item or increase quantity if it exists
    void addItem(int id, const string &name, int qty, int price)
    {
        for (auto &item : items)
        {
            if (item.getFoodID() == id)
            {
                item.addQuantity(qty);
                return;
            }
        }
        items.push_back(OrderItem(id, qty, price, name));
    }
