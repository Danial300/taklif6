#include <iostream>
using namespace std;
class kasr
{
    int numerator;
    int Denominator;
public:
    kasr(int s=1, int m=1){setkasr(s,m);}
    void setkasr(int s, int m){setnum(s); setden(m);}
    void setnum(int i){numerator=i;}
    void setden(int i){Denominator=(i!=0)?i:1;}
    int getnum()const{return numerator;}
    int getden()const{return Denominator;}
    kasr operator+(kasr obj)
    {
        kasr temp;
        temp.numerator=(numerator*obj.Denominator)+(obj.numerator*Denominator);
        temp.Denominator=Denominator*obj.Denominator;
        return temp;
    }
    kasr operator-(kasr obj)
    {
        kasr temp;
        temp.numerator=(numerator*obj.Denominator)-(obj.numerator*Denominator);
        temp.Denominator=Denominator*obj.Denominator;
        return temp;
    }
    kasr operator/(kasr obj)
    {
        kasr temp;
        temp.numerator=numerator*obj.Denominator;
        temp.Denominator=obj.numerator*Denominator;
        return temp;
    }
    friend ostream &operator<<( ostream &output, const kasr &k );
    friend istream &operator>>( istream  &input, kasr &k );
};
ostream &operator<<( ostream &output, const kasr &k )
{
    output<< k.numerator << "/" << k.Denominator;
    return output;
}
istream &operator>>( istream  &input, kasr &k )
{
    input >> k.numerator >> k.Denominator;
    return input;
}
int main()
{
    kasr k1(3,5),k2(2,7),k3;

    cout << "kasr? " << endl;
    cin >> k3;

    cout << "k1: " << k1 << endl;
    cout << "k2:" << k2 << endl;
    cout << "k3:" << k3 << endl;

    k3= k1+k2;
    cout << "k3:" << k3 << endl;

    k3= k1-k2;
    cout << "k3:" << k3 << endl;

    k3= k1/k2;
    cout << "k3:" << k3 << endl;
    return 0;
}
