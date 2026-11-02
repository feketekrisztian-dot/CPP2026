#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <random>
using namespace std;
void kiirDinVektro(vector<int> din)
{
    for_each(din.begin(), din.end(), [](const int& x)
        {
            cout<<x<<" ";
        });
    cout<<endl;
}
void kiirPairVector(vector<pair<int, string>> a)
{
    for_each(a.begin(), a.end(), [](const pair<int, string>& x)
    {
       cout<<x.first<<","<<x.second<<" ";
    });
    cout<<endl;
}
void kiirDinVektroFloat(vector<float> din)
{
    for_each(din.begin(), din.end(), [](const float& x)
        {
            cout<<x<<" ";
        });
    cout<<endl;
}


int main()
{
    vector<string> fruits {"melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"};
    auto it = find_if(fruits.begin(), fruits.end(), [](const string& str)
    {
       return str.contains("berry");
    });
    if (it != fruits.end())
        cout<<"Van"<<endl;
    else cout<<"Nincs"<<endl;

    vector<int> din = {3,2,4,246,34,524,24,2,24};
    if (all_of(din.begin(), din.end(), [](const int& x){
        return (x+1)%2;
    }))
        cout<<"Minden"<<endl;
    else cout<<"Nem minden"<<endl;

    cout<<"3. Elotte"<<endl;
    kiirDinVektro(din);

    for_each(din.begin(), din.end(), [](int& x)
    {
        x*=2;
    });
    cout<<"Utanna"<<endl;
    kiirDinVektro(din);

    vector<string> months {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
       };
    int db=0;
    for_each(months.begin(), months.end(), [&db](const string& x)
    {
        if (x.size() == 5)db++;
    });
    cout<<endl<<"4. : "<<db<<endl;

    sort(din.begin(), din.end(), [](const int& x, const int& y)
    {
        return x>y;
    });
    cout<<"5.fel elso fele:"<<endl;
    kiirDinVektro(din);

    sort(din.begin(), din.end(), std::greater<int>());
    cout<<"5.fel Masodik fele:"<<endl;
    kiirDinVektro(din);

    vector<pair<int, string>> honapok = {{7, "Januar"},
                                        {10,"Februar"},
                                        {145,"Mar"},
                                        {14,"Apr"},
                                        {3,"Maj"},
                                        {20,"Jun"},
                                        {1,"Jul"},
                                        {754,"Aug"}
    };
    cout<<endl<<endl<<"6. ELotte "<<endl;
    kiirPairVector(honapok);
    sort(honapok.begin(), honapok.end(), std::less<pair<int, string>>());
    cout<<"Utanna: "<<endl;
    kiirPairVector(honapok);


    vector<float> din2 = {3.325,3.7,24.623,1,-262.53,2422.9,34.1,676.3,245.3,2,24.765};

    cout<<"7. Ellotte: "<<endl;

    kiirDinVektroFloat(din2);
    sort(din2.begin(), din2.end(), [](const float& x,const float& y)
    {
        return abs(x)<abs(y);
    });
    cout<<"7. Utanna: "<<endl;
    kiirDinVektroFloat(din2);

    cout<<"8. Elotte"<<endl;
    kiirPairVector(honapok);

    for_each(honapok.begin(), honapok.end(), [](pair<int, string>& x)
    {
        x.second=strlwr(x.second.data());
    });

    cout<<"8. Utanna"<<endl;
    kiirPairVector(honapok);


    struct FurcsaABC
    {
        char abc[256];

        FurcsaABC()
        {
            char tmp[256];
            for (int i=0;i<256;i++)
            {
                abc[i]=i;
            }

            random_device rd;
            mt19937 g(rd());
            shuffle(abc,abc+256,g);
            //tmp['a']='z';
            //tmp['z']='a';

            /*for (int i=0;i<256;i++)
            {
                abc[tmp[i]]=i;
            }*/
        }
        bool operator()(const string& a, const string& b)
        {
            return lexicographical_compare(a.begin(),a.end(),b.begin(),b.end(),[this](char chrA,char chrB)
            {
                return abc[chrA]<abc[chrB];
            });
        };
    };
    FurcsaABC fAbc;
    cout<<endl<<endl;
    for (int i=0;i<256;i++)
    {
        cout<<fAbc.abc[i]<<' ';
    }


}