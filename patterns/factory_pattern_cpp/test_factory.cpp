#include <iostream>
using namespace std;

class Product
{
// Your stuff
};
class CP1 : public Product
{
// Your stuff
};
class CP2 : public Product
{
// Your stuff
};

class ProductFactory
{
    public:
    virtual Product* createProduct() = 0;
};

class MyProductFactory : public ProductFactory
{
public:
	Product* createProduct()
	{
	cout << "CP1 just made\n";
	return new CP1;
	}
};

class YourProductFactory : public ProductFactory
{
public:
    Product* createProduct()
    {
	cout << "CP2 just made\n";
        return new CP2;
    }
};

ProductFactory * getFactory(){
    cout << "1. My Factory, 2. Your factory: " << endl;
    int k; cin >> k;
    if (k == 1)
        return new MyProductFactory;
    if (k == 2)
        return new YourProductFactory();
     // Default or future extensions here
    return new MyProductFactory;
}

class Option
{ // Abstract base class for the options in this book
public:
virtual double Price() const = 0;
};

class ExactEuropeanOption : public Option
{
   virtual double Price() const;
};
double ExactEuropeanOption::Price() const{
    return 4;
}
class ExecutiveOption : public Option
{
virtual double Price() const;
};
double ExecutiveOption::Price() const{
    return 4;
}

class OptionFactory
{
public:
virtual Option* createOption() = 0;
};
class MyOptionFactory : public OptionFactory
{
public:
virtual Option* createOption()
{ // In practice this code will be ‘more’
return new ExactEuropeanOption;
}
};
class YourOptionFactory : public OptionFactory
{
public:
virtual Option* createOption()
{
return new ExecutiveOption;
}
};

int main(){
    ProductFactory* currentFactory = getFactory();
    Product* myProduct = currentFactory -> createProduct();
    delete myProduct;
    cout << "1. European, 2. Executive: ";
    int k;
    cin >> k;
    OptionFactory* of;
    if (k == 1)
       of = new MyOptionFactory;
    else
       of = new YourOptionFactory;
   Option* option = of -> createOption();
       double d = option -> Price();
    cout << "Price is: " << d << endl;
    return 0;
}
