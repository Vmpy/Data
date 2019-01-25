#include <iostream>

using namespace std;

int PointPre[10001];

int Find(int);
int Join(int,int);

int main(void)
{
    int N,M;
    cin >> N >> M;
    for(int i = 1;i <= N;i++)
    {
        PointPre[i] = i;
    }
    
    int Z,X,Y;
    for(int i = 0;i < M;i++)
    {
        cin >> Z >> X >> Y;
        switch(Z)
        {
            case 1:
            {
                Join(X,Y);
                break;
            }
            case 2:
            {
                if(Find(X) == Find(Y))
                {
                    cout << 'Y' << endl;
                }
                else
                {
                    cout << 'N' << endl;
                }
                break;
            }
        }
    }
    return 0;
}

int Find(int x)
{
    return PointPre[x] == x ? x:PointPre[x] = Find(PointPre[x]);
}

int Join(int x,int y)
{
    int fx = Find(x);
    int fy = Find(y);
    
    if(fx != fy)
    {
        PointPre[fx] = fy;
    }
    return 0;
}
