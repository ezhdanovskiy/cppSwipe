#pragma once

#include <UserStorage.h>
#include <ContactsStorage.h>
#include <EventStorage.h>

namespace Swipe {

class MainStorage {
    Storage::Users &users;
    Storage::Contacts contacts;
    Storage::Events events;
public:
    MainStorage() : users(Storage::Users::getInstance()) { }

    Storage::Users &getUsers() { return users; };

    Storage::Contacts &getContacts() { return contacts; };

    Storage::Events &getEvents() { return events; };
};

} // namespace Swipe
