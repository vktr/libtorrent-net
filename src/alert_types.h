#pragma once

#include "alert.h"

namespace libtorrent
{
    struct torrent_alert;
    struct peer_alert;
    struct tracker_alert;
    struct torrent_added_alert;
    struct torrent_removed_alert;
    struct read_piece_alert;
    struct file_completed_alert;
    struct file_renamed_alert;
    struct file_rename_failed_alert;
    struct performance_alert;
    struct state_changed_alert;
    struct tracker_error_alert;
    struct tracker_warning_alert;
    struct scrape_reply_alert;
    struct scrape_failed_alert;
    struct tracker_reply_alert;
    struct dht_reply_alert;
    struct tracker_announce_alert;
    struct hash_failed_alert;
    struct peer_ban_alert;
    struct peer_unsnubbed_alert;
    struct peer_snubbed_alert;
    struct peer_error_alert;
    struct peer_connect_alert;
    struct peer_disconnected_alert;
    struct invalid_request_alert;
    struct torrent_finished_alert;
    struct piece_finished_alert;
    struct request_dropped_alert;
    struct block_timeout_alert;
    struct block_finished_alert;
    struct block_downloading_alert;
    struct unwanted_block_alert;
    struct storage_moved_alert;
    struct storage_moved_failed_alert;
    struct torrent_deleted_alert;
    struct torrent_delete_failed_alert;
    struct save_resume_data_alert;
    struct save_resume_data_failed_alert;
    struct torrent_paused_alert;
    struct torrent_resumed_alert;
    struct torrent_checked_alert;
    struct url_seed_alert;
    struct file_error_alert;
    struct metadata_failed_alert;
    struct metadata_received_alert;
    struct udp_error_alert;
    struct external_ip_alert;
    struct listen_failed_alert;
    struct listen_succeeded_alert;
    struct portmap_error_alert;
    struct portmap_alert;
    struct portmap_log_alert;
    struct fastresume_rejected_alert;
    struct peer_blocked_alert;
    struct dht_announce_alert;
    struct dht_get_peers_alert;
    struct stats_alert;
    struct cache_flushed_alert;
    struct anonymous_mode_alert;
    struct lsd_peer_alert;
    struct trackerid_alert;
    struct dht_bootstrap_alert;
    // struct rsss
    struct torrent_error_alert;
    struct torrent_need_cert_alert;
    struct incoming_connection_alert;
    struct add_torrent_alert;
    struct state_update_alert;
    struct torrent_update_alert;
    // struct rss item alert
    struct dht_error_alert;
    struct dht_immutable_item_alert;
    struct dht_mutable_item_alert;
    struct dht_put_alert;
    struct i2p_alert;
}

namespace lt
{
    ref class torrent_handle;

    public ref class torrent_alert : alert
    {
    public:
        torrent_alert(libtorrent::torrent_alert* alert);

        property torrent_handle^ handle
        {
            torrent_handle^ get();
        }

    private:
        torrent_handle^ handle_;
    };

    ///<summary>
    ///The torrent_added_alert is posted once every time a torrent is
    ///successfully added. It doesn't contain any members of its own, 
    ///ut inherits the torrent handle from its base class. It's posted
    ///when the status_notification bit is set in the alert_mask.
    ///</summary>
    public ref class torrent_added_alert : torrent_alert
    {
    public:
        torrent_added_alert(libtorrent::torrent_added_alert* alert);
    };

    ///<summary>
    ///The torrent_removed_alert is posted whenever a torrent is removed.
    ///Since the torrent handle in its baseclass will always be invalid (since
    ///the torrent is already removed) it has the info hash as a member, to
    ///identify it. It's posted when the status_notification bit is set in the
    ///alert_mask.
    ///</summary>
    public ref class torrent_removed_alert : torrent_alert
    {
    public:
        torrent_removed_alert(libtorrent::torrent_removed_alert* alert);
    };

    ///<summary>
    ///This alert is posted when the asynchronous read operation initiated by a
    ///call to torrent_handle::read_piece() is completed. If the read failed,
    ///the torrent is paused and an error state is set and the buffer member of
    ///the alert is 0. If successful, buffer points to a buffer containing all
    ///the data of the piece. piece is the piece index that was read. size is
    ///the number of bytes that was read.
    ///</summary>
    public ref class read_piece_alert : torrent_alert
    {
    public:
        read_piece_alert(libtorrent::read_piece_alert* alert);

        property cli::array<System::Byte>^ buffer
        {
            cli::array<System::Byte>^ get();
        }

        property int piece { int get(); }

        property int size { int get(); }

    private:
        libtorrent::read_piece_alert* alert_;
    };

    ///<summary>
    ///This is posted whenever an individual file completes its download. i.e.
    ///All pieces overlapping this file have passed their hash check.
    ///</summary>
    public ref class file_completed_alert : torrent_alert
    {
    public:
        file_completed_alert(libtorrent::file_completed_alert* alert);

        ///<summary>The index of the file that completed.</summary>
        property int index { int get(); }

    private:
        libtorrent::file_completed_alert* alert_;
    };

    ///<summary>
    ///This is posted as a response to a torrent_handle::rename_file() call, 
    ///if the rename operation succeeds.
    ///</summary>
    public ref class file_renamed_alert : torrent_alert
    {
    public:
        file_renamed_alert(libtorrent::file_renamed_alert* alert);

        ///<summary>The new name of the file.</summary>
        property System::String^ name { System::String^ get(); }

        ///<summary>The index of the file that was renamed.</summary>
        property int index { int get(); }

    private:
        libtorrent::file_renamed_alert* alert_;
    };

    ///<summary>
    ///This is posted as a response to a torrent_handle::rename_file() call,
    ///if the rename operation failed.
    ///</summary>
    public ref class file_rename_failed_alert : torrent_alert
    {
    public:
        file_rename_failed_alert(libtorrent::file_rename_failed_alert* alert);

        ///<summary>The index of the file that was supposed to be renamed.</summary>
        property int index { int get(); }

        // TODO error code

    private:
        libtorrent::file_rename_failed_alert* alert_;
    };

    ///<summary>
    ///This alert is generated when a limit is reached that might have a
    ///negative impact on upload or download rate performance.
    ///</summary>
    public ref class performance_alert : torrent_alert
    {
    public:
        performance_alert(libtorrent::performance_alert* alert);

        property int warning_code { int get(); } // TODO enum

    private:
        libtorrent::performance_alert* alert_;
    };
}
