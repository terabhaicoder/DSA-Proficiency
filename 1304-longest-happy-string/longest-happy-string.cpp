class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Priority queue to always pick the character with the highest remaining count
        priority_queue<pair<int, char>> pq;

        // Add characters 'a', 'b', and 'c' with their counts to the queue
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string result = ""; // Resulting happy string

        while (!pq.empty()) {
            auto first = pq.top();
            pq.pop();

            // Check if the last two characters in the result are the same as the current character
            if (result.size() >= 2 && result[result.size() - 1] == first.second && result[result.size() - 2] == first.second) {
                if (pq.empty()) break; // If no other character to use, break

                auto second = pq.top();
                pq.pop();

                result += second.second; // Add the second character
                second.first--;          // Decrease the count

                if (second.first > 0) pq.push(second); // Push back if there are more of this character

                pq.push(first); // Push the first character back for future use
            } else {
                result += first.second; // Add the first character
                first.first--;          // Decrease the count

                if (first.first > 0) pq.push(first); // Push back if there are more of this character
            }
        }

        return result;
    }
};