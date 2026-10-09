#include "kvstore/store.hpp"

namespace kvstore {

void KVStore::set(const std::string& key, const std::string& value)
{
    data_[key] = value;
}

std::optional<std::string> KVStore::get(const std::string& key) const
{
auto val = data_.find(key);
if (val == data_.end())
{
return std::nullopt;
}
return val -> second;

}

bool KVStore::del(const std::string& key)
{
  auto removed =   data_.erase(key);

  return removed == 1;
}

}