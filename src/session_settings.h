#pragma once

#define SS_PROP(type, name) \
    property type name { type get(); void set(type val); }

namespace libtorrent
{
    struct session_settings;
}

namespace lt
{
    public ref class session_settings
    {
    internal:
        session_settings(libtorrent::session_settings& settings);
        libtorrent::session_settings& ptr();

    public:
        ~session_settings();

        SS_PROP(int, version);
        SS_PROP(System::String^, user_agent);
        SS_PROP(int, tracker_completion_timeout);
        SS_PROP(int, tracker_receive_timeout);
        SS_PROP(int, stop_tracker_timeout);
        SS_PROP(int, tracker_maximum_response_length);
        SS_PROP(int, piece_timeout);
        SS_PROP(int, request_timeout);
        SS_PROP(int, request_queue_time);
        SS_PROP(int, max_allowed_in_request_queue);
        SS_PROP(int, max_out_request_queue);
        SS_PROP(int, whole_pieces_threshold);
        SS_PROP(int, peer_timeout);
        SS_PROP(int, urlseed_timeout);
        SS_PROP(int, urlseed_pipeline_size);
        SS_PROP(int, urlseed_wait_retry);
        SS_PROP(int, file_pool_size);
        SS_PROP(bool, allow_multiple_connections_per_ip);
        SS_PROP(int, max_failcount);
        SS_PROP(int, min_reconnect_time);
        SS_PROP(int, peer_connect_timeout);
        SS_PROP(bool, ignore_limits_on_local_network);
        SS_PROP(int, connection_speed);
        SS_PROP(bool, send_redundant_have);
        SS_PROP(bool, lazy_bitfields);
        SS_PROP(int, inactivity_timeout);
        SS_PROP(int, unchoke_interval);
        SS_PROP(System::String^, announce_ip);
        SS_PROP(int, num_want);
        SS_PROP(int, initial_picker_threshold);
        SS_PROP(int, allowed_fast_set_size);
        SS_PROP(int, suggest_mode);
        SS_PROP(int, max_queued_disk_bytes);
        SS_PROP(int, max_queued_disk_bytes_low_watermark);
        SS_PROP(int, handshake_timeout);
        SS_PROP(bool, use_dht_as_fallback);
        SS_PROP(bool, free_torrent_hashes);
        SS_PROP(bool, upnp_ignore_nonrouters);
        SS_PROP(int, send_buffer_low_watermark);
        SS_PROP(int, send_buffer_watermark);
        SS_PROP(int, send_buffer_watermark_factor);
        SS_PROP(int, choking_algorithm);
        SS_PROP(int, seed_choking_algorithm);
        SS_PROP(bool, use_parole_mode);
        SS_PROP(int, cache_size);
        SS_PROP(int, cache_buffer_chunk_size);
        SS_PROP(int, cache_expiry);
        SS_PROP(bool, use_read_cache);
        SS_PROP(bool, explicit_read_cache);
        SS_PROP(int, explicit_cache_interval);
        SS_PROP(int, disk_io_write_mode);
        SS_PROP(int, disk_io_read_mode);
        SS_PROP(bool, coalesce_reads);
        SS_PROP(bool, coalesce_writes);
        // TODO outgoing ports
        // TODO peer tos
        SS_PROP(int, active_downloads);
        SS_PROP(int, active_seeds);
        SS_PROP(int, active_dht_limit);
        SS_PROP(int, active_tracker_limit);
        SS_PROP(int, active_lsd_limit);
        SS_PROP(int, active_limit);
        SS_PROP(bool, auto_manage_prefer_seeds);
        SS_PROP(bool, dont_count_slow_torrents);
        SS_PROP(int, auto_manage_interval);
        SS_PROP(float, share_ratio_limit);
        SS_PROP(float, seed_time_ratio_limit);
        SS_PROP(int, seed_time_limit);
        SS_PROP(int, peer_turnover_interval);
        SS_PROP(float, peer_turnover);
        SS_PROP(float, peer_turnover_cutoff);
        SS_PROP(bool, close_redundant_connections);
        SS_PROP(int, auto_scrape_interval);
        SS_PROP(int, auto_scrape_min_interval);
        SS_PROP(int, max_peerlist_size);
        SS_PROP(int, max_paused_peerlist_size);
        SS_PROP(int, min_announce_interval);
        SS_PROP(bool, prioritize_partial_pieces);
        SS_PROP(int, auto_manage_startup);
        SS_PROP(bool, rate_limit_ip_overhead);
        SS_PROP(bool, announce_to_all_trackers);
        SS_PROP(bool, announce_to_all_tiers);
        SS_PROP(bool, prefer_udp_trackers);
        SS_PROP(bool, strict_super_seeding);
        SS_PROP(int, seeding_piece_quota);
        SS_PROP(int, max_sparse_regions);
        SS_PROP(bool, lock_disk_cache);
        SS_PROP(int, max_rejects);
        SS_PROP(int, recv_socket_buffer_size);
        SS_PROP(int, send_socket_buffer_size);
        SS_PROP(bool, optimize_hashing_for_speed);
        SS_PROP(int, file_checks_delay_per_block);
        // TODO disk cache algo
        SS_PROP(int, read_cache_line_size);
        SS_PROP(int, write_cache_line_size);
        SS_PROP(int, optimistic_disk_retry);
        SS_PROP(bool, disable_hash_checks);
        SS_PROP(bool, allow_reordered_disk_operations);
        SS_PROP(bool, allow_i2p_mixed);
        SS_PROP(int, max_suggest_pieces);
        SS_PROP(bool, drop_skipped_requests);
        SS_PROP(bool, low_prio_disk);
        SS_PROP(int, local_service_announce_interval);
        SS_PROP(int, dht_announce_interval);
        SS_PROP(int, udp_tracker_token_expiry);
        SS_PROP(bool, volatile_read_cache);
        SS_PROP(bool, guided_read_cache);
        SS_PROP(int, default_cache_min_age);
        SS_PROP(int, num_optimistic_unchoke_slots);
        SS_PROP(bool, no_atime_storage);
        SS_PROP(int, default_est_reciprocation_rate);
        SS_PROP(int, increase_est_reciprocation_rate);
        SS_PROP(int, decrease_est_reciprocation_rate);
        SS_PROP(bool, incoming_starts_queued_torrents);
        SS_PROP(bool, report_true_downloaded);
        SS_PROP(bool, strict_end_game_mode);
        SS_PROP(bool, broadcast_lsd);
        SS_PROP(bool, enable_outgoing_utp);
        SS_PROP(bool, enable_incoming_utp);
        SS_PROP(bool, enable_outgoing_tcp);
        SS_PROP(bool, enable_incoming_tcp);
        SS_PROP(int, max_pex_peers);
        SS_PROP(bool, ignore_resume_timestamps);
        SS_PROP(bool, no_recheck_incomplete_resume);
        SS_PROP(bool, anonymous_mode);
        SS_PROP(bool, force_proxy);
        SS_PROP(int, tick_interval);
        SS_PROP(bool, report_web_seed_downloads);
        SS_PROP(int, share_mode_target);
        SS_PROP(int, upload_rate_limit);
        SS_PROP(int, download_rate_limit);
        SS_PROP(int, local_upload_rate_limit);
        SS_PROP(int, local_download_rate_limit);
        SS_PROP(int, dht_upload_rate_limit);
        SS_PROP(int, unchoke_slots_limit);
        SS_PROP(int, half_open_limit);
        SS_PROP(int, connections_limit);
        SS_PROP(int, connections_slack);
        SS_PROP(int, utp_target_delay);
        SS_PROP(int, utp_gain_factor);
        SS_PROP(int, utp_min_timeout);
        SS_PROP(int, utp_syn_resends);
        SS_PROP(int, utp_fin_resends);
        SS_PROP(int, utp_num_resends);
        SS_PROP(int, utp_connect_timeout);
        SS_PROP(bool, utp_dynamic_sock_buf);
        SS_PROP(int, utp_loss_multiplier);
        SS_PROP(int, mixed_mode_algorithm);
        SS_PROP(bool, rate_limit_utp);
        SS_PROP(int, listen_queue_size);
        SS_PROP(bool, announce_double_nat);
        SS_PROP(int, torrent_connect_boost);
        SS_PROP(bool, seeding_outgoing_connections);
        SS_PROP(bool, no_connect_privileged_ports);
        SS_PROP(int, alert_queue_size);
        SS_PROP(int, max_metadata_size);
        SS_PROP(bool, smooth_connects);
        SS_PROP(bool, always_send_user_agent);
        SS_PROP(bool, apply_ip_filter_to_trackers);
        SS_PROP(int, read_job_every);
        SS_PROP(bool, use_disk_read_ahead);
        SS_PROP(bool, lock_files);
        SS_PROP(int, ssl_listen);
        SS_PROP(int, tracker_backoff);
        SS_PROP(bool, ban_web_seeds);
        SS_PROP(int, max_http_recv_buffer_size);
        SS_PROP(bool, support_share_mode);
        SS_PROP(bool, support_merkle_torrents);
        SS_PROP(bool, report_redundant_bytes);
        SS_PROP(System::String^, handshake_client_version);
        SS_PROP(bool, use_disk_cache_pool);
        SS_PROP(int, inactive_down_rate);
        SS_PROP(int, inactive_up_rate);

    private:
        libtorrent::session_settings* settings_;
    };
}
