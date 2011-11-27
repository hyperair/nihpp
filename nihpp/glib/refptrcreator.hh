#ifndef _NIHPP_REFPTRCREATOR_HH_
#define _NIHPP_REFPTRCREATOR_HH_

#include <glibmm/refptr.h>
#include <nihpp/ptrcreator.hh>

namespace nihpp
{
    namespace Glib
    {
        template <typename T>
        struct RefPtrCreator
        {
            typedef PtrCreator<T, ::Glib::RefPtr<T>> type;
        };
    }
}

#endif // _NIHPP_REFPTRCREATOR_HH
