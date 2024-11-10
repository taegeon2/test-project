#include <iostream>
#define SIZE 6 // 인덱스 0~5
#define INF 0x3f3f3f3f //i->j가 불가능한 상황
using namespace std;

int W[SIZE][SIZE], D[SIZE][SIZE], P[SIZE][SIZE];

void path(int q, int r) {
    if (P[q][r] != 0) {
        path(q, P[q][r]);
        cout << " v" << P[q][r];
        path(P[q][r], r);
    }
}

void floyd2(int n, int W[SIZE][SIZE], int D[SIZE][SIZE], int P[SIZE][SIZE]) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            P[i][j] = 0;
            D[i][j] = W[i][j];
        }
    }

    for (int k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) {
                    P[i][j] = k;
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int weight;
            cin >> weight;
            if (weight == -1) {
                W[i][j] = INF; // -1=경로 없음 의미
            } else {
                W[i][j] = weight;
            }
        }
    }

    floyd2(n, W, D, P);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (D[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << D[i][j] << " ";
            }
        }
        cout << '\n';
    }
    cout << '\n';

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout <<"i: " << i << " j: " << j<< endl;
            path(i,j);
            cout << endl;
        }
    }
}