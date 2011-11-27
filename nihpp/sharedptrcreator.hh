#ifndef _NIHPP_SHAREDPTRCREATOR_HH_
#define _NIHPP_SHAREDPTRCREATOR_HH_

#include <nihpp/ptrcreator.hh>

namespace nihpp
{
    template <typename T>
    struct SharedPtrCreator
    {
        typedef PtrCreator<T, std::shared_ptr<T>> type;
    };
}

#endif // _NIHPP_SHAREDPTRCREATOR_HH_
