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
