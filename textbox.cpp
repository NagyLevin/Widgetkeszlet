#include "textbox.hpp"
#include "box.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace genv;
using namespace std;

TextBox :: TextBox(int x, int y, int sx, int sy ,char r, char g , char b, string szoveg) : Box(int x, int y, int sx, int sy ,char r, char g , char b), _szoveg(szoveg) { //csak egyszer fut le ertekadasok




}



void TextBox :: rajz(){



if(kijelolve == false){
    //gout << move_to(_x,_y) << color(127+127*kijelolve,127+127*kijelolve,127+127*kijelolve) << box(_sx,_sy) << color(0,0,128) << move_to(_x+ablakszele,_y+ablakszele) << box(_sx+ablakszele/2,_sy+ablakszele/2);

    gout << move_to(_x-ablakszele/2,_y-ablakszele/2) << color(127,127,172) <<box(_sx+ablakszele,_sy+ablakszele);
    gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
}
if(kijelolve == true){
     gout << move_to(_x-ablakszele/2,_y-ablakszele/2) << color(255,255,255) <<box(_sx+ablakszele,_sy+ablakszele);
     gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
    }

    //gout << move_to(_x-ablakszele/2,_y-ablakszele/2) << color(255,255,255) <<box(_sx+ablakszele,_sy+ablakszele);
    //gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);



}



