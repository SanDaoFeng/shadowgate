// Modified by Pator@Shadowgate
// AUgust 25 1995
// Remodified 11/2/95 by Pator@shadowgate

#include <priest.h>
inherit SPELL;

object drinks;


create()
{
    ::create();
    set_author("pator");
    set_spell_name("create water");
    set_spell_level(([ "cleric" : 1, "paladin" : 1,"druid" : 1, "inquisitor" : 1 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS create water");
    set_description("This spell creates a pool of drinkable water. You can drink from the pool, to quench your thirst.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}


int preSpell()
{
    if (present("pool of water", place))
    {
        tell_object(caster, "There is already a pool of water here.");
        return 0;
    }
    return 1;
}


void spell_effect(int prof)
{
    object where;
    int d1,d2,duration, amount;

    d1 = 1;
    d2 = 1;
    duration = 1;
    if( interactive(caster) )
    {
        set_verbal_comp();
        set_somatic_comp();
        tell_object(caster, "You create a pool of clean water.");
        tell_room(place, YOU+" makes a pool of water.", caster);
        drinks= new("/cmds/priest/obj/water.c");
        where = environment(caster);
    }
    else
    {
        tell_room(place, YOU+" conjures a puddle of clean water.", ({ caster}));
        drinks= new("/cmds/priest/obj/water.c");
        where = place;
    }
    d1 = (int)caster->query_stats("wisdom");
    d2 = (int)caster->query_stats("constitution");
    // The time the pool of water will be here
    amount = clevel/2;
    amount++;
    drinks->set_drinks(amount);
    drinks->move(where);
    drinks->set_property("spelled", ({TO}) );
    duration = (( (d1 / d2 ) * clevel ) * 60);
    // To prevent that one gets no water
    if ( duration < 90 ) duration=90;
    spell_successful();
    call_out("dest_effect",duration);
}


void dest_effect()
{
    if (objectp(drinks))
    {
        drinks->remove();
        tell_room(ROOM,"The pool of water just vanishes!");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

string query_cast_string() { return "%^BOLD%^%^CYAN%^"+YOU+" focuses on a bit of water and chants softly.\n"; }
