#include<iostream>
using namespace std;


int main(){
    int i,num1, num2, den1, den2, sum,den,hcf=1,smaller;
    char by ='/';

    cout<<"Enter the first numerator & denominator: "<<endl;
    cin>> num1>> den1;

    cout<<"Enter the second numerator & denominator: "<<endl;
    cin>> num2>> den2;

    if(den1>0 && den2>0){
        cout<<"The first fraction is "<<num1<<by<<den1<<endl;
        cout<<"The second fraction is "<<num2<<by<<den2<<endl;
        }
    else cout<<"Invalid Fraction Detected"<<endl;

    sum=num1*den2 + num2*den1;
    den=den1*den2;

    if(sum>den)
        smaller=den;
    else
        smaller=sum;

    for(i=1; i<=smaller; i++){
        if(sum%i==0 && den%i==0)
            hcf=i;
    }


    sum=sum/hcf;
    den=den/hcf;

    cout<<"Sum = "<<sum<<by<<den<<endl;


return 0;
}
