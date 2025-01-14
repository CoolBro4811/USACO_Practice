#include <bits/stdc++.h>
using namespace std;

void getOutput();

int main() {
	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
	
	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		getOutput();
	}

	return 0;
}

void getOutput() {
	int layers;
	cin >> layers;
	int *num_neurons_per_network_layer = int[layers];
	vector<vector<int>> network;
	for (int i = 0; i < layers; i++) {
		for (int j = 0; j < num_neurons_per_network_layer[i]; j++) {
			int in;
			cin >> in;
			network[i].push_back(in);
		}
	}
	cout << network;
}

