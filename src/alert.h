#pragma once

#include <memory>

namespace libtorrent
{
    class alert;
}

namespace lt
{
    public ref class alert
    {
    internal:
        static alert^ create(std::auto_ptr<libtorrent::alert> al);
        alert(libtorrent::alert* al);

    public:
        ~alert();

        System::DateTime timestamp();
        int type();
        System::String^ what();
        System::String^ message();
        int category();
        bool discardable();
        // TODO: clone?

    private:
        libtorrent::alert* alert_;
    };
}
