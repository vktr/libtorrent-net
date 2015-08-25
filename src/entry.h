#pragma once

namespace libtorrent
{
    class entry;
}

namespace lt
{
    public ref class entry
    {
    internal:
        entry(const libtorrent::entry& e);
        libtorrent::entry* ptr();

    public:
        ~entry();

    private:
        libtorrent::entry* entry_;
    };
}
