#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>

using namespace std;

template<class T> string vector_to_string(vector<T> x) {
    ostringstream sout;
    sout<<"[";
    for( int i = 0 ; i < x.size(); i ++ ){
        if( i > 0 )
            sout << ", ";
        sout << x[i];
    }
    sout<<"]";
    return sout.str();
}
vector<int> initial_vector( const int n ){
    vector<int> answer;
    for( int i = 0; i < n; i ++ )
        answer.push_back(i);
    return answer;
}
long long factorial( const int n ){
    long long answer = 1;
    for( long long i = 2; i <= n; i ++ )
        answer *= i;
    return answer; 
}
bool permute(vector<int>& element){
  int i = element.size() - 1;
  while (i > 0 && element[i - 1] >= element[i]) {
    i--;
  }
  if (i <= 0) {
    return false;
  }
  int j = element.size() - 1;
  while (element[j] <= element[i - 1]) {
    j--;
  }
  int temp = element[i - 1];
  element[i - 1] = element[j];
  element[j] = temp;
  j = element.size() - 1;
  while (i < j) {
    temp = element[i];
    element[i++] = element[j];
    element[j--] = temp;
  }
  return true;
};

int main()
{
    const int MAX = 10;
    for ( int n = 1; n <= MAX; n ++ ){
        vector<int> elements = initial_vector(n);
        set<string> all_permutations; 
        clock_t begin_time = clock();
        bool ok = true;
        do {
            all_permutations.insert(vector_to_string(elements));
            for( int i = 0;i < n; i ++ )
                ok = ok && 0 <= elements[i] && elements[i] < n;            
        }while(next_permutation(elements.begin(),elements.end()));
        if( ! ok || all_permutations.size() != factorial(n) ){
            cerr << "\n\nSome big error occur\n\n" << endl;
            break;
        }
        cout << n << "("<<all_permutations.size()<<"=?="<<factorial(n)<<")\t" << (double(clock() - begin_time) / CLOCKS_PER_SEC) << " seconds " << endl;
    }          
    return 0;
}