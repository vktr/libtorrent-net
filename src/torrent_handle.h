#pragma once

namespace libtorrent
{
    struct torrent_handle;
}

namespace lt
{
    ref class torrent_status;

    public ref class torrent_handle
    {
    internal:
        torrent_handle(libtorrent::torrent_handle& handle);

    public:
        ~torrent_handle();

        torrent_status^ status();

    private:
        libtorrent::torrent_handle* handle_;
    };
}
