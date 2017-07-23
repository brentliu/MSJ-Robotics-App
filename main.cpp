#include <iostream>
#include <fstream>
using namespace std;

bool achievable[5000001];

int dfs(int fullness, int T, int A, int B, bool water)
{
    if (fullness > T){
        return 0;
    }
    if (achievable[fullness]){
        return 0;
    }
    achievable[fullness] = true;
    int hi = fullness;
    hi = max(hi, dfs(fullness + A, T, A, B, water));
    hi = max(hi, dfs(fullness + B, T, A, B, water));
    if (!water){
        hi = max(hi, dfs(fullness / 2, T, A, B, true));
    }
    return hi;
}

int main()
{
    ifstream fin("feast.in");
    ofstream fout("feast.out");
    int T, A, B;
    fin >> T >> A >> B;
    fout << dfs(0, T, A, B, false);
}
