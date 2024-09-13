#include<iostream>
using namespace std;
char one=' ',two=' ' , three=' ',four=' ', five=' ', six=' ', seven=' ', eight=' ', nine = ' ';
int win = 0;
int player1;
int player2;

void grid(){
cout<<"|"<<one<< "|"<<two<<"|"<<three<<"|"<<endl;
cout<<"|"<<four<< "|"<<five<<"|"<<six<<"|"<<endl;
cout<<"|"<<seven<< "|"<<eight<<"|"<<nine<<"|"<<endl;
}
void playerone(){
cout<<"player1"<<endl;
cin>>player1;
switch(player1){
    case 1:
    one='X';
    break;
    case 2:
    two='X';
    break;
    case 3:
    three='X';
    break;
    case 4:
    four='X';
    break;
    case 5:
    five='X';
    break;
    case 6:
    six='X';
    break;
    case 7:
    seven='X';
    break;
    case 8:
    eight='X';
    break;
    case 9:
    nine='X';
    break;

}
}
void playertwo(){
cout<<"player2"<<endl;
cin>>player2;
switch(player2){
    case 1:
    one='O';
    break;
    case 2:
    two='O';
    break;
    case 3:
    three='O';
    break;
    case 4:
    four='O';
    break;
    case 5:
    five='O';
    break;
    case 6:
    six='O';
    break;
    case 7:
    seven='O';
    break;
    case 8:
    eight='O';
    break;
    case 9:
    nine='O';
    break;

}
}
void wincheck(){
    if((one=='X' and two=='X' and three=='X') or (one=='O' and two=='O' and three=='O') or(one=='X' and five=='X' and nine=='X') or (one=='O' and five=='O' and nine=='O') or (one=='X' and four=='X' and seven=='X') or (one=='O' and four=='O' and seven=='O') or (two=='X' and five=='X' and eight=='X') or (two=='O' and five=='O' and eight=='O') or (three=='X' and six=='X' and nine=='X') or (three=='O' and six=='O' and nine=='O') or (four=='X' and five=='X' and six=='X') or (four=='O' and five=='O' and six=='O') or (seven=='X' and eight=='X' and nine=='X') or (seven=='O' and eight=='O' and nine=='O') or (three=='X' and five=='X' and seven=='X') or (three=='O' and five=='O' and  seven=='O')){
        win = 1;
    }
}
int main(){

grid();

while(win==0){
if(player1==10 || player2==10){
return 0;
}
playerone();
grid();
wincheck();
if(win==1){
    cout<<"Player one wins! Press anything to exit";
    cin>>player1;
    return 0;
}
playertwo();
grid();
wincheck();
if(win==1){
    cout<<"Player two wins! Press anything to exit";
    cin>>player2;

    return 0;
}

}


}
