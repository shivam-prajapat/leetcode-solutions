class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int start_r = -1, start_c = -1;
        vector<pair<int, int>> litters;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    start_r = r;
                    start_c = c;
                } else if (classroom[r][c] == 'L') {
                    litters.push_back({r, c});
                }
            }
        }

        int k = litters.size();
        int target_mask = (1 << k) - 1;

        vector<vector<int>> litter_id(m, vector<int>(n, -1));
        for (int i = 0; i < k; ++i) {
            litter_id[litters[i].first][litters[i].second] = i;
        }

        int initial_mask = 0;
        if (litter_id[start_r][start_c] != -1) {
            initial_mask |= (1 << litter_id[start_r][start_c]);
        }

        if (initial_mask == target_mask) return 0;

        vector<vector<vector<int>>> max_energy(m, vector<vector<int>>(n, vector<int>(1 << k, -1)));
        queue<tuple<int, int, int>> q;

        q.push({start_r, start_c, initial_mask});
        max_energy[start_r][start_c][initial_mask] = energy;

        int moves = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, mask] = q.front();
                q.pop();

                int e = max_energy[r][c][mask];
                if (e == 0) continue;

                for (int i = 0; i < 4; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        char cell = classroom[nr][nc];
                        if (cell == '#' || cell == 'X') continue;

                        int ne = (cell == 'R') ? energy : e - 1;
                        int nmask = mask;
                        if (litter_id[nr][nc] != -1) {
                            nmask |= (1 << litter_id[nr][nc]);
                        }

                        if (nmask == target_mask) {
                            return moves + 1;
                        }

                        if (ne > max_energy[nr][nc][nmask]) {
                            max_energy[nr][nc][nmask] = ne;
                            q.push({nr, nc, nmask});
                        }
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};