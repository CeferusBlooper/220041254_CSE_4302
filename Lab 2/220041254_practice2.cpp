#include<iostream>
using namespace std;


enum etype{laborer, secretary, manager, accountant, executive,
researcher};

int main(){
    etype employee;
    char ch;
    cin>>ch;

    switch(ch){
    case'l': employee=laborer;
    break;
    case's': employee=secretary;
    break;
    case'm': employee=manager;
    break;
    case'a': employee=accountant;
    break;
    case'e': employee=executive;
    break;
    case'r': employee=researcher;
    break;
    default:
    cout<<"INVALID!"<<endl;

    }
    switch(employee){
    case 0: cout<<"Employee type is Laborer"<<endl;
    break;
    case 1: cout<<"Employee type is secretary"<<endl;
    break;
    case 2: cout<<"Employee type is manager"<<endl;
    break;
    case 3: cout<<"Employee type is accountant"<<endl;
    break;
    case 4: cout<<"Employee type is executive"<<endl;
    break;
    case 5: cout<<"Employee type is researcher"<<endl;
    break;

    }

return 0;


}
