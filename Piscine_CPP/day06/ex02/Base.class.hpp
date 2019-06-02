#ifndef BASECLASS_HPP
#define BASECLASS_HPP

class Base {
    public:
        virtual ~Base(void) {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif