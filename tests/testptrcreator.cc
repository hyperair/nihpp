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

#include <nihpp/sharedptrcreator.hh>
#include <nihpp/glib/refptrcreator.hh>

#include <cassert>
#include <iostream>

namespace {
    class SharedPtrTest : public nihpp::SharedPtrCreator<SharedPtrTest>::type
    {
        int &refcnt;

    public:
        SharedPtrTest (int &refcnt) : refcnt (refcnt)
        {
            refcnt++;
        }

        ~SharedPtrTest ()
        {
            refcnt--;
        }
    };

    class RefPtrTest : public nihpp::Glib::RefPtrCreator<RefPtrTest>::type
    {
        int &refcnt;
        bool &constructed;

    public:
        RefPtrTest (int &refcnt, bool &constructed) :
            refcnt (refcnt),
            constructed (constructed)
        {
            reference ();
            constructed = true;
        }

        void reference ()
        {
            refcnt++;
        }

        void unreference ()
        {
            if (!--refcnt)
                delete this;
        }

        ~RefPtrTest ()
        {
            constructed = false;
        }
    };
}

int main ()
{
    int refcnt = 0;

    {
        SharedPtrTest::Ptr foo = SharedPtrTest::create (refcnt);
        assert (refcnt == 1);   // Make sure refcnt is incremented

        {
            SharedPtrTest::Ptr bar = foo;
            assert (refcnt == 1 && bar.get () == foo.get ());
        }

        assert (refcnt == 1);   // Make sure it's not destroyed
    }

    assert (refcnt == 0);       // Make sure it's destroyed

    bool constructed = false;
    {
        RefPtrTest::Ptr foo = RefPtrTest::create (refcnt, constructed);
        assert (constructed && refcnt == 1);

        {
            RefPtrTest::Ptr bar = foo;
            assert (constructed && refcnt == 2);
        }

        assert (constructed && refcnt == 1);
    }

    assert (!constructed && refcnt == 0);
}
