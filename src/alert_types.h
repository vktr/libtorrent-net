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
    ref class entry;
    ref class torrent_handle;

    /// <summary>
    /// This is a base class for alerts that are associated with a specific
    /// torrent. It contains a handle to the torrent.
    /// </summary>
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

    /// <summary>
    /// The peer alert is a base class for alerts that refer to a specific
    /// peer. It includes all the information to identify the peer. i.e. ip and
    /// peer-id.
    /// </summary>
    public ref class peer_alert : torrent_alert
    {
    public:
        peer_alert(libtorrent::peer_alert* alert);

        // TODO ip
        // TODO peer_id
    };

    /// <summary>
    /// This is a base class used for alerts that are associated with a
    /// specific tracker. It derives from torrent_alert since a tracker is also
    /// associated with a specific torrent.
    /// </summary>
    public ref class tracker_alert : torrent_alert
    {
    public:
        tracker_alert(libtorrent::tracker_alert* alert);

        property System::String^ url { System::String^ get(); }

    private:
        libtorrent::tracker_alert* alert_;
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

    /// <summary>
    /// This alert is generated when a limit is reached that might have a
    /// negative impact on upload or download rate performance.
    /// </summary>
    public ref class performance_alert : torrent_alert
    {
    public:
        performance_alert(libtorrent::performance_alert* alert);

        property int warning_code { int get(); } // TODO enum

    private:
        libtorrent::performance_alert* alert_;
    };

    /// <summary>
    /// Generated whenever a torrent changes its state.
    /// </summary>
    public ref class state_changed_alert : torrent_alert
    {
    public:
        state_changed_alert(libtorrent::state_changed_alert* alert);

        property int state { int get(); } // TODO torrent_status::state_t
        property int prev_state { int get(); } // TODO torrent_status::state_t

    private:
        libtorrent::state_changed_alert* alert_;
    };

    /// <summary>
    /// This alert is generated on tracker time outs, premature disconnects,
    /// invalid response or a HTTP response other than "200 OK". From the alert
    /// you can get the handle to the torrent the tracker belongs to.
    /// </summary>
    public ref class tracker_error_alert : tracker_alert
    {
    public:
        tracker_error_alert(libtorrent::tracker_error_alert* alert);

        property int times_in_row { int get(); }
        property int status_code { int get(); }
        // property  TODO eror code
        property System::String^ msg { System::String^ get(); }

    private:
        libtorrent::tracker_error_alert* alert_;
    };

    /// <summary>
    /// This alert is triggered if the tracker reply contains a warning field.
    /// Usually this means that the tracker announce was successful, but the
    /// tracker has a message to the client.
    /// </summary>
    public ref class tracker_warning_alert : tracker_alert
    {
    public:
        tracker_warning_alert(libtorrent::tracker_warning_alert* alert);

        property System::String^ msg { System::String^ get(); }

    private:
        libtorrent::tracker_warning_alert* alert_;
    };

    /// <summary>
    /// This alert is generated when a scrape request succeeds.
    /// </summary>
    public ref class scrape_reply_alert : tracker_alert
    {
    public:
        scrape_reply_alert(libtorrent::scrape_reply_alert* alert);

        property int incomplete { int get(); }
        property int complete { int get(); }

    private:
        libtorrent::scrape_reply_alert* alert_;
    };

    /// <summary>
    /// If a scrape request fails, this alert is generated. This might be due
    /// to the tracker timing out, refusing connection or returning an http
    /// response code indicating an error.
    /// </summary>
    public ref class scrape_failed_alert : tracker_alert
    {
    public:
        scrape_failed_alert(libtorrent::scrape_failed_alert* alert);

        property System::String^ msg { System::String^ get(); }

    private:
        libtorrent::scrape_failed_alert* alert_;
    };

    /// <summary>
    /// This alert is only for informational purpose. It is generated when a
    /// tracker announce succeeds. It is generated regardless what kind of
    /// tracker was used, be it UDP, HTTP or the DHT.
    /// </summary>
    public ref class tracker_reply_alert : tracker_alert
    {
    public:
        tracker_reply_alert(libtorrent::tracker_reply_alert* alert);

        property int num_peers { int get(); }

    private:
        libtorrent::tracker_reply_alert* alert_;
    };

    /// <summary>
    /// This alert is generated each time the DHT receives peers from a node.
    /// num_peers is the number of peers we received in this packet. Typically
    /// these packets are received from multiple DHT nodes, and so the alerts
    /// are typically generated a few at a time.
    /// </summary>
    public ref class dht_reply_alert : tracker_alert
    {
    public:
        dht_reply_alert(libtorrent::dht_reply_alert* alert);

        property int num_peers { int get(); }

    private:
        libtorrent::dht_reply_alert* alert_;
    };

    /// <summary>
    /// This alert is generated each time a tracker announce is sent (or
    /// attempted to be sent). There are no extra data members in this alert.
    /// The url can be found in the base class however.
    /// </summary>
    public ref class tracker_announce_alert : tracker_alert
    {
    public:
        tracker_announce_alert(libtorrent::tracker_announce_alert* alert);

        property int event { int get(); }

    private:
        libtorrent::tracker_announce_alert* alert_;
    };

    /// <summary>
    /// This alert is generated when a finished piece fails its hash check.
    /// You can get the handle to the torrent which got the failed piece and
    /// the index of the piece itself from the alert.
    /// </summary>
    public ref class hash_failed_alert : torrent_alert
    {
    public:
        hash_failed_alert(libtorrent::hash_failed_alert* alert);

        property int piece_index { int get(); }

    private:
        libtorrent::hash_failed_alert* alert_;
    };

    /// <summary>
    /// This alert is generated when a peer is banned because it has sent too
    /// many corrupt pieces to us. ip is the endpoint to the peer that was banned.
    /// </summary>
    public ref class peer_ban_alert : peer_alert
    {
    public:
        peer_ban_alert(libtorrent::peer_ban_alert* alert);
    };

    /// <summary>
    /// This alert is generated when a peer is unsnubbed. Essentially when it
    /// was snubbed for stalling sending data, and now it started sending data
    /// again.
    /// </summary>
    public ref class peer_unsnubbed_alert : peer_alert
    {
    public:
        peer_unsnubbed_alert(libtorrent::peer_unsnubbed_alert* alert);
    };

    /// <summary>
    /// This alert is generated when a peer is snubbed, when it stops sending
    /// data when we request it.
    /// </summary>
    public ref class peer_snubbed_alert : peer_alert
    {
    public:
        peer_snubbed_alert(libtorrent::peer_snubbed_alert* alert);
    };

    /// <summary>
    /// This alert is generated when a peer sends invalid data over the
    /// peer-peer protocol. The peer will be disconnected, but you get its ip
    /// address from the alert, to identify it.
    /// </summary>
    public ref class peer_error_alert : peer_alert
    {
    public:
        peer_error_alert(libtorrent::peer_error_alert* alert);

        // TODO error code
    private:
        libtorrent::peer_error_alert* alert_;
    };

    /// <summary>
    /// This alert is posted every time an outgoing peer connect attempts
    /// succeeds.
    /// </summary>
    public ref class peer_connect_alert : peer_alert
    {
    public:
        peer_connect_alert(libtorrent::peer_connect_alert* alert);

        property int socket_type { int get(); }
    private:
        libtorrent::peer_connect_alert* alert_;
    };

    /// <summary>
    /// This alert is generated when a peer is disconnected for any reason
    /// (other than the ones covered by peer_error_alert).
    /// </summary>
    public ref class peer_disconnected_alert : peer_alert
    {
    public:
        peer_disconnected_alert(libtorrent::peer_disconnected_alert* alert);
        // TODO error code
    private:
        libtorrent::peer_disconnected_alert* alert_;
    };

    /// <summary>
    /// This is a debug alert that is generated by an incoming invalid piece
    /// request. ip is the address of the peer and the request is the actual
    /// incoming request from the peer. See peer_request for more info.
    /// </summary>
    public ref class invalid_request_alert : peer_alert
    {
    public:
        invalid_request_alert(libtorrent::invalid_request_alert* alert);
        // TODO peer request
    private:
        libtorrent::invalid_request_alert* alert_;
    };

    /// <summary>
    /// This alert is generated when a torrent switches from being a downloader
    /// to a seed. It will only be generated once per torrent. It contains a
    /// torrent_handle to the torrent in question.
    /// </summary>
    public ref class torrent_finished_alert : torrent_alert
    {
    public:
        torrent_finished_alert(libtorrent::torrent_finished_alert* alert);
    };

    /// <summary>
    /// This alert is posted every time a piece completes downloading and
    /// passes the hash check. This alert derives from torrent_alert which
    /// contains the torrent_handle to the torrent the piece belongs to.
    /// </summary>
    public ref class piece_finished_alert : torrent_alert
    {
    public:
        piece_finished_alert(libtorrent::piece_finished_alert* alert);

        property int piece_index { int get(); }
    private:
        libtorrent::piece_finished_alert* alert_;
    };

    /// <summary>
    /// This alert is generated when a peer rejects or ignores a piece request.
    /// </summary>
    public ref class request_dropped_alert : peer_alert
    {
    public:
        request_dropped_alert(libtorrent::request_dropped_alert* alert);

        property int block_index { int get(); }
        property int piece_index { int get(); }
    private:
        libtorrent::request_dropped_alert* alert_;
    };

    /// <summary>
    /// This alert is generated when a block request times out.
    /// </summary>
    public ref class block_timeout_alert : peer_alert
    {
    public:
        block_timeout_alert(libtorrent::block_timeout_alert* alert);

        property int block_index { int get(); }
        property int piece_index { int get(); }
    private:
        libtorrent::block_timeout_alert* alert_;
    };

    /// <summary>
    /// This alert is generated when a block request receives a response.
    /// </summary>
    public ref class block_finished_alert : peer_alert
    {
    public:
        block_finished_alert(libtorrent::block_finished_alert* alert);

        property int block_index { int get(); }
        property int piece_index { int get(); }
    private:
        libtorrent::block_finished_alert* alert_;
    };

    /// <summary>
    /// This alert is generated when a block request is sent to a peer.
    /// </summary>
    public ref class block_downloading_alert : peer_alert
    {
    public:
        block_downloading_alert(libtorrent::block_downloading_alert* alert);

        property System::String^ peer_speedmsg { System::String^ get(); }
        property int block_index { int get(); }
        property int piece_index { int get(); }
    private:
        libtorrent::block_downloading_alert* alert_;
    };

    /// <summary>
    /// This alert is generated when a block is received that was not requeste
    /// or whose request timed out.
    /// </summary>
    public ref class unwanted_block_alert : peer_alert
    {
    public:
        unwanted_block_alert(libtorrent::unwanted_block_alert* alert);

        property int block_index { int get(); }
        property int piece_index { int get(); }
    private:
        libtorrent::unwanted_block_alert* alert_;
    };

    /// <summary>
    /// The storage_moved_alert is generated when all the disk IO has completed
    /// and the files have been moved, as an effect of a call to
    /// torrent_handle::move_storage. This is useful to synchronize with the
    /// actual disk. The path member is the new path of the storage.
    /// </summary>
    public ref class storage_moved_alert : torrent_alert
    {
    public:
        storage_moved_alert(libtorrent::storage_moved_alert* alert);

        property System::String^ path { System::String^ get(); }
    private:
        libtorrent::storage_moved_alert* alert_;
    };

    /// <summary>
    /// The storage_moved_failed_alert is generated when an attempt to move the
    /// storage, via torrent_handle::move_storage(), fails.
    /// </summary>
    public ref class storage_moved_failed_alert : torrent_alert
    {
    public:
        storage_moved_failed_alert(libtorrent::storage_moved_failed_alert* alert);
        // TODO error code
    private:
        libtorrent::storage_moved_failed_alert* alert_;
    };

    /// <summary>
    /// This alert is generated when a request to delete the files of a torrent
    /// complete. The info_hash is the info - hash of the torrent that was just
    /// deleted. Most of the time the torrent_handle in the torrent_alert will
    /// be invalid by the time this alert arrives, since the torrent is being
    /// deleted.The info_hash member is hence the main way of identifying which
    /// torrent just completed the delete.
    /// </summary>
    public ref class torrent_deleted_alert : torrent_alert
    {
    public:
        torrent_deleted_alert(libtorrent::torrent_deleted_alert* alert);
        // TODO info hash
    private:
        libtorrent::torrent_deleted_alert* alert_;
    };

    /// <summary>
    /// This alert is generated when a request to delete the files of a torrent
    /// fails. Just removing a torrent from the session cannot fail.
    /// </summary>
    public ref class torrent_delete_failed_alert : torrent_alert
    {
    public:
        torrent_delete_failed_alert(libtorrent::torrent_delete_failed_alert* alert);
        // TODO error code
        // TODO info hash
    private:
        libtorrent::torrent_delete_failed_alert* alert_;
    };

    /// <summary>
    /// This alert is generated as a response to a
    /// torrent_handle::save_resume_data request. It is generated once the disk
    /// IO thread is done writing the state for this torrent.
    /// </summary>
    public ref class save_resume_data_alert : torrent_alert
    {
    public:
        save_resume_data_alert(libtorrent::save_resume_data_alert* alert);

        property entry^ resume_data { entry^ get(); }
    private:
        libtorrent::save_resume_data_alert* alert_;
    };

    /// <summary>
    /// This alert is generated instead of save_resume_data_alert if there was
    /// an error generating the resume data. error describes what went wrong.
    /// </summary>
    public ref class save_resume_data_failed_alert : torrent_alert
    {
    public:
        save_resume_data_failed_alert(libtorrent::save_resume_data_failed_alert* alert);
        // TODO error code
    private:
        libtorrent::save_resume_data_failed_alert* alert_;
    };

    /// <summary>
    /// This alert is generated as a response to a torrent_handle::pause
    /// request. It is generated once all disk IO is complete and the files in
    /// the torrent have been closed. This is useful for synchronizing with the
    /// disk.
    /// </summary>
    public ref class torrent_paused_alert : torrent_alert
    {
    public:
        torrent_paused_alert(libtorrent::torrent_paused_alert* alert);
    };

    /// <summary>
    /// This alert is generated as a response to a torrent_handle::resume()
    /// request. It is generated when a torrent goes from a paused state to an
    /// active state.
    /// </summary>
    public ref class torrent_resumed_alert : torrent_alert
    {
    public:
        torrent_resumed_alert(libtorrent::torrent_resumed_alert* alert);
    };

    /// <summary>
    /// This alert is posted when a torrent completes checking. i.e. when it
    /// transitions out of the checking files state into a state where it is
    /// ready to start downloading
    /// </summary>
    public ref class torrent_checked_alert : torrent_alert
    {
    public:
        torrent_checked_alert(libtorrent::torrent_checked_alert* alert);
    };

    /// <summary>
    /// This alert is generated when a HTTP seed name lookup fails.
    /// </summary>
    public ref class url_seed_alert : torrent_alert
    {
    public:
        url_seed_alert(libtorrent::url_seed_alert* alert);

        property System::String^ url { System::String^ get(); }
        property System::String^ msg { System::String^ get(); }
    private:
        libtorrent::url_seed_alert* alert_;
    };

    /// <summary>
    /// If the storage fails to read or write files that it needs access to,
    /// this alert is generated and the torrent is paused.
    /// </summary>
    public ref class file_error_alert : torrent_alert
    {
    public:
        file_error_alert(libtorrent::file_error_alert* alert);

        property System::String^ file { System::String^ get(); }
        // TODO error code
    private:
        libtorrent::file_error_alert* alert_;
    };

    /// <summary>
    /// This alert is generated when the metadata has been completely received
    /// and the info-hash failed to match it. i.e. the metadata that was
    /// received was corrupt. libtorrent will automatically retry to fetch it
    /// in this case. This is only relevant when running a torrent-less
    /// download, with the metadata extension provided by libtorrent.
    /// </summary>
    public ref class metadata_failed_alert : torrent_alert
    {
    public:
        metadata_failed_alert(libtorrent::metadata_failed_alert* alert);
        // TODO error code
    private:
        libtorrent::metadata_failed_alert* alert_;
    };

    /// <summary>
    /// This alert is generated when the metadata has been completely received
    /// and the torrent can start downloading. It is not generated on torrents
    /// that are started with metadata, but only those that needs to download
    /// it from peers (when utilizing the libtorrent extension). There are no
    /// additional data members in this alert. Typically, when receiving this
    /// alert, you would want to save the torrent file in order to load it back
    /// up again when the session is restarted.
    /// </summary>
    public ref class metadata_received_alert : torrent_alert
    {
    public:
        metadata_received_alert(libtorrent::metadata_received_alert* alert);
    };

    /// <summary>
    /// This alert is posted when there is an error on the UDP socket. The UDP
    /// socket is used for all uTP, DHT and UDP tracker traffic. It's global to
    /// the session.
    /// </summary>
    public ref class udp_error_alert : alert
    {
    public:
        udp_error_alert(libtorrent::udp_error_alert* alert);
        // TODO endpoint
        // TODO error
    private:
        libtorrent::udp_error_alert* alert_;
    };

    /// <summary>
    /// Whenever libtorrent learns about the machines external IP, this alert
    /// is generated. The external IP address can be acquired from the tracker
    /// (if it supports that) or from peers that supports the extension
    /// protocol. The address can be accessed through the external_address
    /// member.
    public ref class external_ip_alert : alert
    {
    public:
        external_ip_alert(libtorrent::external_ip_alert* alert);
        // TODO external_address
    private:
        libtorrent::external_ip_alert* alert_;
    };

    /// <summary>
    /// This alert is generated when none of the ports, given in the port
    /// range, to session can be opened for listening. The endpoint member is
    /// the interface and port that failed, error is the error code describing
    /// the failure. libtorrent may sometimes try to listen on port 0, if all
    /// other ports failed. Port 0 asks the operating system to pick a port
    /// that's free). If that fails you may see a listen_failed_alert with port
    /// 0 even if you didn't ask to listen on it.
    /// </summary>
    public ref class listen_failed_alert : alert
    {
    public:
        listen_failed_alert(libtorrent::listen_failed_alert* alert);

        // TODO endpoint
        // TODO error code
        property int operation { int get(); }
        // TODO sock type
    private:
        libtorrent::listen_failed_alert* alert_;
    };

    /// <summary>
    /// This alert is posted when the listen port succeeds to be opened on a
    /// particular interface. endpoint is the endpoint that successfully was
    /// opened for listening.
    /// </summary>
    public ref class listen_succeeded_alert : alert
    {
    public:
        listen_succeeded_alert(libtorrent::listen_succeeded_alert* alert);

        // TODO endpoint
        // TODO sock_type
    private:
        libtorrent::listen_succeeded_alert* alert_;
    };

    /// <summary>
    /// This alert is generated when a NAT router was successfully found but
    /// some part of the port mapping request failed. It contains a text
    /// message that may help the user figure out what is wrong. This alert is
    /// not generated in case it appears the client is not running on a NAT:ed
    /// network or if it appears there is no NAT router that can be remote
    /// controlled to add port mappings.
    /// </summary>
    public ref class portmap_error_alert : alert
    {
    public:
        portmap_error_alert(libtorrent::portmap_error_alert* alert);

        property int mapping { int get(); }
        property int map_type { int get(); }
        // TODO error code
    private:
        libtorrent::portmap_error_alert* alert_;
    };

    /// <summary>
    /// This alert is generated when a NAT router was successfully found and a
    /// port was successfully mapped on it. On a NAT:ed network with a NAT-PMP
    /// capable router, this is typically generated once when mapping the TCP
    /// port and, if DHT is enabled, when the UDP port is mapped.
    /// </summary>
    public ref class portmap_alert : alert
    {
    public:
        portmap_alert(libtorrent::portmap_alert* alert);

        property int mapping { int get(); }
        property int external_port { int get(); }
        property int map_type { int get(); }
    private:
        libtorrent::portmap_alert* alert_;
    };

    /// <summary>
    /// This alert is generated to log informational events related to either
    /// UPnP or NAT-PMP. They contain a log line and the type (0 = NAT-PMP and
    /// 1 = UPnP). Displaying these messages to an end user is only useful for
    /// debugging the UPnP or NAT-PMP implementation.
    /// </summary>
    public ref class portmap_log_alert : alert
    {
    public:
        portmap_log_alert(libtorrent::portmap_log_alert* alert);

        property int map_type { int get(); }
        property System::String^ msg { System::String^ get(); }
    private:
        libtorrent::portmap_log_alert* alert_;
    };

    /// <summary>
    /// This alert is generated when a fastresume file has been passed to
    /// add_torrent() but the files on disk did not match the fastresume file.
    /// The error_code explains the reason why the resume file was rejected.
    /// </summary>
    public ref class fastresume_rejected_alert : torrent_alert
    {
    public:
        fastresume_rejected_alert(libtorrent::fastresume_rejected_alert* alert);
        // TODO error code
    private:
        libtorrent::fastresume_rejected_alert* alert_;
    };

    /// <summary>
    /// This alert is posted when an incoming peer connection, or a peer that's
    /// about to be added to our peer list, is blocked for some reason.
    /// </summary>
    public ref class peer_blocked_alert : torrent_alert
    {
    public:
        peer_blocked_alert(libtorrent::peer_blocked_alert* alert);

        // TODO  ip
        property int reason { int get(); }
    private:
        libtorrent::peer_blocked_alert* alert_;
    };

    /// <summary>
    /// This alert is generated when a DHT node announces to an info-hash on
    /// our DHT node. It belongs to the dht_notification category.
    /// </summary>
    public ref class dht_announce_alert : alert
    {
    public:
        dht_announce_alert(libtorrent::dht_announce_alert* alert);

        // TODO ip
        property int port { int get(); }
        // TODO info hash
    private:
        libtorrent::dht_announce_alert* alert_;
    };

    /// <summary>
    /// This alert is generated when a DHT node sends a get_peers message to
    /// our DHT node. It belongs to the dht_notification category.
    /// </summary>
    public ref class dht_get_peers_alert : alert
    {
    public:
        dht_get_peers_alert(libtorrent::dht_get_peers_alert* alert);
        // TODO info hash
    private:
        libtorrent::dht_get_peers_alert* alert_;
    };

    /// <summary>
    /// This alert is posted approximately once every second, and it contains
    /// byte counters of most statistics that's tracked for torrents. Each
    /// active torrent posts these alerts regularly.
    /// </summary>
    public ref class stats_alert : torrent_alert
    {
    public:
        stats_alert(libtorrent::stats_alert* alert);

        property cli::array<int>^ transferred { cli::array<int>^ get(); }
        property int interval { int get(); }
    private:
        libtorrent::stats_alert* alert_;
    };

    /// <summary>
    /// This alert is posted when the disk cache has been flushed for a
    /// specific torrent as a result of a call to
    /// torrent_handle::flush_cache(). This alert belongs to the
    /// storage_notification category, which must be enabled to let this alert
    /// through. The alert is also posted when removing a torrent from the
    /// session, once the outstanding cache flush is complete and the torrent
    /// does no longer have any files open.
    /// </summary>
    public ref class cache_flushed_alert : torrent_alert
    {
    public:
        cache_flushed_alert(libtorrent::cache_flushed_alert* alert);
    };

    /// <summary>
    /// This alert is posted when a bittorrent feature is blocked because of
    /// the anonymous mode. For instance, if the tracker proxy is not set up,
    /// no trackers will be used, because trackers can only be used through
    /// proxies when in anonymous mode.
    /// </summary>
    public ref class anonymous_mode_alert : torrent_alert
    {
    public:
        anonymous_mode_alert(libtorrent::anonymous_mode_alert* alert);

        property int kind { int get(); }
        property System::String^ str { System::String^ get(); }
    private:
        libtorrent::anonymous_mode_alert* alert_;
    };

    /// <summary>
    /// This alert is generated when we receive a local service discovery
    /// message from a peer for a torrent we're currently participating in.
    /// </summary>
    public ref class lsd_peer_alert : peer_alert
    {
    public:
        lsd_peer_alert(libtorrent::lsd_peer_alert* alert);
    };

    /// <summary>
    /// This alert is posted whenever a tracker responds with a trackerid. The
    /// tracker ID is like a cookie. The libtorrent will store the tracker ID
    /// for this tracker and repeat it in subsequent announces.
    /// </summary>
    public ref class trackerid_alert : tracker_alert
    {
    public:
        trackerid_alert(libtorrent::trackerid_alert* alert);

        property System::String^ trackerid { System::String^ get(); }
    private:
        libtorrent::trackerid_alert* alert_;
    };

    /// <summary>
    /// This alert is posted when the initial DHT bootstrap is done.
    /// </summary>
    public ref class dht_bootstrap_alert : alert
    {
    public:
        dht_bootstrap_alert(libtorrent::dht_bootstrap_alert* alert);
    };

    /// <summary>
    /// This is posted whenever a torrent is transitioned into the error state.
    /// </summary>
    public ref class torrent_error_alert : torrent_alert
    {
    public:
        torrent_error_alert(libtorrent::torrent_error_alert* alert);
        // TODO error
    private:
        libtorrent::torrent_error_alert* alert_;
    };

    /// <summary>
    /// This is always posted for SSL torrents. This is a reminder to the
    /// client that the torrent won't work unless
    /// torrent_handle::set_ssl_certificate() is called with a valid
    /// certificate. Valid certificates MUST be signed by the SSL certificate
    /// in the .torrent file.
    /// </summary>
    public ref class torrent_need_cert_alert : torrent_alert
    {
    public:
        torrent_need_cert_alert(libtorrent::torrent_need_cert_alert* alert);
        // TODO error
    private:
        libtorrent::torrent_need_cert_alert* alert_;
    };

    /// <summary>
    /// The incoming connection alert is posted every time we successfully
    /// accept an incoming connection, through any mean. The most
    /// straigh-forward ways of accepting incoming connections are through the
    /// TCP listen socket and the UDP listen socket for uTP sockets. However,
    /// connections may also be accepted ofer a Socks5 or i2p listen socket, or
    /// via a torrent specific listen socket for SSL torrents.
    /// </summary>
    public ref class incoming_connection_alert : alert
    {
    public:
        incoming_connection_alert(libtorrent::incoming_connection_alert* alert);

        property int socket_type { int get(); }
        // TODO ip
    private:
        libtorrent::incoming_connection_alert* alert_;
    };

    /// <summary>
    /// This alert is always posted when a torrent was attempted to be added
    /// and contains the return status of the add operation. The torrent
    /// handle of the new torrent can be found in the base class' handle
    /// member. If adding the torrent failed, error contains the error code.
    /// </summary>
    public ref class add_torrent_alert : torrent_alert
    {
    public:
        add_torrent_alert(libtorrent::add_torrent_alert* alert);

        // TODO params
        // TODO error
    private:
        libtorrent::add_torrent_alert* alert_;
    };

    /// <summary>
    /// This alert is only posted when requested by the user, by calling
    /// session::post_torrent_updates() on the session. It contains the torrent
    /// status of all torrents that changed since last time this message was
    /// posted. Its category is status_notification, but it's not subject to
    /// filtering, since it's only manually posted anyway.
    /// </summary>
    public ref class state_update_alert : alert
    {
    public:
        state_update_alert(libtorrent::state_update_alert* alert);

        // TODO status
    private:
        libtorrent::state_update_alert* alert_;
    };

    /// <summary>
    /// When a torrent changes its info-hash, this alert is posted. This only
    /// happens in very specific cases. For instance, when a torrent is
    /// downloaded from a URL, the true info hash is not known immediately.
    /// First the .torrent file must be downloaded and parsed. Once this
    /// download completes, the torrent_update_alert is posted to notify the
    /// client of the info - hash changing.
    /// </summary>
    public ref class torrent_update_alert : torrent_alert
    {
    public:
        torrent_update_alert(libtorrent::torrent_update_alert* alert);

        // TODO old_ih
        // TODO new_ih
    private:
        libtorrent::torrent_update_alert* alert_;
    };

    /// <summary>
    /// Posted when something fails in the DHT. This is not necessarily a fatal
    /// error, but it could prevent proper operation
    /// </summary>
    public ref class dht_error_alert : alert
    {
    public:
        dht_error_alert(libtorrent::dht_error_alert* alert);
        // TODO error
        // TODO operation
    private:
        libtorrent::dht_error_alert* alert_;
    };
}
