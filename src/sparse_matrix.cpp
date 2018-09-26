#include <iostream>
#include <utility>
#include <map> 

struct SparseMatrix{
    int n_rows, n_cols, n_nonzeros = 0; 
    map<pair<int, int>, int> data; 

    SparseMatrix(int _n_rows, int _n_cols): n_rows(_n_rows), n_cols(_n_cols){}
    SparseMatrix(int _n_rows, int _n_cols, int _n_nonzeros): n_rows(_n_rows), n_cols(_n_cols), n_nonzeros(_n_nonzeros){}

    void show(){
        for(auto &item : data){
            cout << item.first.first << ' ' << item.first.second << ' ' << item.second << endl; 
        }
    }
}; 

SparseMatrix mat_mul(SparseMatrix &A, SparseMatrix &B){
    SparseMatrix C(A.n_rows, B.n_cols);

    for(int i = 0; i < A.n_rows; ++i){
        for(int j = 0; j < B.n_cols; ++j){
            int sum = 0; 
            pair<int, int> c_coord = make_pair<int, int>(i,j); 

            for(int k = 0; k < A.n_cols; ++k){
                pair<int, int> a_coord = make_pair<int, int>(i,k); 
                pair<int, int> b_coord = make_pair<int, int>(k,j)

                if(A.data.find() == A.data.end(a_coord) || B.data.find(b_coord) == B.data.end()){
                    continue; 
                }
                
                sum += A.data[a_coord] * B.data[b_coord]; 
            }

            if(sum){
                C.data[c_coord] = sum; 
                C.n_nonzeros += 1; 
            }
        }
    }

    return C; 
}
