#include <iostream>
#include <map>

using namespace std;

int main(int argc, char ** argv){

    // Default constuctor.
    map<string, int> m;
    
    // Add elements.
    m["Alan"] = 18;
    m["Bob"] = 20;

    // Iterate though a map
    for(map<string,int>::iterator it=m.begin(); it!=m.end(); it++){
        cout<<"{"<<it->first<<","<<it->second<<"}"<<",";
    }
    cout<<endl;

    // Iterate though a map with auto iterator.
    for(auto it=m.begin(); it!=m.end(); it++){
        cout<<"{"<<it->first<<","<<it->second<<"}"<<",";
    }
    cout<<endl;

    // Iterate through a map with range-based for loop.
    for(auto p:m){cout<<"{"<<p.first<<","<<p.second<<"}"<<",";}

    // Access an element with key
    cout<<m["Alan"]<<endl;

    // Check if a element with specific key word exist.
    auto it = m.find("Bob");
    cout<<it->first<<","<<it->second<<endl;
    it = m.find("Cliton");
    cout<<it->first<<","<<it->second<<endl;

    // Access an unexist element with key. Give 0
    // The unexist element will be automatically inserted to the map.
    cout<<m["Clinton"]<<endl;
    for(auto p:m){cout<<"{"<<p.first<<","<<p.second<<"}"<<",";}
    cout<<endl;

    std::map<int, std::string> c = {{1, "one"}, {2, "two"}, {3, "three"},
                                    {4, "four"}, {5, "five"}, {6, "six"}};
 
    // Erase some elements from the map
    // Different from vector, after erasing one object, the iterator will not be
    // assigned to next element automatically, you should use return value of 
    // erase() to mannually reassign it.
    for(auto it = c.begin(); it != c.end(); ) {
        if(it->first % 2 == 1)
            it = c.erase(it);   // Very important
        else
            ++it;
    }
 
    for(auto& p : c) {
        std::cout << p.second << ' ';
    }

}