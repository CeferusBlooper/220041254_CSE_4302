#include<iostream>
using namespace std;

class Counter
{
private:
    int count=0;
    int increment;
public:
    void setIncrementStep(int step){
        increment= step;
    }
    int getCount(){
       return count;

    }
    void Increment(){
        count = count + increment;
    }
    void resetCount(){
        count=0;
    }
};
int main(){
    Counter counter;
    int step,c;
    cin>>step;
    counter.setIncrementStep(step);
    cout<<counter.getCount()<<endl;
    counter.Increment();
    cout<<counter.getCount()<<endl;
    counter.resetCount();
    cout<<counter.getCount()<<endl;

    return 0;

}
