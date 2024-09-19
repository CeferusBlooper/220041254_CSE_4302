#include<iostream>
using namespace std;

class RationalNumber
{
private:
    int num, den;

public:
    void assign(int numerator,int denominator){
        if(denominator==0)
            cout<<"You can not assign 0 as denominator"<<endl;
        else{
            num= numerator;
            den= denominator;
        }
    }

    double convert(){
        double dec;
        dec = num/den;
        return dec;
    }

    void invert(){
        if(num==0){
            cout<<"You can not assign 0 as denominator"<<endl<<"Inversion Failed";
        }
        else
            swap(num,den);
    }
    void print(){
        if (den!=0){
            cout<<"The Rational Number is "<<num<<"/"<<den<<endl;
        }
    }

};
int main(){
    RationalNumber RN;
    double num,denom,result;
    cin>>num;
    cin>>denom;
    RN.assign(num,denom);
    cout<<RN.convert()<<endl;
    RN.invert();
    cout<<RN.convert()<<endl;
    RN.print();
    return 0;


}
