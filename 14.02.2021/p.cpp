#include <bits/stdc++.h>

struct hub
{
    long long num;
    long long capacity;
};

bool hub_sort(hub const &lhs, hub const &rhs)
{
    if (lhs.capacity != rhs.capacity)
        return lhs.capacity > rhs.capacity;
    return lhs.num > rhs.num;
}
int main()
{
    long long n, m;
    std::cin >> n >> m;
    std::vector<hub> hubs;
    long long cap;
    for (size_t i = 0; i < m; ++i)
    {
        std::cin >> cap;
        hubs.push_back({i, cap});
    }
    std::vector<long long> ans;
    std::sort(hubs.begin(), hubs.end(), &hub_sort);
    for (size_t i = 0; i < m && n > 0; ++i)
    {
        n -= hubs[i].capacity;
        if (n > 0)
        {
            n++;
        }
        if (i != 0)
        {
            n++;
        }
        ans.push_back(hubs[i].num);
    }
    if (n > 0)
    {
        std::cout << "Epic fail";
        return 0;
    }
    std::cout << ans.size() << std::endl;
    for (size_t i = 0; i < ans.size(); ++i)
    {
        std::cout << ans[i] + 1 << " ";
    }
}