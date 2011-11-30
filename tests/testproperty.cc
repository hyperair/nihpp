#include <nihpp/property.hh>
#include <cassert>

using nih::Property;
namespace
{
    class foo
    {
    public:
        Property<int> bar;
    };
}

int main ()
{
    foo foo;

    foo.bar = 1;
    assert (foo.bar == 1);

    foo.bar (2);
    assert (foo.bar () == 2);

    return 0;
}
