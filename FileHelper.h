#pragma once
#include <iostream>
#include<string>
#include<sstream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<map>
#include<set>
#include<iterator>
#include<queue>
#include<stack>
#include <climits>
#include<unordered_map>
#include"News.h"
#include"User.h"
using namespace std;
class FileHelper
{
public:
	static void writeUsersToFile(const string& filename, vector<User>& users);
	static void writeNewsToFile(const string& filename, unordered_map<string, vector<News>>& news);
	static vector<User>readUsersFromFile(const string& filename);
	static unordered_map<string, vector<News>> readNewsFromFile(const string& filename);
	static void writeCategories(const string& filename, list<string>& categories);
	static list<string> readCategories(const string& filename);
	static void clearFiles(const string& filename);
    static unordered_map<string, unordered_map<string, int>> ReadRatesFromFile(const string& filePath);
	static void WriteRatesToFile(const string& filePath, const unordered_map<string, unordered_map<string, int>>& rating_map);
	static unordered_map<string, vector<pair<string, string>>> ReadCommentsFromFile(const string& filePath);
	static void WriteCommentsToFile(const std::string& filePath, const unordered_map<string, vector<pair<string, string>>>& data);
};
