ll n; cin>>n;
    ll next=1;
    while(n--){
            string s; cin>>s;
            ll i=0,v=0;
            while(i<s.size()){
                if (T1[v][s[i]-'a']==-1){
                    T1[v][s[i]-'a']=next;
                    v=next;
                    next++;
                }
                else{
                    v=T1[v][s[i]-'a'];
                }
                ++i;
            }
    }
