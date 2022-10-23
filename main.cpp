#include <iostream>
#include <memory>

class Base{
    public:
    Base() :  ba(0){}
    Base(int b) :ba(b){}
    // Always use virtual for dynamic polymorphic effect inorder to call the right destructure
    virtual ~Base(){std::cout << "This is base class destructure! "  << std::endl;}
    virtual void vertFunc(){}; // e polymorphic to use runtime-checked dynamic_cast
    void show(){std::cout << "Base: Ba= " << ba << std::endl;};
protected:
    int ba;
};

// Derived class
class Derv1 : public Base{
public:
    Derv1() : a(0){}
    Derv1(int c, int d) : a(c), Base(d){}
    ~Derv1(){}
    void show() {
        std::cout << "Derv1:  ba=  "  << ba << ", da= " << a << std::endl;
    }
private:
    int a;
};


class Derv2 : public Base{

};



void Display(Base *base){
    std::cout << "The pointer to an object of class ";
    std::cout << typeid(*base).name() << std::endl;
}

int main() {
//// Dyynamic cast part
    Base *ptrBase = new Base(10);
    Derv1 *ptrDerv1 = new Derv1(21,22);
    ptrBase->show(); // Normal
    ptrDerv1->show(); // Normal
    //// derived-to-base: upcast -- points to Base subobject of Derv
    ptrBase = dynamic_cast<Base*>(ptrDerv1);
    ptrBase->show(); //Base:  ba = 22
    ptrBase = new Derv1(31,32); // Normal
    ///// Base to drive  downcast -- (ptrBase must point to a Derv);
    ptrDerv1 = dynamic_cast<Derv1*>(ptrBase);
    ptrDerv1->show(); //// derv: ba=31, da=32
//// Typeid part


    Base *ptrBase2 = new Derv1;  // Pointer to an object of class Derv1
    Display(ptrBase2);

    ptrBase2 = new Derv2;
    Display(ptrBase2); // Pointer to an object of class Derv2;










    return 0;
}
