#include<iostream>
using namespace std;
//using std::ostream;
//using std::istream;
class large_number{
private:
  string string_a;
  int n;
  int array_large_number[100];
public:
  large_number(){
    int i;
    cout << "Enter your number:\n";
    cin >> string_a;
    cout << "How many numbers have you entered:\n";
    cin >> n;
    if(n>99){
      for (i=99;i<n;i++){
        cout << "in progress...\n";
        array_large_number[i] = *new(int);
      }
    }
    for(i=0;n>i;i++){
      array_large_number[i]=string_a[i];
      cout << "Now in loop i=\t" << i << endl;
    }
  }
  void print_large_number(large_number a){
    int i;
    cout << "Print function in progress";
    cout << string_a;
    for(i=0;a.n<i;i++){
      cout << "Now in loop i=" << i;
      cout << a.array_large_number[i];
    }
  }

  friend large_number operator +(const large_number &b){
    large_number a;
    a.string_a=b.string_a;
    return a;
  }
  //overloading operator =
  //two errors -- reason unknown
  /*friend large_number operator =(const large_number &a,const large_number &b){
    int i;
    for(i=0;i<a.n;i++){
      a.array_large_number[i]=b.array_large_number[i];
    }
  }*/
  //overloading operator +
  large_number operator +(const large_number &b){
    large_number a,sum,temp_sum;
    int c[100];
    int i;
    for(i=0;i<99;i++){
      c[i]=0;
    }
    if(a.n>99 && b.n>99){
      for(i=99; i<a.n || i<b.n ;i++ ){
        c[i]= * new(int);
        c[i]=0;
      }
    }
    for(i=0; i<a.n || i<b.n ;i++ ){
      temp_sum.array_large_number[i]=a.array_large_number[i]+b.array_large_number[i]+c[i];
      if(temp_sum.array_large_number[i]<10){
        sum.array_large_number[i]=temp_sum.array_large_number[i];
      }
        else if(temp_sum.array_large_number[i]>=10){
          sum.array_large_number[i]=temp_sum.array_large_number[i]-10;
          c[i+1]=1;
        }

    }
    if(i==a.n){
      for(i=a.n;i<b.n;i++){
        sum.array_large_number[i]=b.array_large_number[i];
      }
    }
    if(i==b.n){
      for(i=b.n;i<a.n;i++){
        sum.array_large_number[i]=a.array_large_number[i];
      }
    }
  }
  //overloadng operator -
  /*friend large_number operator -(const large_number &b){

  }*/
  //overloading operator << and >> agian with a diferrent method
  friend istream operator >> (istream &in , large_number &entry);
  friend ostream& operator << (ostream &out, large_number &entry);
  // overloading operator << and >>
  // The process is erroneous
    /* istream& operator >> (istream &in, large_number &entry){
      in >> entry;
      return in;
    }

    ostream& operator<< (ostream &out , large_number &entry){
      out << entry;
      int i;
      for(i=0;i<n;i++){
        array_large_number[i]=*new(int);
        out<<array_large_number[i];
      }
      return out;
    } */
};
istream operator >> (istream &in , large_number &entry){
  int i;
  for(i=0;i<entry.n;i++){
    entry.array_large_number[i] = *new(int);
    in << entry.array_large_number[i];
  }
  return in;
}
ostream& operator << (ostream &out, large_number &entry){
  out << entry;
  int i;
  for(i=0;i<entry.n;i++){
    entry.array_large_number[i]=*new(int);
    out << entry.array_large_number[i];
  }
  return out;
}



int main(){
  large_number a;
  return 0;
}
