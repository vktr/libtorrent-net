#pragma once

namespace libtorrent
{
    struct create_torrent;
}

namespace lt
{
    ref class entry;
    ref class file_storage;
    ref class sha1_hash;

    public ref class create_torrent
    {
    internal:
        libtorrent::create_torrent& ptr();

    public:
        create_torrent(file_storage^ fs);
        create_torrent(file_storage^ fs, int piece_size);
        create_torrent(file_storage^ fs, int piece_size, int pad_file_limit);
        create_torrent(file_storage^ fs, int piece_size, int pad_file_limit, int flags);
        create_torrent(file_storage^ fs, int piece_size, int pad_file_limit, int flags, int alignment);
        ~create_torrent();

        static void add_files(file_storage^ fs, System::String^ path);
        static void add_files(file_storage^ fs, System::String^ path, unsigned int flags);
        static void set_piece_hashes(create_torrent^ ct, System::String^ path);

        entry^ generate();
        file_storage^ files();
        void set_comment(System::String^ str);
        void set_creator(System::String^ str);
        void set_hash(int index, sha1_hash^ hash);
        void set_file_hash(int index, sha1_hash^ hash);
        void add_url_seed(System::String^ url);
        void add_http_seed(System::String^ url);
        void add_node(System::String^ host, int port);
        void add_tracker(System::String^ url);
        void add_tracker(System::String^ url, int tier);
        void set_root_cert(System::String^ pem);
        bool priv();
        void set_priv(bool p);
        int num_pieces();
        int piece_length();
        int piece_size(int i);
        // TODO merkle tree

    private:
        libtorrent::create_torrent* create_;
    };
}
