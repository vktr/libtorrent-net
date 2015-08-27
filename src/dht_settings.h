#pragma once

#define DS_PROP(type, name) \
    property type name { type get(); void set(type val); }

namespace libtorrent
{
    struct dht_settings;
}

namespace lt
{
    public ref class dht_settings
    {
    internal:
        dht_settings(libtorrent::dht_settings& settings);
        libtorrent::dht_settings& ptr();

    public:
        ~dht_settings();

        DS_PROP(int, max_peers_reply);
        DS_PROP(int, search_branching);
        DS_PROP(int, max_fail_count);
        DS_PROP(int, max_torrents);
        DS_PROP(int, max_dht_items);
        DS_PROP(int, max_torrent_search_reply);
        DS_PROP(bool, restrict_routing_ips);
        DS_PROP(bool, restrict_search_ips);
        DS_PROP(bool, extended_routing_table);
        DS_PROP(bool, aggressive_lookups);
        DS_PROP(bool, privacy_lookups);
        DS_PROP(bool, enforce_node_id);
        DS_PROP(bool, ignore_dark_internet);

    internal:
        libtorrent::dht_settings* settings_;
    };
}
