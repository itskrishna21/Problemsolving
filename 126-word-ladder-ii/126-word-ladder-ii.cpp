class Solution {
public:
	vector<vector<string>> res;
	unordered_map<string, vector<string>> parents;
	vector<string> path;

	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> set(wordList.begin(), wordList.end());
		unordered_map<string, int> visited;

		int currLevel = 0, isFoundEndWord = 0;
		queue<string> q;
		q.push(beginWord);

		while(!q.empty() && !isFoundEndWord) {
			int queue_size = q.size();
			for(int orderPath = 1; orderPath <= queue_size; orderPath++) {
				string currWord = q.front();
				q.pop();

				for(int indexOfDiffrentCharacter = 0; indexOfDiffrentCharacter < currWord.size(); indexOfDiffrentCharacter++) {
					for(char diffCharacter = 'a'; diffCharacter <= 'z'; diffCharacter++) {
						string nextWord = currWord;
						nextWord[indexOfDiffrentCharacter] = diffCharacter;

						if(!set.count(nextWord))
							continue;

						if(visited.count(nextWord) && visited[nextWord] < currLevel)
							continue;

						parents[nextWord].push_back(currWord);

						if(!visited.count(nextWord)) q.push(nextWord);
						if(nextWord == endWord) isFoundEndWord = true;

						visited[nextWord] = currLevel;
					}
				}   
			}

			currLevel++;
		}

		dfs(beginWord, endWord);
		for(auto& path : res) 
			reverse(path.begin(), path.end());
		return res;
	}

	void dfs(string& beginWord, string& currWord) {
		path.push_back(currWord);

		if(currWord == beginWord) {
			res.push_back(path);
			path.pop_back();
			return;
		}

		for(auto& nextWord : parents[currWord]) 
			dfs(beginWord, nextWord);

		path.pop_back();
	}
};