class Solution {
    struct Node {
        int max_len = 0;
        int pref_len = 0;
        int suff_len = 0;
        char pref_char = 0;
        char suff_char = 0;
        int size = 0;
    };

    void merge(Node& parent, const Node& left, const Node& right) {
        parent.size = left.size + right.size;
        parent.pref_char = left.pref_char;
        parent.suff_char = right.suff_char;

        parent.pref_len = left.pref_len;
        if (left.pref_len == left.size && left.pref_char == right.pref_char) {
            parent.pref_len = left.size + right.pref_len;
        }

        parent.suff_len = right.suff_len;
        if (right.suff_len == right.size && right.suff_char == left.suff_char) {
            parent.suff_len = right.size + left.suff_len;
        }

        parent.max_len = max(left.max_len, right.max_len);
        if (left.suff_char == right.pref_char) {
            parent.max_len = max(parent.max_len, left.suff_len + right.pref_len);
        }
    }

    void build(int idx, int l, int r, const string& s, vector<Node>& tree) {
        if (l == r) {
            tree[idx] = {1, 1, 1, s[l], s[l], 1};
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * idx, l, mid, s, tree);
        build(2 * idx + 1, mid + 1, r, s, tree);
        merge(tree[idx], tree[2 * idx], tree[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, char ch, vector<Node>& tree) {
        if (l == r) {
            tree[idx] = {1, 1, 1, ch, ch, 1};
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            update(2 * idx, l, mid, pos, ch, tree);
        } else {
            update(2 * idx + 1, mid + 1, r, pos, ch, tree);
        }
        merge(tree[idx], tree[2 * idx], tree[2 * idx + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        vector<Node> tree(4 * n);
        build(1, 0, n - 1, s, tree);

        int k = queryIndices.size();
        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i], tree);
            ans[i] = tree[1].max_len;
        }
        return ans;
    }
};