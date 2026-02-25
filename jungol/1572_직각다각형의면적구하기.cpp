#include <bits/stdc++.h>
#define X first
#define Y second
using pii = std::pair<int,int>;
using namespace std;

const int LM = 2005; 

bool vert[LM][LM];  
bool horz[LM][LM];  
bool visited[LM][LM]; 

int main() {
#ifndef ONLINE_JUDGE
 freopen("data/1572.txt", "r", stdin);
#endif
 
 int N;
 scanf("%d", &N);
 vector<pii> pts(N);
 
 for (int i = 0; i < N; i++) 
   scanf("%d%d", &pts[i].X, &pts[i].Y);
 
 set<int> xs, ys;
 for (auto& p : pts) {
   xs.insert(p.X);
   ys.insert(p.Y);
 }
 
 for (int i = 0; i < N; i++) {
   int j = (i+1) % N;
   if (pts[i].X == pts[j].X) { 
     int x = pts[i].X;
     int y1 = pts[i].Y, y2 = pts[j].Y;
     if (y1 > y2) swap(y1, y2);
     
     for (int k = 0; k < N; k++) {
       int l = (k+1) % N;
       if (pts[k].Y == pts[l].Y) { 
         int y = pts[k].Y;
         int x1 = pts[k].X, x2 = pts[l].X;
         if (x1 > x2) swap(x1, x2);
         
         if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
           xs.insert(x);
           ys.insert(y);
         }
       }
     }
   }
 }
 
 vector<int> xv(xs.begin(), xs.end());
 vector<int> yv(ys.begin(), ys.end());
 int st = xv.size(), ed = yv.size();
 
 for (int i = 0; i < N; i++) {
   int j = (i+1) % N;
   int x1 = lower_bound(xv.begin(), xv.end(), pts[i].X) - xv.begin();
   int y1 = lower_bound(yv.begin(), yv.end(), pts[i].Y) - yv.begin();
   int x2 = lower_bound(xv.begin(), xv.end(), pts[j].X) - xv.begin();
   int y2 = lower_bound(yv.begin(), yv.end(), pts[j].Y) - yv.begin();
   
   if (x1 == x2) {
    int ymin = min(y1,y2);
    int ymax = max(y1,y2);
    for (int y = ymin; y < ymax; y++) {
      vert[x1][y] = true;
    }
   } else { 
    int xmin = min(x1,x2);
    int xmax = max(x1,x2);
    for (int x = xmin; x < xmax; x++) {
      horz[x][y1] = true;
    }
   }
 }
 
 int ans = 0;
 
 queue<pii> q;
 for (int i = 0; i < st-1; i++) {
   if (!horz[i][0]) { 
     q.push({i, 0});
     visited[i][0] = true;
   }
   if (!horz[i][ed-1]) {
     q.push({i, ed-2});
     visited[i][ed-2] = true;
   }
 }
 for (int j = 0; j < ed-1; j++) {
   if (!vert[0][j]) {
     q.push({0, j});
     visited[0][j] = true;
   }
   if (!vert[st-1][j]) {
     q.push({st-2, j});
     visited[st-2][j] = true;
   }
 }
 
 while (!q.empty()) {
   auto [x, y] = q.front(); q.pop();
   
   if (x > 0 && !vert[x][y] && !visited[x-1][y]) {
     visited[x-1][y] = true;
     q.push({x-1, y});
   }
   if (x < st-2 && !vert[x+1][y] && !visited[x+1][y]) {
     visited[x+1][y] = true;
     q.push({x+1, y});
   }
   if (y > 0 && !horz[x][y] && !visited[x][y-1]) {
     visited[x][y-1] = true;
     q.push({x, y-1});
   }
   if (y < ed-2 && !horz[x][y+1] && !visited[x][y+1]) {
     visited[x][y+1] = true;
     q.push({x, y+1});
   }
 }
 
 for (int i = 0; i < st-1; i++) {
   for (int j = 0; j < ed-1; j++) {
     if (visited[i][j]) continue; 
     
     queue<pii> q2;
     q2.push({i, j});
     visited[i][j] = true;
     int area = 0;
     
     while (!q2.empty()) {
       auto [x, y] = q2.front(); q2.pop();
       
       long long w = xv[x+1] - xv[x];
       long long h = yv[y+1] - yv[y];
       area += w * h;
       
       if (x > 0 && !vert[x][y] && !visited[x-1][y]) {
         visited[x-1][y] = true;
         q2.push({x-1, y});
       }
       if (x < st-2 && !vert[x+1][y] && !visited[x+1][y]) {
         visited[x+1][y] = true;
         q2.push({x+1, y});
       }
       if (y > 0 && !horz[x][y] && !visited[x][y-1]) {
         visited[x][y-1] = true;
         q2.push({x, y-1});
       }
       if (y < ed-2 && !horz[x][y+1] && !visited[x][y+1]) {
         visited[x][y+1] = true;
         q2.push({x, y+1});
       }
     }
     ans = max(ans, area);
   }
 }
 printf("%d\n", ans);
}