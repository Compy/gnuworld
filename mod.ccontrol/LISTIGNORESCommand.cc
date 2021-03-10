/**
 * LISTIGNORESCommand.cc 
 * Shows all ignored masks
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
 * $Id: LISTIGNORESCommand.cc,v 1.10 2006/09/26 17:35:59 kewlio Exp $
 */

#include "CControlCommands.h"
#include "ccontrol.h"
#include "gnuworld_config.h"
#include <cstdlib>
#include <string>

namespace gnuworld {

using std::endl;
using std::string;

namespace uworld {

    bool LISTIGNORESCommand::Exec(iClient* theClient, const string&)
    {
        bot->MsgChanLog("LISTIGNORES \n");
        bot->listIgnores(theClient);
        return true;
    }

}
} // namespace gnuworld
