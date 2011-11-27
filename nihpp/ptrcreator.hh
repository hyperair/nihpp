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

#ifndef _NIHPP_PTRCREATOR_HH_
#define _NIHPP_PTRCREATOR_HH_

#include <utility>
#include <memory>

namespace nihpp
{
    template <typename T, typename U = T*>
    class PtrCreator
    {
    public:
        typedef U Ptr;

        static Ptr create ()
        {
            return Ptr (new T);
        }

        template <typename... Args>
        static Ptr create (Args&&... args)
        {
            return Ptr (new T (std::forward<Args> (args)...));
        }
    };
}
#endif  // _NIH_PTRCREATOR_HH_
