/**
 * ADDCOMMENTCommand.cc
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,
 * USA.
 *
 * $Id: ADDCOMMENTCommand.cc,v 1.4 2003/06/28 01:21:20 dan_karrels Exp $
 */

#include <string>

#include "ELog.h"
#include "StringTokenizer.h"
#include "cservice.h"
#include "levels.h"
#include "responses.h"

namespace gnuworld {
using std::string;

bool ADDCOMMENTCommand::Exec(iClient* theClient, const string& Message)
{
    bot->incStat("COMMANDS.ADDCOMMENT");

    StringTokenizer st(Message);
    if (st.size() < 2) {
        Usage(theClient);
        return true;
    }

    sqlUser* theUser = bot->isAuthed(theClient, false);
    if (!theUser) {
        return false;
    }

    int admLevel = bot->getAdminAccessLevel(theUser);
    if (admLevel < level::addcommentcmd)
        return false;

    /*
 *  Check the person we're trying to add is actually registered.
 */

    sqlUser* targetUser = bot->getUserRecord(st[1]);
    if (!targetUser) {
        bot->Notice(theClient,
            bot->getResponse(theUser,
                   language::not_registered)
                .c_str(),
            st[1].c_str());
        return false;
    }

    /*
 * Add the comment.
 */

    targetUser->writeEvent(sqlUser::EV_COMMENT, theUser, st.assemble(2));

    if (st.size() == 2) {
        bot->Notice(theClient, "Comment Blanked for %s.", targetUser->getUserName().c_str());
    } else {
        bot->Notice(theClient, "Done. Added comment to %s", targetUser->getUserName().c_str());
    }

    return true;
}

} // namespace gnuworld.
