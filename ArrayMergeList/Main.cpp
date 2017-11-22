#include<iostream>
using namespace std;

int main(){
	int m, n;
	cin >> m >> n;

	int* array1 = new int[m];
	int* array2 = new int[n];

	if (m&&n){
		for (int i = 0; i < m; i++)
			cin >> array1[i];
		for (int i = 0; i < n; i++)
			cin >> array2[i];

		int* result = new int[m + n];
		int index1 = 0, index2 = 0;
		for (int i = 0; i < m + n; i++){
			if (index1<m&&index2<n)
				if (array1[index1] < array2[index2]){
					result[i] = array1[index1];
					index1++;
				}
				else{
					result[i] = array2[index2];
					index2++;
				}
			else
				if (array1[index1] < array2[index2]){
					result[i] = array2[index2];
					index2++;
				}
				else{
					result[i] = array1[index1];
					index1++;
				}
		}

		for (int i = 0; i < m + n; i++){
			cout << result[i];
			if (i != m + n - 1)
				cout << " ";
		}
	}

}