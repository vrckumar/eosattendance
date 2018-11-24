#include "manpowertrack.hpp"

[[eosio::action]]
void manpowertrac::add(name user,string firstName,string lastName) {
    auto iterator = _registry.find(user.value);
    if( iterator == _registry.end() )
    {
      _registry.emplace(user, [&]( auto& row ) {
       row.name = user;
       row.first_name = firstName;
       row.last_name = lastName;

      });
    }
    else {
      std::string changes;
      _registry.modify(iterator, user, [&]( auto& row ) {
        row.name = user;
        row.first_name = firstName;
        row.last_name = lastName;
      });
    }
}


EOSIO_DISPATCH(manpowertrac, (add))
