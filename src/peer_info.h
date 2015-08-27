#pragma once

namespace libtorrent
{
    struct peer_info;
}

namespace lt
{
    public ref class peer_info
    {
    internal:
        peer_info(libtorrent::peer_info& info);

    public:
        ~peer_info();

        property unsigned int flags { unsigned int get(); }
        property int source { int get(); }
        // TODO read_state
        // TODO write_state
        // TODO ip
        property int up_speed { int get(); }
        property int down_speed { int get(); }
        property int payload_up_speed { int get(); }
        property int payload_down_speed { int get(); }
        property long long total_download { long long get(); }
        property long long total_upload { long long get(); }
        // TODO pid
        // TODO pieces
        property int upload_limit { int get(); }
        property int download_limit { int get(); }
        property System::TimeSpan last_request { System::TimeSpan get(); }
        property System::TimeSpan last_active { System::TimeSpan get(); }
        property System::TimeSpan download_queue_time { System::TimeSpan get(); }
        property int queue_bytes { int get(); }
        property int request_timeout { int get(); }
        property int send_buffer_size { int get(); }
        property int used_send_buffer { int get(); }
        property int receive_buffer_size { int get(); }
        property int used_receive_buffer { int get(); }
        property int num_hashfails { int get(); }
        property System::String^ country { System::String^ get(); }
        property System::String^ inet_as_name { System::String^ get(); }
        property int inet_as { int get(); }
        property int download_queue_length { int get(); }
        property int timed_out_requests { int get(); }
        property int busy_requests { int get(); }
        property int requests_in_buffer { int get(); }
        property int target_dl_queue_length { int get(); }
        property int upload_queue_length { int get(); }
        property int failcount { int get(); }
        property int downloading_piece_index { int get(); }
        property int downloading_block_index { int get(); }
        property int downloading_progress { int get(); }
        property int downloading_total { int get(); }
        property System::String^ client { System::String^ get(); }
        property int connection_type { int get(); }
        property int remote_dl_rate { int get(); }
        property int pending_disk_bytes { int get(); }
        property int send_quota { int get(); }
        property int receive_quota { int get(); }
        property int rtt { int get(); }
        property int num_pieces { int get(); }
        property int download_rate_peak { int get(); }
        property int upload_rate_peak { int get(); }
        property int progress_ppm { int get(); }
        property int estimated_reciprocation_rate { int get(); }
        // TODO local_endpoint

    private:
        libtorrent::peer_info* info_;
    };
}
