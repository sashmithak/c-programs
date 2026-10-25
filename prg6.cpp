#include<iostream>
#include<memory>
using namespace std;
class Resource
{
  public:
   Resource()
    {
      cout<<"Resource aquired"<<endl;
    }
    ~Resource()
    {
      cout<<"Resource released"<<endl;
    }
   void use()
   {
    cout<<"Resource is being used"<<endl;
   }
};
class Mysmartpointer
{
  private:
  Resource*ptr;
  public:
  Mysmartpointer(Resource*p)
  {ptr=p;}
  ~Mysmartpointer()
  {
    delete ptr;
    cout<<"Manual smart pointer destroyed"<<endl;}
    Resource*operator->()
    {
      return ptr;
    }
    //Disable copying to avoid double deletion
    Mysmartpointer(const Mysmartpointer&)=delete;
  };
int main(){
  cout<<"----Manual RAII smart pointer----"<<endl;
 { Mysmartpointer smartptr(new Resource());
  smartptr->use();
}
cout<<"\n----unique_ptr----"<<endl;
{
  unique_ptr<Resource>uniqueptr=make_unique<Resource>();
  uniqueptr->use();
}
cout<<"\n----shared_ptr----"<<endl;
{
  shared_ptr<Resource>sharedptr1=make_shared<Resource>();
  shared_ptr<Resource>sharedtr2=sharedptr1;
  sharedptr1->use();
  cout<<"shared pointer count:"
      <<sharedptr1.use_count()<<endl;
}
cout<<"\nprogram completed successfully."<<endl;
return 0;
}