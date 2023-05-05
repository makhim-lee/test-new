

inline int Rational::getNumber()const{
    return m_num;
}

inline int Rational::getDenominator()const{
    return m_den;
}

inline void Rational::setNumber(int num){
    m_num = num;
}

inline void Rational::setDen(int den){
    assert(den );
    m_den = den;
}
