#pragma once

namespace libtorrent
{
    class torrent_info;
}

namespace lt
{
    public ref class torrent_info
    {
    public:
        torrent_info(cli::array<System::Byte>^ buffer);
        torrent_info(System::String^ fileName);

        ~torrent_info();

        System::String^ name();
        System::String^ comment();
        System::String^ creator();

    internal:
        torrent_info(libtorrent::torrent_info& info);

        libtorrent::torrent_info* ptr();

    private:
        libtorrent::torrent_info* info_;
    };
}
