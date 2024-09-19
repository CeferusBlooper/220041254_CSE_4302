#include<iostream>
#include<string.h>
using namespace std;

class Medicine
{
private:
    double unit_price=0, discountPercent=5;
    char trade_name[30], gen_name[30];
public:
    void assignName(char name[], char genericName[]){
        strcpy(trade_name,name);
        strcpy(gen_name,genericName);
    }
    void assignPrice(double price){
        if(price>=0)
            unit_price=price;
        else
            cout<<"Invalid Price. Price can not be negative"<<endl;
    }
    void setDiscountPercent(double percent){
        discountPercent=percent;
    }
    double getSellingPrice(int nos){
        double discount= unit_price*(discountPercent/100);
        double selling_price=(unit_price-discount)*nos;
        return selling_price;
    }
    void display(){
        cout<<"MRP. of "<<trade_name<< "is BDT "<<unit_price<<" Current discount "<<discountPercent<<"%."<<endl<<"Selling price BDT" <<getSellingPrice(1)<<"."<<endl;
    }
};
int main(){

}
