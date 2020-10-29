#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>    // std::for_each

using namespace std;

int main(int argc, char **argv) {

    // Initialization 
    vector<int> x = {1, 2, 3, 5, 7};

    // Iterate through a vector with[] operator
    for(int i=0; i<x.size(); i++){cout<<x[i]<<",";} cout<<endl;

    // Iterate through a vector with at() function.
    for(int i=0; i<x.size(); i++){cout<<x.at(i)<<",";} cout<<endl;

    // Iterate through a vector with range-based for loop.
    for(int e : x){cout<<e<<",";} cout<<endl;

    // Iterate through a vector with iterator
    for(vector<int>::iterator it=x.begin(); it != x.end(); it++){ cout<<*it<<",";}
    cout<<endl;

    // Iterate through a vector with auto iterator.
    for(auto it=x.begin(); it != x.end(); it++){cout<<*it<<",";} cout<<endl;

    // Iterate through a vector with for_each()
    std::for_each(x.begin(), x.end(), [](int n){cout<<n<<",";}); cout<<endl;

    // Wrong example!
    // Use iterator with "<" operator.
    // OK for vector (GCC7.5), but not for any container.
    // for(auto it=x.begin(); it<x.end(); it++){cout<<*it<<",";} cout<<endl;

    // Wrong example!
    // Access end() or rend()
    // May no error in compilation, but gives unexpected result!
    // cout<<*(x.end())<<","<<*x.rend()<<endl;

    // Iterate thouth a vector backwards with reversed iterator.
    for(vector<int>::reverse_iterator it=x.rbegin(); it!=x.rend(); it++){
        cout<<*it<<",";
    }
    cout<<endl;

    // Iterate through a vector backwards with auto revserd iterator.
    for(auto it=x.rbegin(); it!=x.rend(); it++){cout<<*it<<",";} cout<<endl;

    // Check if the vector is empty.
    cout<<x.empty()<<endl;

    // Get the size and capacity of a vector.
    cout<<x.size()<<","<<x.capacity()<<endl;

    // Push new element to the back.
    x.push_back(11);
    for(int e : x){cout<<e<<",";} cout<<endl;

    // Pop element at the back.
    x.pop_back();
    for(int e : x){cout<<e<<",";} cout<<endl;

    // Erase an element with iterator.
    x.erase(x.begin()+1);
    for(auto e:x){cout<<e<<",";} cout<<endl;

    // Clear a vector
    x.clear();
    cout<<x.size()<<","<<endl;

    // Reassignment with specific number of same elements.
    x = vector<int>(3,6);   // Gives {6,6,6}
    for(auto e:x){cout<<e<<",";} cout<<endl;

    // Reassignment
    x = {1,3,5,7,11};
    for(auto e:x){cout<<e<<",";} cout<<endl;


}