nihpp: a C++11 general purpose utility library
==============================================

This library is currently mainly a dumping ground of ideas that float by in my
head that I think may be useful in any future C++ projects I take up.

Requirements
------------

 * C++11 compiler (g++ or something that accepts -std=c++0x)
 * C++11 headers

Classes
-------

Currently, classes available include:
 * nih::PtrCreator
 * nih::SharedPtrCreator
 * nih::Glib::RefPtrCreator
 * nih::Singleton
 * sigc::functor_trait

PtrCreator is a templated class that is meant to be derived from, which adds
static create() functions to construct smart pointer classes. See
tests/testptrcreator.cc for an example of how to use it.

SharedptrCreator and Glib::RefPtrCreator are shortcuts for PtrCreator<T,
shared_ptr<T>> and PtrCreator<T, Glib::RefPtr<T>> respectively. They would
ideally be templated typedefs, but g++ does not seem to support them properly
just yet.

Singleton is a class that can be derived from to provide a static ::instance()
function for easy implementation of singleton classes. It only supports the
default constructor, as there is no way to pass arguments into the static
singleton instance.

sigc::functor_trait is a template specialization of sigc::functor_trait as found
in libsigc++ that was implemented to allow lambdas, and other function objects
(including std::function) with return values to work without any code changes
apart from just #include-ing the header. The initial idea was ripped out from
the SIGC_FUNCTOR_TRAIT macro.
