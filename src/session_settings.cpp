#include "session_settings.h"

#include <libtorrent/session_settings.hpp>

#include "interop.h"

#define SS_PROP_IMPL(type, name) \
    type session_settings::name::get() \
    { \
        return settings_->name; \
    } \
    void session_settings::name::set(type val) \
    { \
        settings_->name = val; \
    }

using namespace lt;

session_settings::session_settings(libtorrent::session_settings& settings)
{
    settings_ = new libtorrent::session_settings(settings);
}

session_settings::~session_settings()
{
    delete settings_;
}

libtorrent::session_settings& session_settings::ptr()
{
    return *settings_;
}

SS_PROP_IMPL(int, version);

System::String^ session_settings::user_agent::get()
{
    return interop::from_std_string(settings_->user_agent);
}

void session_settings::user_agent::set(System::String^ val)
{
    settings_->user_agent = interop::to_std_string(val);
}

SS_PROP_IMPL(int, tracker_completion_timeout);
SS_PROP_IMPL(int, tracker_receive_timeout);
SS_PROP_IMPL(int, stop_tracker_timeout);
SS_PROP_IMPL(int, tracker_maximum_response_length);
SS_PROP_IMPL(int, piece_timeout);
SS_PROP_IMPL(int, request_timeout);
SS_PROP_IMPL(int, request_queue_time);
SS_PROP_IMPL(int, max_allowed_in_request_queue);
SS_PROP_IMPL(int, max_out_request_queue);
SS_PROP_IMPL(int, whole_pieces_threshold);
SS_PROP_IMPL(int, peer_timeout);
SS_PROP_IMPL(int, urlseed_timeout);
SS_PROP_IMPL(int, urlseed_pipeline_size);
SS_PROP_IMPL(int, urlseed_wait_retry);
SS_PROP_IMPL(int, file_pool_size);
SS_PROP_IMPL(bool, allow_multiple_connections_per_ip);
SS_PROP_IMPL(int, max_failcount);
SS_PROP_IMPL(int, min_reconnect_time);
SS_PROP_IMPL(int, peer_connect_timeout);
SS_PROP_IMPL(bool, ignore_limits_on_local_network);
SS_PROP_IMPL(int, connection_speed);
SS_PROP_IMPL(bool, send_redundant_have);
SS_PROP_IMPL(bool, lazy_bitfields);
SS_PROP_IMPL(int, inactivity_timeout);
SS_PROP_IMPL(int, unchoke_interval);

System::String^ session_settings::announce_ip::get()
{
    return interop::from_std_string(settings_->announce_ip);
}

void session_settings::announce_ip::set(System::String^ val)
{
    settings_->announce_ip = interop::to_std_string(val);
}

SS_PROP_IMPL(int, num_want);
SS_PROP_IMPL(int, initial_picker_threshold);
SS_PROP_IMPL(int, allowed_fast_set_size);
SS_PROP_IMPL(int, suggest_mode);
SS_PROP_IMPL(int, max_queued_disk_bytes);
SS_PROP_IMPL(int, max_queued_disk_bytes_low_watermark);
SS_PROP_IMPL(int, handshake_timeout);
SS_PROP_IMPL(bool, use_dht_as_fallback);
SS_PROP_IMPL(bool, free_torrent_hashes);
SS_PROP_IMPL(bool, upnp_ignore_nonrouters);
SS_PROP_IMPL(int, send_buffer_low_watermark);
SS_PROP_IMPL(int, send_buffer_watermark);
SS_PROP_IMPL(int, send_buffer_watermark_factor);
SS_PROP_IMPL(int, choking_algorithm);
SS_PROP_IMPL(int, seed_choking_algorithm);
SS_PROP_IMPL(bool, use_parole_mode);
SS_PROP_IMPL(int, cache_size);
SS_PROP_IMPL(int, cache_buffer_chunk_size);
SS_PROP_IMPL(int, cache_expiry);
SS_PROP_IMPL(bool, use_read_cache);
SS_PROP_IMPL(bool, explicit_read_cache);
SS_PROP_IMPL(int, explicit_cache_interval);
SS_PROP_IMPL(int, disk_io_write_mode);
SS_PROP_IMPL(int, disk_io_read_mode);
SS_PROP_IMPL(bool, coalesce_reads);
SS_PROP_IMPL(bool, coalesce_writes);
// TODO outgoing ports
// TODO peer tos
SS_PROP_IMPL(int, active_downloads);
SS_PROP_IMPL(int, active_seeds);
SS_PROP_IMPL(int, active_dht_limit);
SS_PROP_IMPL(int, active_tracker_limit);
SS_PROP_IMPL(int, active_lsd_limit);
SS_PROP_IMPL(int, active_limit);
SS_PROP_IMPL(bool, auto_manage_prefer_seeds);
SS_PROP_IMPL(bool, dont_count_slow_torrents);
SS_PROP_IMPL(int, auto_manage_interval);
SS_PROP_IMPL(float, share_ratio_limit);
SS_PROP_IMPL(float, seed_time_ratio_limit);
SS_PROP_IMPL(int, seed_time_limit);
SS_PROP_IMPL(int, peer_turnover_interval);
SS_PROP_IMPL(float, peer_turnover);
SS_PROP_IMPL(float, peer_turnover_cutoff);
SS_PROP_IMPL(bool, close_redundant_connections);
SS_PROP_IMPL(int, auto_scrape_interval);
SS_PROP_IMPL(int, auto_scrape_min_interval);
SS_PROP_IMPL(int, max_peerlist_size);
SS_PROP_IMPL(int, max_paused_peerlist_size);
SS_PROP_IMPL(int, min_announce_interval);
SS_PROP_IMPL(bool, prioritize_partial_pieces);
SS_PROP_IMPL(int, auto_manage_startup);
SS_PROP_IMPL(bool, rate_limit_ip_overhead);
SS_PROP_IMPL(bool, announce_to_all_trackers);
SS_PROP_IMPL(bool, announce_to_all_tiers);
SS_PROP_IMPL(bool, prefer_udp_trackers);
SS_PROP_IMPL(bool, strict_super_seeding);
SS_PROP_IMPL(int, seeding_piece_quota);
SS_PROP_IMPL(int, max_sparse_regions);
SS_PROP_IMPL(bool, lock_disk_cache);
SS_PROP_IMPL(int, max_rejects);
SS_PROP_IMPL(int, recv_socket_buffer_size);
SS_PROP_IMPL(int, send_socket_buffer_size);
SS_PROP_IMPL(bool, optimize_hashing_for_speed);
SS_PROP_IMPL(int, file_checks_delay_per_block);
// TODO disk cache algo
SS_PROP_IMPL(int, read_cache_line_size);
SS_PROP_IMPL(int, write_cache_line_size);
SS_PROP_IMPL(int, optimistic_disk_retry);
SS_PROP_IMPL(bool, disable_hash_checks);
SS_PROP_IMPL(bool, allow_reordered_disk_operations);
SS_PROP_IMPL(bool, allow_i2p_mixed);
SS_PROP_IMPL(int, max_suggest_pieces);
SS_PROP_IMPL(bool, drop_skipped_requests);
SS_PROP_IMPL(bool, low_prio_disk);
SS_PROP_IMPL(int, local_service_announce_interval);
SS_PROP_IMPL(int, dht_announce_interval);
SS_PROP_IMPL(int, udp_tracker_token_expiry);
SS_PROP_IMPL(bool, volatile_read_cache);
SS_PROP_IMPL(bool, guided_read_cache);
SS_PROP_IMPL(int, default_cache_min_age);
SS_PROP_IMPL(int, num_optimistic_unchoke_slots);
SS_PROP_IMPL(bool, no_atime_storage);
SS_PROP_IMPL(int, default_est_reciprocation_rate);
SS_PROP_IMPL(int, increase_est_reciprocation_rate);
SS_PROP_IMPL(int, decrease_est_reciprocation_rate);
SS_PROP_IMPL(bool, incoming_starts_queued_torrents);
SS_PROP_IMPL(bool, report_true_downloaded);
SS_PROP_IMPL(bool, strict_end_game_mode);
SS_PROP_IMPL(bool, broadcast_lsd);
SS_PROP_IMPL(bool, enable_outgoing_utp);
SS_PROP_IMPL(bool, enable_incoming_utp);
SS_PROP_IMPL(bool, enable_outgoing_tcp);
SS_PROP_IMPL(bool, enable_incoming_tcp);
SS_PROP_IMPL(int, max_pex_peers);
SS_PROP_IMPL(bool, ignore_resume_timestamps);
SS_PROP_IMPL(bool, no_recheck_incomplete_resume);
SS_PROP_IMPL(bool, anonymous_mode);
SS_PROP_IMPL(bool, force_proxy);
SS_PROP_IMPL(int, tick_interval);
SS_PROP_IMPL(bool, report_web_seed_downloads);
SS_PROP_IMPL(int, share_mode_target);
SS_PROP_IMPL(int, upload_rate_limit);
SS_PROP_IMPL(int, download_rate_limit);
SS_PROP_IMPL(int, local_upload_rate_limit);
SS_PROP_IMPL(int, local_download_rate_limit);
SS_PROP_IMPL(int, dht_upload_rate_limit);
SS_PROP_IMPL(int, unchoke_slots_limit);
SS_PROP_IMPL(int, half_open_limit);
SS_PROP_IMPL(int, connections_limit);
SS_PROP_IMPL(int, connections_slack);
SS_PROP_IMPL(int, utp_target_delay);
SS_PROP_IMPL(int, utp_gain_factor);
SS_PROP_IMPL(int, utp_min_timeout);
SS_PROP_IMPL(int, utp_syn_resends);
SS_PROP_IMPL(int, utp_fin_resends);
SS_PROP_IMPL(int, utp_num_resends);
SS_PROP_IMPL(int, utp_connect_timeout);
SS_PROP_IMPL(bool, utp_dynamic_sock_buf);
SS_PROP_IMPL(int, utp_loss_multiplier);
SS_PROP_IMPL(int, mixed_mode_algorithm);
SS_PROP_IMPL(bool, rate_limit_utp);
SS_PROP_IMPL(int, listen_queue_size);
SS_PROP_IMPL(bool, announce_double_nat);
SS_PROP_IMPL(int, torrent_connect_boost);
SS_PROP_IMPL(bool, seeding_outgoing_connections);
SS_PROP_IMPL(bool, no_connect_privileged_ports);
SS_PROP_IMPL(int, alert_queue_size);
SS_PROP_IMPL(int, max_metadata_size);
SS_PROP_IMPL(bool, smooth_connects);
SS_PROP_IMPL(bool, always_send_user_agent);
SS_PROP_IMPL(bool, apply_ip_filter_to_trackers);
SS_PROP_IMPL(int, read_job_every);
SS_PROP_IMPL(bool, use_disk_read_ahead);
SS_PROP_IMPL(bool, lock_files);
SS_PROP_IMPL(int, ssl_listen);
SS_PROP_IMPL(int, tracker_backoff);
SS_PROP_IMPL(bool, ban_web_seeds);
SS_PROP_IMPL(int, max_http_recv_buffer_size);
SS_PROP_IMPL(bool, support_share_mode);
SS_PROP_IMPL(bool, support_merkle_torrents);
SS_PROP_IMPL(bool, report_redundant_bytes);

System::String^ session_settings::handshake_client_version::get()
{
    return interop::from_std_string(settings_->handshake_client_version);
}

void session_settings::handshake_client_version::set(System::String^ val)
{
    settings_->handshake_client_version = interop::to_std_string(val);
}

SS_PROP_IMPL(bool, use_disk_cache_pool);
SS_PROP_IMPL(int, inactive_down_rate);
SS_PROP_IMPL(int, inactive_up_rate);
