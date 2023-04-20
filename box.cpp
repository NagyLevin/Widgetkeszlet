#include "box.hpp"

#include "graphics.hpp"
using namespace genv;

Box :: Box(int x, int y, int sx, int sy ,char r, char g , char b) : _x(x), _y(y), _sx(sx), _sy(sy) ,_r(r),_g(g),_b(b) {

}

void Box :: rajz(){

    gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);


}




