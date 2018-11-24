#include "manpowertrack.hpp"
#include <eosiolib/print.hpp>

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

[[eosio::action]]
void manpowertrac::login(name username){
    auto registry_iterator = _registry.find(username.value);

    if(registry_iterator == _registry.end()){
        //User doesn't exist
        return;
    }

    //Insert login time
    auto tracker_iterator = _tracker.emplace(username, [&]( auto& new_login) {
        new_login.name = username;
       _tracker_size++;
        new_login.key = _tracker_size;
        new_login.login_time = current_time();
    });

}

[[eosio::action]]
void manpowertrac::logout(name username) {
  // Ensure this action is authorized by the player
  // require_auth(username);
     auto registry_iterator = _registry.find(username.value);

    if(registry_iterator == _registry.end()){
        print("User doesn't exist in registry");
        return;
    }
 
  // Create a record in the table if the user doesn't exist in our app yet
  auto login_iterator = _tracker.find(username.value);

    if( login_iterator == _tracker.end() ) {
      print("User did not exist in tracker");
      // Put the error and exit
      return;
    } else {
          std::string changes;
      _tracker.modify(login_iterator, username, [&]( auto& row ) {
        row.logout_time = current_time();
      });
    }


}

EOSIO_DISPATCH(manpowertrac, (add)(login)(logout))
