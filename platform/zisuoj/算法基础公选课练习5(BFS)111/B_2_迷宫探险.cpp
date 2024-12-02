#include<iostream>
#include <queue>

using namespace std;

char grid[105][105];
int dirs[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int N;
int visited[105][105];

int inArea(int x,int y){
    return x>=0&&x<N&&y>=0&&y<N;
}

struct node
{
    int x,y,s;  // distance
    bool operator < (const node o) const
    {
        return s > o.s;
    }
}cur,nextN;

int floodfill(){
    priority_queue<node> q;  // 因为有障碍物，所以需要优先队列才能保证第一次遍历到的是最短路径
    cur.x=0;
    cur.y=0;
    cur.s=0;
    q.push(cur);
    visited[0][0]=1;
    while(!q.empty()){
        cur=q.top();
        q.pop();
        for(int d=0;d<4;d++){
            int nextx=cur.x+dirs[d][0];
            int nexty=cur.y+dirs[d][1];
            if(inArea(nextx,nexty)&&!visited[nextx][nexty]&&grid[nextx][nexty]!='#'){
                nextN.x=nextx;
                nextN.y=nexty;
                if(grid[nextx][nexty]>='1'&&grid[nextx][nexty]<='9'){
                    nextN.s=cur.s+grid[nextx][nexty]-'0'+1;
                }else{
                    nextN.s=cur.s+1;
                }
                q.push(nextN);
                visited[nextx][nexty]=1;
                if(nextx==N-1&&nexty==N-1){
                    return nextN.s;
                }
            }
        }
    }
    return -1;
}

int main()
{
    while(cin>>N){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>grid[i][j];
                visited[i][j]=1;
            }
        }
        int res=floodfill();
        cout << res << endl;
    }
    return 0;
}
