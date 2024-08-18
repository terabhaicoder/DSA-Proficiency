class Solution
{
public:
    typedef long long ll;

    int nthUglyNumber(int n)
    {
        // Create a min Heap
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        // Set to check so that we do not add the same number twice
        unordered_set<ll> vis;

        pq.push(1);
        vis.insert(1);

        ll val = 1;

        while (n > 0)
        {
            //Take the top element
            val = pq.top();
            pq.pop();
            n--; 

            if (vis.find(val * 2) == vis.end())
            {
                pq.push(val * 2);
                vis.insert(val * 2);
            }
            if (vis.find(val * 3) == vis.end())
            {
                pq.push(val * 3);
                vis.insert(val * 3);
            }
            if (vis.find(val * 5) == vis.end())
            {
                pq.push(val * 5);
                vis.insert(val * 5);
            }
        }

        return val; // After n iterations this is the number you get
    }
};