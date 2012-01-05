#include <sigc++/sigc++.h>
#include <nihpp/sigc++/fixfunctors.hh>
#include <cassert>

namespace {
    class Functor
    {
        bool &executed;

    public:
        Functor (bool &executed) : executed (executed)
        {
            executed = false;
        }

        Functor (const Functor &) = default;
        ~Functor () = default;

        int operator() ()
        {
            executed = true;
            return 0;
        }
    };
}

int main ()
{
    sigc::slot<void> a = []() -> void {};
    sigc::slot<bool> b = []() {return true;};

    bool executed = false;
    sigc::slot<int> c = Functor (executed);
    assert (!executed);
    assert (c () == 0);
    assert (executed);

    return 0;
}
