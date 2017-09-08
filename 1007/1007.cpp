    /* 
    *�����Ե����� 
    */  
      
    #include <iostream>  
    #include <algorithm>  
    #include <cmath>  
    using namespace std;  
    const int SIZE = 100005;  
    const int L = -1;  
    const int R = 1;  
      
     typedef struct   
    {  
        int index;    
        double x;  
        double y;   /*���ڼ�¼�����*/  
    }coord;  
      
    coord num[SIZE], c[SIZE]/*������������*/;  
      
    double getDistance(coord &bi1, coord &bi2)  /*�������֮��ľ���*/  
    {  
        return sqrt(pow(bi1.x - bi2.x, 2.0) + pow(bi1.y - bi2.y, 2.0));  
    }  
      
    bool cmpx(coord &bi1, coord &bi2)  
    {  
        if (bi1.x == bi1.x)  
            return bi1.y < bi2.y;  
        else  
        return bi1.x < bi2.x;  
    }  
      
    bool cmpy(coord &bi1, coord &bi2)  
    {  
        if (bi1.y == bi2.y)  
            return bi1.x < bi2.x;  
        else  
            return bi1.y < bi2.y;  
    }  
      
    inline double min(double &bi1, double &bi2, double &bi3)  
    {  
        double minLength;  
        minLength = bi1 > bi2 ? bi2 : bi1;  
        minLength = minLength > bi3 ? bi3 : minLength;  
        return minLength;  
    }  
      
    inline double minDist(double &bi1, double &bi2)  
    {  
        if (bi1 > bi2)  
            return bi2;  
        return bi1;  
    }  
      
      
    double divide_conquer(int low, int high) /*���η�����С����*/  
    {  
        double dis;  
        int count = high - low;  
        if (count == 0)  
        {  
            return 0;  
        }  
        else if (count == 1)  /*������*/  
        {  
            dis = getDistance(num[low], num[high]);  
        }  
        else if (count == 2)  /*������*/  
        {  
            double temp1, temp2, temp3;  
            temp1 = getDistance(num[low], num[low + 1]);  
            temp2 = getDistance(num[low + 1], num[high]);  
            temp3 = getDistance(num[low], num[high]);  
            dis = min(temp1, temp2, temp3);  
        }  
        else   /*���������������*/  
        {  
            double leftmin, rightmin, min;  
            int mid = (low + high) / 2;  
            int p = 0;  
            int i, j;  
      
            leftmin = divide_conquer(low, mid);  /*�����߲��ֵ���Сֵ*/  
            rightmin = divide_conquer(mid + 1, high);  /*����ұ߲��ֵ���Сֵ*/  
            dis = minDist(leftmin, rightmin);  
      
            /*�����������������ҳ�����x��leftCoord��rightCoord֮��ĵ�*/  
            for (i = low; i <= mid; i++)  
            {  
                double leftCoord = num[mid].x - dis;  
                if (num[i].x >= leftCoord)  
                {  
                    c[p].index = L;  /*��ʶ������߲���*/  
                    c[p].x = num[i].x;  
                    c[p].y = num[i].y;  
                    p++;  
                }  
            }  
            for ( ; i <= high; i++)  
            {  
                double rightCoord = num[mid].x + dis;  
                if (num[i].x <= rightCoord)  
                {  
                    c[p].index = R;  /*��ʶ�����ұ߲���*/  
                    c[p].x = num[i].x;  
                    c[p].y = num[i].y;  
                    p++;  
                }  
            }  
            sort(c, c + p, cmpy);   /*�ҵ��ĵ��ٴ�С������y����һ��*/  
            for (i = 0; i < p; i++)  
            {
                for (j = 1; (j <= 7) && (i + j < p); j++)  
                {     
                    if (c[i].index != c[i + j].index) /*��Сֵֻ���ܳ����������ֱ����ڲ�ͬ�ıߵĵ���*/  
                    {  
                        min = getDistance(c[i], c[i + j]);  
                        if(min < dis)  
                        dis = min;  
                    }  
                }  
            }  
        }  
        return dis;  
    }  
      
      
    int main ()  
    {  
        int n;  
        while (cin >> n && n != 0)  
        {  
            double result = 0;  
              
            for (int i = 0; i < n; i++)  
            {  
                num[i].index = 0;  
                cin >> num[i].x >> num[i].y;  
            }  
      
            sort (num, num + n, cmpx);  
      
            result = divide_conquer(0, n - 1);  
      
            printf("%.2lf\n", result / 2);  
        }  
        //system ("pause");  
        return 0;  
    }  
