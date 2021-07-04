// leetcode_355_design_Twitter.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
355. 设计推特
设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：

postTweet(userId, tweetId): 创建一条新的推文
getNewsFeed(userId): 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序。
follow(followerId, followeeId): 关注一个用户
unfollow(followerId, followeeId): 取消关注一个用户
示例:

Twitter twitter = new Twitter();

// 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
twitter.postTweet(1, 5);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
twitter.getNewsFeed(1);

// 用户1关注了用户2.
twitter.follow(1, 2);

// 用户2发送了一个新推文 (推文id = 6).
twitter.postTweet(2, 6);

// 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
// 推文id6应当在推文id5之前，因为它是在5之后发送的.
twitter.getNewsFeed(1);

// 用户1取消关注了用户2.
twitter.unfollow(1, 2);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
// 因为用户1已经不再关注用户2.
twitter.getNewsFeed(1);

状态：通过
执行用时: 0 ms
内存消耗: 7.1 MB
*/

#include <iostream>
#include <vector>
#include "User.h"
#include "Twitter.h"
using namespace std;



/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */


int main()
{
    cout << "Hello World!\n";
    Twitter* obj = new Twitter();
    vector<vector<int>> input = { {1, 5} ,{2, 3},{1, 101},{2, 13},{2, 10},{1, 2},{1, 94},{2, 505},{1, 333},{2, 22},{1, 11},{1, 205},{2, 203},{1, 201},{2, 213},{1, 200},{2, 202},{1, 204},{2, 208},{2, 233},{1, 222},{2, 211} };
    for (int i = 0; i < input.size(); i++) {
        obj->postTweet(input[i][0], input[i][1]);
    }

    vector<int> param_2 = obj->getNewsFeed(1);
    for (int i = 0; i < param_2.size(); i++) {
        cout << param_2[i] << " ";
    }
    cout << endl;
    cout << endl;

    obj->follow(1, 2);

    param_2 = obj->getNewsFeed(1);
    for (int i = 0; i < param_2.size(); i++) {
        cout << param_2[i] << " ";
    }
    cout << endl;
    cout << endl;

    obj->unfollow(1, 2);

    param_2 = obj->getNewsFeed(1);
    for (int i = 0; i < param_2.size(); i++) {
        cout << param_2[i] << " ";
    }
    cout << endl;
    cout << endl;

    return 0;

}




