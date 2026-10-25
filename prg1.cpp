#include <iostream>
#include<string>
using namespace std;
class student{
  private:
   int rollno;
   string name;
  public:
   student(int r,string n)
   {
    rollno=r;
    name=n;
    cout<<"Student object created"<<endl;
   }
   void display()
   {
    cout<<"Roll Number:"<<rollno<<endl;
    cout<<"Name:"<<name<<endl;
   }
   ~student(){
    cout<<"student object destroyed"<<endl;
   }

};
int main()
  {
    student s1(53,"Sashmitha");
    s1.display();
    return 0;

  }
