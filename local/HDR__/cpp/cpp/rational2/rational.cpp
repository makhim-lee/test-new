#include<cassert>
#include"rational.h"

Rational::Rational(){
    this->den = 1;
    this->num = 0;
}

Rational::Rational(int num){
    this->den = 1;
    this->num = num;
}

Rational::Rational(int num, int den){
    assert(den );
    this->den = den;
    this->num = num;
}

Rational::~Rational(){

}

int Rational::getNumber(){
    return this->num;
}



int Rational::getDenominator(){
    return this->den;
}

void Rational::setNumber(int num){
    this->num = num;
}

void Rational::setDen(int den){
    assert(den );
    this->den = den;
}