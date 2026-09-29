#include<bits/stdc++.h>
using namespace std;
class bender {
   
public:
   string name;
   string element;
   int hp = 0;
   int currenthp = 0;
   int attack = 0;
   int defence = 0;
   int speed = 0;
   string moves[4];
   int pls[4];
   
public:
   void display_stats(){
    cout<<name<<"  ("<<element<<") - HP:"<<currenthp<<"/"<<hp<<",Attack: "<<attack<<", Defence: "<<defence<<", Speed: "<<speed<<endl;
    cout<<"Moves: ";
    for (int i=0 ; i<4 ; i++){
        cout<<moves[i]<<" ("<<pls[i]<<")";
        if(i<3) cout<<",";
    }
    cout<<endl;
   }
   void action(bender& a, bender& b, int j){
    bender& hero = a.speed > b.speed ? a : b;
    bender& enemy = a.speed > b.speed ? b : a;
    int damage = static_cast<int>(round(
        static_cast<double>(hero.attack) * hero.pls[j] / enemy.defence));
     cout<<hero.name<<" used "<<hero.moves[j]<<"!"<<endl;
     cout<<enemy.name<<"took "<<damage<<" damage!"<<endl;
     enemy.currenthp= enemy.currenthp-damage;
     enemy.display_stats();
     cout<<enemy.name<<" fainted: ";
     if(enemy.currenthp<=0){
        cout<<"True"<<endl;
     }
     else{
        cout<<"False"<<endl;
     }
    }

};

int main(){
    bender k , m ;
    k.name = "Keal";
    k.element="Fire";
    k.hp = 100;
    k.currenthp = k.hp;
    k.attack= 58;
    k.defence= 38;
    k.speed= 88;  
    k.moves[0] = "Ember Slash";
    k.moves[1] = "Quick Surge";
    k.moves[2] = "Focus";
    k.moves[3] = "Flame Surge";
    k.pls[0]=40;
    k.pls[1]=30;
    k.pls[2]=0;
    k.pls[3]=70;
    k.display_stats();
    m.name = "Mira";
    m.element = "Water";
    m.hp = 92;
    m.currenthp = m.hp;
    m.attack=50;
    m.defence=45;
    m.speed=60;
    m.moves[0] = "Water Whip";
    m.moves[1] = "Tide Push";
    m.moves[2] = "Mist Veil";
    m.moves[3] = "Tidal Wave";
    m.pls[0] = 35;
    m.pls[1] = 25;
    m.pls[2] = 0;
    m.pls[3] = 60;
    m.display_stats();
    k.action(k,m,0);
    return 0;
}