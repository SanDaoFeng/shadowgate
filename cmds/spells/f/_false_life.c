#include <std.h>
#include <dirs.h>
#include <daemons.h>
#include <priest.h>
inherit SPELL;

int bonus;

void create() {
    ::create();
    set_spell_name("false life");
    set_spell_level(([ "mage" : 2, "bard" : 2 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS false life [on TARGET]");
    set_description("With this spell, caster harnesses powers of unlife to grant herself a limited ability to avoid death. While this spell is active, the caster is healthier.");
    set_components(([
      "mage" : ([ "drop of blood":1, "crane's feather":1, ]),
    ]));
	set_helpful_spell(1);
}

string query_casting_string() {
    return "%^RED%^With a shout and a body wide flex, "+caster->QCN+" starts to cast a spell.";
}

void spell_effect(int prof) 
{
    if (!objectp(target)) {
        TO->remove();
        return;
    }
    if (!objectp(caster)) {
        TO->remove();
        return;
    }
    if (caster == target) {
        tell_object(caster,"%^RED%^You slowly summon inner strength, lending the force of your will to the strength of your body.");
        tell_room(environment(caster),"%^RED%^You see a wave of force surround and strengthen "+caster->QCN+"'s body.",({caster}));
    } else {
        tell_object(caster,"%^RED%^You slowly summon inner strength, lending the force of your will to strengthen "+target->QCN+"'s body.");
        tell_object(target,"%^RED%^You feel the force of "+caster->QCN+"'s will strengthen your body.");
        tell_room(environment(caster),"%^RED%^You see a wave of force surround and strengthen "+target->QCN+"'s body.",({target}));
    }
    bonus = 5*clevel;
    caster->add_max_hp_bonus(bonus);
    caster->set_property("spelled",({TO}));
    caster->set_property("false_life",1);
    spell_successful();
    addSpellToCaster();
}

void dest_effect()
{
    if(objectp(target)) 
    {
       target->add_max_hp_bonus(-bonus);
       target->remove_property_value("spelled", ({TO}) );
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}

