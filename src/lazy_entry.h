#pragma once

namespace libtorrent
{
    struct lazy_entry;
}

namespace lt
{
    public ref class lazy_entry
    {
    internal:
        lazy_entry(libtorrent::lazy_entry& le);
        libtorrent::lazy_entry* ptr();

    public:
        ~lazy_entry();

    private:
        libtorrent::lazy_entry* entry_;
    };
}
