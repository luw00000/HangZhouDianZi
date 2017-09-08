#include <iostream>
using namespace std;

int V[200][200];//ǰi����Ʒװ������Ϊj�ı����л�õ�����ֵ
int max(int a, int b)
{
   if(a >= b)
       return a;
   else return b;
}

int KnapSack(int n, int w[], int v[], int x[], int C)
{
    int i, j;
    for(i = 0; i <= n; i++) {
        V[i][0] = 0;
    } 
    for(j = 0; j <= C; j++) {
        V[0][j] = 0;
    } 
    for(i = 0; i <= n - 1; i++) {
        for(j = 0; j <= C; j++) {
            if(j < w[i])
                V[i][j] = V[i - 1][j];
            else
                V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]);
        }
	} 
    j = C;
    for(i = n - 1; i >= 0; i--) {
    	if(V[i][j] > V[i - 1][j]) {
            x[i] = 1;
            j = j - w[i];
        }
        else
            x[i] = 0;
    }
    printf("ѡ�е���Ʒ��:\n");
    for(i = 0; i < n; i++) { 
        printf("%d ", x[i]);
    } 
    printf("\n");
    return V[n - 1][C];
}

int main()
{
    int s;//��õ�����ֵ
    int w[15];//��Ʒ������
    int v[15];//��Ʒ�ļ�ֵ
    int x[15];//��Ʒ��ѡȡ״̬
    int n, i;
    int C;//�����������
    n = 5;
    printf("�����뱳�����������:\n");
    scanf("%d",&C);
    
    printf("������Ʒ��:\n");
    scanf("%d", &n);
    printf("��ֱ�������Ʒ������:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &w[i]);

    printf("��ֱ�������Ʒ�ļ�ֵ:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    s = KnapSack(n, w, v, x, C);

    printf("�����Ʒ��ֵΪ:\n");
    printf("%d\n",s);
   
    return 0;
}
