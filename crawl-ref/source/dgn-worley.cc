#include "AppHdr.h"
#include "env.h"
#include "coord.h"
#include "coordit.h"
#include "perlin.h"
#include "random.h"
#include "cellular.h"
#include <cmath>
#include <iostream>

void layout_worley() {

    double L = 5;
    double T = random2(1000000);

    const coord_def centre(GXM/2,GYM/2);

    for (rectangle_iterator ri(1); ri; ri++) {
        double dist = sqrt(sqrt((double) ri->distance_from(centre))) - 1;
        double x = ri->x;
        double y = ri->y;
        double p = perlin(x*4,y*4,0);
        
        x += perlin(x*7,y*13,2)*3;
        y += perlin(x*17,y*19,5)*3;

        worley::noise_datum d = worley::worley(x/L,y/L,T);

        if (d.distance[0] < dist) {
            grd(*ri) = p < 0.3 ? DNGN_ROCK_WALL : DNGN_FLOOR;
        } else {
            grd(*ri) = p < 0.4 ? DNGN_FLOOR : DNGN_ROCK_WALL;
        }
    }
}
