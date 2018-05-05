/**
 * ip.h
 * This stuff should probably be moved to a static class.
 * xIP provides mostly utilitarian functionality for IP
 * addresses.
 * This class originally created by Orlando Bassotto.
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
 * $Id: ip.h,v 1.7 2004/01/07 03:08:29 dan_karrels Exp $
 */

#ifndef __IP_H
#define __IP_H "$Id: ip.h,v 1.7 2004/01/07 03:08:29 dan_karrels Exp $"

#include	<string>
#include	"Numeric.h"

namespace gnuworld
{

/**
 * A utility class that is used to retrieve information about
 * IP addresses.
 */
class xIP
{

public:

	/**
	 * Construct an xIP instance given an address in std::string
	 * format.
	 */
	xIP( const std::string& IP, bool Base64 = false ) ;

	/**
 	 * Construct an xIP instance given an IP in irc_in_addr struct format.
	 */
	xIP( const irc_in_addr& IP ) ;

	/**
	 * Copy constructor.
	 */
	xIP( const xIP& IP ) ;

	/**
	 * Destruct this xIP instance.  No heap space is allocated.
	 */
	~xIP() {}

	/**
	 * Retrieve the IP in xxx.xxx.xxx.xxx/xx:xx::xx:xx character array format.
	 */
	std::string	GetNumericIP(bool fixedToCIDR64 = false) const ;

	/**
	 * Retrieve the IP as an irc_in_addr struct.
	 */
	const irc_in_addr& GetLongIP() const ;

	/**
	 * Return a character array representation of the base 64
	 * IP.
	 */
	std::string	GetBase64IP() const ;

	/**
	 * Get the 32 bit integer representation of a current IPv4 address.
	 */
	unsigned int getIP32() const;

protected:

	/**
	 * The IP number itself.
	 */
	irc_in_addr	IP;

} ;

} // namespace gnuworld

#endif // __XIP_H
