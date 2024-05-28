#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<pair<int, int>> q;
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    int visited[n][m];
    int time[n][m];
    int max_time = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            visited[i][j] = 0;
            time[i][j] = 0;
            cin >> arr[i][j];
            if(arr[i][j] == 2)
            {
                q.push(make_pair(i, j));
                visited[i][j] = 1;
            }
        }
    }
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();        
        int i = p.first;
        int j = p.second;
        if(i-1 >= 0 && arr[i-1][j] == 1 && visited[i-1][j] == 0)
        {
            q.push(make_pair(i-1, j));
            visited[i-1][j] = 1;
            time[i-1][j] = time[i][j] + 1;
            if(time[i-1][j] > max_time)
                max_time = time[i-1][j];
        }
        if(i+1 < n && arr[i+1][j] == 1 && visited[i+1][j] == 0)
        {
            q.push(make_pair(i+1, j));
            visited[i+1][j] = 1;
            time[i+1][j] = time[i][j] + 1;
            if(time[i+1][j] > max_time)
                max_time = time[i+1][j];
        }
        if(j-1 >= 0 && arr[i][j-1] == 1 && visited[i][j-1] == 0)
        {
            q.push(make_pair(i, j-1));
            visited[i][j-1] = 1;
            time[i][j-1] = time[i][j] + 1;
            if(time[i][j-1] > max_time)
                max_time = time[i][j-1];
        }
    }
    
}