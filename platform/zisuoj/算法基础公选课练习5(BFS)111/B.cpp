#include<iostream>
#include <queue>
 
using namespace std;
 
struct node{
    int x,y,s;
}t,t1;
bool operator<(node a,node b){  // top是小的 
    return a.s>b.s;
}

priority_queue<node> q;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
 
char a[105][105];
int b[105][105];
 
int main()
{
    int f,x1,y1,n;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
                b[i][j]=0;
            }
        }
         
        t.x=1;
        t.y=1;
        t.s=0;
        f=0;  // 表示能否抵达终点 
        b[1][1]=1;
        q.push(t);
        while(!q.empty()){  // BFS
            t=q.top();
            q.pop();
            if(t.x==n && t.y==n){
                cout<<t.s<<'\n';
                f=1;
                break;
            }
             
            // 四个方向的最小时间 
            for(int i=0;i<4;i++){
                x1=t.x+dx[i];
                y1=t.y+dy[i];
                if(x1<1||x1>n||y1<1||y1>n) continue;
                if(b[x1][y1]==1||a[x1][y1]=='#') continue;
                
                b[x1][y1]=1;
                t1.x=x1;
                t1.y=y1;
                if(a[x1][y1]>='1'&&a[x1][y1]<='9'){
                    t1.s=t.s+a[x1][y1]-'0'+1;
                } else {
                    t1.s=t.s+1; 
                }
                q.push(t1);
            }
        }
        if(f==0) cout<<"-1\n";
        while(!q.empty()){
            q.pop();
        }
    }   
    return 0;
} 