// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
    map<int, multiset<string>> marks_map;
    cin>>N;
    string name;
    int marks;
    while(N!=0)
    {
        N--;
        cin>>name;
        cin>>marks;
        marks_map[marks].insert(name);
    }
    auto it = --marks_map.end();
    while(true){
        int marks_students = it->first;
        auto &students = it->second;
        for(auto &names_set:students)
        {
            cout<<names_set<<" "<<marks_students<<endl;
        }
        if(it == marks_map.begin()) {
            break;
        }
        else
        {
            it--;
        }
    }
    return 0;
}
