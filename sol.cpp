#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		// create two hashmaps, one for the score, and the other is for the goal difference
		map<string, int> mp;
		map<string, int> goal_difference;
		for (int i = 0; i < 12; i++) {
			string home_team_name, away_team_name, versus;
			int home_team_goals, away_team_goals;
			cin >> home_team_name >> home_team_goals >> versus >> away_team_goals >> away_team_name;
			if (home_team_goals == away_team_goals) {
				// if two teams have the same score then they both get 1 point
				mp[home_team_name] = (mp.count(home_team_name) ? mp[home_team_name] + 1 : 1);
				mp[away_team_name] = (mp.count(away_team_name) ? mp[away_team_name] + 1 : 1);
			} else if (home_team_goals > away_team_goals) {
				// if the home team's score is greater then it receives 3 points
				mp[home_team_name] = (mp.count(home_team_name) ? mp[home_team_name] + 3 : 3);
			} else {
				// otherwise, the away team receives the 3 points
				mp[away_team_name] = (mp.count(away_team_name) ? mp[away_team_name] + 3 : 3);
			}
			// calculate the goal difference of every home team and away team
			// subtract the goals that they received from the goals that they've scored
			goal_difference[home_team_name] += home_team_goals - away_team_goals;
			goal_difference[away_team_name] += away_team_goals - home_team_goals;
		}
		string top_ranked_team = "";
		int largest_goal_score = INT_MIN;
		int largest_goal_difference = INT_MIN;
		for (auto x : mp) {
			// now find the largest score and if there are two same scores then check their goal difference
			if (x.second == largest_goal_score && goal_difference[x.first] > largest_goal_difference) {
				top_ranked_team = x.first;
				largest_goal_score = x.second;
				largest_goal_difference = goal_difference[x.first];				
			} else if (x.second > largest_goal_score) {
				top_ranked_team = x.first;
				largest_goal_score = x.second;
				largest_goal_difference = goal_difference[x.first];
			}
		}
		string second_top_ranked_team = "";
		int second_largest_goal_score = INT_MIN;
		int second_largest_goal_difference = INT_MIN;
		for (auto x : mp) {
			// now find the second largest score and if there are two same scores then check their goal difference
			// also, exclude the top ranked team in the checking
			if (x.second == second_largest_goal_score && goal_difference[x.first] > second_largest_goal_difference && x.first != top_ranked_team) {
				second_top_ranked_team = x.first;
				second_largest_goal_score = x.second;
				second_largest_goal_difference = goal_difference[x.first];				
			} else if (x.second > second_largest_goal_score && x.first != top_ranked_team) {
				second_top_ranked_team = x.first;
				second_largest_goal_score = x.second;
				second_largest_goal_difference = goal_difference[x.first];
			}
		}
		cout << top_ranked_team << " " << second_top_ranked_team << '\n';
	}
	return 0;
}