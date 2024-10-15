#include<iostream>
#include<math.h>
using namespace std;

class Calculator{
private:
    double angle;
    double get(){
        return angle;
    }
    void set(double ang){
        angle = ang;
    }
public:
    Calculator(){
        angle=0;
    }
    Calculator(double _ang){
        angle= _ang;
    }
    double angleToRad(double ang){
        return ang*(3.1416/180);
    }
    double calculateSine(){
        double ang=get();
        double rad = angleToRad(ang);
        return sin(rad);
    }
    double calculateCosine(){
        double ang=get();
        double rad = angleToRad(ang);
        return cos(rad);
    }
    double calculateTangent(){
        double ang=get();
        if(ang == 90 || ang == 270){
            cout<<"Warning! Tangent is undefined"<<endl;
            return INT_MAX;
        }
        else {
            double rad = angleToRad(ang);
            return tan(rad);
        }
    }
    double calculateArcSine(){
        double ang=get();
        cout<<angleToRad(ang)<<endl;
        return asin(sin(ang));
    }
    double calculateArcCosine(){
        double ang=get();
        return acos(cos(ang));
    }
    float calculateArcTangent(){
        double ang=get();
        return atan(tan(ang));
    }
    void calculateForAngle(double paramAngle){
        set(paramAngle);
        cout<<"Displaying Sine: "<<calculateSine()<<endl;
        cout<<"Displaying Cosine: "<<calculateCosine()<<endl;
        cout<<"Displaying Tangent: "<<calculateTangent()<<endl;
    }
    void clear(){
        set(0.0);
    }
    void display(){
        cout<<"Calculator display: "<<get()<<endl;
    }
    ~Calculator(){
     display();
     cout<<"Destructor of the Calculator object is called."<<endl;
    }

};

int main(){
Calculator c1, c2 (45);
    cout << "Sin " << c2.calculateSine () << endl;
    cout << "Cos " << c2.calculateCosine () << endl;
    cout << "Tan " << c2.calculateTangent () << endl;
    cout << "Arcsin " << c2.calculateArcSine () << endl;
    cout << "Arccos " << c2.calculateArcCosine () << endl;
    cout << "Arctan " << c2.calculateArcTangent () << endl;
}
