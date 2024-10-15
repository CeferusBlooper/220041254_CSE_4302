#include<iostream>
#include<string>
#include<vector>
#include"random.h"
using namespace std;

class Student{
private:
    string Name;
    string Department;
    string Program;
    string Section;
    string Address;

    int admissionYear;
    int GPA;
    int ID;

public:
    Student(){
        Name=getName();
        Department=getDept();
        Program=getProg();
        Section=getSect();
        Address=getAddress();
        GPA=0;
        ID=getID();

    }
    string getName(){
        return Name;
    }
    void setName(string name){
        Name=name;
    }
    string getDept(){
        return Department;
    }
    void setDept(string dept){
        Department=dept;
    }
    string getProg(){
        return Program;
    }
    void setProg(string prog){
        Program=prog;
    }
    string getSect(){
        return Section;
    }
    void setSect(string sec){
        Section=sec;
    }
    string getAddress(){
        return Address;
    }
    void setAddress(string addr){
        Address = addr;
    }
    int getYear(){
        return admissionYear;
    }
    void setYear(int year){
        admissionYear=year;
    }
    int getGPA(){
        return GPA;
    }
    void setGPA(int gpa){
        if(GPA<0 or GPA>4){
            cout<<"This entry is invalid"<<endl;
        }
        GPA=gpa;
    }
    int getID(){
        return ID;
    }

    double calculateGPA(vector<double>& marks){
        float sum=0;
        int n=marks.size();
        for(int i=0; i<n;i++){
            sum+=marks[i];
        }
        double avg= sum*(4/100);
        return avg;
    }
};
 void EditInformationByKeyboard(Student &student){
    string name,dept,prog,sec,addr;
    int year,gpa;
    cout<<"Name: ";
    cin>>name;
    cout<<"Department: ";
    cin>>dept;
    cout<<"Program: ";
    cin>>prog;
    cout<<"Section: ";
    cin>>sec;
    cout<<"Admission Year: ";
    cin>>year;
    cout<<"Address: ";
    getline(cin,addr);
    cout<<"GPA: ";
    cin>>gpa;

    student.setName(name);
    student.setDept(dept);
    student.setProg(prog);
    student.setSect(sec);
    student.setAddress(addr);
    student.setYear(year);
    student.setGPA(gpa);
 }
 void generateInformaiotnRandom(Student &student){
     int firstNameLen = randomInRange(4,10);
     int lastNameLen = randomInRange(4,10);
     string firstName = generateRandomString(firstNameLen);
     string lastName = generateRandomString(lastNameLen);
     string name=firstName+" "+lastName;
     student.setName(name);

     int year= randomInRange(2020,2023);
     student.setYear(year);
     string addr="";
     for(int x=0; x<5; x++){
        string addr = generateRandomString(randomInRange(4,10));
        addr+= addr + " ";
     }
     addr.pop_back();
     student.setAddress(addr);

 }
int genID(){
    int ID = 220041000 + randomInRange(101,270);
    return ID;
}
void ShowAllAlphabetically(Student ar[]){
    for(int i=0;i<99;i++){
        for(int j=i+1;j<100;j++){
            if(ar[i].getID() > ar[j].getID()){
                swap(ar[i],ar[j]);
            }
        }
    }
    for(int i=0; i<100;i++){
        cout<<"Name: "<<ar[i].getName()<<" "<<"ID: "<<ar[i].getID()<<" "<<"GPA: "<<ar[i].getGPA()<<endl;
    }

}
int main(){
    Student arr[100];
    for(int i=0; i<100;i++){
        generateInformaiotnRandom(arr[i]);
    }
     ShowAllAlphabetically(arr);
}

