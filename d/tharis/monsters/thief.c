#include <daemons.h>
inherit "/d/tharis/monsters/wonder.c";
void create() {
    ::create();
        set_name("citizen");
        set_id( ({ "citizen","thief"  }) );
        set("race", "human");
        set_gender("male");
        set("short", " citizen");
        set("long", "This is a common citizen of Tharis.\n");
        set_level(1);
        set_body_type("human");
        set_class("thief");
        set("aggressive", 0);
        set_alignment(3);
        set_size(2);
        set_stats("intelligence",6);
        set_stats("wisdom",4);
        set_stats("strength",13);
        set_stats("charisma",3);
        set_stats("dexterity",8);
        set_stats("constitution",7);
        set_max_mp(0);
        set_mp(query_max_mp());
        set_hd(1, 1);
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
        add_money("silver",random(10));
        add_money("gold",random(5));
        add_money("copper",random(20));
set_thief_skill("pick pockets", 50);
toggle_steal();
}
