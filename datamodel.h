#include <bits/stdc++.h>
using namespace std;

class Product
{
    int id;
    string name;
    int price;

public:
    Product()
    {
    }
    Product(int p_id, string name, int price)
    {
        id = p_id;
        this->name = name;
        this->price = price;
    }

    string displayProductDetails()
    {
        return name + " -> " + to_string(price) + " /- ";
    }
    string getShortName()
    {
        return name.substr(0, 1);
    }
    friend class Item;
    friend class Cart;
};

class Item
{
    Product product;
    int quantity;

public:
    Item() {}
    Item(Product p, int q) : product(p), quantity(q) {}
    int getItemPrice()
    {
        return quantity * product.price;
    }
    string getItemDetails()
    {
        return to_string(quantity) + "x" + product.name + " @" + to_string(product.price) + " => " + to_string(quantity * product.price);
    }
    friend class Cart;
};

class Cart
{
    unordered_map<int, Item> ump;

public:
    void addProduct(Product product)
    {
        if (ump.count(product.id) == 0)
        {
            Item newItem(product, 1);
            ump[product.id] = newItem;
        }
        else
        {
            ump[product.id].quantity += 1;
        }
    }
    int getTotal()
    {
        int total = 0;
        for (auto itemPair : ump)
        {
            auto item = itemPair.second;
            total += item.getItemPrice();
        }
        return total;
    }
    bool isempty()
    {
        return ump.empty();
    }
    string viewCart()
    {
        if (ump.empty())
        {
            return "Cart is empty";
        }
        string itemizedList;
        int cartTotal = getTotal();
        for (auto itemPair : ump)
        {
            auto item = itemPair.second;
            itemizedList.append(item.getItemDetails());
        }
        return itemizedList + "\nTotal Amount: Rs. " + to_string(cartTotal);
    }
};