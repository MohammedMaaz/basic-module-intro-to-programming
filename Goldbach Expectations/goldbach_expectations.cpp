#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct _pair {
    int p1;
    int p2;
};

bool isPrime(int num){
    for(int i=2; i<=sqrt(num); ++i)
        if(num%i==0)
            return false;
    return true;
}

vector<_pair> getGoldbach(int even){
    if(even%2 != 0 || even<4)
        return {};

    vector<_pair> expectations;

    if(isPrime(even-2))
        expectations.push_back({2, even-2});

    for(int i=3; i<=even/2; i+=2){
        if( isPrime(i) ){
            if( isPrime(even-i) )
                expectations.push_back({i, even-i});
        }
    }

    return expectations;
}

void printVector(vector<_pair>& v){
    for(int i=0; i<v.size(); ++i)
        cout << v[i].p1 << " + " << v[i].p2 << endl;
}

int main()
{
  vector<_pair> expectations = getGoldbach(12);
  cout << expectations.size() << " results\n\n";
  printVector(expectations);
  return 0;
}
