
#include "button.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace genv;
using namespace std;

Button :: Button(int x, int y, int sx, int sy ,char r, char g , char b,string szoveg) : TextBox(x,y, sx, sy ,r,g , b,szoveg) { //csak egyszer fut le ertekadasok
megynyom = false;


}
bool Button :: pressed(){
bool mivolt = megynyom;
megynyom = false;

return mivolt;

}



string Button :: funkcio(){
return _szoveg;
}

void Button :: rajz(){


if(kijelolve == false){
    //gout << move_to(_x,_y) << color(127+127*kijelolve,127+127*kijelolve,127+127*kijelolve) << box(_sx,_sy) << color(0,0,128) << move_to(_x+ablakszele,_y+ablakszele) << box(_sx+ablakszele/2,_sy+ablakszele/2);

    gout << move_to(_x-ablakszele/2,_y-ablakszele/2) << color(127,127,172) <<box(_sx+ablakszele,_sy+ablakszele);
    gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);


}
if(kijelolve == true){
     gout << move_to(_x-ablakszele/2,_y-ablakszele/2) << color(255,255,255) <<box(_sx+ablakszele,_sy+ablakszele);
     gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);



    }

if(_szoveg.size()*10 <= _sx){

gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
gout << move_to(_x,_y +_sy/2) << color(_r-100,_g-100,_b-100) << text(_szoveg);
}
if(_szoveg.size()*10 > _sx){
string save = _szoveg.substr(_szoveg.size() - _sx/10 , _szoveg.size());
;
gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
gout << move_to(_x,_y +_sy/2) << color(_r-100,_g-100,_b-100) << text(save);
}

if(megynyom){
    gout << move_to(_x,_y) << color(_r*10,_g*10,_b) <<box(_sx,_sy);


}


}



void Button::eventloop(event ev)
{


if (ev.type == ev_mouse && kivalasztva() && (ev.button==btn_left || ev.keycode == key_enter)) {
    //cout << "megnyomva" <<endl;
    megynyom = !megynyom;


}
















//mozgatas
if(ev.button == 1 && benne()) {

kijelol();
megfog();
//cout <<"talalt"<<endl;
}

if(ev.button == -1 || !benne()) {
    elenged();
    kijelolvege();
}
//mozgatas


}
