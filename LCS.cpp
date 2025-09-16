#include<bits/stdc++.h>
using namespace std;

void print_lcs(vector<char> a,  vector<vector<int>> cost, vector<vector<char>> dir, int x, int y){
    if(dir[x][y] == 'd'){
        print_lcs(a, cost, dir, x-1, y-1);
        cout << a[x];
    }else if(dir[x][y] == 'u'){
        print_lcs(a, cost, dir, x-1, y);
    }else if(dir[x][y] == 's'){
        print_lcs(a, cost, dir, x, y-1);
    }else{
        return;
    }
}

int main(){
    vector<char> a = {'0','e','x','p','o','n','e','n','t','i','a','l'};
    vector<char> b = {'0','p','o','l','y','n','o','m','i','a','l'};
    vector<vector<int>> cost(a.size(), vector<int>(b.size()));
    vector<vector<char>> dir(a.size(), vector<char>(b.size()));
    
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            if(i==0 || j==0){
                cost[i][j] = 0;
                dir[i][j] = 'h';
            }else{
                if(a[i] == b[j]){
                    cost[i][j] = cost[i-1][j-1] + 1;
                    dir[i][j] = 'd';
                }else{
                    if(cost[i-1][j] >= cost[i][j-1]){
                        cost[i][j] = cost[i-1][j];
                        dir[i][j] = 'u';
                    }else{
                        cost[i][j] = cost[i][j-1];
                        dir[i][j] = 's';
                    }
                }
            }
        }
    }

    cout << "  ";
    for(int j=0; j<b.size(); j++){
        cout << b[j] << "    ";
    }
    cout<<endl;
    for(int i=0; i<a.size(); i++){
        cout << a[i] << " ";
        for(int j=0; j<b.size(); j++){
            cout << cost[i][j] << " " << dir[i][j] << "  ";
        }
        cout << endl;
    }

    print_lcs(a, cost, dir, a.size()-1, b.size()-1);

}