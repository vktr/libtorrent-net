#pragma once

namespace libtorrent
{
    struct session_status;
}

namespace lt
{
    public ref class session_status
    {
    internal:
        session_status(libtorrent::session_status& status);

    public:
        ~session_status();

        property bool has_incoming_connections { bool get(); }
        property int upload_rate { int get(); }
        property int download_rate { int get(); }
        property long long total_download { long long get(); }
        property long long total_upload { long long get(); }
        property int payload_upload_rate { int get(); }
        property int payload_download_rate { int get(); }
        property long long total_payload_download { long long get(); }
        property long long total_payload_upload { long long get(); }
        property int ip_overhead_upload_rate { int get(); }
        property int ip_overhead_download_rate { int get(); }
        property long long total_ip_overhead_download { long long get(); }
        property long long total_ip_overhead_upload { long long get(); }
        property int dht_upload_rate { int get(); }
        property int dht_download_rate { int get(); }
        property long long total_dht_download { long long get(); }
        property long long total_dht_upload { long long get(); }
        property int tracker_upload_rate { int get(); }
        property int tracker_download_rate { int get(); }
        property long long total_tracker_download { long long get(); }
        property long long total_tracker_upload { long long get(); }
        property long long total_redundant_bytes { long long get(); }
        property long long total_failed_bytes { long long get(); }
        property int num_peers { int get(); }
        property int num_unchoked { int get(); }
        property int allowed_upload_slots { int get(); }
        property int up_bandwidth_queue { int get(); }
        property int down_bandwidth_queue { int get(); }
        property int up_bandwidth_bytes_queue { int get(); }
        property int down_bandwidth_bytes_queue { int get(); }
        property int optimistic_unchoke_counter { int get(); }
        property int unchoke_counter { int get(); }
        property int disk_write_queue { int get(); }
        property int disk_read_queue { int get(); }
        property int dht_nodes { int get(); }
        property int dht_node_cache { int get(); }
        property int dht_torrents { int get(); }
        property long long dht_global_nodes { long long get(); }
        // TODO active requests
        // TODO dht_routing_Table
        property int dht_total_allocations { int get(); }
        // TODO utp stats
        property int peerlist_size { int get(); }

    private:
        libtorrent::session_status* status_;
    };
}
