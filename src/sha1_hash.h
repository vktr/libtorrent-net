#pragma once

namespace libtorrent
{
    class sha1_hash;
}

namespace lt
{
    public ref class sha1_hash
    {
    internal:
        sha1_hash(const libtorrent::sha1_hash& hash);
        libtorrent::sha1_hash& ptr();

    public:
        sha1_hash(System::String^ val);
        ~sha1_hash();

        System::String^ ToString() override;

    private:
        libtorrent::sha1_hash* hash_;
    };
}
