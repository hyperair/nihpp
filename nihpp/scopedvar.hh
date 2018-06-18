/* nihpp - A general purpose C++ utility library
 * Copyright © 2012  Chow Loong Jin <hyperair@debian.org>
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

#ifndef _NIHPP_SCOPEDVAR_HH_
#define _NIHPP_SCOPEDVAR_HH_

#include <functional>

namespace nihpp
{
    template <typename T>
    class ScopedVariable
    {
        T &ref;
        std::function<void (T &)> restorefn;

    public:
        ScopedVariable (T &ref,
                        std::function<void (T &)> mutatefn,
                        std::function<void (T &)> restorefn) :
            ref (ref),
            restorefn (restorefn)
        {
            mutatefn (ref);
        }

        ScopedVariable (const ScopedVariable &) = delete;
        ~ScopedVariable () {restorefn (ref);}
    };

    class ScopedBool
    {
        bool original;
        ScopedVariable<bool> scoped;

        void restore (bool &ref) {ref = original;}

    public:
        ScopedBool (T &ref) :
            original (ref),
            scoped (ref, [](bool &ref) {ref = !ref;},
                    std::bind (&ScopedBool::restore, *this)) {}
    };

    template <typename T>
    struct ScopedRefCount : ScopedVariable<T>
    {
        ScopedRefCount (T &ref) :
            ScopedVariable<T> (ref, [](T &ref) {ref++;},
                               [](T& ref) {ref--;}) {}
    };
}

#endif _NIHPP_SCOPEDVAR_HH_
