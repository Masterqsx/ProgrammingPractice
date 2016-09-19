#include<iostream>
#include<string>
#include<exception>
using namespace std;

void isolation();
template<typename T>
class RingBuffer{
  private:
    T* array;
    int length;
    int real_length;
    int head;
    int tail;
  public:
    RingBuffer():array(NULL),length(0),real_length(0),head(0),tail(0){}
    
    RingBuffer(int input_length):length(input_length),real_length(0),head(0),tail(0){
      array=new T[length];
    }
    
    void push_back(T input){
      array[tail]=input;
      tail=(++tail)%length;
      if(real_length<=(length-1)){
        real_length++;
      }
      else{
        head=tail;
      }
    }

    T pop_front(){
      if(real_length==0){
        cout<<"empty"<<endl;
        throw exception();
      }
      T buf=array[head];
      head=(++head)%length;
      real_length--;
      return buf;
    }

    ~RingBuffer(){
      delete []array;
    }

    void call(){
      cout<<"Full size "<<length<<endl;
      cout<<"Real size "<<real_length<<endl;
      cout<<"Head index "<<head<<endl;
      cout<<"Tail index "<<tail<<endl;
      isolation();
    }

    
};

void isolation(){
  cout<<"============================"<<endl;
}

int main(){
  cout<<"RingBuffer Realization"<<endl;
  isolation();
  RingBuffer<string>* NewBuffer=new RingBuffer<string>(3);
  NewBuffer->call();
  NewBuffer->push_back("a");
  NewBuffer->call();
  NewBuffer->push_back("b");
  NewBuffer->call();
  NewBuffer->push_back("c");
  NewBuffer->call();
 // NewBuffer->push_back(4);
 // NewBuffer->call();
  try{
    cout<<NewBuffer->pop_front()<<endl;
    NewBuffer->call();
    cout<<NewBuffer->pop_front()<<endl;
    NewBuffer->call();
    cout<<NewBuffer->pop_front()<<endl;
    NewBuffer->call();
    cout<<NewBuffer->pop_front()<<endl;
    NewBuffer->call();
  }
  catch(exception &e){
    cout<<"empty exception"<<endl;
  }
  delete NewBuffer;
  return 0;
}
