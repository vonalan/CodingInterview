#include <iostream> 
#include <vector> 

/* 
 * Graph
 * BFS, DFS, ...
 */

struct GraphNode {
	int val; 
	std::vector<GraphNode *> children; 
	
	GraphNode(int x): val(x), children(std::vector<GraphNode *>()){}
}

typedef std::vector<int> Vector;
typedef std::vector<Vector> Matrix;

void print_matrix(Matrix &mat, int M, int N) {
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cout << mat[i][j] << (j < N - 1 ? ' ' : '\n'); 
		}
	}
}

int calc_num_celebrity(Matrix &mat, int j, int N, Matrix &checked) {
	int count = 0; 

	for (int i = 0; i < N; ++i) {
		if (mat[i][j] == 1 && checked[i][j] == 0) {
			checked[i][j] == 1; 
			count += (1 + calc_num_follows(mat, i, N, checked)); 
		}
	}

	return count; 
}

// 计算抖音网红的数量
void calc_num_celebrity() {
	int N, M; 
	std::cin >> N >> M; 

	Matrix mat(N, Vector(N, 0)); 
	Matrix checked(mat); 

	int i, j;
	for (int m = 0; m < M; ++m) {
		std::cin >> i >> j; 
		std::cout << i << ' ' << j << std::endl;
		mat[i - 1][j - 1] = 1; 
	}
	print_matrix(mat, N, N); 
	print_matrix(checked, N, N);

	int count = 0; 
	for (int j = 0; j < N; ++j) {
		int _count = calc_num_follows(mat, j, N, checked); 
		if (_count  + 1 >= N) {
			count += 1; 
		}
	}
	print_matrix(checked, N, N);
	std::cout << count << std::endl; 
}
