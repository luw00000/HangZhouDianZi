    /* 
    *最近点对的问题 
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
        double y;   /*用于记录坐标点*/  
    }coord;  
      
    coord num[SIZE], c[SIZE]/*用作辅助数组*/;  
      
    double getDistance(coord &bi1, coord &bi2)  /*求得两点之间的距离*/  
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
      
      
    double divide_conquer(int low, int high) /*分治法求最小距离*/  
    {  
        double dis;  
        int count = high - low;  
        if (count == 0)  
        {  
            return 0;  
        }  
        else if (count == 1)  /*两个数*/  
        {  
            dis = getDistance(num[low], num[high]);  
        }  
        else if (count == 2)  /*三个数*/  
        {  
            double temp1, temp2, temp3;  
            temp1 = getDistance(num[low], num[low + 1]);  
            temp2 = getDistance(num[low + 1], num[high]);  
            temp3 = getDistance(num[low], num[high]);  
            dis = min(temp1, temp2, temp3);  
        }  
        else   /*大于三个数的情况*/  
        {  
            double leftmin, rightmin, min;  
            int mid = (low + high) / 2;  
            int p = 0;  
            int i, j;  
      
            leftmin = divide_conquer(low, mid);  /*求得左边部分的最小值*/  
            rightmin = divide_conquer(mid + 1, high);  /*求得右边部分的最小值*/  
            dis = minDist(leftmin, rightmin);  
      
            /*下面从所有坐标点中找出所有x在leftCoord到rightCoord之间的点*/  
            for (i = low; i <= mid; i++)  
            {  
                double leftCoord = num[mid].x - dis;  
                if (num[i].x >= leftCoord)  
                {  
                    c[p].index = L;  /*标识属于左边部分*/  
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
                    c[p].index = R;  /*标识属于右边部分*/  
                    c[p].x = num[i].x;  
                    c[p].y = num[i].y;  
                    p++;  
                }  
            }  
            sort(c, c + p, cmpy);   /*找到的点再从小到大按照y排序一次*/  
            for (i = 0; i < p; i++)  
            {
                for (j = 1; (j <= 7) && (i + j < p); j++)  
                {     
                    if (c[i].index != c[i + j].index) /*最小值只可能出现在两个分别属于不同的边的点上*/  
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
