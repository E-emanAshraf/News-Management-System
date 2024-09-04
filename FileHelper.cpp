#include "FileHelper.h"


void FileHelper::writeUsersToFile(const string& filename, vector<User>& users) {
    ofstream file(filename);
    if (!file.is_open()) {
        return;
    }

    for (auto& user : users) {
        // Write user credentials
        file << user.GetUserName() << "|" << user.GetPassword() << "|" << user.GetEmail() << "|";

        // Write favorite news data
        for (auto& news : user.GetFavourites()) {
            file << news.GetTitle() << "|" << news.GetDescription() << "|" << news.GetDate() << "|"
                << news.GetRate() << "|" << news.GetCategory() << "|";
        }

        file << "\n";
    }

    file.close();
}

void FileHelper::writeNewsToFile(const string& filename, unordered_map<string, vector<News>>& news) {
    ofstream outputFile(filename,ios::app); // Open file in append mode

    if (!outputFile.is_open()) {
        return;
    }

    for (auto& user : news) {
        for (auto& count : user.second) {
            outputFile << count;    // Write each news object to the file
        }
    }

    outputFile.close();
}


void FileHelper::writeCategories(const string& filename, list<string>& categories) {
    ofstream outputFile(filename, ios::app); // Open file in append mode
    if (!outputFile.is_open()) {
        return;
    }

    for (auto& c : categories) {
        outputFile << c << endl;    // Write each category to the file
    }

    outputFile.close();
}

list<string> FileHelper::readCategories(const string& filename) {
    list<string>categories;
    ifstream inputFile(filename); // Open file for reading

    if (!inputFile.is_open()) {
        return categories; // Return an empty list
    }

    string tempcategory;
    while (inputFile >> tempcategory) {
        categories.push_back(tempcategory); // Read each category from the file
    }

    inputFile.close();

    return categories;

}


vector<User> FileHelper::readUsersFromFile(const string& filename) {
    vector<User> users;

    ifstream file(filename);
    if (!file.is_open()) {
        return users; // Return empty vector if file cannot be opened
    }

    string line;
    while (getline(file, line)) {
        User user;
        istringstream iss(line);
        iss >> user;
        users.push_back(user); // Add user to the vector
    }

    file.close();

    return users;
}

unordered_map<string, vector<News>> FileHelper::readNewsFromFile(const string& filename) {
    unordered_map<string, vector<News>>news;

    ifstream inputFile(filename); // Open file for reading

    if (!inputFile.is_open()) {
        return news; // Return an empty unordered_map
    }

    News tempNews;
    while (inputFile >> tempNews) {
        news[tempNews.GetDate()].push_back(tempNews); // Read each news object from the file
    }

    inputFile.close();

    return news;
}



void FileHelper::clearFiles(const std::string& filename) {

    ofstream file(filename,ofstream::out |ofstream::trunc);
    file.close();
}




void FileHelper::WriteRatesToFile(const string& filePath, const unordered_map<string,unordered_map<string, int>>& rating_map) {
    ofstream outFile(filePath);
    if (!outFile.is_open()) {
        return;
    }

    for (const auto& outerPair : rating_map) {
        outFile << outerPair.first << "|";

        for (const auto& innerPair : outerPair.second) {
            outFile << innerPair.first << "|" << innerPair.second << "|";
        }
        outFile <<endl;
    }


}



unordered_map<string, unordered_map<string, int>> FileHelper::ReadRatesFromFile(const string& filePath) {
    unordered_map<string, unordered_map<string, int>> data;

    ifstream inFile(filePath);
    if (!inFile.is_open()) {
        return data;
    }

    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        string outerKey;
        if (!(getline(iss, outerKey, '|'))) {
            continue;
        }

        string innerKey;
        int value;
        unordered_map<string, int> innerMap;

        while (getline(iss, innerKey, '|') && iss >> value) {
            innerMap[innerKey] = value;
            iss.ignore(); // Ignore the '|' delimiter
        }

        data[outerKey] = innerMap;
    }


    return data;
}


void FileHelper::WriteCommentsToFile(const string& filePath, const unordered_map<string, vector<pair<string, string>>>& data) {
    ofstream outFile(filePath);
    if (!outFile.is_open()) {
        return;
    }

    for (const auto& entry : data) {
        outFile << entry.first << "|";
        for (const auto& pair : entry.second) {
            outFile << pair.first << "|" << pair.second << "|";
        }
        outFile << endl;
    }

    outFile.close();
}

unordered_map<string, vector<pair<string, string>>> FileHelper::ReadCommentsFromFile(const string& filePath) {
    unordered_map<string, vector<pair<string, string>>> data;

    ifstream inFile(filePath);
    if (!inFile.is_open()) {
        return data;
    }

    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        string outerKey;
        if (!(getline(iss, outerKey, '|'))) {
            continue;
        }

        string innerKey, value;
        vector<pair<std::string, std::string>> innerMap;

        while (std::getline(iss, innerKey, '|')) {
            if (!(getline(iss, value, '|'))) {
                break;
            }
            innerMap.push_back({ innerKey,value });
        }

        data[outerKey] = innerMap;
    }

    return data;
}



