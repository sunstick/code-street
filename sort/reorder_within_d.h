/*
Given a string of lowercase characters, reorder them such that the same characters are at least distance d from each other.

Input: { a, b, b }, distance = 2
Output: { b, a, b }
*/

int find_max(int freq[], int dist[]) {
    int max_f = -1;
    int max_c = -1;

    for (char c = 'a'; c < 'z'; c++)
        if (dist[c] <= 0 && freq[c] > 0 && freq[c] > max_f) {
            max_f = freq[c];
            max_c = c;
        }

    return max_c;
}

// greedy approach
void reorder(const char *str, int d, char ans[]) {
    int n = strlen(str);
    int freq[256] = {0};
    int dist[256] = {0};

    for (int i = 0; i < n; i++)
        freq[str[i]]++;

    for (int i = 0; i < n; i++) {
        int j = find_max(freq, dist);
        if (j == -1)
            return ;

        ans[i] = j;
        dist[j] = d;
        freq[j]--;

        for (int i = 0; i < 256; i++)
            dist[i]--;
    }

    ans[n] = '\0';
}

void test() {
    string str = "bbaassmnbw";
    int d = 3;
    char *ans = new char[100];
    memset(ans, 0, sizeof(ans));

    reorder(str.c_str(), d, ans);
    cout << ans << endl;
}
