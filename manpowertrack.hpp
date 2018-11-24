#include <eosiolib/eosio.hpp>

using namespace eosio;
using namespace std;
CONTRACT manpowertrac : public contract {

  private:

    enum login_status: int8_t  {
      LOGGED_IN     = 0,
      LOGGED_OUT   = 1
    };

    
    TABLE people {
      name    name;
      string first_name;
      string last_name;

      uint64_t primary_key() const { return name.value;}
    };

    typedef multi_index<"people"_n, people> people_registry;
    
    
    TABLE tracker {
      name    name;
      uint64_t        key = 1;
      uint32_t        login_time = 1;
      uint32_t        logout_time = 1;

      auto primary_key() const { return key; }
    };

   typedef eosio::multi_index<"tracker"_n, tracker> attendance_tracker;

    people_registry _registry;

    attendance_tracker _tracker;


  public:
    using contract::contract;
    manpowertrac(name receiver, name code,  datastream<const char*> ds): contract(receiver, code, ds)
    ,_registry(code, code.value)
    ,_tracker(code, code.value)
     {}

  ACTION add(name username,string firstName,string lastName);
  // ACTION login(name username);
  // ACTION logout(name username);
  // ACTION attendance_report();
  // ACTION exception_report();
};
