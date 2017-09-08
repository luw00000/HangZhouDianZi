#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn = 70;
int m;
int a[maxn], used[maxn];
int aim, cnt;
bool cmp(int x,int y)
{
    return x > y;
}
//stick表示当前组合好的棍子数,len表示已有的长度，pos表示搜索到第几根
//深度搜索 
bool dfs(int stick,int len,int pos)
{
    int i;
    bool sign = (len == 0 ? true : false);
    if(stick == cnt)    //全部完成组合，搜索成功
    {
        return true;
    }
    for(i = pos + 1; i <= m; i++)
    {
        if(used[i]) continue;   //棍子已经用过了
        if(len + a[i] == aim)   //如果加起来等于目标就进行下一组的匹配
        {
            used[i] = true;
            if(dfs(stick + 1, 0, 0))    //开始下一组的匹配
                return true;
            used[i] = false;    //若下一层搜索失败则证明第i根不应该使用
            return false;
        }
        else if(len + a[i] < aim) //长度不够
        {
            used[i] = true; //标记第i根棍子被使用
            if(dfs(stick, len + a[i], i))   //长度不够就再补，所以len + a[i]
            {
                return true;
            }
            used[i] = false;
            if(sign) return false;
            while(a[i] == a[i + 1]) i++; //既然不行，那它后面跟它相同的都不行
        }
    }
    return false;
}
int main()
{
    int i,sum;
    while(cin >> m)
    {
    	if(m == 0) break; 
        sum = 0;
        for(i = 1; i <= m; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        //降序 
        sort(a + 1, a + m + 1, cmp);
        //每根木棍最短为当前的最大值 
        //从最大值递增到总长度 
        for(aim = a[1]; aim <= sum; aim++)
        {
        	//当前长度能被整除，则是一个可能值 
            if(sum % aim == 0)
            {
                cnt = sum / aim; //表示所需木棍的数量
                memset(used, false, sizeof(used));
                if(dfs(1, 0, 0))
                {
                    cout << aim << endl;
                    break;
                }
            }
        }
    }
    return 0;
}

