#include <bits/stdc++.h>
using namespace std;

int games[6][3];
bool played[6];

int main(){
    int t,g;
    cin>>t>>g;
    for(int i=0; i<g; i++){
        int a,b,sa,sb;
        cin>>a>>b>>sa>>sb;
        if(a==1 && b==2){
            if(sa>sb){games[0][0]=3; games[0][1]=3; games[0][2]=3;}
            else if(sb>sa) {games[0][0]=0; games[0][1]=0; games[0][2]=0;}
            else {games[0][0]=1; games[0][1]=1; games[0][2]=1;}
            played[0]=true;
        }
        else if(a==1 && b==3){
            if(sa>sb){games[1][0]=3; games[1][1]=3; games[1][2]=3;}
            else if(sb>sa) {games[1][0]=0; games[1][1]=0; games[1][2]=0;}
            else {games[1][0]=1; games[1][1]=1; games[1][2]=1;}
            played[1]=true;
        }
        else if(a==1 && b==4){
            if(sa>sb){games[2][0]=3; games[2][1]=3; games[2][2]=3;}
            else if(sb>sa) {games[2][0]=0; games[2][1]=0; games[2][2]=0;}
            else {games[2][0]=1; games[2][1]=1; games[2][2]=1;}
            played[2]=true;
        }
        else if(a==2 && b==3){
            if(sa>sb){games[3][0]=3; games[3][1]=3; games[3][2]=3;}
            else if(sb>sa) {games[3][0]=0; games[3][1]=0; games[3][2]=0;}
            else {games[3][0]=1; games[3][1]=1; games[3][2]=1;}
            played[3]=true;
        }
        else if(a==2 && b==4){
            if(sa>sb){games[4][0]=3; games[4][1]=3; games[4][2]=3;}
            else if(sb>sa) {games[4][0]=0; games[4][1]=0; games[4][2]=0;}
            else {games[4][0]=1; games[4][1]=1; games[4][2]=1;}
            played[4]=true;
        }
        else{
            if(sa>sb){games[5][0]=3; games[5][1]=3; games[5][2]=3;}
            else if(sb>sa) {games[5][0]=0; games[5][1]=0; games[5][2]=0;}
            else {games[5][0]=1; games[5][1]=1; games[5][2]=1;}
            played[5]=true;
        }
    }
    for(int i=0; i<6; i++){
        if(!played[i]){games[i][0]=0; games[i][1]=1; games[i][2]=3;}
    }
    int cnt=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                for(int l=0; l<3; l++){
                    for(int m=0; m<3; m++){
                        for(int n=0; n<3; n++){
                            int score[4];
                            score[0]=0; score[1]=0; score[2]=0; score[3]=0;
                            if(games[0][i]==1){score[0]++; score[1]++;}
                            else {score[0]+=games[0][i]; score[1]+=3-games[0][i];}
                            if(games[1][j]==1) {score[0]++; score[2]++;}
                            else {score[0]+=games[1][j]; score[2]+=3-games[1][j];}
                            if(games[2][k]==1){score[0]++; score[3]++;}
                            else {score[0]+=games[2][k]; score[3]+=3-games[2][k];}
                            if(games[3][l]==1){score[1]++; score[2]++;}
                            else {score[1]+=games[3][l]; score[2]+=3-games[3][l];}
                            if(games[4][m]==1){score[1]++; score[3]++;}
                            else {score[1]+=games[4][m]; score[3]+=3-games[4][m];}
                            if(games[5][n]==1){score[2]++; score[3]++;}
                            else {score[2]+=games[5][n]; score[3]+=3-games[5][n];}
                            if(t==1 && score[0]>score[1] && score[0]>score[2] && score[0]>score[3])cnt++;
                            else if(t==2 && score[1]>score[0] && score[1]>score[2] && score[1]>score[3])cnt++;
                            else if(t==3 && score[2]>score[0] && score[2]>score[1] && score[2]>score[3])cnt++;
                            else if(t==4 && score[3]>score[0] && score[3]>score[1] && score[3]>score[2])cnt++;
                        }
                    }
                }
            }
        }
    }
    while(g--) cnt/=3;
    cout<<cnt;
}
