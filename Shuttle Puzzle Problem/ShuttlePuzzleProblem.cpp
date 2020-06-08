bool game(string s,int h,string &ideal, vector<string> &ans)
{
    if(s==ideal)
    {
        return 1;
    }
 
    if(s[h-1]=='W')                     //*W_
    {
        swap(s[h-1],s[h]);
        ans.push_back(s);
        if(game(s,h-1,ideal,ans))
        return 1;
        ans.pop_back();
        swap(s[h-1],s[h]);
    }
    if(s[h+1]=='B')                     //_B*
    {
        swap(s[h+1],s[h]);
        ans.push_back(s);
        if(game(s,h+1,ideal,ans))
        return 1;
        ans.pop_back();
        swap(s[h+1],s[h]);
    }

    if(s[h-1]=='B' && s[h-2]=='W')      //WB_
    {
        swap(s[h-2],s[h]);
        ans.push_back(s);
        if(game(s,h-2,ideal,ans))
        return 1;
        ans.pop_back();
        swap(s[h-2],s[h]);
    }

    if(s[h+1]=='W' && s[h+2]=='B')      //_WB
    {
        swap(s[h+2],s[h]);
        ans.push_back(s);
        if(game(s,h+2,ideal,ans))
        return 1;
        ans.pop_back();
        swap(s[h+2],s[h]);
    }
    return 0;
}
vector<string> Solution::solve(int A) {
    vector<string> ans;
    string s;
    string ideal;
    for(int i=0;i<A;i++)
    {
        s.push_back('W');
        ideal.push_back('B');
    }
    s.push_back('H');
    ideal.push_back('H');
    for(int i=0;i<A;i++)
    {
        s.push_back('B');
        ideal.push_back('W');
    }
    ans.push_back(s);
    swap(s[A-1],s[A]);
    ans.push_back(s);
    game(s,A-1,ideal,ans);
    return ans;
}

Page 2 of 2
