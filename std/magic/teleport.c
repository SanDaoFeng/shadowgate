/**
 * @file
 * @brief Teleport functions and checks. You can either include it or use as a "daemon" object.
 * Note that stric types are enabled for this object
 */

#include <std.h>

#pragma strict_types

int object_can_be_teleported(object teleportee, object destination, int clevel)
{
    if (!objectp(destination)) {
        return 0;
    }
    if (!destination->is_room()) {
        return 0;
    }
    if (destination->is_flight_room()) {
        return 0;
    }
    if (teleportee->query_property("teleport proof") - 9 + random(20) > clevel) {
        return 0;
    }

    if (destination->query_property("no teleport") ||
        environment(teleportee)->query_property("no teleport")) {
        return 0;
    }

    {
        int startpower, endpower;
        startpower = environment(teleportee)->query_property("teleport proof");
        endpower = destination->query_property("teleport proof");
        if ((clevel - 9 + random(20) < startpower) ||
            (clevel - 9 + random(20) < endpower)) {
            return 0;
        }
    }
    return 1;
}

object scatter_destination(mixed destination)
{
    string fname;
    string* files;
    object destobj;
    object tmp;

    fname = base_name(destination);

    files = dir_listing(fname);

    foreach (tmp in files)
    {
        if (catch(destobj = find_object_or_load(tmp))) {
            files -= ({ tmp });
        }

        if (!destobj->is_room()) {
            files -= ({tmp});
        }
    }

    destobj = find_object_or_load(files[random(sizeof(files))]);

    return destobj;
}

mixed teleport_object(object invoker, mixed teleportee, mixed destination, int clevel)
{
    object tped, destroom;

    if (stringp(teleportee)) {
        tped = present(teleportee, invoker);
        if (!objectp(tped)) {
            write(teleportee + " can't be found");
            return 0;
        }
    } else if (objectp(teleportee)) {
        tped = teleportee;
    } else {
        return 0;
    }

    if (stringp(destination)) {
        if (!(destroom = invoker->query_rem_room(destination))) {
            tell_object(invoker, "You can't remember " + destination);
            return 0;
        }
    } else if (objectp(destination)) {
        destroom = destination;
    } else {
        return 0;
    }

    if (!object_can_be_teleported(tped, destroom, clevel)) {
        return 0;
    }

    destroom->set_property("recent teleport", ENV(tped));
    ENV(tped)->set_property("recent teleport", destroom);

    tped->move_player(destroom);

    return destroom;
}

string* dir_listing(string tempfil)
{
    string* tmpstor, path;
    tmpstor = explode(tempfil, "/");

    path = "/" +
        implode(tmpstor - ({ tmpstor[sizeof(tmpstor) - 1] }),"/")
        + "/";

    tmpstor = map_array(get_dir(path + "*.c"), (: $2 + $1:), path);

    return tmpstor;
}
