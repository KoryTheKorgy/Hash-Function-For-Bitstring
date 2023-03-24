#include <iostream>
#include <fstream>
#include <random>

using namespace std;
const int maxTC = 1e7; //amount of bit string
const int maxLen = 100; //bit string length;

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);

    std::ofstream fout;
    fout.open("../Input/input0.txt");
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_int_distribution<int> dist(0,1);
    std::uniform_int_distribution<int> testcase(1,maxTC);
    std::uniform_int_distribution<int> length(1,maxLen);
    // int tc = testcase(e2); 
    int tc = maxTC;
    fout << tc << "\n";
    unsigned long long maxL = 0;
    while(tc--){
        string s="";
        int len = length(e2);
        for (int i = 0; i < len; i++) s+=char('0'+dist(e2));
        maxL = max(maxL,s.length());
        fout << s << "\n";
    }
    fout.close();
    return 0;
}