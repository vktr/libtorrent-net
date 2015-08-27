#include "session_status.h"

#include <libtorrent/session_status.hpp>

#define SESS_PROP(type, name) \
    type session_status::name::get() \
    { \
        return status_->name; \
    }

using namespace lt;

session_status::session_status(libtorrent::session_status& status)
{
    status_ = new libtorrent::session_status(status);
}

session_status::~session_status()
{
    delete status_;
}

SESS_PROP(bool, has_incoming_connections);
SESS_PROP(int, upload_rate);
SESS_PROP(int, download_rate);
SESS_PROP(long long, total_download);
SESS_PROP(long long, total_upload);
SESS_PROP(int, payload_upload_rate);
SESS_PROP(int, payload_download_rate);
SESS_PROP(long long, total_payload_download);
SESS_PROP(long long, total_payload_upload);
SESS_PROP(int, ip_overhead_upload_rate);
SESS_PROP(int, ip_overhead_download_rate);
SESS_PROP(long long, total_ip_overhead_download);
SESS_PROP(long long, total_ip_overhead_upload);
SESS_PROP(int, dht_upload_rate);
SESS_PROP(int, dht_download_rate);
SESS_PROP(long long, total_dht_download);
SESS_PROP(long long, total_dht_upload);
SESS_PROP(int, tracker_upload_rate);
SESS_PROP(int, tracker_download_rate);
SESS_PROP(long long, total_tracker_download);
SESS_PROP(long long, total_tracker_upload);
SESS_PROP(long long, total_redundant_bytes);
SESS_PROP(long long, total_failed_bytes);
SESS_PROP(int, num_peers);
SESS_PROP(int, num_unchoked);
SESS_PROP(int, allowed_upload_slots);
SESS_PROP(int, up_bandwidth_queue);
SESS_PROP(int, down_bandwidth_queue);
SESS_PROP(int, up_bandwidth_bytes_queue);
SESS_PROP(int, down_bandwidth_bytes_queue);
SESS_PROP(int, optimistic_unchoke_counter);
SESS_PROP(int, unchoke_counter);
SESS_PROP(int, disk_write_queue);
SESS_PROP(int, disk_read_queue);
SESS_PROP(int, dht_nodes);
SESS_PROP(int, dht_node_cache);
SESS_PROP(int, dht_torrents);
SESS_PROP(long long, dht_global_nodes);
SESS_PROP(int, dht_total_allocations);
SESS_PROP(int, peerlist_size);
