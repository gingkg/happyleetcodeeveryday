#include "Twitter.h"

Twitter::Twitter()
{
	timestamp = 0;
}

Twitter::~Twitter()
{
}

/** user 发表⼀条 tweet 动态 */
void Twitter::postTweet(int userId, int tweetId)
{
	//  若 userId 不存在， 则新建
	if (!userMap.count(userId)) {
		userMap.emplace(userId, User(userId));
	}
	//userMap.at(userId).post(tweetId, timestamp);
	User* u = &userMap.at(userId);
	u->post(tweetId, timestamp);
	timestamp++;
}

/**返回该 user 关注的⼈（包括他⾃⼰） 最近的动态 id，
最多 10 条， ⽽且这些动态必须按从新到旧的时间线顺序排列。*/
vector<int> Twitter::getNewsFeed(int userId)
{
	vector<int> res;
	priority_queue<Tweet*, vector<Tweet*>, cmp> PriorityQueue;
	if (!userMap.count(userId)) return res;
	// 关注列表的⽤户 Id
	unordered_set<int> users = userMap.at(userId).followed;
	// ⾃动通过 time 属性从⼤到⼩排序， 容量为 users 的⼤⼩

	// 先将所有链表头节点插⼊优先级队列
	for (int id : users) {
		Tweet* twt = userMap.at(id).head;
		if (twt == nullptr) {
			continue;
		}
		PriorityQueue.push(twt);
	}


	while (!PriorityQueue.empty()) {
		// 最多返回 10 条就够了
		if (res.size() == 10) break;
		// 弹出 time 值最⼤的（最近发表的）
		Tweet* twt = PriorityQueue.top();
		PriorityQueue.pop();
		res.push_back(twt->id);
		// 将下⼀篇 Tweet 插⼊进⾏排序
		if (twt->next != nullptr) {
			PriorityQueue.push(twt->next);
		}
	}

	return res;
}

/**follower 关注 followee */
void Twitter::follow(int followerId, int followeeId)
{
	// 若 follower 不存在， 则新建
	if (!userMap.count(followerId)) {
		userMap.emplace(followerId, User(followerId));
	}
	if (!userMap.count(followeeId)) {
		userMap.emplace(followeeId, User(followeeId));
	}
	userMap.at(followerId).follow(followeeId);
}

/**follower 取关 followee， 如果 Id 不存在则什么都不做 */
void Twitter::unfollow(int followerId, int followeeId)
{
	if (userMap.count(followerId)) {
		userMap.at(followerId).unfollow(followeeId);
	}
}

