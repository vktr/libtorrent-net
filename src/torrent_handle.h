#pragma once

namespace libtorrent
{
    class torrent_handle;
}

namespace lt
{
    public ref class torrent_handle
    {
    internal:
        torrent_handle(libtorrent::torrent_handle& handle);

    public:
        ~torrent_handle();

    private:
        libtorrent::torrent_handle* handle_;
    };
}
