#include<bits/stdc++.h>
#include <chrono>
#include <thread>
#include <windows.h>
using namespace std;
int alive( vector<vector<char>> grid , int r ,int c , int h , int v ){
    int dr[] ={-1,0,1};
    int dc[] ={-1,0,1};
    int count =0;
     for(int i=0;i<3;i++){
        for(int j=0 ;j<3;j++){
            if(i==1&&j==1) continue;
            if(h+dr[i]<0||h+dr[i]>r-1||v+dc[j]<0||v+dc[j]>c-1)continue;
            if(grid[h+dr[i]][v+dc[j]]=='#') count++;
        }
    }
    return count;
}
int main(){
    int r,c,g;
    vector<vector<vector<char>>> history;
    cin>>r>>c>>g;
    int total=0;
   vector<vector<char>> grid (r,vector<char>(c,0)) ;
    for(int i=0;i<r;i++){
        for(int j=0 ;j<c;j++){
            cin>>grid[i][j];
        }
    }
    history.push_back(grid);
    int a , b;
    vector<vector<int>> alivenbh (r,vector<int>(c,0));
    for(int l=0;l<=g;l++){
    for(int i=0;i<r;i++){
        for(int j=0 ;j<c;j++){
            int k = alive(grid,r , c,i ,j );
            alivenbh[i][j]=k;
        }
    } 
      for(int i=0;i<r;i++){
        for(int j=0 ;j<c;j++){
        if(grid[i][j]=='#') ;
            if(alivenbh[i][j]<2&&grid[i][j]=='#') grid[i][j]='.';
            if(alivenbh[i][j]>3&&grid[i][j]=='#') grid[i][j]='.';
            if(alivenbh[i][j]==3&&grid[i][j]=='.') grid[i][j]='#';
        }
    }
     history.push_back(grid);
     vector<vector<char>>&t=history[l];
     for(int i=0;i<r;i++){
        for(int j=0 ;j<c;j++){
        if(grid[i][j]=='#') total++;
        }
    }
        cout<<"generation:"<<l<<"  "<<"population:"<<total<<endl;
        total=0;
        for(int a=0;a<r;a++){
        for(int b=0 ;b<c;b++){
            cout<<t[a][b]<<' ';
            if(b==c-1) cout<<endl;
        }
    }
    cout.flush();
    Sleep(2000);
    cout << "\033[2J\033[1;1H";
    }
    cout<<"simulation complete";
    return 0;
 }