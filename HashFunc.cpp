#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

typedef unsigned long long ull;

const unsigned long M = 33554467; // Độ to của bảng
string bucket[M]; //Bảng

uint32_t hashFunc(string&str){
  str.insert(0,100-str.length(),'0');                     //lấp đầy bitstring tới độ dài 100 bằng các số 0 vô nghĩa
  string s1 = str.substr(0,49), s2 = str.substr(50,99);   //chia bitstring thành 2 bitstring độ dài 50
  uint64_t v1 = stoull(s1,0,2), v2 = stoull(s2,0,2);      //đổi bitstring thành một số trong hệ thập phân
  return (v1+v2)%M;                                       //có hash key bằng việc cộng hai số lại với nhau và mod với M để cho vừa bảng băm
}

signed main(){
  //Reading File
  ifstream fin; ofstream fout;
  fin.open("Input/input0.txt"); 
  fout.open("Output/output0.txt");

  //input
  int num, count = 0; fin >> num;
  string s;
  int tc = num;

  while(tc--){
    fin >> s;
    int t = hashFunc(s);                      //Get key
    int check = 0;                            //Check if collision
    while(bucket[t]!="" && bucket[t]!=s){
      t++;                                    //Open Addressing
      check=1;
    }
    if (bucket[t]!="") check=0;
    bucket[t] = s;
    count+=check;                             //Increase if there is collision
  }
  fout << "Amount of collision: " << count << "\nCollision rate: " << setprecision(5) << (float)count*1.0/num;
  fin.close();
  fout.close();
  return 0;
}