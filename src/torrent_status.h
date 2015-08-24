#pragma once

namespace libtorrent
{
    struct torrent_handle;
    struct torrent_status;
}

namespace lt
{
    public ref class torrent_status
    {
    internal:
        torrent_status(libtorrent::torrent_status& status);

    public:
        ~torrent_status();

        // TODO handle

        property System::String^ error { System::String^ get(); }
        property System::String^ save_path { System::String^ get(); }
        property System::String^ name { System::String^ get(); }
        // TODO torrent file
        property System::TimeSpan next_announce { System::TimeSpan get(); }
        property System::TimeSpan announce_interval { System::TimeSpan get(); }
        property System::String^ current_tracker { System::String^ get(); }
        property long long total_download { long long get(); }
        property long long total_upload { long long get(); }
        property long long total_payload_download { long long get(); }
        property long long total_payload_upload { long long get(); }
        property long long total_failed_bytes { long long get(); }
        property long long total_reduntant_bytes { long long get(); }
        // TODO pieces
        // TODO verified pieces
        property long long total_done { long long get(); }
        property long long total_wanted_done { long long get(); }
        property long long total_wanted { long long get(); }
        property long long all_time_upload { long long get(); }
        property long long all_time_download { long long get(); }
        property System::DateTime added_time { System::DateTime get(); }
        property System::DateTime completed_time { System::DateTime get(); }
        property System::DateTime last_seen_complete { System::DateTime get(); }
        // TODO storage mode
        property float progress { float get(); }
        property int progress_ppm { int get(); }
        property int queue_position { int get(); }
        property int download_rate { int get(); }
        property int upload_rate { int get(); }
        property int download_payload_rate { int get(); }
        property int upload_payload_rate { int get(); }
        property int num_seeds { int get(); }
        property int num_peers { int get(); }
        property int num_complete { int get(); }
        property int num_incomplete { int get(); }
        property int list_seeds { int get(); }
        property int list_peers { int get(); }
        property int connect_candidates { int get(); }
        property int num_pieces { int get(); }
        property int distributed_full_copies { int get(); }
        property int distributed_fraction { int get(); }
        property float distributed_copies { float get(); }
        property int block_size { int get(); }
        property int num_uploads { int get(); }
        property int num_connections { int get(); }
        property int uploads_limit { int get(); }
        property int connections_limit { int get(); }
        property int up_bandwidth_queue { int get(); }
        property int down_bandwidth_queue { int get(); }
        property int time_since_upload { int get(); }
        property int time_since_download { int get(); }
        property int active_time { int get(); }
        property int finished_time { int get(); }
        property int seeding_time { int get(); }
        property int seed_rank { int get(); }
        property int last_scrape { int get(); }
        property int sparse_regions { int get(); }
        property int priority { int get(); }
        // TODO state
        property bool need_save_resume { bool get(); }
        property bool ip_filter_applies { bool get(); }
        property bool upload_mode { bool get(); }
        property bool share_mode { bool get(); }
        property bool super_seeding { bool get(); }
        property bool paused { bool get(); }
        property bool auto_managed { bool get(); }
        property bool sequential_download { bool get(); }
        property bool is_seeding { bool get(); }
        property bool is_finished { bool get(); }
        property bool has_metadata { bool get(); }
        property bool has_incoming { bool get(); }
        property bool seed_mode { bool get(); }
        property bool moving_storage { bool get(); }
        // TODO info hash

    private:
        libtorrent::torrent_status* status_;
    };
}
