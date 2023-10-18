/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 */

// @lc code=start
class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<forward_list<pair<int, double>>> adj(n); // from -> to, prob

        for (int i = 0; i < n; i++)
        {
            adj[edges[i][0]].push_front({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_front({edges[i][0], succProb[i]});
        }

        vector<double> prob(n, -1);
        priority_queue<pair<double, int>> heap;

        heap.push({0, start});

        while (!heap.empty())
        {
            auto currNode = heap.top();
            heap.pop();

            for (auto &neig : adj[currNode.second])
            {
                if (prob[neig.first] > prob[currNode.second] + currNode.first)
                {
                    prob[neig.first] = prob[currNode.second] + currNode.first;
                    heap.push({neig.first, prob[neig.first]});
                }
                vector<forward_list<pair<int, double>>> adj(n); // from -> to, prob

                for (int i = 0; i < n; i++)
                {
                    adj[edges[i][0]].push_front({edges[i][1], succProb[i]});
                    adj[edges[i][1]].push_front({edges[i][0], succProb[i]});
                }

                vector<double> prob(n, -1);
                priority_queue<pair<double, int>> heap;

                heap.push({0, start});

                while (!heap.empty())
                {
                    auto currNode = heap.top();
                    heap.pop();

                    for (auto &neig : adj[currNode.second])
                    {
                        if (prob[neig.first] < prob[currNode.second] + currNode.first)
                        {
                            prob[neig.first] = prob[currNode.second] + currNode.first;
                            heap.push({neig.first, prob[neig.first]});
                        }
                    }
                }

                return prob[end];
            }
            
        }

        return prob[end];
    
    }
};
// @lc code=end
