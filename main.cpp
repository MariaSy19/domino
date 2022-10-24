#include<bits/stdc++.h>
#include<vector>

using namespace std;

struct domino {

    int leftdots;
    int rightdots;

};


vector<domino> print;
vector<domino> print2;


bool extend(int lastdots,vector<domino> & dominos ){
    if(dominos.empty()){return true;}
    else{
        for (int i=0;i<dominos.size();i++){
            domino next=dominos[i];
            vector<domino> rest=dominos;
            rest.erase(rest.begin()+i);

            //rest.removeAt(i);
            if(lastdots==-1 || lastdots==next.leftdots){
                print.push_back(next);
                if (extend(next.rightdots,rest)){return true;}
            }
            if(lastdots==-1||lastdots==next.rightdots){
                print.push_back(next);
                if (extend(next.leftdots,rest)){return true;}
            }

        }
        return false;
    }
}

bool chain(vector<domino> & dominos){
    /// (1 | 4) (2 | 6) (4 | 4) (6 | 1) (4 | 3)

//for (int i=0;i<dominos.size();i++){}
    return extend(-1,dominos);

}





int main()
{

int obj1[5],obj2[5];
//domino obj;
//obj.leftdots=2;
//obj.rightdots=5;
    for (int i = 0; i < 5 ; ++i)
    {
        cout << "Input the numbers  : "<<endl;
        cin >> obj1[i] >> obj2[i];
    }
    vector<domino> vec;
    vec.push_back(domino()); /// push back in the vector element of the struct

    vec[0].leftdots=obj1[0];
    vec[0].rightdots=obj2[0];

    vec.push_back(domino()); /// push back in the vector element of the struct
    vec[1].leftdots=obj1[1];
    vec[1].rightdots=obj2[1];

    vec.push_back(domino()); /// push back in the vector element of the struct
    vec[2].leftdots=obj1[2];
    vec[2].rightdots=obj2[2];

    vec.push_back(domino()); /// push back in the vector element of the struct
    vec[3].leftdots=obj1[3];
    vec[3].rightdots=obj2[3];

    vec.push_back(domino()); /// push back in the vector element of the struct

    vec[4].leftdots=obj1[4];
    vec[4].rightdots=obj2[4];


    cout<<chain(vec);
    cout<<endl;
    for(int i=print.size()-vec.size();i<print.size();i++){
        cout<<print[i].leftdots<<"|"<<print[i].rightdots<<" ";

    }
    cout<<endl;


//cout<<vec.size()<<endl;

/// print=12   vec=5 12-5=7


    for(int i=print2.size()-vec.size();i<print2.size();i++){
        cout<<print2[i].leftdots<<"|"<<print2[i].rightdots<<" ";

    }
    cout<<endl;

    return 0;

}
