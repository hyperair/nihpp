/* nihpp - A general purpose C++ utility library
 * Copyright © 2011  Chow Loong Jin <hyperair@ubuntu.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _NIHPP_SHAREDPTRCREATOR_HH_
#define _NIHPP_SHAREDPTRCREATOR_HH_

#include <memory>
#include <nihpp/ptrcreator.hh>

namespace nihpp
{
    template <typename T>
    using UniquePtrCreator = PtrCreator<T, std::unique_ptr<T>>;
}

#endif // _NIHPP_SHAREDPTRCREATOR_HH_
