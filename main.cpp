#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <map>

using std::cout, std::endl, std::vector, std::map;

int solution(vector<int> &A)
{
    map<int,int> Frequency;
    auto n=A.size()+1;
    vector<bool> equal(n, false);
//___________________________________________________________________________
//Mapping values with its frequencies
    for (auto i=0; i<n; i++)
    {
        int count {};
        for(auto j=0; j<n; j++)
        {

            if (A[j]==A[i])
            {
                ++count;
            }
        }
        Frequency.insert({A[i],count});
    }
//___________________________________________________________________________
//see values and its frequencies
//    for (auto el=Frequency.begin(); el!=Frequency.end(); ++el)
//    {
//        cout<<el->first<<'\t'<<el->second<<'\n';
//    }
//___________________________________________________________________________
    for (auto el=Frequency.begin(); el!=Frequency.end(); ++el)
    {
        if(el->first==el->second)
        {
            //see values who have equal frequency
            //cout<<"Jest rowny = "<<el->first<<"\t"<<el->second<<endl;
            equal[el->second]=true;
        }
    }
//___________________________________________________________________________
//see which positions have equal number to frequency
//    for(auto z: equal)
//    {
//        cout<<z<<endl;
//    }
//___________________________________________________________________________
//find maximum pair of value matched with frequency
    int max{};
    for(int p{}; p<equal.size(); p++)
    {

        if(equal[p]==true & p>max)
        {
            max=p;
        }
        else
        {
            continue;
        }
    }
    cout<<max;
//___________________________________________________________________________
    return 0;
};

void displaySolution(vector<int> A)
{

    for(auto a: A)
        cout<<a<<" ";
    cout<<endl;
    solution(A);
    cout<<endl;
}

int main() {
    vector<int> v1 {3,8,2,3,3,2};
    vector<int> v2 {7,1,2,8,2};
    vector<int> v3 {3,1,4,1,5};
    vector<int> v4 {5,5,5,5,5};
    //std::ranges::sort(v);
    cout<<"Solution for vector 1 =  ";
    displaySolution(v1);
    cout<<"Solution for vector 2 =  ";
    displaySolution(v2);
    cout<<"Solution for vector 3 =  ";
    displaySolution(v3);
    cout<<"Solution for vector 4 =  ";
    displaySolution(v4);
    return 0;
}
