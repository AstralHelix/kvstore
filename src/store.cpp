#include "kvstore/store.hpp"

namespace kvstore {

void KVStore::set(const std::string& key, const std::string& value)
{
    data_[key] = value;
}


}