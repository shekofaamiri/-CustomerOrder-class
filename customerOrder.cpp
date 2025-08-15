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