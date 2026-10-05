/*
    Extensible: Add new product types by creating new factory classes, without touching existing code.
    Polymorphic: Factories themselves can be passed around and chosen dynamically.
    Cleaner: Each factory has a single responsibility.
*/


#include <iostream>

using namespace std;

class Product{
    public:
        virtual void use() = 0;
};

class ProductA : public Product{
    public:
        void use() override{
            cout<<"We are accessing productA\n";
        }
};

class ProductB : public Product{
    public:
        void use() override{
            cout<<"We are accessing productB\n";
        }
};

class Factory{
    public:
        virtual unique_ptr<Product>createProduct() = 0;
        virtual ~Factory(){
            
        };
    
};
class FactoryA : public Factory{
    public:
        unique_ptr<Product>createProduct(){
            return make_unique<ProductA>();
        }
        ~FactoryA()override{
            
        }
    
};
class FactoryB : public Factory{
    public:
        unique_ptr<Product>createProduct(){
            return make_unique<ProductB>();
        }
        ~FactoryB()override{
            
        }
    
};

int main(){
    FactoryA factoryA;
    factoryA.createProduct()->use();
    FactoryB factoryB;
    factoryB.createProduct()->use();
    return 0;
}