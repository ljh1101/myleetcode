#include <map>
#include <string>
using namespace std;
class AuthenticationManager {
  private:
    map<string, int> info;
    int time_to_live;

  public:
    AuthenticationManager(int timeToLive)
    {
        time_to_live = timeToLive;
    }

    void generate(string tokenId, int currentTime)
    {
        info.emplace(pair<string, int>(tokenId, currentTime));
    }

    void renew(string tokenId, int currentTime)
    {
        auto pos = info.find(tokenId);
        if (pos != info.end() && currentTime - pos->second < time_to_live) {
            pos->second = currentTime;
        }
    }

    int countUnexpiredTokens(int currentTime)
    {
        int count = 0;
        for (auto iter : info) {
            if (currentTime - iter.second < time_to_live) {
                ++count;
            }
        }
        return count;
    }
};
