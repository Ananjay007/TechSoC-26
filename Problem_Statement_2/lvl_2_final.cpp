#include<bits/stdc++.h>
using namespace std;
int criticalnum =0;
int effectivehit =0;

int randomnum(int min_val , int max_val) {
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> distr(min_val, max_val); 
    int random_num = distr(gen);
    return random_num;
}
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
   int criticalmultiplier(){
    int n= randomnum(1,10);
    if(n==10){
        criticalnum++;
        cout<<"Critical Hit !"<<endl;
        return 2;
    }
    else{
        return 1;
    }
   }
//    int totaldamage(bender& hero, bender& enemy,int j){
//    int damage = static_cast<int>(std::round(static_cast<double>(hero.attack) * hero.pls[j] / enemy.defence));
//     damage = static_cast<int>(damage*criticalmultiplier()*criticalmultiplier(hero,enemy,0));
//     enemy.currenthp=enemy.currenthp - damage;
//     return damage;
//    }
    int totaldamage(bender& hero, bender& enemy,int j){
    double base = static_cast<double>(hero.attack) * hero.pls[j] / enemy.defence;
    double crit = criticalmultiplier();
    double effect = criticalmultiplier(hero,enemy,0);
    int damage = static_cast<int>(std::round(base * crit * effect));
    damage = max(1,damage);
    enemy.currenthp = max(0, enemy.currenthp - damage);
    return damage;
   }
   double criticalmultiplier(bender&hero,bender&enemy,int g ){
      int&a= effectivehit;
      string h = hero.element;
      string e = enemy.element;
      if(h=="Water"&&e=="Fire"){
        if(g==1){ cout<<"Super Effective! (Water is strong against Fire)"<<endl; a++; }
        if(g==0) return 2;
      }
      else if(e=="Water"&&h=="Fire"){
         if(g==1) cout<<"Not very effective... (Fire is weak against Water)"<<endl;
         if(g==0) return 0.5;
      }
      else if(h=="Fire"&&e=="Air"){
        if(g==1){ cout<<"Super Effective! (Fire is strong against Air)"<<endl; a++; }
        if(g==0) return 2;
      }
      else if(e=="Fire"&&h=="Air"){
        if(g==1) cout<<"Not very effective... (Air is weak against Fire)"<<endl;
        if(g==0) return 0.5;
      }
      else if(h=="Air"&&e=="Earth"){
        if(g==1){ cout<<"Super Effective! (Air  is strong against Earth)"<<endl; a++; }
        if(g==0) return 2;
      }
      else if(h=="Earth"&&e=="Air"){
        if(g==1) cout<<"Not very effective... (Earth is weak against Air)"<<endl;
        if(g==0) return 0.5;
      }
      else if(h=="Earth"&&e=="Water"){
        if(g==1){ cout<<"Super Effective! (Earth is strong against Water)"<<endl; a++; }
        if(g==0) return 2;
      }
      else if(e=="Earth"&&h=="Water"){
        if(g==1) cout<<"Not very effective... (Water is weak against Earth)"<<endl;
        if(g==0) return 0.5;
      }
      return 1;
   }
   void round(bender &hero,bender &enemy,int n){
    cout<<endl<<endl<<endl;
    if(n==1){
        cout<<"Turn"<<n<<": "<<hero.name<<" goes first!";
        cout<<"   (Speed : "<<hero.speed<<" VS "<<enemy.speed<<")"<<endl;
    }
    else{
        cout<<"Turn"<<n<<": "<<hero.name<<" strikes back!"<<endl;
    }
        
   }
   void duel(bender&a,bender&b){
    bender hero,enemy;
    int n =1;
    int i = randomnum(0,3);
    cout<<"===DUEL BEGINS!==="<<endl;

    if(a.speed>b.speed){
        hero = a;
        enemy = b;
    }else if ( a.speed<b.speed){
        hero = b;
        enemy = a;
    }
    else{
        int k = randomnum(0,1);
        hero = a ;
        enemy = b;
        if (k==0){
          swap(hero,enemy);
        }
    }
    cout<<hero.name<<" ("<<hero.element<<", HP:"<<hero.hp<<"/"<<hero.hp<<")"<<" VS ";
    cout<<enemy.name<<" ("<<enemy.element<<", HP:"<<enemy.hp<<"/"<<enemy.hp<<")"<<endl;
    bool faint= false;
    while(!faint){
        round(hero,enemy,n);
        cout<<hero.name<<" used "<<hero.moves[i]<<"!"<<endl;
        criticalmultiplier(hero,enemy,1);
        int d = totaldamage(hero,enemy,i);
        cout<<enemy.name<<" took "<<d<<" damage !"<<endl;
        cout<<enemy.name<<" HP: "<<enemy.currenthp<<"/"<<enemy.hp<<endl;
        if(enemy.currenthp<=0){
            cout<<endl<<endl<<enemy.name<<" fainted !"<<endl;
            break;
        }
        cout<<endl;
        swap(hero,enemy);
        n++;
    }
    cout<<"Duel Summary :"<<endl;
    cout<<"- Winner: "<<hero.name<<endl;
    cout<<"- Turns: "<<n<<endl;
    cout<<"- Critical Hits: "<<criticalnum<<endl;
    cout<<"- Super Effective Hits: "<<effectivehit<<endl;
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
    k.duel(k,m);
    return 0;
}
