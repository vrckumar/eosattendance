#include "manpowertrack.hpp"

void manpowertrack::add(name user,string firstName,string lastName) {
    auto iterator = _registry.find(user.value);
    if( iterator == _registry.end() )
    {
      _registry.emplace(user, [&]( auto& row ) {
       row.key = user;
       row.first_name = firstName;
       row.last_name = lastName;

      });
    }
    else {
      std::string changes;
      addresses.modify(iterator, user, [&]( auto& row ) {
        row.key = user;
        row.first_name = firstName;
        row.last_name = lastName;
      });
    }
}


EOSIO_DISPATCH(manpowertrack, (add)(login)(logout)(attendance_report)(exception_report))
