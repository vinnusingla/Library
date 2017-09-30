int maxhist(vector<int>a){
    int siz=a.size();
    int ans=INT_MIN;
    stack<int>s;
    vector<int>r(siz,0),l(siz,0);
    for(int i=siz-1;i>-1;i--){
        while(!s.empty() && a[s.top()]>=a[i])s.pop();
        if(s.empty())r[i]=siz;
        else r[i]=s.top();
        s.push(i);
    }
    while(!s.empty())s.pop();
    for(int i=0;i<siz;i++){
        while(!s.empty() && a[s.top()]>=a[i])s.pop();
        if(s.empty())l[i]=-1;
        else l[i]=s.top();
        s.push(i);
    }
    for(int i=0;i<siz;i++){
        ans=max(ans,(r[i]-l[i]-1)*a[i]);
    }
    
    return ans;
}
