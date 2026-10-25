#include<iostream>
#include<chrono>
#include<queue>
#include<stack>
using namespace std;
using namespace chrono;
template<class T>
class Mystack
{
  private:
   T data[10000];
   int top;
  public:
   Mystack()
   {
    top=-1;
   }
   void push(T value){
    if (top<9999)
     data[++top]=value;
   }
   void pop()
   {
    if(top>=0)
    top--;
   }
};
template <class T>
class Myqueue
{
  private:
  T data[10000];
  int front,rear;
  public:
    Myqueue()
   {
    front=0;
    rear=-1;
   }
   void enqueue(T value)
   {
    if(rear<9999)
     data[++rear]=value;
   }
   void dequeue()
   {
    if (front<=rear)
    front ++;
   }
};
int main()
{
  const int N=10000;
  //custom stack benchmark
  auto start=high_resolution_clock::now();
  Mystack<int>mystack;
  for(int i=0;i<N;i++)
   mystack.push(i);
  for(int i=0;i<N;i++)
   mystack.pop();
  auto end=high_resolution_clock::now();
  auto customStackTime=duration_cast<microseconds>(end-start);
  //STL stack benchmark
  start=high_resolution_clock::now();
  stack<int>stlstack;
  for(int i=0;i<N;i++)
   stlstack.push(i);
  for(int i=0;i<N;i++)
   stlstack.pop();
  end=high_resolution_clock::now();
  auto stlStackTime=duration_cast<microseconds>(end-start);
  //Custom queue benchmark
  start=high_resolution_clock::now();
  Myqueue<int>myqueue;
  for(int i=0;i<N;i++)
   myqueue.enqueue(i);
  for(int i=0;i<N;i++)
   myqueue.dequeue();
   end=high_resolution_clock::now();
   auto customqueueTime=duration_cast<microseconds>(end-start);
   //STL queue benchmark
   start=high_resolution_clock::now();
   queue<int>stlqueue;
   for(int i=0;i<N;i++)
    stlqueue.push(i);
   for(int i=0;i<N;i++)
    stlqueue.pop();
   end=high_resolution_clock::now();
   auto stlqueueTime=duration_cast<microseconds>(end-start);
   cout<<"Custom stack Time:"
       <<customStackTime.count()<<"microseconds"<<endl;
   cout<<"STL Stack Time:"
       <<stlStackTime.count()<<"microseconds"<<endl;
    cout<<"custom queue Time:"
       <<customqueueTime.count()<<"microseconds"<<endl;
    cout<<"STL queue Time:"
       <<stlqueueTime.count()<<"microseconds"<<endl;
    return 0;
   
}