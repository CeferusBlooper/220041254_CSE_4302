#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Employee{
private:
    string EmpName;
    int memId;
    int age;
    double salary;
    string getStatus(){
        string status;
        if(age>=25){
            if(salary<=20000)
                status="Low";
            else
                status="High";
        }
        else{
            if(salary<=21000)
                status="Low";
            else if(salary>21000 and salary<=60000)
                status="Moderate";
            else
                status="High";
        }

    }
public:
    Employee(string name,int id,int Age,double sal, string stat){
    EmpName=name;
    memId=id;
    age=Age;
    salary=sal;
    status=stat;
    }
};

