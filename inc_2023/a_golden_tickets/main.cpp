#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; // team count
  int m; // top m teams to pass
  int k; // k teams to get golden ticket

  cin >> n >> m >> k;

  unordered_map<string, bool> inst_haswon_pair;
  inst_haswon_pair.reserve(100);
  vector<string> awarded_teams;
  awarded_teams.reserve(100);

  string team_name(12, '\0');
  string inst_name(12, '\0');
  for (int i = 0; i < n; i++) {
    std::cin >> team_name >> inst_name;
    if (i < m) {
      auto inst = inst_haswon_pair.find(inst_name);
      if (inst == inst_haswon_pair.end()) {
        inst_haswon_pair.insert({inst_name, true});
      }
      continue;
    }

    if (awarded_teams.size() < k) {
      auto inst = inst_haswon_pair.find(inst_name);
      if (inst == inst_haswon_pair.end()) {
        inst_haswon_pair.insert({inst_name, true});
        awarded_teams.push_back(team_name);
      }
      continue;
    }
  }

  cout << awarded_teams.size() << '\n';
  for (string team : awarded_teams) {
    cout << team << '\n';
  }

  return 0;
}
