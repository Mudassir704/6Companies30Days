#include <bits/stdc++.h>
using namespace std;
vector<int> minHeap(10);
map<int, bool> mp;
int cnt = 0;

void heapify(int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < cnt && minHeap[l] < minHeap[smallest])
        smallest = l;
    if (r < cnt && minHeap[r] < minHeap[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(minHeap[i], minHeap[smallest]);
        heapify(smallest);
    }
}

void add(int x)
{
    if (!mp[x])
    {
        mp[x] = true;
        if (cnt < 10)
        {
            minHeap[cnt] = x;
            heapify(0);
            cnt++;
        }
        else
        {
            if (minHeap[0] < x)
            {
                minHeap[0] = x;
                heapify(0);
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter 10 million+ numbers" << '\n';
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        add(a);
    }
    for (int i = 0; i < 10; i++)
        cout << minHeap[i] << " ";
}
