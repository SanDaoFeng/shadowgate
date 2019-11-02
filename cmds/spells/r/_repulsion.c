#include <std.h>
#include <priest.h>
inherit SPELL;

int flag;

void create()
{
    ::create();
    set_spell_name("repulsion");
    set_spell_level(([ "cleric" : 7, "inquisitor" : 6, "mage" : 6]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS repulsion");
    set_damage_desc("perpetually pushes everyone attacking you further away");
    set_description("This spell is a modification of armor spell. With this you place a force field around yourself that will push everyone aiming to harm you away, perpetually removing them from combat. Strong willed will pass through the shield.");
    set_save("will");

}

int preSpell()
{
    if(caster->query_property("repulsion"))
    {
        tell_object(caster,"You are already under this spell.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 2) * clevel;
    tell_room(place,"%^CYAN%^As "+caster->QCN+" raises a field of magical force around "+caster->QP+".",caster);
    tell_object(caster,"%^CYAN%^You feel you're surrounded by a force field.");
    caster->set_property("repulsion",1);
    caster->set_property("spelled", ({TO}) );
    caster->set_property("added short",({"%^RESET%^%^CYAN%^ (in a field of force)%^RESET%^"}));
    addSpellToCaster();
    spell_successful();
    call_out("dest_effect",duration);
}

void execute_attack()
{
    object *attackers,room;
    int i;

    ::execute_attack();
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    room      = environment(caster);
    attackers = caster->query_attackers();
    attackers = filter_array(attackers,"is_non_immortal",FILTERS_D);
    attackers = target_filter(attackers);
    for(i=0;i<sizeof(attackers)&&i<6;i++)
    {
        if(do_save(attackers[i],4))
            continue;
        tell_room(room,"%^CYAN%^"+attackers[i]->QCN+" is pushed away by a force field from "+caster->QCN+".%^RESET%^",({attackers[i]}));
        tell_object(attackers[i],"%^CYAN%^You are pushed away by a force field around "+caster->QCN+".%^RESET%^");
        attackers[i]->remove_attacker(caster);
        caster->remove_attacker(attackers[i]);
    }
    room->addObjectToCombatCycle(TO,1);
}

void dest_effect(){
    if(objectp(caster)){
        tell_room(environment(caster),"%^BOLD%^%^CYAN%^The force field around "+caster->QCN+" vanishes.%^RESET%^");
        caster->remove_property("repulsion");
        caster->remove_property_value("added short",({"%^RESET%^%^CYAN%^ (in a field of force)%^RESET%^"}));
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}