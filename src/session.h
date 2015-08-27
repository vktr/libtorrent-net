#pragma once

namespace libtorrent
{
    class session;
}

namespace lt
{
    ref class alert;
    ref class add_torrent_params;
    ref class dht_settings;
    ref class entry;
    ref class lazy_entry;
    ref class session_settings;
    ref class session_status;
    ref class sha1_hash;
    ref class torrent_handle;

    class session_alert_dispatcher;

    public ref class session
    {
    public:
        session();
        ~session();

        void load_state(lazy_entry^ e);
        entry^ save_state(unsigned int flags);
        // TODO refresh_torrent_status
        // TODO get torrent status
        void post_torrent_updates();
        torrent_handle^ find_torrent(sha1_hash^ hash);
        cli::array<torrent_handle^>^ get_torrents();
        void async_add_torrent(add_torrent_params^ params);
        torrent_handle^ add_torrent(add_torrent_params^ params);
        // TODO abort
        void pause();
        void resume();
        bool is_paused();
        session_status^ status();
        // TODO get cache status
        // TODO get cache info
        // TODO add feed
        // TODO remove feed
        // TODO get feeds
        bool is_dht_running();
        dht_settings^ get_dht_settings();
        void start_dht();
        void stop_dht();
        void set_dht_settings(dht_settings^ settings);

        /// <summary>
        /// Takes a host name and port pair. That endpoint will be pinged, and
        /// if a valid DHT reply is received, the node will be added to the
        /// routing table.
        /// </summary>
        void add_dht_router(System::String^ host, int port);

        /// <summary>
        /// adds the given endpoint to a list of DHT router nodes. If a search
        /// is ever made while the routing table is empty, those nodes will be
        /// used as backups. Nodes in the router node list will also never be
        /// added to the regular routing table, which effectively means they
        /// are only used for bootstrapping, to keep the load off them.
        /// </summary>
        void add_dht_node(System::String^ host, int port);

        // TODO dht get item
        // TODO dht put item
        // TODO add extension
        void load_country_db(System::String^ file);
        void load_asnum_db(System::String^ file);
        // TODO int as_for_ip(System::Net::IP)
        // TODO get ip filter
        // TODO set ip filter
        // TODO set port filter
        // TODO id
        // TODO set peer id
        void set_key(int key);
        void listen_on(int minPort, int maxPort /* TODO: network interface */);
        bool is_listening();
        int listen_port();
        int ssl_listen_port();
        void remove_torrent(torrent_handle^ handle, int options);
        session_settings^ settings();
        void set_settings(session_settings^ settings);
        // TODO get pe settings
        // TODO set pe settings
        // TODO set proxy
        // TODO proxy
        // TODO i2p proxy
        // TODO set i2p proxy
        // TODO pop alerts
        // TODO pop alert
        // TODO wait for alert
        void set_alert_mask(unsigned int mask);
        void set_alert_dispatch(System::Action<alert^>^ dispatch);
        void clear_alert_dispatch();
        void stop_lsd();
        void start_lsd();
        void stop_upnp();
        void start_upnp();
        void delete_port_mapping(int handle);
        // TODO add port mapping
        void stop_natpmp();
        void start_natpmp();

    private:
        session_alert_dispatcher* dispatcher_;
        libtorrent::session* session_;
    };
}
