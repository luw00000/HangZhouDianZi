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
//stick��ʾ��ǰ��ϺõĹ�����,len��ʾ���еĳ��ȣ�pos��ʾ�������ڼ���
//������� 
bool dfs(int stick,int len,int pos)
{
    int i;
    bool sign = (len == 0 ? true : false);
    if(stick == cnt)    //ȫ�������ϣ������ɹ�
    {
        return true;
    }
    for(i = pos + 1; i <= m; i++)
    {
        if(used[i]) continue;   //�����Ѿ��ù���
        if(len + a[i] == aim)   //�������������Ŀ��ͽ�����һ���ƥ��
        {
            used[i] = true;
            if(dfs(stick + 1, 0, 0))    //��ʼ��һ���ƥ��
                return true;
            used[i] = false;    //����һ������ʧ����֤����i����Ӧ��ʹ��
            return false;
        }
        else if(len + a[i] < aim) //���Ȳ���
        {
            used[i] = true; //��ǵ�i�����ӱ�ʹ��
            if(dfs(stick, len + a[i], i))   //���Ȳ������ٲ�������len + a[i]
            {
                return true;
            }
            used[i] = false;
            if(sign) return false;
            while(a[i] == a[i + 1]) i++; //��Ȼ���У��������������ͬ�Ķ�����
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
        //���� 
        sort(a + 1, a + m + 1, cmp);
        //ÿ��ľ�����Ϊ��ǰ�����ֵ 
        //�����ֵ�������ܳ��� 
        for(aim = a[1]; aim <= sum; aim++)
        {
        	//��ǰ�����ܱ�����������һ������ֵ 
            if(sum % aim == 0)
            {
                cnt = sum / aim; //��ʾ����ľ��������
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

