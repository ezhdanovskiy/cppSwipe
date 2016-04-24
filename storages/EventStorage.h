#pragma once

#include <map>

#include <SystemDefines.h>
#include <Logger.h>
#include <User.h>

namespace Storage {

class Events {
public:
    typedef System::TUserId Key;

    struct Value {
        Value() { }

        Value(int type, System::TUserId ownerId, const std::string &text) : type(type), ownerId(ownerId), text(text) { }

        Value &setId(Key id) {
            Value::id = id;
            return *this;
        }

        Key id = 0;
        int type;
        System::TUserId ownerId;
        std::string text;
    };

    Key add(const Value &value) {
        Key key = storage.size() + 1;
        storage[key] = value;
        LOG("Storage::Event::add(" << key << ", type=" << value.type << ", ownerId=" << value.ownerId << ", text='" << value.text << "')")
        return key;
    };

    Value get(const Key &key) {
        return storage[key].setId(key);
    };

private:
    std::map<Key, Value> storage;
};

} // namespace Storage
