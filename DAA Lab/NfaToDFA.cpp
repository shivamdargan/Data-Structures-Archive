#include<bits/stdc++.h>
using namespace std;


//FUNCTION TO CALCULATE EPSILON OF A PARTICULAR STATE
vector<int> epsilonClosure(int nfaTable[10][4], int state){
	
	// To Store And Return The E-Closure Of A State
	vector<int> ans;
	
    //Stack To Keep Track Of Future Branches Of E-Closure And Thus Popping Of Those States, Once Explored
	stack<int> st;
	
    //Intially Pusing The Start State Because The State Itself Is Present In Its E-Closure 
	st.push(state);
	ans.push_back(state);
	
	while(!st.empty()){
		
		int top = st.top();
		st.pop();
        //checking if epsilon is read on that particular state or not
		if(nfaTable[top][2] != -1){
			st.push(nfaTable[top][2]);
			ans.push_back(nfaTable[top][2]);
		}
		if(nfaTable[top][3] != -1){
			st.push(nfaTable[top][3]);
			ans.push_back(nfaTable[top][3]);
		}
		
	}
	
	
	return ans;
}


vector<int> computeClosureWithVariables(int nfaTable[10][4], int variableRead, vector<int> stateClosure){

    //Creating A Resultant Vector To Store The States That Are Succesfully Read On The Provided Variable
    vector<int> res;

    for(int i = 0; i < stateClosure.size(); i++){
        
        if(nfaTable[stateClosure[i]][variableRead] != -1){
            res.push_back(nfaTable[stateClosure[i]][variableRead]);
        }
    }

    //2D Vector To Store All The Computed CLosures Of Different States
    vector<vector<int>> computedClosures;

    for(int i = 0; i < res.size(); i++){
        computedClosures.push_back(epsilonClosure(nfaTable, res[i]));
    }

    //Final Answer Vector Which Stores All The Closures After Taking Union
    vector<int> finalAnswer;

    // Inital First Element Of Each Closure Of Each State Stored In The Final Vector
    for(int i = 0; i < computedClosures[0].size(); i++){
        finalAnswer.push_back(computedClosures[0][i]);
    }

    // Taking Union Of All The Closures

    //For Traversing The Number Of Closures (whose union has to be taken) 
    for(int i = 1; i < computedClosures.size(); i++){
        //For Traversing Each Particular Closure's State 
        for(int j = 0; j < computedClosures[i].size(); j++){
            //For Traversing Final Answer Vector And Ensuring No Duplicates In Union
            for(int k = 0; k < finalAnswer.size(); k++){

                if(computedClosures[i][j] != finalAnswer[k]){

                    finalAnswer.push_back(computedClosures[i][j]);
                    break;
                }
            }
        }
    }

    sort(finalAnswer.begin(),finalAnswer.end());
    return finalAnswer;
    
}


// Function To Create The DFA Rsultant DFA Table Using The Above Supporting Functions.
vector<vector<int>> computeSubsetConstruction(int nfaTable[10][4]){
	
    //Computing The Epsilon Closure Of The Start State i.e 0 And Storing It In The Start State Of The DFA
	vector<int> startState = epsilonClosure(nfaTable,0);

    // Stack Vector To Maintain The Branch/Record(Exploring All Combinations) For New 
    // Further States That Are Created By The computeClosureWithVariables Funciton
    stack<vector<int>> st;

    //DFA Table Which Stores All The Data
    vector<pair<vector<int>, pair<vector<int>, vector<int>>>> dfa;


    sort(startState.begin(), startState.end());
    // Stack To Mantain The New And Old DFA States Being Generated
    st.push(startState);
    //Resulant 2D Vector To Store Unique And Distinct States For DFA
    vector<vector<int>> states;
    states.push_back(startState);
    

    while(!st.empty()){
        vector<int> temp = st.top();
        //Once An Old State's Combinations Are Explored With Different Variables Such as a or b, then that state is popped off stack
        st.pop();
        vector<int> tempWithA = computeClosureWithVariables(nfaTable, 0, temp);
        vector<int> tempWithB = computeClosureWithVariables(nfaTable, 1, temp);
        // Boolean Variables Which Are Used Later As A Flag To Check Whether The New States That Are Computed Are Unique Or Already Existing/Previous States
        bool duplicateWithA = false;
        bool duplicateWithB = false;

        dfa.push_back(make_pair(temp, make_pair(tempWithA, tempWithB)));


        for(int i = 0; i < states.size(); i++){

            if(tempWithA == states[i]){
                duplicateWithA = true;
                break;
            }
        }
        for(int i = 0; i < states.size(); i++){

            if(tempWithB == states[i]){
                duplicateWithB = true;
                break;
            }
        }
        if(duplicateWithA == false){
            st.push(tempWithA);
            states.push_back(tempWithA);
        }
        if(duplicateWithB == false){
            st.push(tempWithB);
            states.push_back(tempWithB);
        }
        
    }

    //DISPLAYING THE DFA
    cout<<"State \t\t"<<"Variable a\t\t"<<"Variable b"<<endl;
    for(int i = 0; i < dfa.size(); i++){

        for(int j = 0; j < dfa[i].first.size(); j++){

            cout<<dfa[i].first[j]<<" ";
        }
        cout<<"     ";

        for(int k = 0; k < dfa[i].second.first.size(); k++){

            cout<<dfa[i].second.first[k]<<" ";
        }
        cout<<"     ";

        for(int l = 0; l < dfa[i].second.second.size(); l++){

            cout<<dfa[i].second.second[l]<<" ";
        }
        cout<<endl;
    }
	
	
}


int main(){
	
	int nfaTable[10][4];
	
	for (int i = 0; i < 10; i++)
  		for (int j = 0; j < 4; j++)
    		nfaTable[i][j] = -1;
	
    //HERE SECOND INDEX POINTS TO THE VARIABLE OR THE VALUE i.e
    // 0 -> a
    // 1 -> b 
    // 2 -> epsilon 1
    // 3 -> epsilon 2

    // FIRST INDEX POINTS TO THE STATE 

    //EPSILON MOVES
	nfaTable[0][2] = 1;
	nfaTable[0][3] = 7;
	nfaTable[1][2] = 2;
	nfaTable[1][3] = 4;
	nfaTable[3][2] = 6;
	nfaTable[5][2] = 6;
	nfaTable[6][2] = 7;
	nfaTable[6][3] = 1;
    
    //VALID a variable or b variable moves
    nfaTable[2][0] = 3;
    nfaTable[4][1] = 5;
    nfaTable[7][0] = 8;
    nfaTable[8][1] = 9;


    computeSubsetConstruction(nfaTable);
	
	
	return 0;
}