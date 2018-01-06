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

class AbstractProductFactory
{ // One particular interface for use in Abstract Factory pattern
public:
virtual Product* createCP1() = 0;
virtual Product* createCP2() = 0;
};


class MyConfigurator: AbstractProductFactory
{ // One particular interface for use in Abstract Factory pattern
public:
Product* createCP1() { return new CP1; }
Product* createCP2() { return new CP2; }
};

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
