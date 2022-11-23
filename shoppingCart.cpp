#include <iostream>
#include "datamodel.h"
#include <vector>
using namespace std;

vector<Product> allProducts =
    {
        Product(1, "Apple", 10),
        Product(2, "Mango", 20),
        Product(3, "Kiwi", 30),
        Product(4, "Orange", 40),
        Product(5, "Banana", 50)};

Product *chooseProduct()
{
    cout << "*****************************************************" << endl;
    cout << "Available Products " << endl;
    for (auto product : allProducts)
    {
        cout << product.displayProductDetails() << endl;
    }
    cout << "*****************************************************" << endl;
    cout << "Please enter product initials for selecting that product..." << endl;
    cout << "*****************************************************" << endl;
    string choice;
    cin >> choice;
    for (int i = 0; i < allProducts.size(); i++)
    {
        if (allProducts[i].getShortName() == choice)
        {
            return &allProducts[i];
        }
    }
    cout << "Product Not Found" << endl;
    return NULL;
}
bool checkout(Cart &cart)
{
    if (cart.isempty())
    {
        return false;
    }
    int totalPay = cart.getTotal();
    cout << "Pay in Cash" << endl;
    int paid;
    cin >> paid;
    if (paid >= totalPay)
    {
        cout << "Change " << paid - totalPay << endl;
        cout << "Thank you for shopping with us" << endl;
        return true;
    }
    else
    {
        cout << "Not enough cash" << endl;
        return false;
    }
}
int main()
{
    char action;
    Cart cart;
    while (true)
    {
        cout << "Select an action to proceed..." << endl;
        cout << "A - Add an item to Cart" << endl;
        cout << "V - View an item of Cart" << endl;
        cout << "C - Checkout the Cart" << endl;
        cout << "*****************************************************" << endl;
        cout << "Please enter appropiate character as shown..." << endl;
        cout << "*****************************************************" << endl;
        cin >> action;
        if (action == 'A')
        {
            Product *p = chooseProduct();
            if (p != NULL)
            {
                cout << "*****************************************************" << endl;
                cout << "Added to cart " << p->displayProductDetails() << endl;
                cout << "*****************************************************" << endl;
                cart.addProduct(*p);
            }
        }
        else if (action == 'V')
        {
            cout << "*****************************************************" << endl;
            cout << cart.viewCart() << endl;
            cout << "*****************************************************" << endl;
        }
        else
        {
            cart.viewCart();
            if (checkout(cart))
            {
                break;
            }
        }
    }
    return 0;
}