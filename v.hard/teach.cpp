#include <vector>
#include <unordered_set>
#include <algorithm>
#include<iostream>

class Solution {
public:
    // Calculates the minimum number of languages needed to be taught
    // such that every friendship is possible without a language barrier.
    int minimumTeachings(int totalLanguages, std::vector<std::vector<int>>& languages, std::vector<std::vector<int>>& friendships) {
        std::unordered_set<int> usersNeedingTeaching; // Contains IDs of users who need teaching

        // Check if users in each friendship speak a common language
        for (auto& friendship : friendships) {
            int user1 = friendship[0], user2 = friendship[1];
            // If users don't have a common language, add them to the set
            if (!shareCommonLanguage(user1, user2, languages)) {
                usersNeedingTeaching.insert(user1);
                usersNeedingTeaching.insert(user2);
            }
        }

        // If no users need teaching, return 0
        if (usersNeedingTeaching.empty()) {
            return 0;
        }

        // Count how many users speak each language
        std::vector<int> languageCounts(totalLanguages + 1);
        for (int user : usersNeedingTeaching) {
            for (int& language : languages[user - 1]) {
                ++languageCounts[language];
            }
        }

        // The number of teachings required is the size of users needing teaching
        // minus the most common language among them
        return usersNeedingTeaching.size() - *std::max_element(languageCounts.begin(), languageCounts.end());
    }

private:
    // Returns true if the two users share at least one common language
    bool shareCommonLanguage(int user1, int user2, std::vector<std::vector<int>>& languages) {
        for (int language1 : languages[user1 - 1]) {
            for (int language2 : languages[user2 - 1]) {
                if (language1 == language2) {
                    return true; // A common language is found
                }
            }
        }
        return false; // No common language between the two users
    }
};
int main() {
    Solution s;
    
    // Example input
    int totalLanguages = 3; // Total number of languages
    std::vector<std::vector<int>> languages = {
        {1, 2},   // User 1 knows languages 1 and 2
        {2, 3},   // User 2 knows languages 2 and 3
        {3}       // User 3 knows language 3
    };
    std::vector<std::vector<int>> friendships = {
        {1, 3},   // Friendship between User 1 and User 3
        {2, 3}    // Friendship between User 2 and User 3
    };

    // Calculate and print the minimum number of teachings required
    int result = s.minimumTeachings(totalLanguages, languages, friendships);
    std::cout << "Answer: " << result << std::endl;

    return 0;
}