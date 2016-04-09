#pragma once

#include <inttypes.h>
#include <set>

namespace Storage {
namespace Contacts {

typedef uint64_t TContactId;
typedef std::set<TContactId> TContactIds;

void addFollower(TContactId userId, TContactId followerId);

void addFollowers(TContactId userId, const TContactIds& followerIds);

TContactIds getFollowers(TContactId userId);

TContactIds getFollowings(TContactId followerId);

}
}
