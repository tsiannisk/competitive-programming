string s;
cin >> s;
for (int j = 0; j <= s.size(); j++) {
    for (int i = 0; i < s.size() - j; i++) {
		dp[i][i + j] = dp[i + 1][i + j] + 1;
		for (int k = i + 1; k <= i + j; k++) {
			if (s[k] == s[i]) {  
				dp[i][i + j] = min(dp[i][i + j], dp[i + 1][k - 1] + dp[k + 1][i + j]);
			}
		}
	}
}

