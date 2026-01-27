//Butano
#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_sprite_ptr.h>
#include <bn_random.h>
#include <bn_vector.h> //Arraylist equivalent
#include <bn_keypad.h>

#include "bn_sprite_items_bug.h"

int main(){
    bn::core::init();

    bn::random rng = bn::random();

    bn::backdrop::set_color(bn::color(31, 11, 11));

    bn::vector<bn::sprite_ptr, 50> bugs = {}; //Making the vector (a list)

    // bn::sprite_ptr green_beetle = bn::sprite_items::bug.create_sprite();

    while (true){
        for(bn::sprite_ptr& green_beetle : bugs){
            bn::fixed new_x = green_beetle.x() + rng.get_fixed(-1,1);
            bn::fixed new_y = green_beetle.y() + rng.get_fixed(-1,1);

            green_beetle.set_x(new_x);
            green_beetle.set_y(new_y);
        }

        if(bn::keypad::a_pressed()){
            bugs.push_back(bn::sprite_items::bug.create_sprite());
        }

        rng.update();
        bn::core::update();
    }
}