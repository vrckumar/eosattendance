#include <eosiolib/eosio.hpp>

using namespace eosio;
CONTRACT manpowertrack : public contract {

  private:

    enum login_status: int8_t  {
      LOGGED_IN     = 0,
      LOGGED_OUT   = 1
    };

    TABLE people_registry {
      name    name;
      string first_name;
      string last_name;

      uint64_t primary_key() const { return name.value;}
    };

    typedef multi_index<"people_registry"_n, people_registry> people_registry;

    TABLE attendance_tracker {
      name    name;
      uint64_t        key = 1;
      uint32_t        login_time = 1;
      uint32_t        logout_time = 1;

      auto primary_key() const { return key; }
    };

   typedef eosio::multi_index<"attendance_tracker"_n, attendance_tracker> attendance_tracker;

    people_registry _registry;

    attendance_tracker _tracker;


  public:

    attendance(name receiver, name code,  datastream<const char*> ds): contract(receiver, code, ds) {}


};