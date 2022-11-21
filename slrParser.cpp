#include <bits/stdc++.h>

using namespace std;


struct Prod{
	
	string lhs;
	string rhs;
	
};



vector<Prod> goto(vector<Prod> prodItem, int index){
	
	size_t temp = prodItem[index].rhs.find('.');
	
	char found = prodItem[index].rhs[temp+1];
	
	swap(prodItem[index].rhs[temp], prodItem[index].rhs[temp+1]);
	
	if(found >= 'A' && found <= 'Z'){
		//Closure()
	}
	for(int i = index+1 ; i < prodItem.size(); i++){
		
		size_t temp = prodItem[i].rhs.find('.');
		
		
		if(prodItem[i].rhs[temp+1] == found){
			swap(prodItem[i].rhs[temp], prodItem[i].rhs[temp+1]);
		}
	}
}




int main(){
	
	int n = 0;
	cin>>n;
	
	Prod prodList[n];
	for(int i = 0; i < n; i++){
		
		cin>>prodList[i].lhs>>prodList[i].rhs;
	}
	
	
	
	
	return 0;
}