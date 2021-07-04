#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>
#include "User.h"
#include "Tweet.h"
using namespace std;


class Twitter {
public:
    int timestamp;
    // 我们需要⼀个映射将 userId 和 User 对象对应起来
    unordered_map<int, User> userMap;

public:
    public:
    /** Initialize your data structure here. */
    Twitter();
    ~Twitter();

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId);

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId);

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId);

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId);
};


class cmp
{
public:
    bool operator()(Tweet* a, Tweet* b)
    {
        return a->time < b->time;
    }
};


