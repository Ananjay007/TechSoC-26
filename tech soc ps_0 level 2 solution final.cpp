#include <bits/stdc++.h>
using namespace std;

// Prints per-container weights, total/avg, max/min, and capacity check.
void solv(vector<int>& W) {
    int N = W.size();
    for (int i = 0; i < N; i++) {
        cout << "weight of container W" << i + 1 << " is " << W[i] << endl;
    }

    int Cap;
    cout << "enter the maximum storage capacity of port: ";
    cin >> Cap;

    int Total = 0;
    for (int i = 0; i < N; i++) {
        Total += W[i];
    }
    cout << "Total shipment weight: " << Total << endl;

    double avgW = (double)Total / N;
    cout << "Average container weight: " << avgW << endl;

    int maxi = W[0], mini = W[0];
    for (int i = 1; i < N; i++) {
        maxi = max(W[i], maxi);
        mini = min(W[i], mini);
    }
    cout << "Weight of heaviest container: " << maxi << endl;
    cout << "Weight of lightest container: " << mini << endl;

    if (Total <= Cap) {
        cout << "shipment can unload" << endl;
    } else {
        cout << "ship cannot unload" << endl;
    }
}

int main() {
    int shipno;
    cout << "please enter the no of ships to be unloaded: ";
    cin >> shipno;

    for (int k = 0; k < shipno; k++) {
        int N;
        cout << "enter the number of elements in the container" << endl;
        cin >> N;

        vector<int> W(N);
        for (int i = 0; i < N; i++) {
            cout << "enter the weight of container W" << i + 1 << endl;
            cin >> W[i];
        }

        solv(W);

        // Bubble sort ascending
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N - i - 1; j++) {
                if (W[j] > W[j + 1]) {
                    swap(W[j], W[j + 1]);
                }
            }
        }

        cout << "sorted weights: ";
        for (auto el : W) {
            cout << el << " ";
        }
        cout << endl;

        // Find whether a container of a given weight exists
        int weh;
        cout << "enter weight of container to know its name: ";
        cin >> weh;
        bool found = false;
        for (int l = 0; l < N; l++) {
            if (W[l] == weh) {
                cout << "container found (sorted position " << l + 1 << ")" << endl;
                found = true;
            }
        }
        if (!found) cout << "no container with that weight" << endl;

        // kth heaviest element (1-indexed): after ascending sort,
        // the heaviest is at the end, so kth heaviest = W[N - k]
        int o;
        cout << "enter k to know kth heaviest element: ";
        cin >> o;
        if (o >= 1 && o <= N) {
            cout << o << "th heaviest element is of weight " << W[N - o] << endl;
        } else {
            cout << "invalid k" << endl;
        }
    }
    return 0;
}