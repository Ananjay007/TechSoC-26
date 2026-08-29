#include<bits/stdc++.h>
using namespace std;
int alive( vector<vector<char>> grid , int r ,int c , int h , int v ){
    int dr[] ={-1,0,1};
    int dc[] ={-1,0,1};
    int count =0;
     for(int i=0;i<3;i++){
        for(int j=0 ;j<3;j++){
            if(i==1&&j==1) continue;
            if(grid[(h+dr[i]+r)%r][(v+dc[j]+c)%c]=='#') count++;
        }
    }
    return count;
}
bool same(vector<vector<char>>&g1 , vector<vector<char>>&g2,int r , int c){
     for(int i=0;i<r;i++){
     for(int j=0 ;j<c;j++){
        if(g1[i][j]!=g2[i][j]) return false;
     }
  }
}
int main(){
    int r,c,g;
    bool status=true;
    vector<vector<vector<char>>> history;
    cin>>r>>c>>g;
    int total=0;
    int t=0;
    int rmax=0;
    int cmax=0;
    int cmin=r;
    int rmin=c;
    double cor=0;
    double coc=0;
   vector<vector<char>> grid (r,vector<char>(c,0)) ;
    for(int i=0;i<r;i++){
        for(int j=0 ;j<c;j++){
            cin>>grid[i][j];
        }
    }
    history.push_back(grid);
    for(int i=0;i<r;i++){
     for(int j=0 ;j<c;j++){
         if(grid[i][j]=='#'){
           rmax = max(rmax,i);
           cmax = max(cmax,j);
           rmin = min(rmin,i);
           cmin = min(cmin,j);
           cor+=i;
           coc+=j;
           t++;
        }
      }
    }
    cout<<"total live cells:"<<t<<endl;
    cout<<"Bounding box:"<<rmax-rmin+1<<"x"<<cmax-cmin+1<<endl;
    cor=cor/t;
    coc=coc/t;
    cout<<"center of mass:("<<setprecision(2)<<cor<<","<<setprecision(2)<<coc<<")"<<endl;
    
    int maxi=0;
    int a , b;
    vector<vector<int>> alivenbh (r,vector<int>(c,0));
    for(int l=0;l<=g+1;l++){
    for(int i=0;i<r;i++){
        for(int j=0 ;j<c;j++){
            int k = alive(grid,r , c,i ,j );
            alivenbh[i][j]=k;
        }
    } 
      for(int i=0;i<r;i++){
        for(int j=0 ;j<c;j++){
        if(grid[i][j]=='#') total++;
            if(alivenbh[i][j]<2&&grid[i][j]=='#') grid[i][j]='.';
            if(alivenbh[i][j]>3&&grid[i][j]=='#') grid[i][j]='.';
            if(alivenbh[i][j]==3&&grid[i][j]=='.') grid[i][j]='#';
        }
    }
     if(total==0){
         cout<<"classification:extinct\n"<<"extinct at step:"<<l<<endl;
         status=false;
     }
     history.push_back(grid);
     if(l==0)cout<<"initial polpulation is:"<<total<<endl;
     if(l==g) cout<<"final polpulation is:"<<total<<endl;
     maxi = max(total,maxi);
     total=0;
     if(l==g) cout<<"max polpulation is:"<<maxi<<endl;
     if(l==g-1){ 
        cout<<"final grid:"<<endl;
        for(int a=0;a<r;a++){
        for(int b=0 ;b<c;b++){
            cout<<grid[a][b]<<' ';
            if(b==c-1) cout<<endl;
        }
    }
   }
  }
 if(status==true){
    for(int i=0;i<=g;i++){
     for(int j=i+1 ; j<=g ; j++){
        bool p= same(history[i],history[j],r,c);
        if(p&&j-i==1){
          cout<<"classification:still life\n"<<"period:"<<j-i<<endl<<"first step of repetation:"<<j<<endl;
          status=false; break; 
        }
        if(p&&status){ 
         cout<<"classification:oscillator\n"<<"period:"<<j-i<<endl<<"first step of repetation:"<<j<<endl;
          status=false;break;
        }
      }
    }
   if(status==true)cout<<"classification:active" ;
 }
return 0;
}