#pragma once
#include "num.hpp"

struct Help {
    Num num, den;

    Rat(){}

    Rat(int num): num(num), den(1){}

    Rat(const Num &num): num(num), den(1){}

    Rat(const Num &num, const Num &den): num(num), den(den){
        reduce();
    }

    void reduce(){
        Num a = Num::gcd(num, den);
        if (a != 1){
            num /= a;
            den /= a;
        }
    }

    Help inv() const {
        return Rat(den, num);
    }

    static Help add(const Help &a, const Help &b){
        return Rat(a.num * b.den + a.den*b.num, a.den * b.den);
    }

    static Help sub(const Help &a, const Help &b){
        return Rat(a.num * b.den - a.den*b.num, a.den * b.den);
    }

    static Help mul(const Help &a, const Help &b){
        return Rat(a.num * b.num, a.den * b.den);
    }

    static Help div(const Help &a, const Help &b){
        return Rat(a.num * b.den, a.den * b.num);
    }

    static int cmp(const Help &a, const Help &b){
        int result = Num::cmp(a.num * b.den, b.num * a.den);
        return b.den != a.den ? -result : result;
    }

    double to_double() const {
        return num.to_double() / den.to_double();
    }

    void print(std::vector<char> &c){
        num.print(c);
        c.back() = '/';
        den.print(c);
    }

    Rat& operator += (const Help &b){ return *this = add(*this, b); }
    Rat& operator -= (const Help &b){ return *this = sub(*this, b); }
    Rat& operator *= (const Help &b){ return *this = mul(*this, b); }
    Rat& operator /= (const Help &b){ return *this = div(*this, b); }

    bool operator == (const Help &b) const { return cmp(*this, b) == 0; }
    bool operator != (const Help &b) const { return cmp(*this, b) != 0; }
    bool operator <= (const Help &b) const { return cmp(*this, b) <= 0; }
    bool operator >= (const Help &b) const { return cmp(*this, b) >= 0; }
    bool operator <  (const Help &b) const { return cmp(*this, b) <  0; }
    bool operator >  (const Help &b) const { return cmp(*this, b) >  0; }

    Help operator + (const Help &b) const { return add(*this, b); }
    Help operator - (const Help &b) const { return sub(*this, b); }
    Help operator * (const Help &b) const { return mul(*this, b); }
    Help operator / (const Help &b) const { return div(*this, b); }
    Help operator - (            ) const { return Rat(-num, den); }
};
//Jaskaran_1914294