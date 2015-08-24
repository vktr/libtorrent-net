#pragma once

namespace libtorrent
{
    struct add_torrent_params;
}

namespace lt
{
    ref class torrent_info;

    public ref class add_torrent_params
    {
    public:
        add_torrent_params();
        ~add_torrent_params();

        property System::String^ name
        {
            System::String^ get();
            void set(System::String^ value);
        }

        property System::String^ save_path
        {
            System::String^ get();
            void set(System::String^ value);
        }

        property torrent_info^ ti
        {
            torrent_info^ get();
            void set(torrent_info^ value);
        }

    internal:
        libtorrent::add_torrent_params* ptr();

    private:
        libtorrent::add_torrent_params* params_;
    };
}
