#pragma once

namespace libtorrent
{
    class session;
}

namespace lt
{
    ref class alert;
    ref class add_torrent_params;

    class session_alert_dispatcher;

    public ref class session
    {
    public:
        session();
        ~session();

        void async_add_torrent(add_torrent_params^ params);
        void pause();
        void resume();
        bool is_paused();
        void listen_on(int minPort, int maxPort /* TODO: network interface */);
        bool is_listening();
        int listen_port();
        int ssl_listen_port();
        void set_alert_mask(unsigned int mask);
        void set_alert_dispatch(System::Action<alert^>^ dispatch);

        session_alert_dispatcher* dispatcher_;
        libtorrent::session* session_;
    };
}
